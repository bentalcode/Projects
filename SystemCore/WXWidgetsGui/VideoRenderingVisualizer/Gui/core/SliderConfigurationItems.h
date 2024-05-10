#ifndef SLIDER_CONFIGURATION_ITEMS_H_392ed2b0_c76d_406e_a440_a68a9d51fcf8
#define SLIDER_CONFIGURATION_ITEMS_H_392ed2b0_c76d_406e_a440_a68a9d51fcf8

#include "ISliderConfigurationItems.h"

namespace VideoRenderingVisualizer {

     namespace Gui {

        /**
         * The SliderConfigurationItems class implements configuration items of sliders.
         */
        class SliderConfigurationItems final : public ISliderConfigurationItems {
        public:
            /**
             * Reads slider configuration items from configuration.
             */
            static const ISliderConfigurationItems& Read();

            /**
             * Creates slider configuration items.
             */
            static GuiConfiguration::IConfigurationItemsSharedPtr Make();

            /**
             * The SliderConfigurationItems constructor.
             */
            SliderConfigurationItems();

            /**
             * The SliderConfigurationItems destructor.
             */
            virtual ~SliderConfigurationItems();

            /**
             * Gets category name of data items.
             */
            virtual const std::wstring& GetName() const override;

            /**
             * Gets name of main right top window lower sub window - slider min number of units.
             */
            virtual const unsigned int GetMainRightTopWindowLowerSubWindowSliderMinNumberOfUnits() const override;

            /**
             * Gets name of main right top window lower sub window - slider max number of units.
             */
            virtual const unsigned int GetMainRightTopWindowLowerSubWindowSliderMaxNumberOfUnits() const override;

        private:
            static const std::wstring NAME;
            static const unsigned int MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_SLIDER_MIN_NUMBER_OF_UNITS;
            static const unsigned int MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_SLIDER_MAX_NUMBER_OF_UNITS;
        };

     } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // SLIDER_CONFIGURATION_ITEMS_H_392ed2b0_c76d_406e_a440_a68a9d51fcf8
