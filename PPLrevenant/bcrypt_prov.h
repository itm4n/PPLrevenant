#pragma once

#include <bcrypt.h>

#ifdef __cplusplus
extern "C" {
#endif

    _Must_inspect_result_
        NTSTATUS
        WINAPI
        BCryptRegisterProvider(
            _In_ LPCWSTR pszProvider,
            _In_ ULONG dwFlags,
            _In_ PCRYPT_PROVIDER_REG pReg);

    _Must_inspect_result_
        NTSTATUS
        WINAPI
        BCryptUnregisterProvider(
            _In_ LPCWSTR pszProvider);

#ifdef __cplusplus
}
#endif