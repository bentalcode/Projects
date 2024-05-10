#ifndef I_GUI_CONFIGURATION_MANAGER_f52c51c7_5c9b_4be7_adef_e0796cfc22c3
#define I_GUI_CONFIGURATION_MANAGER_f52c51c7_5c9b_4be7_adef_e0796cfc22c3

#include "IAppConfiguration.h"
#include "IClientConfiguration.h"
#include "IFramesConfiguration.h"
#include "IDialogsConfiguration.h"
#include "IMenuItemsConfiguration.h"
#include "IMenusConfiguration.h"
#include "ISlidersConfiguration.h"
#include "ILabelsConfiguration.h"

namespace GuiConfiguration {

    /**
     * The IGuiConfigurationManager class defines an interface of configuration manager of GUI.
     */
    class IGuiConfigurationManager {
    public:
        IGuiConfigurationManager() = default;
        virtual ~IGuiConfigurationManager() = default;

        /**
         * Sets configuration of app.
         */
        virtual void SetAppConfiguration(IAppConfigurationSharedPtr configuration) = 0;

        /**
         * Sets configuration of client.
         */
        virtual void SetClientConfiguration(IClientConfigurationSharedPtr configuration) = 0;

        /**
         * Sets configuration of frames.
         */
        virtual void SetFramesConfiguration(IFramesConfigurationSharedPtr configuration) = 0;

        /**
         * Sets configuration of dialogs.
         */
        virtual void SetDialogsConfiguration(IDialogsConfigurationSharedPtr configuration) = 0;

        /**
         * Sets configuration of menus.
         */
        virtual void SetMenusConfiguration(IMenusConfigurationSharedPtr configuration) = 0;

        /**
         * Sets configuration of menu items.
         */
        virtual void SetMenuItemsConfiguration(IMenuItemsConfigurationSharedPtr configuration) = 0;

        /**
         * Sets configuration of sliders.
         */
        virtual void SetSlidersConfiguration(ISlidersConfigurationSharedPtr configuration) = 0;

        /**
         * Sets configuration of labels.
         */
        virtual void SetLabelsConfiguration(ILabelsConfigurationSharedPtr configuration) = 0;

        /**
         * Gets configuration of app.
         */
        virtual IAppConfigurationSharedPtr GetAppConfiguration() const = 0;

        /**
         * Gets configuration of client.
         */
        virtual IClientConfigurationSharedPtr GetClientConfiguration() const = 0;

        /**
         * Gets configuration of frames.
         */
        virtual IFramesConfigurationSharedPtr GetFramesConfiguration() const = 0;

        /**
         * Gets configuration of dialogs.
         */
        virtual IDialogsConfigurationSharedPtr GetDialogsConfiguration() const = 0;

        /**
         * Gets configuration of menus.
         */
        virtual IMenusConfigurationSharedPtr GetMenusConfiguration() const = 0;

        /**
         * Gets configuration of menu items.
         */
        virtual IMenuItemsConfigurationSharedPtr GetMenuItemsConfiguration() const = 0;

        /**
         * Gets configuration of sliders.
         */
        virtual ISlidersConfigurationSharedPtr GetSlidersConfiguration() const = 0;

        /**
         * Gets configuration of labels.
         */
        virtual ILabelsConfigurationSharedPtr GetLabelsConfiguration() const = 0;
    };

    //
    // Defines the Shared Ptr of GUI Configuration Manager.
    //
    using IGuiConfigurationManagerSharedPtr = std::shared_ptr<IGuiConfigurationManager>;

} // namespace GuiConfiguration

#endif // I_GUI_CONFIGURATION_MANAGER_f52c51c7_5c9b_4be7_adef_e0796cfc22c3
