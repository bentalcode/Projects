#pragma once

#include "IConsoleWindow.h"

namespace console_windows {

    /**
     * The ConsoleWindow class implements a dedicated window for running console.
     */
    class ConsoleWindow final : public IConsoleWindow {
    public:
        /**
         * Creates a Console Window.
         */
        static IConsoleSharedPtr Make();

        /**
         * The ConsoleWindow constructor.
         */
        ConsoleWindow();

        /**
         * The ConsoleWindow destructor.
         */
        virtual ~ConsoleWindow();
    };

} // namespace console_windows
