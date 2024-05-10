#ifndef CONFIGURATION_PROVIDER_H_41309c58_8418_433d_83e4_a3c01847cd9c
#define CONFIGURATION_PROVIDER_H_41309c58_8418_433d_83e4_a3c01847cd9c

#include "IConfigurationProvider.h"
#include <mutex>

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The ConfigurationProvider class implements a proider of configuration.
         */
        class ConfigurationProvider final : public IConfigurationProvider {
        public:
            /**
             * Gets an instance of a provider.
             */
            static IConfigurationProviderSharedPtr GetInstance();

            /**
             * Creates a Configuration Provider.
             */
            static IConfigurationProviderSharedPtr Create();

            /**
             * The ConfigurationProvider constructor.
             */
            ConfigurationProvider();

            /**
             * The ConfigurationProvider destructor.
             */
            virtual ~ConfigurationProvider();

            /**
             * Gets a configuration manager of GUI.
             */
            virtual GuiConfiguration::IGuiConfigurationManagerSharedPtr GetGuiConfigurationManager() const override;

        private:
            /**
             * Creates a GUI configuration manager.
             */
            static GuiConfiguration::IGuiConfigurationManagerSharedPtr CreateGuiConfigurationManager();

            //
            // The Singletone instance and mutex...
            //
            static IConfigurationProviderSharedPtr INSTANCE;
            static std::mutex MUTEX;

            GuiConfiguration::IGuiConfigurationManagerSharedPtr m_guiConfigurationManager;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // CONFIGURATION_PROVIDER_H_41309c58_8418_433d_83e4_a3c01847cd9c
