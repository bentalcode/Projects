#ifndef I_CONSOLE_WINDOW_MANAGER_H_36c78822_52dd_4bd6_a405_9961b0e0007f
#define I_CONSOLE_WINDOW_MANAGER_H_36c78822_52dd_4bd6_a405_9961b0e0007f

#include <memory>

namespace consolefilefinder
{
    /**
     * The IConsoleWindowManager interface defines a Console Window Manager.
     */
    class IConsoleWindowManager
    {
    public:
        /**
         * Creates a new console window manager.
         */
        std::shared_ptr<IConsoleWindowManager> Make();

        /**
         * The constructor.
         */
        IConsoleWindowManager() = default;

        /**
         * The destructor.
         */
        virtual ~IConsoleWindowManager() = default;

        /**
         * The copy/move constructors.
         */
        IConsoleWindowManager(const IConsoleWindowManager&) = delete;
        IConsoleWindowManager(IConsoleWindowManager&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsoleWindowManager& operator=(const IConsoleWindowManager&) = delete;
        IConsoleWindowManager& operator=(IConsoleWindowManager&&) = delete;

        /**
         * Creates a window.
         */
        virtual void CreateWindow(const std::wstring& name) = 0;
    };

    //
    // Defines the SharedPtr of Console Window Manager...
    //
    using IConsoleWindowManagerSharedPtr = std::shared_ptr<IConsoleWindowManager>;

} // namespace consolefilefinder

#endif // I_CONSOLE_WINDOW_MANAGER_H_36c78822_52dd_4bd6_a405_9961b0e0007f
