#pragma once

#include <memory>

namespace console_windows {

    /**
     * The IConsoleProcess interface defines a Console Process.
     */
    class IConsoleProcess {
    public:
        IConsoleProcess() = default;
        virtual ~IConsoleProcess() = default;
    };

    /**
     * Defines the Shared Ptr of Console Process.
     */
    using IConsoleProcessSharedPtr = std::shared_ptr<IConsoleProcess>;

} // namespace console_windows
