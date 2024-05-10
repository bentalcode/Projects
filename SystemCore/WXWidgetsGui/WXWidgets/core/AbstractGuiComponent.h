#ifndef ABSTRACT_GUI_COMPONENT_f3e77033_de7b_4e28_8b8a_5431f882a2e8
#define ABSTRACT_GUI_COMPONENT_f3e77033_de7b_4e28_8b8a_5431f882a2e8

#include "IGuiComponent.h"
#include "IGuiController.h"
#include "IWXEventHandler.h"
#include "IDataContainer.h"
#include "IDataContainerUpdateFunctors.h"
#include <functional>
#include "ILoggers.h"

class wxEvtHandler;
class wxCommandEvent;

namespace wxwidgets {

    /**
     * The AbstractGuiComponent class implements an abstract base class of a GUI component.
     */
    class AbstractGuiComponent : public IGuiComponent {
    public:
        //
        // Defines a SharedPtr of On Trigger Start Refreshing Functor...
        //
        using IOnTriggerStartRefreshingFunctor = std::function<void()>;
        using IOnTriggerStartRefreshingFunctorSharedPtr = std::shared_ptr<IOnTriggerStartRefreshingFunctor>;

        //
        // Defines a SharedPtr of On Trigger End Refreshing Functor...
        //
        using IOnTriggerEndRefreshingFunctor = std::function<void()>;
        using IOnTriggerEndRefreshingFunctorSharedPtr = std::shared_ptr<IOnTriggerEndRefreshingFunctor>;

        /**
         * The AbstractGuiComponent constructor.
         */
        AbstractGuiComponent();

        /**
         * The AbstractGuiComponent destructor.
         */
        virtual ~AbstractGuiComponent();

        /**
         * Initializes a GUI component.
         */
        void Initialize(
            const IOnTriggerStartRefreshingFunctorSharedPtr onTriggerStartRefreshingFunctor,
            const IOnTriggerEndRefreshingFunctorSharedPtr onTriggerEndRefreshingFunctor,
            const std::wstring& name,
            wxEvtHandler& eventHandler,
            IGuiControllerSharedPtr guiController);

        /**
         * Gets a name of component.
         */
        virtual const std::wstring GetName() const override;

        /**
         * Gets an event handler.
         */
        virtual IWXEventHandler& GetEventHandler() override;

        /**
         * Gets a gui controller.
         */
        virtual IGuiControllerSharedPtr GetGuiController() override;

        /**
         * Gets a data container.
         */
        virtual DataContainerManagement::IDataContainer& GetData() override;

        /**
         * Gets a data update functors.
         */
        virtual DataContainerManagement::IDataContainerUpdateFunctors& GetDataUpdateFunctors() override;

        /**
         * The On Trigger Start Refreshing callback - Default Implementation.
         */
        virtual void OnTriggerStartRefreshing();

        /**
         * The On Trigger End Refreshing callback - Default Implementation.
         */
        virtual void OnTriggerEndRefreshing();

        /**
         * Updates data container (show mode).
         */
        static void UpdateDataContainerShowMode(
            DataContainerManagement::IDataContainer& data,
            bool showMode);

    protected:
         /**
          * Updates data from data container - Default Implementation.
          * Returns true in case data has been updated.
          */
         virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer);

         /**
          * Updates component - Default Implementation.
          */
         virtual void Update();

         /**
          * Gets logger of GUI component.
          */
         logging::ILoggerSharedPtr GetLogger();

         /**
          * Gets logger of GUI component.
          */
         logging::ILoggerSharedPtr GetLogger() const;

         /**
          * Gets static logger of GUI component.
          */
         static logging::ILoggerSharedPtr GetSLogger();

    private:
        /**
         * Verifies that a component is initialized.
         */
        void VerifyInitialized() const;

        /**
         * Verifies that a component is not initialized.
         */
        void VerifyNotInitialized() const;

        /**
         * The internal On Trigger Start Refreshing callback.
         */
        void InternalOnTriggerStartRefreshing(wxCommandEvent& event);

        /**
         * The internal On Trigger End Refreshing callback.
         */
        void InternalOnTriggerEndRefreshing(wxCommandEvent& event);

        //
        // The functors...
        //
        IOnTriggerStartRefreshingFunctorSharedPtr m_onTriggerStartRefreshingFunctor;
        IOnTriggerEndRefreshingFunctorSharedPtr m_onTriggerEndRefreshingFunctor;

        //
        // The initialized flag...
        //
        bool m_initialized;

        //
        // The name of a component...
        //
        std::wstring m_name;

        //
        // The event handler of a component...
        //
        IWXEventHandlerSharedPtr m_eventHandler;

        //
        // The data of a component...
        //
        DataContainerManagement::IDataContainerSharedPtr m_data;

        //
        // The data update functors...
        //
        DataContainerManagement::IDataContainerUpdateFunctorsSharedPtr m_dataUpdateFunctors;

        //
        // The GUI controller, which is shared between all components...
        //
        IGuiControllerSharedPtr m_guiController;

        //
        // The Loggers of the GUI component...
        //
        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace wxwidgets

#endif // ABSTRACT_GUI_COMPONENT_f3e77033_de7b_4e28_8b8a_5431f882a2e8
