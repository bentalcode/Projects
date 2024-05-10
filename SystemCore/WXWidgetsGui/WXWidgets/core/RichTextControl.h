#ifndef RICH_TEXT_CONTROL_493f793f_bd52_4199_a442_50c936876d20
#define RICH_TEXT_CONTROL_493f793f_bd52_4199_a442_50c936876d20

#include "Window.h"
#include "WXObjectId.h"
#include "WXObjectPtr.h"
#include <wx/richtext/richtextctrl.h>

namespace wxwidgets {

    /**
     * The Rich Text Control class implements a rich text control.
     */
    class RichTextControl : public Window, public wxRichTextCtrl {
    public:
        /**
         * Creates a rich text control.
         */
        static std::shared_ptr<RichTextControl> Make(
            wxWindow& parent,
            const wxString& name,
            const wxString& value = wxEmptyString,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxRE_MULTILINE,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The RichTextControl constructor.
         */
        RichTextControl(
            wxWindow& parent,
            const wxString& name,
            const wxString& value,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            long style,
            const wxValidator& validator);

        /**
         * The RichTextControl destructor.
         */
        virtual ~RichTextControl();

        /**
         * Initializes a GUI component.
         */
        void Initialize(IGuiControllerSharedPtr guiController);
    };

    //
    // Defines the WX Object Ptr for Rich Text Control.
    //
    using RichTextControlPtr = WXObjectPtr<RichTextControl>;

} // namespace wxwidgets

#endif // RICH_TEXT_CONTROL_493f793f_bd52_4199_a442_50c936876d20
