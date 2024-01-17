#ifndef I_CONSOLE_PROCESS_H_f9bd237e_c73b_4df4_9932_90577a32a728
#define I_CONSOLE_PROCESS_H_f9bd237e_c73b_4df4_9932_90577a32a728

#include <memory>

namespace console_windows {

    /**
     * The IConsoleProcess interface defines a Console Process.
     */
    class IConsoleProcess {
    public:
        IConsoleProcess() = default;
        virtual ~IConsoleProcess() = default;

        /**
         * Terminates the running process.
         */
        virtual void Terminate(int exitCode) = 0;
    };

    /**
     * Defines the Shared Ptr of Console Process.
     */
    using IConsoleProcessSharedPtr = std::shared_ptr<IConsoleProcess>;

} // namespace console_windows

#endif // I_CONSOLE_PROCESS_H_f9bd237e_c73b_4df4_9932_90577a32a728
