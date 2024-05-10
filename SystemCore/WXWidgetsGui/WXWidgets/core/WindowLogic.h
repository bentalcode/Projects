#ifndef WINDOW_LOGIC_ea841748_dfd3_4c49_8806_ea7e190b1855
#define WINDOW_LOGIC_ea841748_dfd3_4c49_8806_ea7e190b1855

#include "IWindowLogic.h"
#include "ILoggers.h"

namespace wxwidgets {

    /**
     * The WindowLogic class implements logic related to windows.
     */
    class WindowLogic : public IWindowLogic {
    public:
        /**
         * Creates a window logic.
         */
        static IWindowLogicSharedPtr Make();

        /**
         * The WindowLogic constructor.
         */
        WindowLogic();

        /**
         * The WindowLogic destructor.
         */
        virtual ~WindowLogic();

        /**
         * Gets root window.
         */
        virtual wxWindow& GetRootWindow(wxWindow& window) const override;

        /**
         * Gets root window.
         */
        virtual const wxWindow& GetRootWindow(const wxWindow& window) const override;

        /**
         * Gets parent windows.
         */
        virtual void GetParentWindows(
            wxWindow& window,
            std::vector<wxWindow*>& windows) const override;

        /**
         * Gets parent windows.
         */
        virtual void GetParentWindows(
            const wxWindow& window,
            std::vector<const wxWindow*>& windows) const override;

        /**
         * Finds a common ancestor window.
         * Returns nullptr if no common ancestor has been found.
         */
        virtual wxWindow* FindCommonAncestor(
            wxWindow& left,
            wxWindow& right) const override;

        /**
         * Finds a common ancestor window.
         * Returns nullptr if no common ancestor has been found.
         */
        virtual const wxWindow* FindCommonAncestor(
            const wxWindow& first,
            const wxWindow& second) const override;

    private:
        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace wxwidgets

#endif // WINDOW_LOGIC_ea841748_dfd3_4c49_8806_ea7e190b1855
