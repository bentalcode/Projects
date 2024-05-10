#ifndef SPLITTER_WINDOW_93801574_4685_4443_87f1_b551154753c8
#define SPLITTER_WINDOW_93801574_4685_4443_87f1_b551154753c8

#include "AbstractSplitterWindow.h"
#include "WXObjectId.h"

namespace wxwidgets {

    /**
     * The SplitterWindow class implements a splitter window,
     * which can be splitted in two directions: vertically or horizontally.
     */
    class SplitterWindow : public AbstractSplitterWindow {
    public:
        /**
         * The SplitterWindow constructor.
         */
        SplitterWindow(
            const wxString& name,
            wxWindow& parent,
            wxWindowID id = wxwidgets::WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxSP_3D);

        /**
         * The SplitterWindow destructor.
         */
        virtual ~SplitterWindow();

        /**
         * The On Updation callback.
         */
        virtual void OnUpdation(const ISplitterWindowConfiguration& configuration);

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;
    };

} // namespace wxwidgets

#endif // SPLITTER_WINDOW_93801574_4685_4443_87f1_b551154753c8
