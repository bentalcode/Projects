#ifndef I_APP_CONFIGUATION_PROVIDER_H_250d64cc_eb88_44bd_bd1e_0af6710b446d
#define I_APP_CONFIGUATION_PROVIDER_H_250d64cc_eb88_44bd_bd1e_0af6710b446d

#include "IGuiConfigurationManager.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The IConfigurationProvider class defines an interface of
         * a provider of a configuration.
         */
        class IConfigurationProvider {
        public:
            IConfigurationProvider() = default;
            virtual ~IConfigurationProvider() = default;

            /**
             * Gets a configuration manager of GUI.
             */
            virtual GuiConfiguration::IGuiConfigurationManagerSharedPtr GetGuiConfigurationManager() const = 0;
        };

        //
        // Defines the Shared Ptr of Configuration Provider.
        //
        using IConfigurationProviderSharedPtr = std::shared_ptr<IConfigurationProvider>;

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_APP_CONFIGUATION_PROVIDER_H_250d64cc_eb88_44bd_bd1e_0af6710b446d
