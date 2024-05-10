#ifndef I_CONSOLE_WINDOW_EXCEPTION_H_ca50c1a5_ffbd_4790_a93b_15b95fd6f8cd
#define I_CONSOLE_WINDOW_EXCEPTION_H_ca50c1a5_ffbd_4790_a93b_15b95fd6f8cd

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
            long errorCode,
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

} // namespace console_windows

#endif // I_CONSOLE_WINDOW_EXCEPTION_H_ca50c1a5_ffbd_4790_a93b_15b95fd6f8cd
