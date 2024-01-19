#ifndef CONSOLE_WINDOW_MANAGER_CONFIGURATION_H_a754cbc6_aa38_4d8e_997f_81a6fb9a032a
#define CONSOLE_WINDOW_MANAGER_CONFIGURATION_H_a754cbc6_aa38_4d8e_997f_81a6fb9a032a

#include "IConsoleWindowManagerConfiguration.h"

namespace consolefilefinder {

    /**
     * The ConsoleWindowManagerConfiguration class implements a configuration of Console Window Manager.
     */
    class ConsoleWindowManagerConfiguration final : public IConsoleWindowManagerConfiguration
    {
    public:
        /**
         * Creates a Console Window Manager configuration.
         */
        static IConsoleWindowManagerConfigurationSharedPtr Make();

        /**
         * The ConsoleWindowManagerConfiguration constructor.
         */
        explicit ConsoleWindowManagerConfiguration(const std::wstring& consoleHelperPath);

        /**
         * The ConsoleWindowManagerConfiguration destructor.
         */
        virtual ~ConsoleWindowManagerConfiguration();

        /**
         * Gets path of console helper.
         */
        virtual const std::wstring& GetConsoleHelperPath() const override;

    private:
        static const std::wstring CONSOLE_HELPER_PATH;

        std::wstring m_consoleHelperPath;
    };

} // namespace consolefilefinder

#endif // CONSOLE_WINDOW_MANAGER_CONFIGURATION_H_a754cbc6_aa38_4d8e_997f_81a6fb9a032a
