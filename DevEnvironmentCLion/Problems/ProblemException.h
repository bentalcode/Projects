#ifndef PROBLEM_EXCEPTION_H_abbc3bde_152e_4403_a28f_8dc43dddff83
#define PROBLEM_EXCEPTION_H_abbc3bde_152e_4403_a28f_8dc43dddff83

#include "BaseException.h"

namespace problems {

    /**
     * The ProblemException captured errors in the problems module.
     */
    class ProblemException : public base::BaseException
    {
    public:
        explicit ProblemException(const std::string& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        ProblemException(
            const std::string& errorMessage,
            std::exception& innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };

}

#endif // PROBLEM_EXCEPTION_H_abbc3bde_152e_4403_a28f_8dc43dddff83
