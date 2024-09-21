#include "common.h"
#include "ntdll.h"
#include <shlwapi.h>
#include <softpub.h>
#include <sspi.h>
#include <mscat.h>
#include <schannel.h>
#include <winioctl.h>

#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "wintrust.lib")
#pragma comment(lib, "rpcrt4.lib")

VOID Util::PrintLastError(IN DWORD ErrorCode)
{
    LPWSTR pwszErrorMessage = NULL;

    FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        ErrorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPWSTR)&pwszErrorMessage,
        0,
        NULL
    );

    if (!pwszErrorMessage)
        return;

    wprintf(L"[-] Error code %d | 0x%08x | %ws", ErrorCode, ErrorCode, pwszErrorMessage);

    LocalFree(pwszErrorMessage);
}

// https://gist.github.com/ccbrown/9722406
VOID Util::PrintBuffer(IN PVOID Buffer, IN DWORD Size)
{
    wchar_t ascii[17];
    size_t i, j;
    ascii[16] = L'\0';
    for (i = 0; i < Size; ++i) {
        wprintf(L"%02X ", ((unsigned char*)Buffer)[i]);
        if (((unsigned char*)Buffer)[i] >= ' ' && ((unsigned char*)Buffer)[i] <= '~') {
            ascii[i % 16] = ((unsigned char*)Buffer)[i];
        }
        else {
            ascii[i % 16] = L'.';
        }
        if ((i + 1) % 8 == 0 || i + 1 == Size) {
            wprintf(L" ");
            if ((i + 1) % 16 == 0) {
                wprintf(L"|  %ws \n", ascii);
            }
            else if (i + 1 == Size) {
                ascii[(i + 1) % 16] = L'\0';
                if ((i + 1) % 16 <= 8) {
                    wprintf(L" ");
                }
                for (j = (i + 1) % 16; j < 16; ++j) {
                    wprintf(L"   ");
                }
                wprintf(L"|  %ws \n", ascii);
            }
        }
    }
}

//VOID Util::PressEnterToContinue()
//{
//    wprintf(L"Press ENTER to continue...");
//    int c = getc(stdin);
//    return;
//}

BOOL Util::AddCatalogFile(IN LPWSTR FilePath)
{
    BOOL bResult = FALSE;
    GUID dav = DRIVER_ACTION_VERIFY;
    HCATADMIN hCatAdmin = NULL;
    HCATINFO hCatInfo = NULL;

    EXIT_ON_ERROR(!CryptCATAdminAcquireContext(&hCatAdmin, &dav, 0));
    EXIT_ON_ERROR((hCatInfo = CryptCATAdminAddCatalog(hCatAdmin, FilePath, NULL, CRYPTCAT_ADDCATALOG_HARDLINK)) == NULL);
    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());
    if (hCatInfo) CryptCATAdminReleaseCatalogContext(hCatAdmin, hCatInfo, 0);
    if (hCatAdmin) CryptCATAdminReleaseContext(hCatAdmin, 0);

    return bResult;
}

BOOL Util::RemoveCatalogFile(IN LPWSTR FilePath)
{
    BOOL bResult = FALSE;
    GUID dav = DRIVER_ACTION_VERIFY;
    HCATADMIN hCatAdmin = NULL;

    EXIT_ON_ERROR(!CryptCATAdminAcquireContext(&hCatAdmin, &dav, 0));
    EXIT_ON_ERROR(!CryptCATAdminRemoveCatalog(hCatAdmin, FilePath, 0));
    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());
    if (hCatAdmin) CryptCATAdminReleaseContext(hCatAdmin, 0);

    return bResult;
}

ULONG_PTR Util::GetProcedureAddress(IN LPCWSTR Module, IN LPCSTR Procedure)
{
    ULONG_PTR proc = 0;
    HMODULE hModule;

    if ((hModule = GetModuleHandleW(Module)) != NULL)
        proc = (ULONG_PTR)GetProcAddress(hModule, Procedure);

    return proc;
}

BOOL Filesystem::PathExists(IN LPWSTR FilePath)
{
    return PathFileExistsW(FilePath);
}

BOOL Filesystem::PathIsAbsolute(IN LPWSTR FilePath)
{
    return !PathIsRelativeW(FilePath);
}

HANDLE Filesystem::SetFileOpLock(IN LPCWSTR FilePath, IN DWORD ShareMode, IN BOOL Exclusive, IN OUT LPOVERLAPPED Overlapped)
{
    BOOL bResult = FALSE;
    HANDLE hFile = INVALID_HANDLE_VALUE;
    DWORD dwBytesReturned, dwControlCode;

    dwControlCode = Exclusive ? FSCTL_REQUEST_OPLOCK_LEVEL_1 : FSCTL_REQUEST_OPLOCK;

    hFile = CreateFileW(FilePath, GENERIC_READ, ShareMode, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        Util::PrintLastError(GetLastError());
        goto cleanup;
    }

    EXIT_ON_ERROR((Overlapped->hEvent = CreateEventW(NULL, FALSE, FALSE, NULL)) == NULL);

    if (!DeviceIoControl(hFile, dwControlCode, NULL, 0, NULL, 0, &dwBytesReturned, Overlapped))
    {
        if (GetLastError() != ERROR_IO_PENDING)
        {
            Util::PrintLastError(GetLastError());
            goto cleanup;
        }
    }

    bResult = TRUE;

cleanup:
    if (!bResult)
    {
        //PRINT_ERROR(L"Failed to create oplock on file '%ws'.", FilePath);
        if (Overlapped->hEvent) CloseHandle(Overlapped->hEvent);
        if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);
        hFile = INVALID_HANDLE_VALUE;
    }

    return hFile;
}

SC_HANDLE Service::Open(IN LPCWSTR ServiceName, DWORD DesiredAccess)
{
    SC_HANDLE hSCM = NULL, hService = NULL;

    EXIT_ON_ERROR((hSCM = OpenSCManagerW(NULL, SERVICES_ACTIVE_DATABASE, SC_MANAGER_CONNECT)) == NULL);
    EXIT_ON_ERROR((hService = OpenServiceW(hSCM, ServiceName, DesiredAccess)) == NULL);

cleanup:
    if (!hService) Util::PrintLastError(GetLastError());
    if (hSCM) CloseServiceHandle(hSCM);

    return hService;
}

BOOL Service::QueryStatus(IN SC_HANDLE ServiceHandle, OUT LPSERVICE_STATUS_PROCESS ServiceStatus)
{
    BOOL bResult = FALSE;
    DWORD dwBytesNeeded;

    EXIT_ON_ERROR(!QueryServiceStatusEx(ServiceHandle, SC_STATUS_PROCESS_INFO, (LPBYTE)ServiceStatus, sizeof(*ServiceStatus), &dwBytesNeeded));
    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());

    return bResult;
}

BOOL Service::QueryState(IN SC_HANDLE ServiceHandle, OUT LPDWORD State)
{
    BOOL bResult = FALSE;
    SERVICE_STATUS_PROCESS ssp;

    EXIT_ON_ERROR(!Service::QueryStatus(ServiceHandle, &ssp));
    *State = ssp.dwCurrentState;
    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());

    return bResult;
}

BOOL Service::QueryState(IN LPCWSTR ServiceName, OUT LPDWORD State)
{
    BOOL bResult = FALSE;
    SC_HANDLE hService = NULL;
    DWORD dwServiceState;

    EXIT_ON_ERROR((hService = Service::Open(ServiceName, SERVICE_QUERY_STATUS)) == NULL);
    EXIT_ON_ERROR(!Service::QueryState(hService, &dwServiceState));
    *State = dwServiceState;
    bResult = TRUE;

cleanup:
    if (hService) Service::Close(hService);

    return bResult;
}

BOOL Service::QueryPid(IN SC_HANDLE ServiceHandle, OUT LPDWORD ProcessId)
{
    BOOL bResult = FALSE;
    SERVICE_STATUS_PROCESS ssp;

    EXIT_ON_ERROR(!Service::QueryStatus(ServiceHandle, &ssp));
    *ProcessId = ssp.dwProcessId;
    bResult = TRUE;

cleanup:

    return bResult;
}

BOOL Service::Start(IN SC_HANDLE ServiceHandle, IN BOOL Wait)
{
    BOOL bResult = FALSE;
    SERVICE_STATUS_PROCESS ssp;
    DWORD64 dwStartTime;
    DWORD dwWaitTime;

    ZeroMemory(&ssp, sizeof(ssp));
    dwStartTime = GetTickCount64();

    EXIT_ON_ERROR(!StartServiceW(ServiceHandle, 0, NULL));
    EXIT_ON_ERROR(!Service::QueryStatus(ServiceHandle, &ssp));

    if (Wait)
    {
        while (ssp.dwCurrentState != SERVICE_RUNNING)
        {
            if (ssp.dwWin32ExitCode)
            {
                SetLastError(ssp.dwWin32ExitCode);
                break;
            }

            if (ssp.dwServiceSpecificExitCode)
            {
                SetLastError(ssp.dwServiceSpecificExitCode);
                break;
            }

            dwWaitTime = ssp.dwWaitHint / 10;

            if (dwWaitTime < 1000)
                dwWaitTime = 1000;
            else if (dwWaitTime > 10000)
                dwWaitTime = 10000;

            Sleep(dwWaitTime);

            if (!Service::QueryStatus(ServiceHandle, &ssp))
                break;

            if (GetTickCount64() - dwStartTime > TIMEOUT)
            {
                SetLastError(ERROR_TIMEOUT);
                break;
            }
        }

        bResult = ssp.dwCurrentState == SERVICE_RUNNING;
    }
    else
    {
        bResult = TRUE;
    }

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());

    return bResult;
}

BOOL Service::Start(IN LPCWSTR ServiceName, IN BOOL Wait)
{
    BOOL bResult = FALSE;
    SC_HANDLE hService = NULL;

    EXIT_ON_ERROR((hService = Service::Open(ServiceName, SERVICE_QUERY_STATUS | SERVICE_START)) == NULL);
    EXIT_ON_ERROR(!Service::Start(hService, Wait));
    bResult = TRUE;

cleanup:
    if (hService) Service::Close(hService);

    return bResult;
}

BOOL Service::Stop(IN SC_HANDLE ServiceHandle, IN BOOL Wait)
{
    BOOL bResult = FALSE;
    SERVICE_STATUS_PROCESS ssp;
    DWORD64 dwStartTime;
    DWORD dwWaitTime;

    ZeroMemory(&ssp, sizeof(ssp));
    dwStartTime = GetTickCount64();

    EXIT_ON_ERROR(!ControlService(ServiceHandle, SERVICE_CONTROL_STOP, (LPSERVICE_STATUS)&ssp));
    EXIT_ON_ERROR(!Service::QueryStatus(ServiceHandle, &ssp));

    if (Wait)
    {
        while (ssp.dwCurrentState != SERVICE_STOPPED)
        {
            if (ssp.dwWin32ExitCode)
            {
                SetLastError(ssp.dwWin32ExitCode);
                break;
            }

            if (ssp.dwServiceSpecificExitCode)
            {
                SetLastError(ssp.dwServiceSpecificExitCode);
                break;
            }

            dwWaitTime = ssp.dwWaitHint / 10;

            if (dwWaitTime < 1000)
                dwWaitTime = 1000;
            else if (dwWaitTime > 10000)
                dwWaitTime = 10000;

            Sleep(dwWaitTime);

            if (!Service::QueryStatus(ServiceHandle, &ssp))
                break;

            if (GetTickCount64() - dwStartTime > TIMEOUT)
            {
                SetLastError(ERROR_TIMEOUT);
                break;
            }
        }

        bResult = ssp.dwCurrentState == SERVICE_STOPPED;
    }
    else
    {
        bResult = TRUE;
    }

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());

    return bResult;
}

BOOL Service::Stop(IN LPCWSTR ServiceName, IN BOOL Wait)
{
    BOOL bResult = FALSE;
    SC_HANDLE hService = NULL;

    EXIT_ON_ERROR((hService = Service::Open(ServiceName, SERVICE_QUERY_STATUS | SERVICE_STOP)) == NULL);
    EXIT_ON_ERROR(!Service::Stop(hService, Wait));
    bResult = TRUE;

cleanup:
    if (hService) Service::Close(hService);

    return bResult;
}

VOID Service::Close(IN SC_HANDLE ServiceHandle)
{
    if (ServiceHandle)
        CloseServiceHandle(ServiceHandle);
}

DWORD Process::FindProcessId(IN LPCWSTR ProcessName)
{
    DWORD dwProcessId = 0;
    NTSTATUS status;
    DWORD dwReturnLen;
    PSYSTEM_PROCESS_INFORMATION pProcInfo = NULL, pProcInfoIndex;

    status = NtQuerySystemInformation(SystemProcessInformation, NULL, 0, &dwReturnLen);
    if (!NT_SUCCESS(status))
    {
        if (status != STATUS_INFO_LENGTH_MISMATCH)
        {
            SetLastError(RtlNtStatusToDosError(status));
            goto cleanup;
        }
    }

    EXIT_ON_ERROR((pProcInfo = (PSYSTEM_PROCESS_INFORMATION)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwReturnLen)) == NULL);

    status = NtQuerySystemInformation(SystemProcessInformation, pProcInfo, dwReturnLen, &dwReturnLen);
    if (!NT_SUCCESS(status))
    {
        SetLastError(RtlNtStatusToDosError(status));
        goto cleanup;
    }

    for (
        pProcInfoIndex = pProcInfo;
        pProcInfoIndex->NextEntryOffset != 0;
        pProcInfoIndex = (PSYSTEM_PROCESS_INFORMATION)((PBYTE)pProcInfoIndex + pProcInfoIndex->NextEntryOffset))
    {
        if (pProcInfoIndex->ImageName.Buffer)
        {
            if (!_wcsicmp(pProcInfoIndex->ImageName.Buffer, ProcessName))
            {
                dwProcessId = HandleToULong(pProcInfoIndex->UniqueProcessId);
                break;
            }
        }
    }

cleanup:
    if (!dwProcessId) Util::PrintLastError(GetLastError());
    if (pProcInfo) HeapFree(GetProcessHeap(), 0, pProcInfo);

    return dwProcessId;
}

BOOL Process::QueryProtectionLevel(IN DWORD ProcessId, IN OUT PPS_PROTECTION Protection)
{
    BOOL bResult = FALSE;
    HANDLE hProcess = NULL;

    EXIT_ON_ERROR((hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, ProcessId)) == NULL);
    EXIT_ON_ERROR(!Process::QueryProtectionLevel(hProcess, Protection));

    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());
    if (hProcess) CloseHandle(hProcess);

    return bResult;
}

BOOL Process::QueryProtectionLevel(IN HANDLE ProcessHandle, IN OUT PPS_PROTECTION Protection)
{
    BOOL bResult = FALSE;
    NTSTATUS status;

    if (!NT_SUCCESS(status = NtQueryInformationProcess(ProcessHandle, (PROCESSINFOCLASS)PROCESS_PROTECTION_INFORMATION, Protection, sizeof(*Protection), NULL)))
    {
        SetLastError(RtlNtStatusToDosError(status));
        goto cleanup;
    }

    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());

    return bResult;
}

BOOL Process::IsModuleLoaded(IN DWORD ProcessId, IN LPCWSTR ModuleName)
{
    BOOL bModuleFound = FALSE, bFreeModule = FALSE;
    HMODULE hModule = NULL;
    HANDLE hProcess = NULL;
    CLIENT_ID cid = { 0 };
    OBJECT_ATTRIBUTES ObjectAttributes = { 0 };
    MEMORY_BASIC_INFORMATION mbi = { 0 };

    if ((hModule = GetModuleHandleW(ModuleName)) == NULL)
    {
        EXIT_ON_ERROR((hModule = LoadLibraryW(ModuleName)) == NULL);
        bFreeModule = TRUE;
    }

    cid.UniqueProcess = (HANDLE)(ULONG_PTR)ProcessId;

    EXIT_ON_ERROR(!NT_SUCCESS(NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, &ObjectAttributes, &cid)));
    EXIT_ON_ERROR(!NT_SUCCESS(NtQueryVirtualMemory(hProcess, hModule, MemoryBasicInformation, &mbi, sizeof(mbi), NULL)));
    
    bModuleFound = mbi.AllocationBase == hModule;

cleanup:
    if (hProcess) NtClose(hProcess);
    if (bFreeModule) FreeLibrary(hModule);

    return bModuleFound;
}

BOOL Registry::QueryValue(IN HKEY Key, IN LPCWSTR SubKey, IN OPTIONAL LPCWSTR ValueName, OUT OPTIONAL LPDWORD Type, OUT LPBYTE* Data, IN OUT LPDWORD DataSize)
{
    BOOL bResult = FALSE;
    LSTATUS status = ERROR_SUCCESS;
    HKEY hKey = NULL;

    EXIT_ON_ERROR((status = RegOpenKeyExW(Key, SubKey, 0, KEY_QUERY_VALUE, &hKey)) != ERROR_SUCCESS);
    EXIT_ON_ERROR((status = RegQueryValueExW(hKey, ValueName, NULL, Type, NULL, DataSize)) != ERROR_SUCCESS);
    EXIT_ON_ERROR((*Data = (LPBYTE)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, *DataSize)) == NULL);
    EXIT_ON_ERROR((status = RegQueryValueExW(hKey, ValueName, NULL, Type, *Data, DataSize)) != ERROR_SUCCESS);

    bResult = TRUE;

cleanup:
    if (!bResult && *Data) HeapFree(GetProcessHeap(), 0, *Data);
    if (hKey) RegCloseKey(hKey);

    if (!bResult) SetLastError(status);

    return bResult;
}

BOOL Registry::SetValue(IN HKEY Key, IN LPCWSTR SubKey, IN OPTIONAL LPCWSTR ValueName, IN DWORD Type, IN LPBYTE Data, IN DWORD DataSize)
{
    BOOL bResult = FALSE;
    LSTATUS status = ERROR_SUCCESS;
    HKEY hKey = NULL;

    EXIT_ON_ERROR((status = RegOpenKeyExW(Key, SubKey, 0, KEY_SET_VALUE, &hKey)) != ERROR_SUCCESS);
    EXIT_ON_ERROR((status = RegSetValueExW(hKey, ValueName, NULL, Type, Data, DataSize)) != ERROR_SUCCESS);

    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(status);
    if (hKey) RegCloseKey(hKey);

    return bResult;
}

BOOL Registry::DeleteValue(IN HKEY Key, IN OPTIONAL LPCWSTR SubKey, IN LPCWSTR ValueName)
{
    BOOL bResult = FALSE;
    LSTATUS status = ERROR_SUCCESS;
    HKEY hKey = NULL;

    if (SubKey)
    {
        EXIT_ON_ERROR((status = RegOpenKeyExW(Key, SubKey, 0, KEY_SET_VALUE, &hKey)) != ERROR_SUCCESS);
    }
    else
    {
        hKey = Key;
    }

    EXIT_ON_ERROR((status = RegDeleteValueW(hKey, ValueName)) != ERROR_SUCCESS);
    bResult = TRUE;

cleanup:
    if (!bResult) Util::PrintLastError(GetLastError());

    return bResult;
}

RPC_BINDING_HANDLE KeyIso::CreateBindingHandle()
{
    RPC_STATUS status = RPC_S_OK;
    RPC_BINDING_HANDLE hBinding = NULL;
    RPC_WSTR strBinding = NULL;

    EXIT_ON_ERROR((status = RpcStringBindingComposeW(NULL, (RPC_WSTR)L"ncalrpc", NULL, NULL, NULL, &strBinding)) != RPC_S_OK);
    EXIT_ON_ERROR((status = RpcBindingFromStringBindingW(strBinding, &hBinding)) != RPC_S_OK);
    EXIT_ON_ERROR((status = RpcBindingSetAuthInfoExW(hBinding, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_AUTHN_DEFAULT, NULL, 0, NULL)) != RPC_S_OK);

cleanup:
    if (status != RPC_S_OK) Util::PrintLastError(status);
    if (strBinding) RpcStringFreeW(&strBinding);

    return hBinding;
}

VOID KeyIso::CloseBindingHandle(IN RPC_BINDING_HANDLE BindingHandle)
{
    RpcBindingFree(&BindingHandle);
}

RPC_STATUS KeyIso::CreateContext(IN RPC_BINDING_HANDLE BindingHandle, OUT PVOID* ContextHandle)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCreateContext(BindingHandle, ContextHandle);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::ReleaseContext(IN RPC_BINDING_HANDLE BindingHandle, IN OUT PVOID* ContextHandle)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcReleaseContext(BindingHandle, ContextHandle);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptOpenStorageProvider(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, OUT PVOID* ProviderHandle, IN LPCWSTR ProviderName)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCryptOpenStorageProvider(BindingHandle, ContextHandle, (PLONG_PTR)ProviderHandle, ProviderName, 0);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptFreeProvider(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCryptFreeProvider(BindingHandle, ContextHandle, (LONG_PTR)ProviderHandle);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptEnumKeys(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN PULONG_PTR Buffer)
{
    RPC_STATUS status;
    _NCryptKeyName* ckn = NULL;

    __try
    {
        status = s_SrvRpcCryptEnumKeys(BindingHandle, ContextHandle, (LONG_PTR)ProviderHandle, NULL, &ckn, (PLONG_PTR)Buffer, 0);

        if (ckn)
        {
            //
            // CryptFreeBuffer returns the error code 0x80090027 (NTE_INVALID_PARAMETER).
            //

            KeyIso::CryptFreeBuffer(BindingHandle, ContextHandle, (ULONG_PTR)ckn);
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptFreeBuffer(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN ULONG_PTR Buffer)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCryptFreeBuffer(BindingHandle, ContextHandle, Buffer);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptGetProviderProperty(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN LPCWSTR PropertyName, IN OUT PVOID Buffer, IN DWORD BufferSize, OUT LPLONG Written)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCryptGetProviderProperty(BindingHandle, ContextHandle, (LONG_PTR)ProviderHandle, PropertyName, (PBYTE)Buffer, BufferSize, Written, 0);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptSetProviderProperty(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN LPCWSTR PropertyName, IN PVOID Buffer, IN DWORD BufferSize)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCryptSetProviderProperty(BindingHandle, ContextHandle, (LONG_PTR)ProviderHandle, PropertyName, (PBYTE)Buffer, BufferSize, 0);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptCreatePersistedKey(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, OUT PVOID* KeyHandle, IN LPCWSTR AlgId, IN LPCWSTR KeyName, IN DWORD Flags)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCryptCreatePersistedKey(BindingHandle, ContextHandle, (LONG_PTR)ProviderHandle, (PLONG_PTR)KeyHandle, AlgId, KeyName, 0, Flags);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        //Util::PrintLastError(status);
    }

    return status;
}

RPC_STATUS KeyIso::CryptFreeKey(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN PVOID KeyHandle)
{
    RPC_STATUS status;

    __try
    {
        status = s_SrvRpcCryptFreeKey(BindingHandle, ContextHandle, (LONG_PTR)ProviderHandle, (LONG_PTR)KeyHandle);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        status = RpcExceptionCode();
        //Util::PrintLastError(status);
    }

    return status;
}

int TlsClient::Connect(PTLS_SOCKET s, const char* hostname, unsigned short port)
{
    int result = -1;
    char sport[32];
    WSADATA wsadata;
    SCHANNEL_CRED cred = { 0 };
    SECURITY_STATUS ss;
    CtxtHandle* context = NULL;
    SecBuffer inbuffers[2];
    SecBuffer outbuffers[1];
    SecBufferDesc indesc = { 0 };
    SecBufferDesc outdesc = { 0 };
    DWORD flags;

    s->sock = INVALID_SOCKET;
    sprintf_s(sport, sizeof(sport), "%u", port);

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) goto exit;

    s->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (s->sock == INVALID_SOCKET)
    {
        PRINT_ERROR(L"socket err: 0x%08x", WSAGetLastError());
        Util::PrintLastError(WSAGetLastError());
        goto exit;
    }

    if (!WSAConnectByNameA(s->sock, hostname, sport, NULL, NULL, NULL, NULL, NULL, NULL))
    {
        PRINT_ERROR(L"WSAConnectByNameA err: 0x%08x", WSAGetLastError());
        goto exit;
    }

    cred.dwVersion = SCHANNEL_CRED_VERSION;
    cred.dwFlags = SCH_CRED_IGNORE_REVOCATION_OFFLINE | SCH_CRED_IGNORE_NO_REVOCATION_CHECK | SCH_CRED_REVOCATION_CHECK_CHAIN | SCH_CRED_AUTO_CRED_VALIDATION | SCH_CRED_NO_DEFAULT_CREDS;
    cred.grbitEnabledProtocols = SP_PROT_TLS1_2_CLIENT | SP_PROT_TLS1_1_CLIENT | SP_PROT_TLS1_CLIENT;

    ss = AcquireCredentialsHandleA(NULL, (LPSTR)UNISP_NAME_A, SECPKG_CRED_OUTBOUND, NULL, &cred, NULL, NULL, &s->handle, NULL);
    if (ss != SEC_E_OK)
    {
        PRINT_ERROR(L"AcquireCredentialsHandleA err: 0x%08x", ss);
        Util::PrintLastError(ss);
        goto exit;
    }

    s->received = s->used = 0;

    for (;;)
    {
        ZeroMemory(inbuffers, sizeof(inbuffers));
        inbuffers[0].BufferType = SECBUFFER_TOKEN;
        inbuffers[0].pvBuffer = s->incoming;
        inbuffers[0].cbBuffer = s->received;
        inbuffers[1].BufferType = SECBUFFER_EMPTY;

        ZeroMemory(outbuffers, sizeof(outbuffers));
        outbuffers[0].BufferType = SECBUFFER_TOKEN;

        indesc = { SECBUFFER_VERSION, ARRAYSIZE(inbuffers), inbuffers };
        outdesc = { SECBUFFER_VERSION, ARRAYSIZE(outbuffers), outbuffers };

        flags = ISC_REQ_USE_SUPPLIED_CREDS | ISC_REQ_ALLOCATE_MEMORY | ISC_REQ_CONFIDENTIALITY | ISC_REQ_REPLAY_DETECT | ISC_REQ_SEQUENCE_DETECT | ISC_REQ_STREAM;

        ss = InitializeSecurityContextA(
            &s->handle,
            context,
            context ? NULL : (SEC_CHAR*)hostname,
            flags,
            0,
            0,
            context ? &indesc : NULL,
            0,
            context ? NULL : &s->context,
            &outdesc,
            &flags,
            NULL
        );

        context = &s->context;

        if (inbuffers[1].BufferType == SECBUFFER_EXTRA)
        {
            MoveMemory(s->incoming, s->incoming + (s->received - inbuffers[1].cbBuffer), inbuffers[1].cbBuffer);
            s->received = inbuffers[1].cbBuffer;
        }
        else
        {
            s->received = 0;
        }

        if (ss == SEC_E_OK)
        {
            // tls handshake completed
            result = 0;
            break;
        }
        else if (ss == SEC_I_CONTINUE_NEEDED)
        {
            if (outbuffers[0].pvBuffer)
            {
                // need to send data to server
                char* buffer = (char*)outbuffers[0].pvBuffer;
                int size = outbuffers[0].cbBuffer;

                while (size != 0)
                {
                    int d = send(s->sock, buffer, size, 0);
                    if (d <= 0)
                    {
                        break;
                    }
                    size -= d;
                    buffer += d;
                }
                FreeContextBuffer(outbuffers[0].pvBuffer);
                if (size != 0)
                {
                    // failed to fully send data to server
                    result = -1;
                    break;
                }
            }
        }
        else
        {
            PRINT_ERROR(L"InitializeSecurityContextA unexpected error: 0x%08x", ss);
            Util::PrintLastError(ss);
            result = -1;
            break;
        }

        int r = recv(s->sock, s->incoming + s->received, sizeof(s->incoming) - s->received, 0);
        if (r == 0)
        {
            // server disconnected socket
            result = 0;
            goto exit;
        }
        else if (r < 0)
        {
            // socket error
            result = -1;
            break;
        }

        s->received += r;
    }

    if (result != 0)
    {
        FreeCredentialsHandle(&s->handle);
        goto exit;
    }

exit:
    if (result != 0)
    {
        if (context != NULL) DeleteSecurityContext(context);
        if (s->sock != INVALID_SOCKET) closesocket(s->sock);
        WSACleanup();
    }

    return result;
}

void TlsClient::Disconnect(PTLS_SOCKET s)
{
    DWORD type = SCHANNEL_SHUTDOWN;
    SecBuffer inbuffers[1] = { 0 };
    SecBufferDesc indesc = { 0 };
    SecBuffer outbuffers[1] = { 0 };
    SecBufferDesc outdesc = { 0 };
    DWORD flags;
    SECURITY_STATUS ss;

    ZeroMemory(inbuffers, sizeof(inbuffers));
    inbuffers[0].BufferType = SECBUFFER_TOKEN;
    inbuffers[0].pvBuffer = &type;
    inbuffers[0].cbBuffer = sizeof(type);
    indesc = { SECBUFFER_VERSION, ARRAYSIZE(inbuffers), inbuffers };

    ApplyControlToken(&s->context, &indesc);

    ZeroMemory(outbuffers, sizeof(outbuffers));
    outbuffers[0].BufferType = SECBUFFER_TOKEN;
    outdesc = { SECBUFFER_VERSION, ARRAYSIZE(outbuffers), outbuffers };

    flags = ISC_REQ_ALLOCATE_MEMORY | ISC_REQ_CONFIDENTIALITY | ISC_REQ_REPLAY_DETECT | ISC_REQ_SEQUENCE_DETECT | ISC_REQ_STREAM;

    ss = InitializeSecurityContextA(&s->handle, &s->context, NULL, flags, 0, 0, &outdesc, 0, NULL, &outdesc, &flags, NULL);
    if (ss == SEC_E_OK && outbuffers[0].pvBuffer)
    {
        char* buffer = (char*)outbuffers[0].pvBuffer;
        int size = outbuffers[0].cbBuffer;
        while (size != 0)
        {
            int d = send(s->sock, buffer, size, 0);
            if (d <= 0)
            {
                // ignore any failures socket will be closed anyway
                break;
            }
            buffer += d;
            size -= d;
        }
        FreeContextBuffer(outbuffers[0].pvBuffer);
    }

    shutdown(s->sock, SD_BOTH);

    DeleteSecurityContext(&s->context);
    FreeCredentialsHandle(&s->handle);
    closesocket(s->sock);
    WSACleanup();

    return;
}

BOOL ModuleParser::GetImportedFunctionThunkAddress(IN HMODULE Module, IN LPCSTR ModuleName, IN LPCSTR FunctionName, OUT PULONG_PTR FunctionThunkAddress)
{
    BOOL bResult = FALSE;
    PIMAGE_NT_HEADERS pNtHeaders;
    PIMAGE_DATA_DIRECTORY pImportDirectory;
    PIMAGE_IMPORT_DESCRIPTOR pImportDescriptor;
    PIMAGE_THUNK_DATA pImageThunkData, pFirstThunk;
    PIMAGE_IMPORT_BY_NAME pImportByName;
    LPSTR pszModuleName;

    EXIT_ON_ERROR((pNtHeaders = RtlImageNtHeader(Module)) == NULL);

    pImportDirectory = &pNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    pImportDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)((ULONG_PTR)Module + pImportDirectory->VirtualAddress);

    while (pImportDescriptor->Name)
    {
        pszModuleName = (LPSTR)((ULONG_PTR)Module + pImportDescriptor->Name);

        if (!_stricmp(pszModuleName, ModuleName))
        {
            pImageThunkData = (PIMAGE_THUNK_DATA)((ULONG_PTR)Module + pImportDescriptor->OriginalFirstThunk);
            pFirstThunk = (PIMAGE_THUNK_DATA)((ULONG_PTR)Module + pImportDescriptor->FirstThunk);

            while (pImageThunkData->u1.AddressOfData)
            {
                pImportByName = (PIMAGE_IMPORT_BY_NAME)((ULONG_PTR)Module + pImageThunkData->u1.AddressOfData);
               
                if (!_stricmp(pImportByName->Name, FunctionName))
                {
                    *FunctionThunkAddress = (ULONG_PTR)pFirstThunk;
                    bResult = TRUE;
                    break;
                }

                pImageThunkData++;
                pFirstThunk++;
            }
        }

        pImportDescriptor++;
    }

cleanup:
    if (!bResult) PRINT_ERROR(L"Failed to determine the thunk address of imported function in module @ 0x%llx\n", (ULONG_PTR)Module);

    return bResult;
}

BOOL ModuleParser::GetSectionAddressAndSize(IN HMODULE Module, IN LPCSTR SectionName, OUT PULONG_PTR SectionAddress, OUT LPDWORD SectionSize)
{
    BOOL bResult = FALSE;
    const DWORD dwBufferSize = PAGE_SIZE;
    PIMAGE_NT_HEADERS pNtHeaders;
    PIMAGE_SECTION_HEADER pSectionHeader;
    PBYTE pBuffer = NULL;

    EXIT_ON_ERROR((pBuffer = (PBYTE)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwBufferSize)) == NULL);
    EXIT_ON_ERROR((pNtHeaders = RtlImageNtHeader(Module)) == NULL);

    for (int i = 0; i < pNtHeaders->FileHeader.NumberOfSections; i++)
    {
        pSectionHeader = (PIMAGE_SECTION_HEADER)((ULONG_PTR)pNtHeaders + sizeof(*pNtHeaders) + i * sizeof(*pSectionHeader));

        if (!strcmp((char*)pSectionHeader->Name, SectionName))
        {
            *SectionAddress = (ULONG_PTR)((PBYTE)Module + pSectionHeader->VirtualAddress);
            *SectionSize = pSectionHeader->SizeOfRawData;
            bResult = TRUE;
            break;
        }
    }

cleanup:
    if (pBuffer) HeapFree(GetProcessHeap(), 0, pBuffer);
    if (!bResult) PRINT_ERROR(L"Failed to determine address and size of section in module @ 0x%llx", (ULONG_PTR)Module);

    return bResult;
}

BOOL ModuleParser::SearchPattern(IN PBYTE Pattern, IN DWORD PatternLength, IN ULONG_PTR StartAddress, IN DWORD Size, OUT PULONG_PTR PatternAddress)
{
    BOOL bResult = FALSE;
    ULONG_PTR pModulePointer = NULL, pModuleLimit;

    //PRINT_DEBUG(L"Start address 0x%llx (size=%d)", StartAddress, Size);

    pModulePointer = StartAddress;
    pModuleLimit = StartAddress + Size - PatternLength;

    do
    {
        if (!memcmp(Pattern, (PVOID)pModulePointer, PatternLength))
        {
            *PatternAddress = pModulePointer;
            bResult = TRUE;
            break;
        }

        pModulePointer++;

    } while ((pModulePointer < pModuleLimit) && !bResult);

    return bResult;
}

#pragma warning( push )
#pragma warning( disable : 28251 )
void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
    return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
    free(p);
}
#pragma warning( pop )