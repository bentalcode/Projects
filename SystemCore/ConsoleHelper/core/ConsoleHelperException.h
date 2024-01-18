#ifndef CONSOLE_HELPER_EXCEPTION_H_bc1e0911_d64c_497e_9d1f_630a97eded49
#define CONSOLE_HELPER_EXCEPTION_H_bc1e0911_d64c_497e_9d1f_630a97eded49

#include "BaseException.h"

namespace console_helper {

    /**
     * The ConsoleHelperException captured errors in the Console Helper module.
     */
    class ConsoleHelperException : public base::BaseException
    {
    public:
        /**
         * The ConsoleHelperException constructor.
         */
        ConsoleHelperException(
            long statusCode,
            const std::wstring& errorMessage) :
            base::BaseException(statusCode, errorMessage)
        {
        }
    };

} // namespace console_helper

#endif // CONSOLE_HELPER_EXCEPTION_H_bc1e0911_d64c_497e_9d1f_630a97eded49
