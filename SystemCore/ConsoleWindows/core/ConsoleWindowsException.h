#pragma once

#include "BaseException.h"

namespace console_windows {

    /**
     * The ConsoleWindowsException class implements an exception in the Console Windows module.
     */
    class ConsoleWindowsException final : public base::BaseException {
    public:
        /**
         * The ConsoleWindowsException constructor.
         */
        explicit ConsoleWindowsException(const std::wstring& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        /**
         * The ConsoleWindowsException constructor.
         */
        ConsoleWindowsException(
            unsigned long errorCode,
            const std::wstring& errorMessage) :
                base::BaseException(
                    errorCode,
                    errorMessage)
        {
        }

        /**
         * The ConsoleWindowsException destructor.
         */
        virtual ~ConsoleWindowsException() = default;
    };

}  // namespace TabularData
