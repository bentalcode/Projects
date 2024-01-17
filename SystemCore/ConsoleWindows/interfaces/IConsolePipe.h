#pragma once

#include <memory>

namespace console_windows {

/**
 * The IConsolePipe interface defines a Console Pipe.
 */
class IConsolePipe {
public:
    IConsolePipe() = default;
    virtual ~IConsolePipe() = default;

    /**
     * The copy/move constructors.
     */
    IConsolePipe(const IConsolePipe&) = delete;
    IConsolePipe(IConsolePipe&&) = delete;

    /**
     * The copy/move assignment operators.
     */
    IConsolePipe& operator=(const IConsolePipe&) = delete;
    IConsolePipe& operator=(IConsolePipe&&) = delete;
};

/**
 * Defines the Shared Ptr of Console Pipe.
 */
using IConsolePipeSharedPtr = std::shared_ptr<IConsolePipe>;

} // namespace console_windows
