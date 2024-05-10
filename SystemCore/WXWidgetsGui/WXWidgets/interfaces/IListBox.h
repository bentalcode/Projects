#ifndef I_LIST_BOX_83395ff3_963c_493f_91bf_766f8ed75831
#define I_LIST_BOX_83395ff3_963c_493f_91bf_766f8ed75831

#include "IGuiController.h"
#include "WXObjectPtr.h"
#include <vector>
#include <string>

namespace wxwidgets {

    class IWindow;

    /**
     * The IListBox interface defines a list box.
     */
    class IListBox {
    public:
        IListBox() = default;
        virtual ~IListBox() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const std::vector<std::wstring>& items,
            IGuiControllerSharedPtr guiController,
            bool showMode = true) = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;

        /**
         * Set a selected item.
         */
        virtual bool SetSelectedItem(int index) = 0;

        /**
         * The On Selected Item callback.
         */
        virtual void OnSelectedItem(const std::wstring& item) = 0;
    };

    //
    // Defines the WX Object Ptr of List Box.
    //
    using IListBoxPtr = WXObjectPtr<IListBox>;

} // namespace wxwidgets

#endif // I_LIST_BOX_83395ff3_963c_493f_91bf_766f8ed75831
