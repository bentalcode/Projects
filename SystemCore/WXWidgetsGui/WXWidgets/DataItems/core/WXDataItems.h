#ifndef WX_DATA_ITEMS_5bd0dd83_31a1_4c7d_abff_66a0b9f204fa
#define WX_DATA_ITEMS_5bd0dd83_31a1_4c7d_abff_66a0b9f204fa

#include "IWXDataItems.h"

namespace wxwidgets {

    /**
     * The WXDataItems class implements data items.
     */
    class WXDataItems : public IWXDataItems {
    public:
        /**
         * Reads data item from catalog.
         */
        static const IWXDataItems& Read();

        /**
         * Creates data items.
         */
        static IDataItemsSharedPtr Make();

        /**
         * The WXDataItems constructor.
         */
        WXDataItems();

        /**
         * The WXDataItems destructor.
         */
        virtual ~WXDataItems();

        /**
         * Gets category name of data items.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets a component show mode.
         */
        virtual const std::wstring& GetComponentShowMode() const override;

        /**
         * Gets a list box items.
         */
        virtual const std::wstring& GetListBoxItems() const override;

        /**
         * Gets a list view headers.
         */
        virtual const std::wstring& GetListViewHeaders() const override;

        /**
         * Gets a list view values.
         */
        virtual const std::wstring& GetListViewValues() const override;

        /**
         * Gets a text control value.
         */
        virtual const std::wstring& GetTextControlValue() const override;

        /**
         * Gets a slider dimension value.
         */
        virtual const std::wstring& GetSliderDimensionValue() const override;

        /**
         * Gets a slider dimension min value.
         */
        virtual const std::wstring& GetSliderDimensionMinValue() const override;

        /**
         * Gets a slider dimension max value.
         */
        virtual const std::wstring& GetSliderDimensionMaxValue() const override;

        /**
         * Gets a static text value.
         */
        virtual const std::wstring& GetStaticTextValue() const override;

        /**
         * Gets a html window content.
         */
        virtual const std::wstring& GetHtmlWindowContent() const override;

        /**
         * Gets a splitter window first sub-window show mode.
         */
        virtual const std::wstring& GetSplitterWindowFirstSubWindowShowMode() const override;

        /**
         * Gets a splitter window second sub-window show mode.
         */
        virtual const std::wstring& GetSplitterWindowSecondSubWindowShowMode() const override;

    private:
        static const std::wstring NAME;
        static const std::wstring COMPONENT_SHOW_MODE;
        static const std::wstring LIST_BOX_ITEMS;
        static const std::wstring LIST_VIEW_HEADERS;
        static const std::wstring LIST_VIEW_VALUES;
        static const std::wstring STATIC_TEXT_VALUE;
        static const std::wstring TEXT_CONTROL_VALUE;
        static const std::wstring HTML_WINDOW_CONTENT;

        static const std::wstring SLIDER_DIMENSION_VALUE;
        static const std::wstring SLIDER_DIMENSION_MIN_VALUE;
        static const std::wstring SLIDER_DIMENSION_MAX_VALUE;

        static const std::wstring SPLITTER_WINDOW_FIRST_SUB_WINDOW_SHOW_MODE;
        static const std::wstring SPLITTER_WINDOW_SECOND_SUB_WINDOW_SHOW_MODE;
    };

} // namespace wxwidgets

#endif // WX_DATA_ITEMS_5bd0dd83_31a1_4c7d_abff_66a0b9f204fa
