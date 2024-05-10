#ifndef ABSTRACT_FRAME_df228e06_f89a_4b6d_882a_f6be995532d2
#define ABSTRACT_FRAME_df228e06_f89a_4b6d_882a_f6be995532d2

#include "IFrame.h"
#include "Window.h"
#include "wx/frame.h"

namespace WXWidgets {

    /**
     * The AbstractFrame class implements an abstract base class of a frame.
     */
    class AbstractFrame : public IFrame, public Window, public wxFrame {
    public:
        /**
         * The AbstractFrame constructor.
         */
        AbstractFrame(
            wxWindow* parent,
            const wxString& name,
            const wxString& title,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            long style);

        /**
         * The AbstractFrame destructor.
         */
        virtual ~AbstractFrame();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Sets menu bar.
         */
        virtual void SetMenuBar(wxMenuBar& menuBar) override;

        /**
         * Sets status text.
         */
        virtual void SetStatusText(const wxString& text) override;

        /**
         * Maximizes frame.
         */
        virtual void Maximize() override;

        /**
         * Maximizes and centeralizes frame.
         */
        virtual void MaximizeAndCenteralize() override;
    };

} // namespace WXWidgets

#endif // ABSTRACT_FRAME_df228e06_f89a_4b6d_882a_f6be995532d2
