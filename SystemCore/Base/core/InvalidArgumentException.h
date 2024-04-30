#ifndef INVALID_ARGUMENT_EXCEPTION_H_984aa847_fd95_4af5_a092_2734b14a553f
#define INVALID_ARGUMENT_EXCEPTION_H_984aa847_fd95_4af5_a092_2734b14a553f

#include "BaseException.h"

namespace base {

    /**
     * The InvalidArgumentException class implements an invalid argument exception.
     */
    class InvalidArgumentException : public BaseException
    {
    public:
        /**
         * The InvalidArgumentException constructor.
         */
        explicit InvalidArgumentException(const std::wstring& errorMessage) :
            BaseException(
                ErrorCodes::NOT_IMPLEMENTED,
                errorMessage)
        {
        }
    };

} // namespace base

#endif // INVALID_ARGUMENT_EXCEPTION_H_984aa847_fd95_4af5_a092_2734b14a553f
