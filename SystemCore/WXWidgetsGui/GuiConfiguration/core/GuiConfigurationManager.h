#ifndef GUI_CONFIGURATION_MANAGER_a67f7d00_935c_467e_9fd2_3c686dc589a8
#define GUI_CONFIGURATION_MANAGER_a67f7d00_935c_467e_9fd2_3c686dc589a8

#include "IGuiConfigurationManager.h"

namespace GuiConfiguration {

    /**
     * The GuiConfigurationManager class implements configuration manager of GUI.
     */
    class GuiConfigurationManager final : public IGuiConfigurationManager {
    public:
        /**
         * Creates a GUI configuration manager.
         */
        static IGuiConfigurationManagerSharedPtr Make();

        /**
         * The GuiConfigurationManager constructor.
         */
        GuiConfigurationManager();

        /**
         * The GuiConfigurationManager destructor.
         */
        virtual ~GuiConfigurationManager();

        /**
         * Sets configuration of app.
         */
        virtual void SetAppConfiguration(IAppConfigurationSharedPtr configuration) override;

        /**
         * Sets configuration of client.
         */
        virtual void SetClientConfiguration(IClientConfigurationSharedPtr configuration) override;

        /**
         * Sets configuration of frames.
         */
        virtual void SetFramesConfiguration(IFramesConfigurationSharedPtr configuration) override;

        /**
         * Sets configuration of dialogs.
         */
        virtual void SetDialogsConfiguration(IDialogsConfigurationSharedPtr configuration) override;

        /**
         * Sets configuration of menus.
         */
        virtual void SetMenusConfiguration(IMenusConfigurationSharedPtr configuration) override;

        /**
         * Sets configuration of menu items.
         */
        virtual void SetMenuItemsConfiguration(IMenuItemsConfigurationSharedPtr configuration) override;

        /**
         * Sets configuration of sliders.
         */
        virtual void SetSlidersConfiguration(ISlidersConfigurationSharedPtr configuration) override;

        /**
         * Sets configuration of labels.
         */
        virtual void SetLabelsConfiguration(ILabelsConfigurationSharedPtr configuration) override;

        /**
         * Gets configuration of app.
         */
        virtual IAppConfigurationSharedPtr GetAppConfiguration() const override;

        /**
         * Gets configuration of client.
         */
        virtual IClientConfigurationSharedPtr GetClientConfiguration() const override;

        /**
         * Gets configuration of frames.
         */
        virtual IFramesConfigurationSharedPtr GetFramesConfiguration() const override;

        /**
         * Gets configuration of dialogs.
         */
        virtual IDialogsConfigurationSharedPtr GetDialogsConfiguration() const override;

        /**
         * Gets configuration of menus.
         */
        virtual IMenusConfigurationSharedPtr GetMenusConfiguration() const override;

        /**
         * Gets configuration of menu items.
         */
        virtual IMenuItemsConfigurationSharedPtr GetMenuItemsConfiguration() const override;

        /**
         * Gets configuration of sliders.
         */
        virtual ISlidersConfigurationSharedPtr GetSlidersConfiguration() const override;

        /**
         * Gets configuration of labels.
         */
        virtual ILabelsConfigurationSharedPtr GetLabelsConfiguration() const override;

    private:
        IAppConfigurationSharedPtr m_appConfiguration;
        IClientConfigurationSharedPtr m_clientConfiguration;
        IFramesConfigurationSharedPtr m_framesConfiguration;
        IDialogsConfigurationSharedPtr m_dialogsConfiguration;
        IMenusConfigurationSharedPtr m_menusConfiguration;
        IMenuItemsConfigurationSharedPtr m_menuItemsConfiguration;
        ISlidersConfigurationSharedPtr m_slidersConfiguration;
        ILabelsConfigurationSharedPtr m_labelsConfiguration;
    };

} // namespace GuiConfiguration

#endif // GUI_CONFIGURATION_MANAGER_a67f7d00_935c_467e_9fd2_3c686dc589a8
