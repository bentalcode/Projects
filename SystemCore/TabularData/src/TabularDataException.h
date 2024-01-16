#pragma once

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
        unsigned long errorCode, 
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
