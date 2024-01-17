#ifndef I_CONSOLE_PROCESS_H_3ae44474_7a31_4763_bb07_78e8d7d11bac
#define I_CONSOLE_PROCESS_H_3ae44474_7a31_4763_bb07_78e8d7d11bac

#include "IConsoleProcess.h"
#include <vector>
#include <string>
#include <Windows.h>

namespace console_windows {

    /**
     * The ConsoleProcess class implements a dedicated process for running console.
     */
    class ConsoleProcess final : public IConsoleProcess {
    public:
        /**
         * Creates a Console Process.
         */
        static IConsoleProcessSharedPtr Make(
            const std::wstring& executablePath,
            const std::wstring& commandArgs);

        /**
         * The ConsoleProcess constructor.
         */
        ConsoleProcess(
            const std::wstring& executablePath,
            const std::wstring& commandArgs);

        /**
         * The ConsoleProcess destructor.
         */
        virtual ~ConsoleProcess();

        /**
         * Terminates the running process.
         */
        virtual void Terminate(int exitCode = 0) override;

    private:
        /**
         * Creates a process.
         */
        static void CreateProcess(
            const std::wstring& executablePath,
            const std::wstring& commandArgs,
            PROCESS_INFORMATION& processInformation);

        /**
         * Terminates a process.
         */
        static void TerminateProcess(
            PROCESS_INFORMATION& processInformation,
            int exitCode);

        PROCESS_INFORMATION m_processInformation;
    };

} // namespace console_windows

#endif // I_CONSOLE_PROCESS_H_3ae44474_7a31_4763_bb07_78e8d7d11bac
