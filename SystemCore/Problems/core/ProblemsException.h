#ifndef PROBLEM_EXCEPTION_H_abbc3bde_152e_4403_a28f_8dc43dddff83
#define PROBLEM_EXCEPTION_H_abbc3bde_152e_4403_a28f_8dc43dddff83

#include "BaseException.h"

namespace problems {

    /**
     * The ProblemException captured errors in the problems module.
     */
    class ProblemException final : public base::BaseException
    {
    public:
        explicit ProblemException(const std::wstring& errorMessage) :
            base::BaseException(errorMessage)
        {
        }
    };

}

#endif // PROBLEM_EXCEPTION_H_abbc3bde_152e_4403_a28f_8dc43dddff83
