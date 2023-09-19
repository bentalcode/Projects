#pragma once

#include "StringUtils.h"
#include <memory>
#include "utilities_exception.h"

namespace Utilities {

/**
 * The SmartPointers class implements generic utilities for smart pointers.
 */
class SmartPointers final {
public:
    SmartPointers() = delete;
    ~SmartPointers() = delete;

    /**
     * Validate a shared ptr.
     */
    template <typename T>
    static void Validate(std::shared_ptr<T> ptr);
};

/**
 * Validate a shared ptr.
 */
template <typename T>
inline void SmartPointers::Validate(std::shared_ptr<T> ptr)
{
    if (!ptr) {
        std::wstring typeName = StringUtils::StringToWideString(typeid(T).name());

        long errorCode = ErrorCodes::INVALID_ARG;
        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Shared Ptr of type: " << typeName << L"is not defined" 
            << L"; ErrorCode: " << ErrorCodes::GetErrorCodeString(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw utilities_exception(errorCode, errorMessage);
    }
}

}  // namespace Utilities
