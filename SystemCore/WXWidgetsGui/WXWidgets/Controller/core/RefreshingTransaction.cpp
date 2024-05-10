#include "RefreshingTransaction.h"
#include "IControllerManager.h"
#include "IGuiComponent.h"
#include "IDataContainer.h"
#include "IWXEventHandler.h"
#include "IDataContainerUpdateFunctors.h"
#include "TriggerStartRefreshingEvent.h"

using namespace wxwidgets::controller;

/**
 * Creates a refreshing transaction.
 */
IRefreshingTransactionSharedPtr RefreshingTransaction::Make(IControllerManager& controllerManager)
{
    return std::make_shared<RefreshingTransaction>(controllerManager);
}

/**
 * The RefreshingTransaction constructor.
 */
RefreshingTransaction::RefreshingTransaction(IControllerManager& controllerManager) : 
    AbstractTransaction(controllerManager)
{
}

/**
 * The RefreshingTransaction destructor.
 */
RefreshingTransaction::~RefreshingTransaction() 
{
}

/**
 * Updates data with a boolean.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName, 
    bool value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr updateFunctor = 
        updateFunctors.GetBooleanUpdateFunctor(functorName);
    
    updateFunctor->operator()(value);
}

/**
 * Updates data with an integer.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName, 
    int value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr updateFunctor =
        updateFunctors.GetIntegerUpdateFunctor(functorName);
    
    updateFunctor->operator()(value);
}

/**
 * Updates data with a long.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName, 
    long value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::ILongFunctorSharedPtr updateFunctor =
        updateFunctors.GetLongUpdateFunctor(functorName);

    updateFunctor->operator()(value);
}

/**
 * Updates data with a double.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName, 
    double value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr updateFunctor =
        updateFunctors.GetDoubleUpdateFunctor(functorName);

    updateFunctor->operator()(value);
}

/**
 * Updates data with a double.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName,
    const std::wstring& value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctorSharedPtr updateFunctor =
        updateFunctors.GetStringUpdateFunctor(functorName);

    updateFunctor->operator()(value);
}

/**
 * Updates data with a date-time.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName,
    const base::DateTime& value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr updateFunctor =
        updateFunctors.GetDateTimeUpdateFunctor(functorName);

    updateFunctor->operator()(value);
}

/**
 * Updates data with a duration.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName,
    const base::Duration& value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::IDurationFunctorSharedPtr updateFunctor =
        updateFunctors.GetDurationUpdateFunctor(functorName);

    updateFunctor->operator()(value);
}

/**
 * Updates data with a string array.
 */
void RefreshingTransaction::UpdateData(
    const std::wstring& componentName, 
    const std::wstring& functorName,
    const std::vector<std::wstring>& value)
{
    DataContainerManagement::IDataContainerUpdateFunctors& updateFunctors = GetUpdateFunctors(componentName);
    DataContainerManagement::IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr updateFunctor =
        updateFunctors.GetStringArrayUpdateFunctor(functorName);

    updateFunctor->operator()(value);
}

/**
 * Gets an update functors.
 */
DataContainerManagement::IDataContainerUpdateFunctors& RefreshingTransaction::GetUpdateFunctors(const std::wstring& componentName)
{
    IControllerManager& controllerManager = GetControllerManager();
    IGuiComponent& component = controllerManager.GetComponent(componentName);

    return component.GetDataUpdateFunctors();
}

/**
 * Commits a transaction.
 */
void RefreshingTransaction::Commit()
{
    //
    // Send a trigger start refreshing event to the app...
    //
    IWXEventSharedPtr triggerStartRefreshingEvent = wxwidgets::TriggerStartRefreshingEvent::Create();

    IControllerManager& controllerManager = GetControllerManager();
    IGuiComponent& appComponent = controllerManager.GetAppComponent();
    appComponent.GetEventHandler().SendEvent(triggerStartRefreshingEvent);
}
