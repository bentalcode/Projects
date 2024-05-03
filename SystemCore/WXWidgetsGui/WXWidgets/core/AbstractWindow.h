#ifndef ABSTRACT_WINDOW_dfff1e58_5ce8_4e4d_99a8_a89a66b83b3b
#define ABSTRACT_WINDOW_dfff1e58_5ce8_4e4d_99a8_a89a66b83b3b

#include "IWindow.h"
#include "GuiComponent.h"
#include "IGuiTransaction.h"
#include <functional>

namespace WXWidgets {

    class PreRefreshEventInternal;
    class RefreshEventInternal;
    class PostRefreshEventInternal;
    class WindowUpdationEventInternal;

    /**
     * The AbstractWindow class implements an abstract base class of a window.
     */
    class AbstractWindow : public IWindow, public GuiComponent {
    public:
        //
        // Defines a SharedPtr of On Pre Refresh Functor...
        //
        using IOnPreRefreshFunctor = std::function<void(IGuiTransactionSharedPtr)>;
        using IOnPreRefreshFunctorSharedPtr = std::shared_ptr<IOnPreRefreshFunctor>;

        //
        // Defines a SharedPtr of On Refresh Functor...
        //
        using IOnRefreshFunctor = std::function<void(IGuiTransactionSharedPtr)>;
        using IOnRefreshFunctorSharedPtr = std::shared_ptr<IOnRefreshFunctor>;

        //
        // Defines a SharedPtr of On Post Refresh Functor...
        //
        using IOnPostRefreshFunctor = std::function<void(IGuiTransactionSharedPtr)>;
        using IOnPostRefreshFunctorSharedPtr = std::shared_ptr<IOnPostRefreshFunctor>;

        //
        // Defines a SharedPtr of On Updation Functor...
        //
        using IOnUpdationFunctor = std::function<void()>;
        using IOnUpdationFunctorSharedPtr = std::shared_ptr<IOnUpdationFunctor>;

        /**
         * The AbstractWindow constructor.
         */
        AbstractWindow();

        /**
         * The AbstractWindow destructor.
         */
        virtual ~AbstractWindow();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const IOnPreRefreshFunctorSharedPtr onPreRefreshFunctor,
            const IOnRefreshFunctorSharedPtr onRefreshFunctor,
            const IOnPostRefreshFunctorSharedPtr onPostRefreshFunctor,
            const IOnUpdationFunctorSharedPtr onUpdationFunctor,
            wxWindow& window,
            IGuiControllerSharedPtr guiController,
            bool showMode);

        /**
         * Sets size.
         */
        virtual void SetSize(const wxSize& size) override;

        /**
         * Maximizes window.
         */
        virtual void Maximize() override;

        /**
         * Centralizes window.
         */
        virtual void Centralize() override;

        /**
         * Maximizes and centeralize window.
         */
        virtual void MaximizeAndCenteralize() override;

        /**
         * Gets a window.
         */
        virtual wxWindow& AsWindow() override;

        /**
         * Gets a GUI component.
         */
        virtual IGuiComponent& GetComponent() override;

        /**
         * Show or hide a window.
         */
        virtual void ShowOrHide(bool showMode) override;

        /**
         * The On Pre Refresh callback - Default Implementation.
         */
        virtual void OnPreRefresh(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The On Refresh callback - Default Implementation.
         */
        virtual void OnRefresh(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The On Post Refresh callback - Default Implementation.
         */
        virtual void OnPostRefresh(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The On Updation callback - Default Implementation.
         */
        virtual void OnUpdation();

        /**
         * Gets parent windows.
         */
        virtual void GetParentWindows(std::vector<wxWindow*>& windows) override;
        virtual void GetParentWindows(std::vector<const wxWindow*>& windows) const override;

        /**
         * Finds a common ancestor window.
         */
        virtual wxWindow* FindCommonAncestor(wxWindow& left, wxWindow& right) override;
        virtual const wxWindow* FindCommonAncestor(const wxWindow& left, const wxWindow& right) const override;

        /**
         * Checks whether a window has a scrollbar.
         */
        virtual bool ScrollbarExists(Orient orient) const override;

        /**
         * Sets scrollbar of a window to min position.
         */
        virtual void SetScrollbarToMinPosition(Orient orient) override;

        /**
         * Sets scrollbar of a window to max position.
         */
        virtual void SetScrollbarToMaxPosition(Orient orient) override;

    protected:
        /**
         * Updates data from data container.
         * Returns true in case data has been updated.
         */
        virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

        /**
         * Updates component.
         */
        virtual void Update() override;


    private:
        /**
         * Resets component.
         */
        void Reset();

        /**
         * The internal On Pre Refresh callback.
         */
        void InternalOnPreRefresh(PreRefreshEventInternal& event);

        /**
         * The internal On Refresh callback.
         */
        void InternalOnRefresh(RefreshEventInternal& event);

        /**
         * The internal On Post Refresh callback.
         */
        void InternalOnPostRefresh(PostRefreshEventInternal& event);

        /**
         * The internal On Updation callback.
         */
        void InternalOnUpdation(const WindowUpdationEventInternal& event);

        //
        // The functors...
        //
        IOnPreRefreshFunctorSharedPtr m_onPreRefreshFunctor;
        IOnPreRefreshFunctorSharedPtr m_onRefreshFunctor;
        IOnPostRefreshFunctorSharedPtr m_onPostRefreshFunctor;
        IOnUpdationFunctorSharedPtr m_onUpdationFunctor;

        wxWindow* m_window;
        bool m_showMode;
    };

}  // namespace WXWidgets

#endif // ABSTRACT_WINDOW_dfff1e58_5ce8_4e4d_99a8_a89a66b83b3b
