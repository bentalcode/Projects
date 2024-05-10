#ifndef GUI_CONFIGURATION_FACTORY_H_941cae27_8fcc_40ac_bd65_e597e4121e78
#define GUI_CONFIGURATION_FACTORY_H_941cae27_8fcc_40ac_bd65_e597e4121e78

#include "IGuiConfigurationFactory.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The GuiConfigurationFactory class implements a configuration of a factory.
         */
        class GuiConfigurationFactory final : public IGuiConfigurationFactory {
        public:
            /**
             * Creates a GUI Configuration Factory.
             */
            static IGuiConfigurationFactorySharedPtr Make();

            /**
             * The GuiConfigurationFactory constructor.
             */
            GuiConfigurationFactory();

            /**
             * The GuiConfigurationFactory destructor.
             */
            virtual ~GuiConfigurationFactory();

            /**
             * Creates a configuration manager of GUI.
             */
            virtual GuiConfiguration::IGuiConfigurationManagerSharedPtr CreateConfigurationManager() const override;

        private:
            /**
             * Creates a configuration of app.
             */
            static GuiConfiguration::IAppConfigurationSharedPtr CreateAppConfiguration();

            /**
             * Creates a configuration of client.
             */
            static GuiConfiguration::IClientConfigurationSharedPtr CreateClientConfiguration();

            /**
             * Creates a configuration of frames.
             */
            static GuiConfiguration::IFramesConfigurationSharedPtr CreateFramesConfiguration();

            /**
             * Creates a configuration of dialogs.
             */
            static GuiConfiguration::IDialogsConfigurationSharedPtr CreateDialogsConfiguration();

            /**
             * Creates a configuration of menus.
             */
            static GuiConfiguration::IMenusConfigurationSharedPtr CreateMenusConfiguration();

            /**
             * Creates a configuration of menu items.
             */
            static GuiConfiguration::IMenuItemsConfigurationSharedPtr CreateMenuItemsConfiguration();

            /**
             * Creates a configuration of sliders.
             */
            static GuiConfiguration::ISlidersConfigurationSharedPtr CreateSlidersConfiguration();

            /**
             * Creates a configuration of labels.
             */
            static GuiConfiguration::ILabelsConfigurationSharedPtr CreateLabelsConfiguration();

            /**
             * Creates a configuration of an open menu item.
             */
            static GuiConfiguration::IMenuItemConfigurationSharedPtr CreateOpenMenuItemConfiguration();

            /**
             * Creates a configuration of an exit menu item.
             */
            static GuiConfiguration::IMenuItemConfigurationSharedPtr CreateExitMenuItemConfiguration();

            /**
             * Creates a configuration of a rendering pipelines menu item.
             */
            static GuiConfiguration::IMenuItemConfigurationSharedPtr CreateRenderingPipelinesMenuItemConfiguration();

            /**
             * Creates a configuration of an event viewer menu item.
             */
            static GuiConfiguration::IMenuItemConfigurationSharedPtr CreateEventViewerMenuItemConfiguration();

            /**
             * Creates a configuration of a log statistics menu item.
             */
            static GuiConfiguration::IMenuItemConfigurationSharedPtr CreateLogStatisticsMenuItemConfiguration();

            /**
             * Creates a configuration of an app log menu item.
             */
            static GuiConfiguration::IMenuItemConfigurationSharedPtr CreateAppLogMenuItemConfiguration();

            /**
             * Creates a configuration of an about menu item.
             */
            static GuiConfiguration::IMenuItemConfigurationSharedPtr CreateAboutMenuItemConfiguration();
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // GUI_CONFIGURATION_FACTORY_H_941cae27_8fcc_40ac_bd65_e597e4121e78
