#ifndef I_CONSOLE_WINDOW_H_360e288c_3016_4494_b598_0786a26b4237
#define I_CONSOLE_WINDOW_H_360e288c_3016_4494_b598_0786a26b4237

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
    using IConsoleWindowSharedPtr = std::shared_ptr<IConsoleWindow>;

} // namespace console_windows

#endif // I_CONSOLE_WINDOW_H_360e288c_3016_4494_b598_0786a26b4237
