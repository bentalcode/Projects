#ifndef I_WINDOW_LOGIC_bc7bed15_c747_47ec_9b47_57652037186e
#define I_WINDOW_LOGIC_bc7bed15_c747_47ec_9b47_57652037186e

#include <memory>
#include <vector>

class wxWindow;

namespace WXWidgets {

    class IWindow;

    /**
     * The IWindowLogic interface defines a logic related to windows.
     */
    class IWindowLogic {
    public:
        IWindowLogic() = default;
        virtual ~IWindowLogic() = default;

        /**
         * Gets root window.
         */
        virtual wxWindow& GetRootWindow(wxWindow& window) const = 0;
        virtual const wxWindow& GetRootWindow(const wxWindow& window) const = 0;

        /**
         * Gets parent windows.
         */
        virtual void GetParentWindows(
            wxWindow& window,
            std::vector<wxWindow*>& windows) const = 0;

        virtual void GetParentWindows(
            const wxWindow& window,
            std::vector<const wxWindow*>& windows) const = 0;

        /**
         * Finds a common ancestor window.
         * Returns nullptr if no common ancestor has been found.
         */
        virtual wxWindow* FindCommonAncestor(
            wxWindow& left,
            wxWindow& right) const = 0;

        /**
         * Finds a common ancestor window.
         * Returns nullptr if no common ancestor has been found.
         */
        virtual const wxWindow* FindCommonAncestor(
            const wxWindow& left,
            const wxWindow& right) const = 0;
    };

    //
    // Defines the Shared Ptr of Window Logic.
    //
    using IWindowLogicSharedPtr = std::shared_ptr<IWindowLogic>;

} // namespace WXWidgets

#endif // I_WINDOW_LOGIC_bc7bed15_c747_47ec_9b47_57652037186e

