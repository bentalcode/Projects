#ifndef I_WX_DATA_ITEMS_e75df3cd_30f7_47a6_a1d7_8a06c2d69921
#define I_WX_DATA_ITEMS_e75df3cd_30f7_47a6_a1d7_8a06c2d69921

#include "IDataItems.h"

namespace wxwidgets {

    /**
     * The IWXDataItems interface defines WX data items.
     */
    class IWXDataItems : public IDataItems {
    public:
        IWXDataItems() = default;
        virtual ~IWXDataItems() = default;

        /**
         * Gets a component show mode.
         */
        virtual const std::wstring& GetComponentShowMode() const = 0;

        /**
         * Gets a list box items.
         */
        virtual const std::wstring& GetListBoxItems() const = 0;

        /**
         * Gets a list view headers.
         */
        virtual const std::wstring& GetListViewHeaders() const = 0;

        /**
         * Gets a list view values.
         */
        virtual const std::wstring& GetListViewValues() const = 0;

        /**
         * Gets a text control value.
         */
        virtual const std::wstring& GetTextControlValue() const = 0;

        /**
         * Gets a slider dimension value.
         */
        virtual const std::wstring& GetSliderDimensionValue() const = 0;

        /**
         * Gets a slider dimension min value.
         */
        virtual const std::wstring& GetSliderDimensionMinValue() const = 0;

        /**
         * Gets a slider dimension max value.
         */
        virtual const std::wstring& GetSliderDimensionMaxValue() const = 0;

        /**
         * Gets a static text value.
         */
        virtual const std::wstring& GetStaticTextValue() const = 0;

        /**
         * Gets a html window content.
         */
        virtual const std::wstring& GetHtmlWindowContent() const = 0;

        /**
         * Gets a splitter window first sub-window show node.
         */
        virtual const std::wstring& GetSplitterWindowFirstSubWindowShowMode() const = 0;

        /**
         * Gets a splitter window second sub-window show node.
         */
        virtual const std::wstring& GetSplitterWindowSecondSubWindowShowMode() const = 0;
    };

} // namespace wxwidgets

#endif // I_WX_DATA_ITEMS_e75df3cd_30f7_47a6_a1d7_8a06c2d69921
