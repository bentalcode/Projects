#ifndef CONSOLE_WINDOW_MANAGER_H_f9879a33_be9f_48b3_8071_18574b7e0d0e
#define CONSOLE_WINDOW_MANAGER_H_f9879a33_be9f_48b3_8071_18574b7e0d0e

#include "IConsoleWindowManager.h"

namespace consolefilefinder {

    /**
     * The ConsoleWindowManager class implements a console window manager.
     */
    class ConsoleWindowManager final : public IConsoleWindowManager
    {
    public:
        /**
         * Creates a console window manager.
         */
        static IConsoleWindowManagerSharedPtr Make();

        /**
         * The ConsoleWindowManager constructor.
         */
        ConsoleWindowManager();

        /**
         * The ConsoleWindowManager destructor.
         */
        virtual ~ConsoleWindowManager();

        /**
         * Creates a window.
         */
        virtual void CreateWindow(const std::wstring& name) override;

    private:

    };

} // namespace consolefilefinder

#endif // CONSOLE_WINDOW_MANAGER_H_f9879a33_be9f_48b3_8071_18574b7e0d0e
