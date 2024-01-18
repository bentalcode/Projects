#ifndef CONSOLE_HELPER_H_5460031e_9873_4a92_88c3_7d6dfa549d40
#define CONSOLE_HELPER_H_5460031e_9873_4a92_88c3_7d6dfa549d40

#include "AbstractCommand.h"
#include "IConsoleHelper.h"
#include "IConsoleHelperParameters.h"
#include "IConsolePipe.h"
#include <atomic>

namespace console_helper {

    /**
     * The ConsoleHelper class implements a Console Helper command.
     */
    class ConsoleHelper final : public command::AbstractCommand, public IConsoleHelper
    {
    public:
        /**
         * Creates a Console Helper.
         */
         static IConsoleHelperSharedPtr Make();

        /**
         * The ConsoleHelper constructor.
         */
        ConsoleHelper();

        /**
         * The ConsoleHelper destructor.
         */
        virtual ~ConsoleHelper();

        /**
         * Runs the command.
         */
        virtual void Run() override;

        /**
         * Gets the command.
         */
        virtual command::ICommand& GetCommand() override;

    private:
        static const size_t DEFAULT_BUFFER_SIZE;

        /**
         * Initializes the command.
         */
        void Initialize();

        /**
         * Checks whether the process is running.
         */
        bool IsRunning() const;

        /**
         * Sets title of console.
         */
        static void UpdateConsoleTitle(const std::wstring& title);

        /**
         * Refresh data of console.
         */
        static void RefreshConsoleData(
            console_windows::IConsolePipe& pipe,
            size_t bufferSize = DEFAULT_BUFFER_SIZE);

        /**
         * Opens pipe for reading.
         */
        static console_windows::IConsolePipeSharedPtr OpenPipe(const std::wstring& pipeName);

        //
        // The parameters of command...
        //
        IConsoleHelperParametersSharedPtr m_parameters;

        //
        // The console pipe to read data from...
        //
        console_windows::IConsolePipeSharedPtr m_pipe;

        //
        // The console pipe to read data from...
        //
        std::atomic<bool> m_running;
    };

} // namespace console_helper

#endif // CONSOLE_HELPER_H_5460031e_9873_4a92_88c3_7d6dfa549d40
