#ifndef I_LIST_VIEW_57c7bc02_0b37_49d2_a3d4_0e318bf65be6
#define I_LIST_VIEW_57c7bc02_0b37_49d2_a3d4_0e318bf65be6

#include "IGuiController.h"
#include "IColor.h"
#include "WXObjectPtr.h"
#include "wx\listbase.h"
#include <vector>
#include <string>

namespace wxwidgets {

    class IWindow;
    class IFont;

    /**
     * The IListView interface defines a list view.
     */
    class IListView {
    public:
        IListView() = default;
        virtual ~IListView() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const std::vector<std::wstring>& headers,
            const std::vector<std::vector<std::wstring>>& values,
            const wxListColumnFormat& headerFormat,
            size_t headerWidth,
            IGuiControllerSharedPtr guiController,
            bool showMode = true) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Sets headers.
         */
        virtual void SetHeaders(const std::vector<std::wstring>& headers) = 0;

        /**
         * Sets header attributes.
         */
        virtual void SetHeaderAttributes(
            ColorType fontColorType,
            ColorType backgroundColorType,
            const IFont& font) = 0;

        /**
         * Sets rows.
         */
        virtual void SetRows(const std::vector<std::vector<std::wstring>>& values) = 0;

        /**
         * Sets a row.
         */
        virtual void SetRow(size_t rowIndex, const std::vector<std::wstring>& values) = 0;

        /**
         * Sets a value.
         */
        virtual void SetValue(size_t rowIndex, size_t columnIndex, const std::wstring& value) = 0;

        /**
         * Gets headers.
         */
        virtual void GetHeaders(std::vector<std::wstring>& headers) const = 0;

        /**
         * Gets values.
         */
        virtual void GetValues(std::vector<std::vector<std::wstring>>& values) const = 0;

        /**
         * Clears all values.
         */
        virtual void Clear() = 0;

        /**
         * Aligns columns widths by header.
         */
        virtual void AlignColumnsWidthByHeader() = 0;

        /**
         * Aligns column width by header.
         */
        virtual void AlignColumnWidthByHeader(size_t columnIndex) = 0;

        /**
         * Sets background color of a row.
         */
        virtual void SetRowBackgroundColor(
            size_t rowIndex,
            ColorType colorType) = 0;
    };

    //
    // Defines the WX Object Ptr of List View.
    //
    using IListViewPtr = WXObjectPtr<IListView>;

} // namespace wxwidgets

#endif // I_LIST_VIEW_57c7bc02_0b37_49d2_a3d4_0e318bf65be6
