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
        explicit NotImplementedException(const std::wstring& errorMessage) :
            BaseException(
                ErrorCodes::NOT_IMPLEMENTED,
                errorMessage)
        {
        }
    };

} // namespace base

#endif // NOT_IMPLEMENTED_EXCEPTION_H_937c4291_c5f9_4bdb_ab07_e4de067d5001
