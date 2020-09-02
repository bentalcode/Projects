#ifndef CONCURRENCY_EXCEPTION_H_3e965933_2909_43a0_b74f_9e7f0c489243
#define CONCURRENCY_EXCEPTION_H_3e965933_2909_43a0_b74f_9e7f0c489243

#include "BaseException.h"

namespace concurrency {

    /**
     * The ConcurrencyException captured errors in the concurrency module.
     */
    class ConcurrencyException : public base::BaseException
    {
    public:
        explicit ConcurrencyException(const std::string& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        explicit ConcurrencyException(
            const std::string& errorMessage,
            std::exception& innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };

}

#endif // CONCURRENCY_EXCEPTION_H_3e965933_2909_43a0_b74f_9e7f0c489243
