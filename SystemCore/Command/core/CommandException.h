#ifndef COMMAND_EXCEPTION_H_332eb58f_317e_4562_ba1e_ba80df3e0ac6
#define COMMAND_EXCEPTION_H_332eb58f_317e_4562_ba1e_ba80df3e0ac6

#include "BaseException.h"

namespace command {

    /**
     * The CommandException class implements an exception for capturing errors in the Command module.
     */
    class CommandException : public base::BaseException {
    public:
        explicit CommandException(
            long statusCode,
            const std::wstring& errorMessage) :
            base::BaseException(statusCode, errorMessage)
        {
        }
    };

} // namespace command

#endif // COMMAND_EXCEPTION_H_332eb58f_317e_4562_ba1e_ba80df3e0ac6
