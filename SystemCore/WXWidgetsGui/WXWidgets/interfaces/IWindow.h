#ifndef I_WINDOW_1e683655_6c51_4b03_bb91_0a29b09bb6d7
#define I_WINDOW_1e683655_6c51_4b03_bb91_0a29b09bb6d7

#include "Orient.h"
#include <vector>

class wxWindow;
class wxSize;

namespace wxwidgets {

    class IGuiComponent;

    /**
     * The IWindow interface defines a window component.
     */
    class IWindow {
    public:
        IWindow() = default;
        virtual ~IWindow() = default;

        /**
         * Sets size.
         */
        virtual void SetSize(const wxSize& size) = 0;

        /**
         * Maximizes window.
         */
        virtual void Maximize() = 0;

        /**
         * Centralizes window.
         */
        virtual void Centralize() = 0;

        /**
         * Maximizes and centeralize window.
         */
        virtual void MaximizeAndCenteralize() = 0;

        /**
         * Gets a window.
         */
        virtual wxWindow& AsWindow() = 0;

        /**
         * Gets a GUI component.
         */
        virtual IGuiComponent& GetComponent() = 0;

        /**
         * Shows or hides a window.
         */
        virtual void ShowOrHide(bool showMode) = 0;

        /**
         * Gets parent windows.
         */
        virtual void GetParentWindows(std::vector<wxWindow*>& windows) = 0;
        virtual void GetParentWindows(std::vector<const wxWindow*>& windows) const = 0;

        /**
         * Finds a common ancestor window.
         */
        virtual wxWindow* FindCommonAncestor(wxWindow& first, wxWindow& second) = 0;
        virtual const wxWindow* FindCommonAncestor(const wxWindow& first, const wxWindow& second) const = 0;

        /**
         * Checks whether a window has a scrollbar.
         */
        virtual bool ScrollbarExists(Orient orient) const = 0;

        /**
         * Sets scrollbar of a window to min position.
         */
        virtual void SetScrollbarToMinPosition(Orient orient) = 0;

        /**
         * Sets scrollbar of a window to max position.
         */
        virtual void SetScrollbarToMaxPosition(Orient orient) = 0;
    };

} // namespace wxwidgets

#endif // I_WINDOW_1e683655_6c51_4b03_bb91_0a29b09bb6d7
