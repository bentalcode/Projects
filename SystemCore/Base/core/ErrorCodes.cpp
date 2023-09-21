#include "ErrorCodes.h"

using namespace base;

/**
 * Gets error code string.
 */
std::wstring ErrorCodes::GetErrorCodeString(long errorCode)
{
    std::wstringstream stream;
    stream << L"0x" << std::hex << errorCode;
    return stream.str();
}

#if WINDOWS
/**
 * Converts a HRESULT to an Error Code.
 */
long ErrorCodes::HResultToErrorCode(HRESULT hr)
{
    return hr;
}

/**
 * Gets the last error code.
 */
long ErrorCodes::GetLastErrorCode()
{
    DWORD errorCode = GetLastError();
    return HRESULT_FROM_WIN32(errorCode);
}
#endif
