#ifndef TABULAR_DATA_EXCEPTION_H_b2447514_a296_426c_88d9_cbe92680ccb0
#define TABULAR_DATA_EXCEPTION_H_b2447514_a296_426c_88d9_cbe92680ccb0

#include "BaseException.h"

namespace tabular_data {

/**
 * The TabularDataException class implements an exception in the Tabular Data module.
 */
class TabularDataException : public base::BaseException {
public:
    /**
     * The TabularDataException constructor.
     */
    explicit TabularDataException(const std::wstring& errorMessage) :
        base::BaseException(errorMessage)
    {
    }

    /**
     * The TabularDataException constructor.
     */
    TabularDataException(
        long errorCode,
        const std::wstring& errorMessage) :
            base::BaseException(
                errorCode, 
                errorMessage)
    {
    }

    /**
     * The TabularDataException destructor.
     */
    virtual ~TabularDataException() = default;
};

}  // namespace tabular_data

#endif // TABULAR_DATA_EXCEPTION_H_b2447514_a296_426c_88d9_cbe92680ccb0
