#ifndef I_SLIDER_CONFIGURATION_ITEMS_H_492b68e0_22a4_4149_ada4_0d23441f102c
#define I_SLIDER_CONFIGURATION_ITEMS_H_492b68e0_22a4_4149_ada4_0d23441f102c

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        /**
         * The ISliderConfigurationItems interface defines
         * configuration items of sliders.
         */
        class ISliderConfigurationItems : public GuiConfiguration::IConfigurationItems {
        public:
            ISliderConfigurationItems() = default;
            virtual ~ISliderConfigurationItems() = default;

            /**
             * Gets name of main right top window lower sub window - min number of units.
             */
            virtual const unsigned int GetMainRightTopWindowLowerSubWindowSliderMinNumberOfUnits() const = 0;

            /**
             * Gets name of main right top window lower sub window - max number of units.
             */
            virtual const unsigned int GetMainRightTopWindowLowerSubWindowSliderMaxNumberOfUnits() const = 0;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_SLIDER_CONFIGURATION_ITEMS_H_492b68e0_22a4_4149_ada4_0d23441f102c
