#pragma once

#include "IConsoleProcess.h"

namespace console_windows {

    /**
     * The ConsoleProcess class implements a dedicated process for running console.
     */
    class ConsoleProcess final : public IConsoleProcess {
    public:
        /**
         * Creates a Console Process.
         */
        static IConsoleProcessSharedPtr Make();

        /**
         * The ConsoleProcess constructor.
         */
        ConsoleProcess();

        /**
         * The ConsoleProcess destructor.
         */
        virtual ~ConsoleProcess();
    };

} // namespace console_windows
