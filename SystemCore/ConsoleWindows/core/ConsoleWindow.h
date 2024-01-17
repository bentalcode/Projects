#ifndef I_CONSOLE_WINDOW_H_7099f489_1986_4d0a_8d49_5b3a5c0d53b9
#define I_CONSOLE_WINDOW_H_7099f489_1986_4d0a_8d49_5b3a5c0d53b9

#include "IConsoleWindow.h"
#include "IConsoleProcess.h"
#include "IConsolePipe.h"
#include "IConsoleStreamBuffer.h"
#include <sstream>

namespace console_windows {

    /**
     * The ConsoleWindow class implements a dedicated window for running console.
     */
class ConsoleWindow final : public std::wostream, public IConsoleWindow {
    public:
        /**
         * Creates a Console Window.
         */
        static IConsoleWindowSharedPtr Make(
            const std::wstring& name,
            size_t bufferSize = DEFAULT_BUFFER_SIZE);

        /**
         * The ConsoleWindow constructor.
         */
        ConsoleWindow(
            const std::wstring& name,
            IConsoleStreamBufferSharedPtr pipeBuffer);

    public:
        /**
         * The ConsoleWindow destructor.
         */
        virtual ~ConsoleWindow();

    private:
        //
        // Defines the default size of console...
        //
        static const size_t DEFAULT_BUFFER_SIZE;

        //
        // Defines the name of the executable of the console process...
        //
        static const std::wstring EXECUTABLE_NAME;

        /**
         * Creates a pipe.
         */
        static IConsolePipeSharedPtr CreatePipe(const std::wstring& name);

        /**
         * Creates a console process.
         */
        static IConsoleProcessSharedPtr CreateConsoleProcess(
            const std::wstring& executableName,
            const std::wstring& consoleName,
            const std::wstring& pipeName);

        /**
         * Creates a unique pipe name.
         */
        static std::wstring CreateUniquePipeName(const std::wstring& name);

        /**
         * Builds command line.
         */
        static std::wstring BuildCommandLine(
            const std::wstring& executableName,
            const std::wstring& consoleName,
            const std::wstring& pipeName);

        //
        // The name of the console window...
        //
        std::wstring m_name;

        //
        // The console stream buffer to transfer the data...
        //
        IConsoleStreamBufferSharedPtr m_pipeBuffer;

        //
        // The pipe for reading and writing data...
        //
        IConsolePipeSharedPtr m_pipe;

        //
        // The dedicated process for hosting the console...
        //
        IConsoleProcessSharedPtr m_process;
    };

} // namespace console_windows

#endif // I_CONSOLE_WINDOW_H_7099f489_1986_4d0a_8d49_5b3a5c0d53b9
