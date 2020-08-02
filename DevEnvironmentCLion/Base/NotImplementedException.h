#ifndef NOT_IMPLEMENTED_EXCEPTION_H_937c4291_c5f9_4bdb_ab07_e4de067d5001
#define NOT_IMPLEMENTED_EXCEPTION_H_937c4291_c5f9_4bdb_ab07_e4de067d5001

#include "BaseException.h"

/**
 * The NotImplementedException class implements a not implemented exception.
 */
class NotImplementedException : public BaseException
{
public:
    explicit NotImplementedException(const std::string& errorMessage) :
        BaseException(errorMessage)
    {
    }

    NotImplementedException(
        const std::string& errorMessage,
        std::exception& innerException) :
        BaseException(errorMessage, innerException)
    {
    }
};

#endif // NOT_IMPLEMENTED_EXCEPTION_H_937c4291_c5f9_4bdb_ab07_e4de067d5001
