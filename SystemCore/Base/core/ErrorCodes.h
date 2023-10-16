#ifndef ERROR_CODES_H_2fb42be0_4a55_43a5_a430_a8adb867fe6b
#define ERROR_CODES_H_2fb42be0_4a55_43a5_a430_a8adb867fe6b

#include <sstream>
#include <iomanip>

#if WINDOWS
    #include <windows.h>
#endif

#include "ErrorMessages.h"

namespace base {

    /**
     * The ErrorCodes class defines cross platform error codes.
     */
    class ErrorCodes final {
    public:
        ErrorCodes() = delete;
        ~ErrorCodes() = delete;

        static const long SUCCESS = 0;
        static const long FAIL = 0x80004005L;
        static const long INVALID_ARG = 0x80070057L;
        static const long NOT_IMPLEMENTED = 0x80004001L;
        static const long NO_INTERFACE = 0x80004002L;
        static const long POINTER = 0x80004003L;
        static const long ABORT = 0x80004004L;
        static const long UNEXPECTED = 0x8000FFFFL;
        static const long ACCESS_DENIED = 0x80070005L;
        static const long HANDLE = 0x80070006L;
        static const long OUT_OF_MEMORY = 0x8007000EL;
        static const long OUT_OF_RANGE = 0x80070057L;
        static const long RESOURCE_NOT_FOUND = 0x490L;
        static const long RESOURCE_ALREADY_EXISTS = 0xb7L;
        static const long RESOURCE_TEMPLATE_NOT_FOUND = 0x490L;
        static const long RESOURCE_TEMPLATE_ALREADY_EXISTS = 0xb7L;

        /**
         * Gets an error code string.
         */
        static std::wstring GetErrorCodeString(long statusCode);

#if WINDOWS
        /**
         * Gets the last error code.
         */
        static long GetLastErrorCode();

        /**
         * Converts a HRESULT to an Error Code.
         */
        static long HResultToErrorCode(HRESULT hr);

#endif
    };

} // namespace base

#endif // ERROR_CODES_H_2fb42be0_4a55_43a5_a430_a8adb867fe6b
