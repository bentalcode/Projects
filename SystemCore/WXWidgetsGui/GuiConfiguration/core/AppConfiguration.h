#ifndef APP_CONFIGURATION_b1b8e35c_2bdb_453e_bc45_348450da8152
#define APP_CONFIGURATION_b1b8e35c_2bdb_453e_bc45_348450da8152

#include "IAppConfiguration.h"

namespace GuiConfiguration {

    /**
     * The AppConfiguration class implements configuration of an app.
     */
    class AppConfiguration final : public IAppConfiguration {
    public:
        /**
         * Creates an app configuration.
         */
        static IAppConfigurationSharedPtr Make(
            const std::wstring& name,
            const std::wstring& logPath);

        /**
         * The AppConfiguration constructor.
         */
        AppConfiguration(
            const std::wstring& name,
            const std::wstring& logPath);

        /**
         * The AppConfiguration destructor.
         */
        virtual ~AppConfiguration();

        /**
         * Gets name of an app.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets log path.
         */
        virtual const std::wstring& GetLogPath() const override;

    private:
        std::wstring m_name;
        std::wstring m_logPath;
    };

} // namespace GuiConfiguration

#endif // APP_CONFIGURATION_b1b8e35c_2bdb_453e_bc45_348450da8152
