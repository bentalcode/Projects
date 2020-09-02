#ifndef NOT_IMPLEMENTED_EXCEPTION_H_937c4291_c5f9_4bdb_ab07_e4de067d5001
#define NOT_IMPLEMENTED_EXCEPTION_H_937c4291_c5f9_4bdb_ab07_e4de067d5001

#include "BaseException.h"

namespace base {

    /**
     * The NotImplementedException class implements a not implemented exception.
     */
    class NotImplementedException : public base::BaseException
    {
    public:
        explicit NotImplementedException(const std::string &errorMessage) :
                base::BaseException(errorMessage)
        {
        }

        NotImplementedException(
            const std::string &errorMessage,
            std::exception &innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };

}

#endif // NOT_IMPLEMENTED_EXCEPTION_H_937c4291_c5f9_4bdb_ab07_e4de067d5001
