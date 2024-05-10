#ifndef FRAME_a0c6df4e_2819_426f_b1d2_6720e99b21cb
#define FRAME_a0c6df4e_2819_426f_b1d2_6720e99b21cb

#include "AbstractFrame.h"
#include "WXObjectId.h"

namespace wxwidgets {

    /**
     * The Frame class implements a frame.
     */
    class Frame : public AbstractFrame {
    public:
        /**
         * Creates a frame.
         */
        static IFramePtr Make(
            wxWindow* parent,
            const wxString& name,
            const wxString& title,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_FRAME_STYLE);

        /**
         * The Frame constructor.
         */
        Frame(
            wxWindow* parent,
            const wxString& name,
            const wxString& title,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_FRAME_STYLE);

        /**
         * The Frame destructor.
         */
        virtual ~Frame();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;
    };

} // namespace wxwidgets

#endif // FRAME_a0c6df4e_2819_426f_b1d2_6720e99b21cb
