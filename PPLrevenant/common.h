#pragma once

#define SECURITY_WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Windows.h>
#include <security.h>
#include <iostream>
#include "ntdll.h"
#include "keyiso_h.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "secur32.lib")

#define TIMEOUT 10000
#define PROCESS_PROTECTION_INFORMATION 61
#define PAGE_SIZE 0x1000
#define LARGE_BUFFER_SIZE (256 * 1024 * 1024)
#define TLS_MAX_PACKET_SIZE (16384+512)

#define WIDEH(x) L##x
#define WIDE(x) WIDEH(x)
#define PRINT_DEBUG_FORMAT(f) L"[*] %ws | " f "\n"
#define PRINT_DEBUG(format, ...) if (g_bDebug) { wprintf( PRINT_DEBUG_FORMAT(format), WIDE(__FUNCTION__), __VA_ARGS__ ); }
#define PRINT_BUFFER(b, s) if (g_bDebug) { Util::PrintBuffer(b, s); }
#define PRINT_SUCCESS_FORMAT(f) L"[+] " f "\n"
#define PRINT_SUCCESS(format, ...) wprintf( PRINT_SUCCESS_FORMAT(format), __VA_ARGS__ )
#define PRINT_ERROR_FORMAT(f) L"[-] " f "\n"
#define PRINT_ERROR(format, ...) wprintf( PRINT_ERROR_FORMAT(format), __VA_ARGS__ )
#define PRINT_WARNING_FORMAT(f) L"[!] " f "\n"
#define PRINT_WARNING(format, ...) wprintf( PRINT_WARNING_FORMAT(format), __VA_ARGS__ )
#define PRINT_INFO_FORMAT(f) L"[*] " f "\n"
#define PRINT_INFO(format, ...) wprintf( PRINT_INFO_FORMAT(format), __VA_ARGS__ )
#define EXIT_ON_ERROR(c) if (c) { goto cleanup; }

extern BOOL g_bDebug;

namespace Util
{
    VOID PrintLastError(IN DWORD ErrorCode);
    VOID PrintBuffer(IN PVOID Buffer, IN DWORD Size);
    //VOID PressEnterToContinue();
    BOOL AddCatalogFile(IN LPWSTR FilePath);
    BOOL RemoveCatalogFile(IN LPWSTR FilePath);
    ULONG_PTR GetProcedureAddress(IN LPCWSTR Module, IN LPCSTR Procedure);
}

namespace Filesystem
{
    BOOL PathExists(IN LPWSTR FilePath);
    BOOL PathIsAbsolute(IN LPWSTR FilePath);
    HANDLE SetFileOpLock(IN LPCWSTR FilePath, IN DWORD ShareMode, IN BOOL Exclusive, IN OUT LPOVERLAPPED Overlapped);
}

namespace Service
{
    SC_HANDLE Open(IN LPCWSTR ServiceName, DWORD DesiredAccess);
    BOOL QueryStatus(IN SC_HANDLE ServiceHandle, OUT LPSERVICE_STATUS_PROCESS ServiceStatus);
    BOOL QueryState(IN SC_HANDLE ServiceHandle, OUT LPDWORD State);
    BOOL QueryState(IN LPCWSTR ServiceName, OUT LPDWORD State);
    BOOL QueryPid(IN SC_HANDLE ServiceHandle, OUT LPDWORD ProcessId);
    BOOL Start(IN SC_HANDLE ServiceHandle, IN BOOL Wait);
    BOOL Start(IN LPCWSTR ServiceName, IN BOOL Wait);
    BOOL Stop(IN SC_HANDLE ServiceHandle, IN BOOL Wait);
    BOOL Stop(IN LPCWSTR ServiceName, IN BOOL Wait);
    VOID Close(IN SC_HANDLE ServiceHandle);
}

namespace Process
{
    DWORD FindProcessId(IN LPCWSTR ProcessName);
    BOOL QueryProtectionLevel(IN DWORD ProcessId, IN OUT PPS_PROTECTION Protection);
    BOOL QueryProtectionLevel(IN HANDLE ProcessHandle, IN OUT PPS_PROTECTION Protection);
    BOOL IsModuleLoaded(IN DWORD ProcessId, IN LPCWSTR ModuleName);
}

namespace Registry
{
    BOOL QueryValue(IN HKEY Key, IN LPCWSTR SubKey, IN OPTIONAL LPCWSTR ValueName, OUT OPTIONAL LPDWORD Type, OUT LPBYTE* Data, IN OUT LPDWORD DataSize);
    BOOL SetValue(IN HKEY Key, IN LPCWSTR SubKey, IN OPTIONAL LPCWSTR ValueName, IN DWORD Type, IN LPBYTE Data, IN DWORD DataSize);
    BOOL DeleteValue(IN HKEY Key, IN OPTIONAL LPCWSTR SubKey, IN LPCWSTR ValueName);
}

namespace KeyIso
{
    RPC_BINDING_HANDLE CreateBindingHandle();
    VOID CloseBindingHandle(IN RPC_BINDING_HANDLE BindingHandle);
    RPC_STATUS CreateContext(IN RPC_BINDING_HANDLE BindingHandle, OUT PVOID* ContextHandle);
    RPC_STATUS ReleaseContext(IN RPC_BINDING_HANDLE BindingHandle, IN OUT PVOID* ContextHandle);
    RPC_STATUS CryptOpenStorageProvider(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, OUT PVOID* ProviderHandle, IN LPCWSTR ProviderName);
    RPC_STATUS CryptFreeProvider(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle);
    RPC_STATUS CryptEnumKeys(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN PULONG_PTR Buffer);
    RPC_STATUS CryptFreeBuffer(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN ULONG_PTR Buffer);
    RPC_STATUS CryptGetProviderProperty(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN LPCWSTR PropertyName, IN OUT PVOID Buffer, IN DWORD BufferSize, OUT LPLONG Written);
    RPC_STATUS CryptSetProviderProperty(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN LPCWSTR PropertyName, IN PVOID Buffer, IN DWORD BufferSize);
    RPC_STATUS CryptCreatePersistedKey(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, OUT PVOID* KeyHandle, IN LPCWSTR AlgId, IN LPCWSTR KeyName, IN DWORD Flags);
    RPC_STATUS CryptFreeKey(IN RPC_BINDING_HANDLE BindingHandle, IN PVOID ContextHandle, IN PVOID ProviderHandle, IN PVOID KeyHandle);
}

// https://gist.github.com/mmozeiko/c0dfcc8fec527a90a02145d2cc0bfb6d
namespace TlsClient
{
    typedef struct _TLS_SOCKET
    {
        SOCKET sock;
        CredHandle handle;
        CtxtHandle context;
        int received;    // byte count in incoming buffer (ciphertext)
        int used;        // byte count used from incoming buffer to decrypt current packet
        char incoming[TLS_MAX_PACKET_SIZE];
    } TLS_SOCKET, * PTLS_SOCKET;

    int Connect(PTLS_SOCKET s, const char* hostname, unsigned short port);
    void Disconnect(PTLS_SOCKET s);
}

namespace ModuleParser
{
    BOOL GetImportedFunctionThunkAddress(IN HMODULE Module, IN LPCSTR ModuleName, IN LPCSTR FunctionName, OUT PULONG_PTR FunctionThunkAddress);
    BOOL GetSectionAddressAndSize(IN HMODULE Module, IN LPCSTR SectionName, OUT PULONG_PTR SectionAddress, OUT LPDWORD SectionSize);
    BOOL SearchPattern(IN PBYTE Pattern, IN DWORD PatternLength, IN ULONG_PTR StartAddress, IN DWORD Size, OUT PULONG_PTR PatternAddress);
}

#pragma warning( push )
#pragma warning( disable : 28251 )
void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes);
void __RPC_USER midl_user_free(void __RPC_FAR* p);
#pragma warning( pop )