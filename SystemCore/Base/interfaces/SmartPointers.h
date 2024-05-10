#ifndef SMART_POINTERS_H_0e76a850_57d1_11ee_8c99_0242ac120002
#define SMART_POINTERS_H_0e76a850_57d1_11ee_8c99_0242ac120002

#include "StringUtils.h"
#include "BaseException.h"
#include <memory>

namespace base {

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

        /**
         * Validates a shared ptr and returns it value.
         */
        template <typename T>
        static std::shared_ptr<T> ValidateAndReturn(std::shared_ptr<T> ptr);
    };

    /**
     * Validates a shared ptr.
     */
    template <typename T>
    inline void SmartPointers::Validate(std::shared_ptr<T> ptr)
    {
        if (!ptr) {
            std::wstring typeName = StringUtils::StringToWideString(typeid(T).name());

            long errorCode = ErrorCodes::INVALID_ARG;
            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The Shared Ptr of type: " << typeName << L" is not defined"
                << ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw BaseException(errorCode, errorMessage);
        }
    }

    /**
     * Validates a shared ptr and returns it value.
     */
    template <typename T>
    inline std::shared_ptr<T> SmartPointers::ValidateAndReturn(std::shared_ptr<T> ptr) {
        Validate(ptr);
        return ptr;
    }

} // namespace base

#endif // SMART_POINTERS_H_0e76a850_57d1_11ee_8c99_0242ac120002
