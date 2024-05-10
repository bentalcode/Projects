#ifndef I_GUI_CONFIGUATION_FACTORY_H_f62a6862_ab26_4b89_b88c_32662d9615f9
#define I_GUI_CONFIGUATION_FACTORY_H_f62a6862_ab26_4b89_b88c_32662d9615f9

#include "IGuiConfigurationManager.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The IGuiConfigurationFactory class defines an interface of
         * a factory of a configuration of Gui.
         */
        class IGuiConfigurationFactory {
        public:
            IGuiConfigurationFactory() = default;
            virtual ~IGuiConfigurationFactory() = default;

            /**
             * Creates a configuration manager of GUI.
             */
            virtual GuiConfiguration::IGuiConfigurationManagerSharedPtr CreateConfigurationManager() const = 0;
        };

        //
        // Defines the Shared Ptr of Gui Configuration Factory.
        //
        using IGuiConfigurationFactorySharedPtr = std::shared_ptr<IGuiConfigurationFactory>;

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_GUI_CONFIGUATION_FACTORY_H_f62a6862_ab26_4b89_b88c_32662d9615f9
