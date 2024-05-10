#ifndef ABSTRACT_LIST_VIEW_104cadef_a5f4_46bb_8877_9bad766c606d
#define ABSTRACT_LIST_VIEW_104cadef_a5f4_46bb_8877_9bad766c606d

#include "IListView.h"
#include "Window.h"
#include "ILoggerFactory.h"
#include "wx/listctrl.h"

namespace WXWidgets {

    /**
     * The AbstractListView class implements an abstract base class of a list view.
     */
    class AbstractListView : public IListView, public Window, public wxListView {
    public:
        /**
         * The AbstractListView constructor.
         */
        AbstractListView(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            long style,
            const wxValidator& validator);

        /**
         * The AbstractListView destructor.
         */
        virtual ~AbstractListView();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const std::vector<std::wstring>& headers,
            const std::vector<std::vector<std::wstring>>& values,
            const wxListColumnFormat& headerFormat,
            size_t headerWidth,
            IGuiControllerSharedPtr guiController,
            bool showMode = true) override;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Sets headers.
         */
        virtual void SetHeaders(const std::vector<std::wstring>& headers) override;

        /**
         * Sets rows.
         */
        virtual void SetRows(const std::vector<std::vector<std::wstring>>& values) override;

        /**
         * Sets a row.
         */
        virtual void SetRow(
            size_t rowIndex,
            const std::vector<std::wstring>& values) override;

        /**
         * Sets a value.
         */
        virtual void SetValue(
            size_t rowIndex,
            size_t columnIndex,
            const std::wstring& value) override;

        /**
         * Gets headers.
         */
        virtual void GetHeaders(std::vector<std::wstring>& headers) const override;

        /**
         * Sets headers attributes.
         */
        virtual void SetHeaderAttributes(
            ColorType colorType,
            ColorType backgroundColorType,
            const IFont& font) override;

        /**
         * Gets values.
         */
        virtual void GetValues(std::vector<std::vector<std::wstring>>& values) const override;

        /**
         * Clears all values.
         */
        virtual void Clear() override;

        /**
         * Aligns columns widths by header.
         */
        virtual void AlignColumnsWidthByHeader() override;

        /**
         * Aligns column width by header.
         */
        virtual void AlignColumnWidthByHeader(size_t columnIndex) override;

        /**
         * Sets background color of a row.
         */
        virtual void SetRowBackgroundColor(
            size_t rowIndex,
            ColorType colorType) override;

        /**
         * Updates data container (headers).
         */
        static void UpdateDataContainerHeaders(
            DataContainerManagement::IDataContainer& data,
            const std::vector<std::wstring>& headers);

        /**
         * Updates data container (values).
         */
        static void UpdateDataContainerValues(
            DataContainerManagement::IDataContainer& data,
            const std::vector<std::vector<std::wstring>>& values);

    protected:
        /**
         * Updates data from data container.
         * Returns true in case data has been updated.
         */
        virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

        /**
         * Updates component.
         */
        virtual void Update() override;

    private:
        /**
         * Resets component.
         */
        void Reset();

        /**
         * Gets headers.
         */
        void GetHeaders(std::vector<wxListItem>& headers) const;

        /**
         * Creates headers.
         */
        void CreateHeaders(const std::vector<std::wstring>& headers);

        /**
         * Deletes headers.
         */
        void DeleteHeaders();

        /**
         * Deletes values.
         */
        void DeleteValues();

        /**
         * Gets number of headers.
         */
        size_t GetHeadersCount() const;

        /**
         * Creates a header and returns it's index.
         */
        long CreateHeader(
            const std::wstring& name,
            wxListColumnFormat format,
            int width);

        /**
         * Creates a header at specific index.
         */
        long CreateHeader(
            long index,
            const std::wstring& name,
            wxListColumnFormat format,
            int width);

        /**
         * Creates a row and returns it's index.
         */
        long CreateRow(size_t rowIndex);

        /**
         * Gets properties of a header.
         */
        void GetHeaderProperties(int index, wxListItem& item) const;

        /**
         * Validates headers defined.
         */
        void ValidateHeadersDefined() const;

        /**
         * Validates headers.
         */
        static void ValidateHeaders(const std::vector<std::wstring>& headers);

        /**
         * Validates rows.
         */
        static void ValidateRows(
            const std::vector<std::vector<std::wstring>>& values,
            size_t expectedSize);

        /**
         * Validates row.
         */
        static void ValidateRow(
            const std::vector<std::wstring>& values,
            size_t expectedSize);

        /**
         * Checks whether headers are valid.
         */
        static bool AreHeadersValid(const std::vector<std::wstring>& headers);

        /**
         * Checks whether rows are valid.
         */
        static bool AreRowsValid(
            const std::vector<std::vector<std::wstring>>& values,
            size_t expectedSize);

        /**
         * Checks whether a row is valid.
         */
        static bool IsRowValid(
            const std::vector<std::wstring>& values,
            size_t expectedSize);

        //
        // The format of header...
        //
        wxListColumnFormat m_headerFormat;

        //
        // The width of header...
        //
        size_t m_headerWidth;

        //
        // The headers of the list view...
        //
        std::vector<std::wstring> m_headers;

        //
        // The values of the list view...
        //
        std::vector<std::vector<std::wstring>> m_values;
    };

} // namespace WXWidgets

#endif // ABSTRACT_LIST_VIEW_104cadef_a5f4_46bb_8877_9bad766c606d
