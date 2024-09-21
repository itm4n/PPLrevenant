#pragma once

#ifndef __NTDLL_H__
#define __NTDLL_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NTDLL_SELF_
#pragma comment(lib, "Ntdll.lib")
#endif

#ifndef _NTDEF_
    typedef _Return_type_success_(return >= 0) LONG NTSTATUS;
    typedef NTSTATUS* PNTSTATUS;
#endif

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status)   ((NTSTATUS)(Status) >= 0)
#endif

#define STATUS_SUCCESS                              0x00000000
#define STATUS_INFO_LENGTH_MISMATCH                 0xC0000004
#define STATUS_INSUFFICIENT_RESOURCES               0xC000009a

// https://github.com/winsiderss/systeminformer/blob/master/phnt/include/ntrtl.h
#define RtlOffsetToPointer(Base, Offset) ((PCHAR)(((PCHAR)(Base)) + ((ULONG_PTR)(Offset))))
#define RtlPointerToOffset(Base, Pointer) ((ULONG)(((PCHAR)(Pointer)) - ((PCHAR)(Base))))

// https://github.com/winsiderss/systeminformer/blob/master/phlib/include/phsup.h
#define PTR_ADD_OFFSET(Pointer, Offset) ((PVOID)((ULONG_PTR)(Pointer) + (ULONG_PTR)(Offset)))
#define PTR_SUB_OFFSET(Pointer, Offset) ((PVOID)((ULONG_PTR)(Pointer) - (ULONG_PTR)(Offset)))
#define ALIGN_UP_BY(Address, Align) (((ULONG_PTR)(Address) + (Align) - 1) & ~((Align) - 1))
#define ALIGN_UP_POINTER_BY(Pointer, Align) ((PVOID)ALIGN_UP_BY(Pointer, Align))
#define ALIGN_UP(Address, Type) ALIGN_UP_BY(Address, sizeof(Type))
#define ALIGN_UP_POINTER(Pointer, Type) ((PVOID)ALIGN_UP(Pointer, Type))
#define ALIGN_DOWN_BY(Address, Align) ((ULONG_PTR)(Address) & ~((ULONG_PTR)(Align) - 1))
#define ALIGN_DOWN_POINTER_BY(Pointer, Align) ((PVOID)ALIGN_DOWN_BY(Pointer, Align))
#define ALIGN_DOWN(Address, Type) ALIGN_DOWN_BY(Address, sizeof(Type))
#define ALIGN_DOWN_POINTER(Pointer, Type) ((PVOID)ALIGN_DOWN(Pointer, Type))

// https://github.com/antonioCoco/MalSeclogon/blob/master/ntdef.h
#define OBJECT_TYPES_FIRST_ENTRY(ObjectTypes) (POBJECT_TYPE_INFORMATION) RtlOffsetToPointer(ObjectTypes, ALIGN_UP(sizeof(OBJECT_TYPES_INFORMATION), ULONG_PTR))
#define OBJECT_TYPES_NEXT_ENTRY(ObjectType) (POBJECT_TYPE_INFORMATION) RtlOffsetToPointer(ObjectType, sizeof(OBJECT_TYPE_INFORMATION) + ALIGN_UP(ObjectType->TypeName.MaximumLength, ULONG_PTR))

    typedef LONG KPRIORITY;

    typedef struct _UNICODE_STRING
    {
        USHORT Length;
        USHORT MaximumLength;
        PWSTR  Buffer;
    } UNICODE_STRING, * PUNICODE_STRING;

    typedef enum _OBJECT_INFORMATION_CLASS
    {
        ObjectBasicInformation,
        ObjectNameInformation,
        ObjectTypeInformation,
        ObjectTypesInformation,
        ObjectHandleFlagInformation,
        ObjectSessionInformation,
        MaxObjectInfoClass

    } OBJECT_INFORMATION_CLASS;

    typedef enum _SYSTEM_INFORMATION_CLASS
    {
        SystemBasicInformation,                     // 0x00
        SystemProcessorInformation,                 // 0x01
        SystemPerformanceInformation,               // 0x02
        SystemTimeOfDayInformation,                 // 0x03
        SystemPathInformation,                      // 0x04 (Obsolete: Use KUSER_SHARED_DATA)
        SystemProcessInformation,                   // 0x05
        SystemCallCountInformation,                 // 0x06
        SystemDeviceInformation,                    // 0x07
        SystemProcessorPerformanceInformation,      // 0x08
        SystemFlagsInformation,                     // 0x09
        SystemCallTimeInformation,                  // 0x0a
        SystemModuleInformation,                    // 0x0b
        SystemLocksInformation,                     // 0x0c
        SystemStackTraceInformation,                // 0x0d
        SystemPagedPoolInformation,                 // 0x0e
        SystemNonPagedPoolInformation,              // 0x0f
        SystemHandleInformation,                    // 0x10
        SystemObjectInformation,                    // 0x11
        SystemPageFileInformation,                  // 0x12
        SystemVdmInstemulInformation,               // 0x13
        SystemVdmBopInformation,                    // 0x14
        SystemFileCacheInformation,                 // 0x15
        SystemPoolTagInformation,                   // 0x16
        SystemInterruptInformation,                 // 0x17
        SystemDpcBehaviorInformation,               // 0x18
        SystemFullMemoryInformation,                // 0x19
        SystemLoadGdiDriverInformation,             // 0x1a
        SystemUnloadGdiDriverInformation,           // 0x1b
        SystemTimeAdjustmentInformation,            // 0x1c
        SystemSummaryMemoryInformation,             // 0x1d
        SystemMirrorMemoryInformation,              // 0x1e
        SystemPerformanceTraceInformation,          // 0x1f
        SystemObsolete0,                            // 0x20
        SystemExceptionInformation,                 // 0x21
        SystemCrashDumpStateInformation,            // 0x22
        SystemKernelDebuggerInformation,            // 0x23
        SystemContextSwitchInformation,             // 0x24
        SystemRegistryQuotaInformation,             // 0x25
        SystemExtendServiceTableInformation,        // 0x26
        SystemPrioritySeperation,                   // 0x27
        SystemPlugPlayBusInformation,               // 0x28
        SystemDockInformation,                      // 0x29
        SystemPowerInformationNative,               // 0x2a
        SystemProcessorSpeedInformation,            // 0x2b
        SystemCurrentTimeZoneInformation,           // 0x2c
        SystemLookasideInformation,
        SystemTimeSlipNotification,
        SystemSessionCreate,
        SystemSessionDetach,
        SystemSessionInformation,
        SystemRangeStartInformation,
        SystemVerifierInformation,
        SystemAddVerifier,
        SystemSessionProcessesInformation,
        SystemLoadGdiDriverInSystemSpaceInformation,
        SystemNumaProcessorMap,
        SystemPrefetcherInformation,
        SystemExtendedProcessInformation,
        SystemRecommendedSharedDataAlignment,
        SystemComPlusPackage,
        SystemNumaAvailableMemory,
        SystemProcessorPowerInformation,
        SystemEmulationBasicInformation,
        SystemEmulationProcessorInformation,
        SystemExtendedHandleInformation,
        SystemLostDelayedWriteInformation,
        SystemBigPoolInformation,
        SystemSessionPoolTagInformation,
        SystemSessionMappedViewInformation,
        SystemHotpatchInformation,
        SystemObjectSecurityMode,
        SystemWatchDogTimerHandler,
        SystemWatchDogTimerInformation,
        SystemLogicalProcessorInformation,
        SystemWo64SharedInformationObosolete,
        SystemRegisterFirmwareTableInformationHandler,
        SystemFirmwareTableInformation,
        SystemModuleInformationEx,
        SystemVerifierTriageInformation,
        SystemSuperfetchInformation,
        SystemMemoryListInformation,
        SystemFileCacheInformationEx,
        SystemThreadPriorityClientIdInformation,
        SystemProcessorIdleCycleTimeInformation,
        SystemVerifierCancellationInformation,
        SystemProcessorPowerInformationEx,
        SystemRefTraceInformation,
        SystemSpecialPoolInformation,
        SystemProcessIdInformation,
        SystemErrorPortInformation,
        SystemBootEnvironmentInformation,
        SystemHypervisorInformation,
        SystemVerifierInformationEx,
        SystemTimeZoneInformation,
        SystemImageFileExecutionOptionsInformation,
        SystemCoverageInformation,
        SystemPrefetchPathInformation,
        SystemVerifierFaultsInformation,
        MaxSystemInfoClass,
    } SYSTEM_INFORMATION_CLASS, * PSYSTEM_INFORMATION_CLASS;

    typedef enum _PROCESSINFOCLASS {
        ProcessBasicInformation,                // 0x00
        ProcessQuotaLimits,                     // 0x01
        ProcessIoCounters,                      // 0x02
        ProcessVmCounters,                      // 0x03
        ProcessTimes,                           // 0x04
        ProcessBasePriority,                    // 0x05
        ProcessRaisePriority,                   // 0x06
        ProcessDebugPort,                       // 0x07
        ProcessExceptionPort,                   // 0x08
        ProcessAccessToken,                     // 0x09
        ProcessLdtInformation,                  // 0x0A
        ProcessLdtSize,                         // 0x0B
        ProcessDefaultHardErrorMode,            // 0x0C
        ProcessIoPortHandlers,                  // 0x0D Note: this is kernel mode only
        ProcessPooledUsageAndLimits,            // 0x0E
        ProcessWorkingSetWatch,                 // 0x0F
        ProcessUserModeIOPL,                    // 0x10
        ProcessEnableAlignmentFaultFixup,       // 0x11
        ProcessPriorityClass,                   // 0x12
        ProcessWx86Information,                 // 0x13
        ProcessHandleCount,                     // 0x14
        ProcessAffinityMask,                    // 0x15
        ProcessPriorityBoost,                   // 0x16
        ProcessDeviceMap,                       // 0x17
        ProcessSessionInformation,              // 0x18
        ProcessForegroundInformation,           // 0x19
        ProcessWow64Information,                // 0x1A
        ProcessImageFileName,                   // 0x1B
        ProcessLUIDDeviceMapsEnabled,           // 0x1C
        ProcessBreakOnTermination,              // 0x1D
        ProcessDebugObjectHandle,               // 0x1E
        ProcessDebugFlags,                      // 0x1F
        ProcessHandleTracing,                   // 0x20
        ProcessIoPriority,                      // 0x21
        ProcessExecuteFlags,                    // 0x22
        ProcessTlsInformation,
        ProcessCookie,
        ProcessImageInformation,
        ProcessCycleTime,
        ProcessPagePriority,
        ProcessInstrumentationCallback,
        ProcessThreadStackAllocation,
        ProcessWorkingSetWatchEx,
        ProcessImageFileNameWin32,
        ProcessImageFileMapping,
        ProcessAffinityUpdateMode,
        ProcessMemoryAllocationMode,
        ProcessGroupInformation,
        ProcessTokenVirtualizationEnabled,
        ProcessConsoleHostProcess,
        ProcessWindowInformation,
        MaxProcessInfoClass                     // MaxProcessInfoClass should always be the last enum
    } PROCESSINFOCLASS;

    typedef enum _MEMORY_INFORMATION_CLASS
    {
        MemoryBasicInformation, // q: MEMORY_BASIC_INFORMATION
        MemoryWorkingSetInformation, // q: MEMORY_WORKING_SET_INFORMATION
        MemoryMappedFilenameInformation, // q: UNICODE_STRING
        MemoryRegionInformation, // q: MEMORY_REGION_INFORMATION
        MemoryWorkingSetExInformation, // q: MEMORY_WORKING_SET_EX_INFORMATION // since VISTA
        MemorySharedCommitInformation, // q: MEMORY_SHARED_COMMIT_INFORMATION // since WIN8
        MemoryImageInformation, // q: MEMORY_IMAGE_INFORMATION
        MemoryRegionInformationEx, // MEMORY_REGION_INFORMATION
        MemoryPrivilegedBasicInformation, // MEMORY_BASIC_INFORMATION
        MemoryEnclaveImageInformation, // MEMORY_ENCLAVE_IMAGE_INFORMATION // since REDSTONE3
        MemoryBasicInformationCapped, // 10
        MemoryPhysicalContiguityInformation, // MEMORY_PHYSICAL_CONTIGUITY_INFORMATION // since 20H1
        MemoryBadInformation, // since WIN11
        MemoryBadInformationAllProcesses, // since 22H1
        MaxMemoryInfoClass
    } MEMORY_INFORMATION_CLASS;

    typedef struct _OBJECT_ATTRIBUTES
    {
        ULONG Length;
        HANDLE RootDirectory;
        PUNICODE_STRING ObjectName;
        ULONG Attributes;
        PVOID SecurityDescriptor; // PSECURITY_DESCRIPTOR;
        PVOID SecurityQualityOfService; // PSECURITY_QUALITY_OF_SERVICE
    } OBJECT_ATTRIBUTES, * POBJECT_ATTRIBUTES;

    typedef struct _CLIENT_ID
    {
        HANDLE UniqueProcess;
        HANDLE UniqueThread;
    } CLIENT_ID, * PCLIENT_ID;

    typedef struct _PS_PROTECTION {
        union {
            UCHAR Level;
            struct {
                UCHAR Type : 3;
                UCHAR Audit : 1;                  // Reserved
                UCHAR Signer : 4;
            } l;
        };
    } PS_PROTECTION, * PPS_PROTECTION;

    typedef struct _SYSTEM_PROCESS_INFORMATION
    {
        ULONG NextEntryOffset;
        ULONG NumberOfThreads;
        LARGE_INTEGER SpareLi1;
        LARGE_INTEGER SpareLi2;
        LARGE_INTEGER SpareLi3;
        LARGE_INTEGER CreateTime;
        LARGE_INTEGER UserTime;
        LARGE_INTEGER KernelTime;
        UNICODE_STRING ImageName;
        KPRIORITY BasePriority;
        HANDLE UniqueProcessId;
        HANDLE InheritedFromUniqueProcessId;
        ULONG HandleCount;
        ULONG SessionId;
        ULONG_PTR PageDirectoryBase;

        //
        // This part corresponds to VM_COUNTERS_EX.
        // NOTE: *NOT* THE SAME AS VM_COUNTERS!
        //
        SIZE_T PeakVirtualSize;
        ULONG VirtualSize;
        SIZE_T PageFaultCount;
        SIZE_T PeakWorkingSetSize;
        SIZE_T WorkingSetSize;
        SIZE_T QuotaPeakPagedPoolUsage;
        SIZE_T QuotaPagedPoolUsage;
        SIZE_T QuotaPeakNonPagedPoolUsage;
        SIZE_T QuotaNonPagedPoolUsage;
        SIZE_T PagefileUsage;
        SIZE_T PeakPagefileUsage;
        SIZE_T PrivatePageCount;

        //
        // This part corresponds to IO_COUNTERS
        //
        LARGE_INTEGER ReadOperationCount;
        LARGE_INTEGER WriteOperationCount;
        LARGE_INTEGER OtherOperationCount;
        LARGE_INTEGER ReadTransferCount;
        LARGE_INTEGER WriteTransferCount;
        LARGE_INTEGER OtherTransferCount;

        //SYSTEM_THREAD_INFORMATION TH[1];
    } SYSTEM_PROCESS_INFORMATION, * PSYSTEM_PROCESS_INFORMATION;

    // https://github.com/winsiderss/systeminformer/blob/master/phnt/include/ntobapi.h
    typedef struct _OBJECT_TYPES_INFORMATION
    {
        ULONG NumberOfTypes;
    } OBJECT_TYPES_INFORMATION, * POBJECT_TYPES_INFORMATION;

    // https://github.com/winsiderss/systeminformer/blob/master/phnt/include/ntobapi.h
    typedef struct _OBJECT_TYPE_INFORMATION
    {
        UNICODE_STRING TypeName;
        ULONG TotalNumberOfObjects;
        ULONG TotalNumberOfHandles;
        ULONG TotalPagedPoolUsage;
        ULONG TotalNonPagedPoolUsage;
        ULONG TotalNamePoolUsage;
        ULONG TotalHandleTableUsage;
        ULONG HighWaterNumberOfObjects;
        ULONG HighWaterNumberOfHandles;
        ULONG HighWaterPagedPoolUsage;
        ULONG HighWaterNonPagedPoolUsage;
        ULONG HighWaterNamePoolUsage;
        ULONG HighWaterHandleTableUsage;
        ULONG InvalidAttributes;
        GENERIC_MAPPING GenericMapping;
        ULONG ValidAccessMask;
        BOOLEAN SecurityRequired;
        BOOLEAN MaintainHandleCount;
        UCHAR TypeIndex; // since WINBLUE
        CHAR ReservedByte;
        ULONG PoolType;
        ULONG DefaultPagedPoolCharge;
        ULONG DefaultNonPagedPoolCharge;
    } OBJECT_TYPE_INFORMATION, * POBJECT_TYPE_INFORMATION;

    // https://github.com/winsiderss/systeminformer/blob/master/phnt/include/ntexapi.h
    typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX {
        PVOID Object;
        ULONG_PTR UniqueProcessId;
        ULONG_PTR HandleValue;
        ULONG GrantedAccess;
        USHORT CreatorBackTraceIndex;
        USHORT ObjectTypeIndex;
        ULONG  HandleAttributes;
        ULONG  Reserved;
    } SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX, * PSYSTEM_HANDLE_TABLE_ENTRY_INFO_EX;

    // https://github.com/winsiderss/systeminformer/blob/master/phnt/include/ntexapi.h
    typedef struct _SYSTEM_HANDLE_INFORMATION_EX {
        ULONG_PTR NumberOfHandles;
        ULONG_PTR Reserved;
        SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX Handles[1];
    } SYSTEM_HANDLE_INFORMATION_EX, * PSYSTEM_HANDLE_INFORMATION_EX;

    // https://github.com/winsiderss/systeminformer/blob/master/phnt/include/ntobapi.h
    typedef struct _OBJECT_NAME_INFORMATION
    {
        UNICODE_STRING Name;
    } OBJECT_NAME_INFORMATION, * POBJECT_NAME_INFORMATION;

    NTSYSAPI
        PIMAGE_NT_HEADERS
        NTAPI
        RtlImageNtHeader(
            IN      PVOID               ModuleAddress
        );

    NTSYSAPI
        ULONG
        NTAPI
        RtlNtStatusToDosError(
            IN      NTSTATUS            Status
        );

    NTSYSAPI
        NTSTATUS
        NTAPI
        NtImpersonateThread(
            IN      HANDLE              ThreadHandle,
            IN      HANDLE              ThreadToImpersonate,
            IN      PSECURITY_QUALITY_OF_SERVICE SecurityQualityOfService
        );

    NTSYSAPI
        NTSTATUS
        NTAPI
        NtQueryObject(
            IN      HANDLE              ObjectHandle,
            IN      OBJECT_INFORMATION_CLASS ObjectInformationClass,
            OUT     PVOID               ObjectInformation,
            IN      ULONG               Length,
            OUT     PULONG              ResultLength OPTIONAL
        );

    NTSYSAPI
        NTSTATUS
        NTAPI
        NtQueryInformationProcess(
            IN HANDLE ProcessHandle,
            IN PROCESSINFOCLASS ProcessInformationClass,
            OUT PVOID ProcessInformation,
            IN ULONG ProcessInformationLength,
            OUT PULONG ReturnLength OPTIONAL
        );

    NTSYSAPI
        NTSTATUS
        NTAPI NtQuerySystemInformation(
            IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
            IN OUT PVOID SystemInformation,
            IN ULONG SystemInformationLength,
            OUT PULONG ReturnLength OPTIONAL
        );

    NTSYSCALLAPI
        NTSTATUS
        NTAPI
        NtOpenProcess(
            _Out_ PHANDLE ProcessHandle,
            _In_ ACCESS_MASK DesiredAccess,
            _In_ POBJECT_ATTRIBUTES ObjectAttributes,
            _In_opt_ PCLIENT_ID ClientId
        );

    NTSYSCALLAPI
        NTSTATUS
        NTAPI
        NtQueryVirtualMemory(
            _In_ HANDLE ProcessHandle,
            _In_opt_ PVOID BaseAddress,
            _In_ MEMORY_INFORMATION_CLASS MemoryInformationClass,
            _Out_writes_bytes_(MemoryInformationLength) PVOID MemoryInformation,
            _In_ SIZE_T MemoryInformationLength,
            _Out_opt_ PSIZE_T ReturnLength
        );

    NTSYSCALLAPI
        NTSTATUS
        NTAPI
        NtClose(
            _In_ _Post_ptr_invalid_ HANDLE Handle
        );

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __NTDLL_H__