#ifndef UN_EXPECTED_EXCEPTION_H_26a0ffd4_5803_11ee_8c99_0242ac120002
#define UN_EXPECTED_EXCEPTION_H_26a0ffd4_5803_11ee_8c99_0242ac120002

#include "BaseException.h"

namespace base {

    /**
     * The UnexpectedException class implements an unexpected exception.
     */
    class UnexpectedException : public base::BaseException
    {
    public:
        explicit UnexpectedException(const std::wstring &errorMessage) :
            BaseException(
                ErrorCodes::UNEXPECTED,
                errorMessage)
        {
        }
    };

} // namespace base

#endif // UN_EXPECTED_EXCEPTION_H_26a0ffd4_5803_11ee_8c99_0242ac120002
