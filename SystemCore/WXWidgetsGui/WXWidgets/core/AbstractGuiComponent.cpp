#include "AbstractGuiComponent.h"
#include "DataContainer.h"
#include "DataContainerUpdateFunctors.h"
#include "DataItem.h"
#include "IDataItems.h"
#include "WXDataItems.h"
#include "WXEventHandler.h"
#include "TriggerStartRefreshingEventInternal.h"
#include "TriggerEndRefreshingEventInternal.h"
#include "SmartPointers.h"
#include "Loggers.h"
#include "WXWidgetsException.h"

using namespace WXWidgets;

namespace AbstractGuiComponentFunctors {

/**
 * The UpdateDataContainerShowModeFunctor class implements an update functor of show mode.
 */
class UpdateDataContainerShowModeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerShowModeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(bool showMode) 
    { 
        AbstractGuiComponent::UpdateDataContainerShowMode(m_dataContainer, showMode); 
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

} // namespace AbstractGuiComponentFunctors

/**
 * The AbstractGuiComponent constructor.
 */
AbstractGuiComponent::AbstractGuiComponent() : 
    m_initialized(false), 
    m_dataUpdateFunctors(DataContainerManagement::DataContainerUpdateFunctors::Make()), 
    m_loggers(logging::Loggers::Make(typeid(AbstractGuiComponent)))
{
}

/**
 * The AbstractGuiComponent destructor.
 */
AbstractGuiComponent::~AbstractGuiComponent() 
{
    //
    // Remove current component from GUI controller...
    //
    if (m_guiController->HasComponent(m_name)) {
        m_guiController->RemoveComponent(m_name);
    }

    std::wstringstream informationalStream;
    informationalStream << L"The WXWidget GUI Component: [" << m_name << L"] has been uninitialized sucessfully.";
    std::wstring informationalMessage = informationalStream.str();

    LOG_INFO(GetLogger(), informationalMessage);
}

/**
 * Initializes a GUI component.
 */
void AbstractGuiComponent::Initialize(
    const IOnTriggerStartRefreshingFunctorSharedPtr onTriggerStartRefreshingFunctor,
    const IOnTriggerEndRefreshingFunctorSharedPtr onTriggerEndRefreshingFunctor,
    const std::wstring& name, 
    wxEvtHandler& eventHandler, 
    IGuiControllerSharedPtr guiController)
{
    base::SmartPointers::Validate<IGuiController>(guiController);
    VerifyNotInitialized();

    //
    // Initialize functors...
    //
    m_onTriggerStartRefreshingFunctor = onTriggerStartRefreshingFunctor;
    m_onTriggerEndRefreshingFunctor = onTriggerEndRefreshingFunctor;

    //
    // Initialize data...
    //
    m_name = name;
    m_eventHandler = WXEventHandler::Create(eventHandler);
    m_data = DataContainerManagement::DataContainer::Make(name);
    m_guiController = guiController;

    //
    // Bind callbacks...
    //
    eventHandler.Bind(
        TriggerStartRefreshingEventInternal::TYPE, 
        &AbstractGuiComponent::InternalOnTriggerStartRefreshing,
        this);

    eventHandler.Bind(
        TriggerEndRefreshingEventInternal::TYPE, 
        &AbstractGuiComponent::InternalOnTriggerEndRefreshing, 
        this);

    //
    // Mark component as initialized...
    //
    m_initialized = true;

    //
    // Register data items...
    //
    std::wstring dataItemComponentShowMode = WXDataItems::Read().GetComponentShowMode();
    m_data->GetCatalog().RegisterDataItem(dataItemComponentShowMode);

    //
    // Register data container update functors...
    //
    DataContainerManagement::IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr updateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IBooleanFunctor>(
            AbstractGuiComponentFunctors::UpdateDataContainerShowModeFunctor{ *m_data });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemComponentShowMode, 
        updateFunctor);

    //
    // Add current component to GUI controller...
    //
    m_guiController->AddComponent(*this);

    std::wstringstream informationalStream;
    informationalStream << L"The WXWidget GUI Component: [" << m_name << L"] has been initialized sucessfully.";
    std::wstring informationalMessage = informationalStream.str();

    LOG_INFO(GetLogger(), informationalMessage);
}

/**
 * Gets a name of component.
 */
const std::wstring AbstractGuiComponent::GetName() const
{
    VerifyInitialized();
    return m_name;
}

/**
 * Gets an event handler.
 */
IWXEventHandler& AbstractGuiComponent::GetEventHandler()
{  
    VerifyInitialized();
    return *m_eventHandler;
}

/**
 * Gets a GUI controller.
 */
IGuiControllerSharedPtr AbstractGuiComponent::GetGuiController()
{
    VerifyInitialized();
    return m_guiController;
}

/**
 * Gets a data container.
 */
DataContainerManagement::IDataContainer& AbstractGuiComponent::GetData()
{
    VerifyInitialized();
    return *m_data;
}

/**
 * Gets a data container update functors.
 */
DataContainerManagement::IDataContainerUpdateFunctors& AbstractGuiComponent::GetDataUpdateFunctors()
{
    VerifyInitialized();
    return *m_dataUpdateFunctors;
}

/**
 * Updates data container (show mode).
 */
void AbstractGuiComponent::UpdateDataContainerShowMode(
    DataContainerManagement::IDataContainer& data,
    bool showMode)
{
    std::wstring dataItemName = WXDataItems::Read().GetComponentShowMode();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            showMode);

    data.SetDataItem(dataItem);
}

/**
 * The On Trigger Start Refreshing callback - Default Implementation.
 */
void AbstractGuiComponent::OnTriggerStartRefreshing() 
{
}

/**
 * The On Trigger End Refreshing callback - Default Implementation.
 */
void AbstractGuiComponent::OnTriggerEndRefreshing() {
}

/**
 * Updates data from data container - Default Implementation.
 * Returns true in case data has been updated.
 */
bool AbstractGuiComponent::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    return false;
}

/**
 * Updates component - Default Implementation.
 */
void AbstractGuiComponent::Update() 
{
}

/**
 * Gets logger of GUI component.
 */
logging::ILoggerSharedPtr AbstractGuiComponent::GetLogger()
{
    return m_loggers->GetLogger();
}

/**
 * Gets logger of GUI component.
 */
logging::ILoggerSharedPtr AbstractGuiComponent::GetLogger() const
{
    return m_loggers->GetLogger();
}

/**
 * Gets static logger of GUI component.
 */
logging::ILoggerSharedPtr AbstractGuiComponent::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(WXWidgets::AbstractGuiComponent));
    return loggers->GetLogger();
}

/**
 * Verifies that a component is initialized.
 */
void AbstractGuiComponent::VerifyInitialized() const
{
    if (!m_initialized) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
        
        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The GUI component has not been initialized"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }
}

/**
 * Verifies that a component is not initialized.
 */
void AbstractGuiComponent::VerifyNotInitialized() const
{
    if (m_initialized) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The GUI component has been initialized before" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }
}

/**
 * The internal On Trigger Start Refreshing callback.
 */
void AbstractGuiComponent::InternalOnTriggerStartRefreshing(wxCommandEvent& event)
{
    //
    // Perform callback logic...
    //
    if (m_onTriggerStartRefreshingFunctor) {
        m_onTriggerStartRefreshingFunctor->operator()();
    }
}

/**
 * The internal On Trigger End Refreshing callback.
 */
void AbstractGuiComponent::InternalOnTriggerEndRefreshing(wxCommandEvent& event)
{
    //
    // Perform callback logic...
    //
    if (m_onTriggerEndRefreshingFunctor) {
        m_onTriggerEndRefreshingFunctor->operator()();
    }
}
