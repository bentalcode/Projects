#ifndef COMMAND_EXCEPTION_H_332eb58f_317e_4562_ba1e_ba80df3e0ac6
#define COMMAND_EXCEPTION_H_332eb58f_317e_4562_ba1e_ba80df3e0ac6

#include "BaseException.h"

namespace command {

    /**
     * The CommandException class implements an exception for capturing errors in the Command module.
     */
    class CommandException : public base::BaseException {
    public:
        explicit CommandException(const std::string &errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        CommandException(
            const std::string &errorMessage,
            std::exception &innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };
}

#endif // COMMAND_EXCEPTION_H_332eb58f_317e_4562_ba1e_ba80df3e0ac6
