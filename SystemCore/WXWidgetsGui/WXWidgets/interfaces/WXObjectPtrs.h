#ifndef WX_OBJECT_PTRS_2ad0a03e_dfa3_4045_9a81_153699c5d916
#define WX_OBJECT_PTRS_2ad0a03e_dfa3_4045_9a81_153699c5d916

#include "WXObjectPtr.h"

class wxWindow;
class wxMenuBar;
class wxPanel;
class wxBoxSizer;
class wxStaticBoxSizer;
class wxComboBox;
class wxListBox;
class wxTextCtrl;

namespace WXWidgets {

    //
    // Defines the WX Object Ptr of wxWindow.
    //
    using WXWindowPtr = WXObjectPtr<wxWindow>;

    //
    // Defines the WX Object Ptr of wxMenuBar.
    //
    using WXMenueBarPtr = WXObjectPtr<wxMenuBar>;

    //
    // Defines the WX Object Ptr of wxPanel.
    //
    using WXPanelPtr = WXObjectPtr<wxPanel>;

    //
    // Defines the WX Object Ptr of wxBoxSizer.
    //
    using WXBoxSizerPtr = WXObjectPtr<wxBoxSizer>;

    //
    // Defines the WX Object Ptr of wxStaticBoxSizer.
    //
    using WXStaticBoxSizerPtr = WXObjectPtr<wxStaticBoxSizer>;

    //
    // Defines the WX Object Ptr of wxComboBox.
    //
    using WXComboBoxPtr = WXObjectPtr<wxComboBox>;

    //
    // Defines the WX Object Ptr of wxListBox.
    //
    using WXListBoxPtr = WXObjectPtr<wxListBox>;

    //
    // Defines the WX Object Ptr of wxTextCtrl.
    //
    using WXTextCtrlPtr = WXObjectPtr<wxTextCtrl>;

} // namespace WXWidgets

#endif // WX_OBJECT_PTRS_2ad0a03e_dfa3_4045_9a81_153699c5d916
