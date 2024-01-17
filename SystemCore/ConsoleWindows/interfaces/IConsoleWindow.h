#pragma once

#include <memory>

namespace console_windows {

    /**
     * The IConsoleWindow interface defines a Console Window.
     */
    class IConsoleWindow {
    public:
        IConsoleWindow() = default;
        virtual ~IConsoleWindow() = default;
    };

    /**
     * Defines the Shared Ptr of Console Window.
     */
    using IConsoleSharedPtr = std::shared_ptr<IConsoleWindow>;

} // namespace console_windows
