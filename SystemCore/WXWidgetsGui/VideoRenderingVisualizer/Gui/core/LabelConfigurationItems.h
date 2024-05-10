#ifndef LABEL_CONFIGURATION_ITEMS_H_2f9791e5_397a_4ead_bc3e_1c38185091a8
#define LABEL_CONFIGURATION_ITEMS_H_2f9791e5_397a_4ead_bc3e_1c38185091a8

#include "ILabelConfigurationItems.h"
#include <string>

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        /**
         * The LabelConfigurationItems class implements configuration items of labels.
         */
        class LabelConfigurationItems final : public ILabelConfigurationItems {
        public:
            /**
             * Reads label configuration items from configuration.
             */
            static const ILabelConfigurationItems& Read();

            /**
             * Creates label configuration items.
             */
            static GuiConfiguration::IConfigurationItemsSharedPtr Make();

            /**
             * The LabelConfigurationItems constructor.
             */
            LabelConfigurationItems();

            /**
             * The LabelConfigurationItems destructor.
             */
            virtual ~LabelConfigurationItems();

            /**
             * Gets category name of data items.
             */
            virtual const std::wstring& GetName() const override;

            /**
             * Gets label of main left window.
             */
            virtual const std::wstring& GetMainLeftWindowLabel() const override;

            /**
             * Gets label of main right bottom window.
             */
            virtual const std::wstring& GetMainRightWindowLabel() const override;

            /**
             * Gets label of main left top window.
             */
            virtual const std::wstring& GetMainLeftTopWindowLabel() const override;

            /**
             * Gets label of main left bottom window.
             */
            virtual const std::wstring& GetMainLeftBottomWindowLabel() const override;

            /**
             * Gets label of main left top window - upper sub window.
             */
            virtual const std::wstring& GetMainLeftTopWindowUpperSubWindowLabel() const override;

            /**
             * Gets label of main left top window - lower sub window.
             */
            virtual const std::wstring& GetMainLeftTopWindowLowerSubWindowLabel() const override;

            /**
             * Gets label of main right top window.
             */
            virtual const std::wstring& GetMainRightTopWindowLabel() const override;

            /**
             * Gets label of main right bottom window.
             */
            virtual const std::wstring& GetMainRightBottomWindowLabel() const override;

            /**
             * Gets label of main right top window - upper sub window.
             */
            virtual const std::wstring& GetMainRightTopWindowUpperSubWindowLabel() const override;

            /**
             * Gets label of main right top window - lower sub window.
             */
            virtual const std::wstring& GetMainRightTopWindowLowerSubWindowLabel() const override;

        private:
            static const std::wstring NAME;
            static const std::wstring MAIN_LEFT_WINDOW_LABEL;
            static const std::wstring MAIN_RIGHT_WINDOW_LABEL;
            static const std::wstring MAIN_LEFT_TOP_WINDOW_LABEL;
            static const std::wstring MAIN_LEFT_BOTTOM_WINDOW_LABEL;
            static const std::wstring MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL;
            static const std::wstring MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL;
            static const std::wstring MAIN_RIGHT_TOP_WINDOW_LABEL;
            static const std::wstring MAIN_RIGHT_BOTTOM_WINDOW_LABEL;
            static const std::wstring MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL;
            static const std::wstring MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // LABEL_CONFIGURATION_ITEMS_H_2f9791e5_397a_4ead_bc3e_1c38185091a8
