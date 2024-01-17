#ifndef I_CONSOLE_WINDOW_H_7099f489_1986_4d0a_8d49_5b3a5c0d53b9
#define I_CONSOLE_WINDOW_H_7099f489_1986_4d0a_8d49_5b3a5c0d53b9

#include "IConsoleWindow.h"
#include "IConsoleProcess.h"
#include "IConsolePipe.h"
#include <string>

namespace console_windows {

    /**
     * The ConsoleWindow class implements a dedicated window for running console.
     */
    class ConsoleWindow final : public IConsoleWindow {
    public:
        /**
         * Creates a Console Window.
         */
        static IConsoleSharedPtr Make(const std::wstring name);

        /**
         * The ConsoleWindow constructor.
         */
        ConsoleWindow(const std::wstring name);

        /**
         * The ConsoleWindow destructor.
         */
        virtual ~ConsoleWindow();

    private:
        //
        // The name of the console window...
        //
        std::wstring m_name;

        //
        // The dedicated process for hosting the console...
        //
        IConsoleProcessSharedPtr m_process;

        //
        // The pipe for reading and writing data...
        //
        IConsolePipeSharedPtr m_pipe;
    };

} // namespace console_windows

#endif // I_CONSOLE_WINDOW_H_7099f489_1986_4d0a_8d49_5b3a5c0d53b9
