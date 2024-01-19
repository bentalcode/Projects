#ifndef I_CONSOLE_WINDOW_MANAGER_CONFIGURATION_H_87990552_3c1e_497b_bcd9_91c8ffeb4faa
#define I_CONSOLE_WINDOW_MANAGER_CONFIGURATION_H_87990552_3c1e_497b_bcd9_91c8ffeb4faa

#include <string>
#include <memory>

namespace consolefilefinder
{
    /**
     * The IConsoleWindowManagerConfiguration interface defines configuration of Console Window Manager.
     */
    class IConsoleWindowManagerConfiguration
    {
    public:
        /**
         * The constructor.
         */
        IConsoleWindowManagerConfiguration() = default;

        /**
         * The destructor.
         */
        virtual ~IConsoleWindowManagerConfiguration() = default;

        /**
         * The copy/move constructors.
         */
        IConsoleWindowManagerConfiguration(const IConsoleWindowManagerConfiguration&) = delete;
        IConsoleWindowManagerConfiguration(IConsoleWindowManagerConfiguration&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsoleWindowManagerConfiguration& operator=(const IConsoleWindowManagerConfiguration&) = delete;
        IConsoleWindowManagerConfiguration& operator=(IConsoleWindowManagerConfiguration&&) = delete;

        /**
         * Gets path of console helper.
         */
        virtual const std::wstring& GetConsoleHelperPath() const = 0;
    };

    //
    // Defines the SharedPtr of Console Window Manager Configuration...
    //
    using IConsoleWindowManagerConfigurationSharedPtr = std::shared_ptr<IConsoleWindowManagerConfiguration>;

} // namespace consolefilefinder

#endif // I_CONSOLE_WINDOW_MANAGER_CONFIGURATION_H_87990552_3c1e_497b_bcd9_91c8ffeb4faa
