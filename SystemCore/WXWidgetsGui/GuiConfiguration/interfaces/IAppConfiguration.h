#ifndef I_APP_CONFIGURATION_e3236732_11db_4b4e_97be_9f4da3f9ce8e
#define I_APP_CONFIGURATION_e3236732_11db_4b4e_97be_9f4da3f9ce8e

#include <memory>
#include <string>

namespace GuiConfiguration {

    /**
     * The IAppConfiguration class defines an interface of configuration of an app.
     */
    class IAppConfiguration {
    public:
        IAppConfiguration() = default;
        virtual ~IAppConfiguration() = default;

        /**
         * Gets name of an app.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Gets log path.
         */
        virtual const std::wstring& GetLogPath() const = 0;
    };

    //
    // Defines the Shared Ptr of App Configuration.
    //
    using IAppConfigurationSharedPtr = std::shared_ptr<IAppConfiguration>;

} // namespace GuiConfiguration

#endif // I_APP_CONFIGURATION_e3236732_11db_4b4e_97be_9f4da3f9ce8e

