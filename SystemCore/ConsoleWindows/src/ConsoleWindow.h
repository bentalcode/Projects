#pragma once

#include "IConsoleWindow.h"

namespace ConsoleWindows {

/**
 * The ConsoleWindow class implements a console window.
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

private:
};

} // namespace ConsoleWindows
