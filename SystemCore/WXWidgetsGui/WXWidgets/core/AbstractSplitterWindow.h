#ifndef ABSTRACT_SPLITTER_WINDOW_6ae0fc8c_9959_447f_88cb_299353629b77
#define ABSTRACT_SPLITTER_WINDOW_6ae0fc8c_9959_447f_88cb_299353629b77

#include "ISplitterWindow.h"
#include "Window.h"
#include "Orient.h"
#include "ISplitterWindowConfiguration.h"
#include "WXObjectPtrs.h"
#include "wx/splitter.h"

namespace WXWidgets {

    class SplitterWindowUpdationEventInternal;

    /**
     * The AbstractSplitterWindow class implements an abstract splitter window,
     * which can be splitted in two directions: vertically or horizontally.
     */
    class AbstractSplitterWindow : public ISplitterWindow, public Window, public wxSplitterWindow {
    public:
        //
        // Defines a SharedPtr of On Updation Functor...
        //
        using IOnUpdationFunctor = std::function<void(const ISplitterWindowConfiguration&)>;
        using IOnUpdationFunctorSharedPtr = std::shared_ptr<IOnUpdationFunctor>;

        /**
         * The AbstractSplitterWindow constructor.
         */
        AbstractSplitterWindow(
            const wxString& name,
            wxWindow& parent,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            long style);

        /**
         * The SplitterWindow destructor.
         */
        virtual ~AbstractSplitterWindow();

        /**
         * Initializes a GUI component.
         */
        void Initialize(
            const IOnUpdationFunctorSharedPtr onUpdationFunctor,
            IGuiControllerSharedPtr guiController);

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Splits a window vertically.
         */
        virtual std::pair<wxWindow*, wxWindow*> SplitVertically(const ISplitterWindowConfigurationSharedPtr configuration) override;

        /**
         * Splits a window horizontally.
         */
        virtual std::pair<wxWindow*, wxWindow*> SplitHorizontally(const ISplitterWindowConfigurationSharedPtr configuration) override;

        /**
         * Connects windows (left/right or upper/bottom).
         */
        virtual void ConnectWindows(
            wxWindow& firstWindow,
            wxWindow& secondWindow) override;

        /**
         * Updates data container (first window show mode).
         */
        static void UpdateDataContainerFirstWindowShowMode(
            DataContainerManagement::IDataContainer& data,
            bool showMode);

        /**
         * Updates data container (second window show mode).
         */
        static void UpdateDataContainerSecondWindowShowMode(
            DataContainerManagement::IDataContainer& data,
            bool showMode);

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
         * Splits a window vertically or horizontally.
         */
        std::pair<wxWindow*, wxWindow*> Split(
            const ISplitterWindowConfigurationSharedPtr configuration,
            Orient orient);

        /**
         * Creates a panel of splitter window.
         */
        std::tuple<WXPanelPtr, WXBoxSizerPtr, wxBoxSizer*> CreatePanel(
            Orient orient,
            const IBorderWindowConfigurationSharedPtr borderWindowConfiguration,
            bool show);

        /**
         * Initializes a splitter window in a box sizer.
         */
        void InitializeInBoxSizer(Orient orient);

        /**
         * Fits components of splitter window.
         */
        void FitComponents();

        //
        // The first/second components...
        //
        WXPanelPtr m_firstPanel;
        WXBoxSizerPtr m_firstBoxSizer;
        wxBoxSizer* m_firstTopBoxSizer;

        WXPanelPtr m_secondPanel;
        WXBoxSizerPtr m_secondBoxSizer;
        wxBoxSizer* m_secondTopBoxSizer;

        wxWindow* m_firstWindow;
        wxWindow* m_secondWindow;

        //
        // The configuration...
        //
        ISplitterWindowConfigurationSharedPtr m_configuration;

        //
        // The configured functors...
        //
        IOnUpdationFunctorSharedPtr m_onUpdationFunctor;
    };

}  // namespace WXWidgets

#endif // ABSTRACT_SPLITTER_WINDOW_6ae0fc8c_9959_447f_88cb_299353629b77
