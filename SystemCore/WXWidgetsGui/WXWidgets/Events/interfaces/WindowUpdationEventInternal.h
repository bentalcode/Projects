#ifndef WINDOW_UPDATION_EVENT_INTERNAL_6be98cfa_ed93_41ab_a2fe_81710e56d334
#define WINDOW_UPDATION_EVENT_INTERNAL_6be98cfa_ed93_41ab_a2fe_81710e56d334

#include "wx/event.h"

namespace WXWidgets {

    /**
     * The WindowUpdationEventInternal class implements an internal event for updation of a window.
     */
    class WindowUpdationEventInternal final : public wxCommandEvent {
    public:
        //
        // Defines the WX Event Type...
        //
        using Type = wxEventTypeTag<WindowUpdationEventInternal>;
        static const Type TYPE;

        /**
         * Gets an event id.
         */
        static int GetId();

        /**
         * The WindowUpdationEventInternal constructor.
         */
        WindowUpdationEventInternal();

        /**
         * The WindowUpdationEventInternal destructor.
         */
        virtual ~WindowUpdationEventInternal();

        /**
         * Clones an event.
         */
        wxEvent* Clone() const;
    };

} // namespace WXWidgets

#endif // WINDOW_UPDATION_EVENT_INTERNAL_6be98cfa_ed93_41ab_a2fe_81710e56d334
