#include "GuiTransaction.h"
#include "IGuiComponent.h"
#include "Loggers.h"
#include "WXWidgetsException.h"
#include <assert.h>

using namespace WXWidgets;

/**
 * Creates a GUI Transaction.
 */
IGuiTransactionSharedPtr GuiTransaction::Make()
{
    return std::make_shared<GuiTransaction>();
}

/**
 * The GuiTransaction constructor.
 */
GuiTransaction::GuiTransaction() : 
    m_counter(0), 
    m_loggers(logging::Loggers::Make(typeid(WXWidgets::GuiTransaction)))
{
}

/**
 * The GuiTransaction destructor.
 */
GuiTransaction::~GuiTransaction() 
{
}

/**
 * Registers a component.
 */
void GuiTransaction::RegisterComponent(IGuiComponent& component)
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);

    std::wstring name = component.GetName();

    if (HasComponent(name)) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"GUI component with name: " << name << L" is already registered in current transaction"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    std::pair<IGuiComponent*, bool> componentState = std::make_pair(&component, false);
    m_componentState.insert(std::make_pair(name, componentState));
}

/**
 * Unregisters a component.
 */
void GuiTransaction::UnregisterComponent(const std::wstring& name)
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);

    if (!HasComponent(name)) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Gui component with name: " << name << L" is not registered with current transaction"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    std::pair<IGuiComponent*, bool>& componentState = m_componentState[name];
    bool state = componentState.second;
    
    if (state) {
        --m_counter;
    }
    
    m_componentState.erase(name);
}

/**
 * Checks whether a component is registered.
 */
bool GuiTransaction::ComponentRegistered(const std::wstring& name) const 
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);

    return HasComponent(name);
}

/**
 * Sets a component transaction as completed.
 */
void GuiTransaction::SetComponentTransactionCompleted(const std::wstring& name)
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);

    std::pair<IGuiComponent*, bool>& componentState = m_componentState[name];
    componentState.second = true;

    ++m_counter;

    if (TransactionCompleted() && m_onCompletionEventHandler != nullptr) {
        m_onCompletionEventHandler->SendEvent(m_onCompletionEvent);
    }
}

/**
 * Sets an on completion event.
 */
void GuiTransaction::SetOnCompletionEvent(
    IWXEventHandler& eventHandler,
    IWXEventSharedPtr event)
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);

    m_onCompletionEventHandler = &eventHandler;
    m_onCompletionEvent = event;
}

/**
 * Checks whether a component exists.
 */
bool GuiTransaction::HasComponent(const std::wstring& name) const 
{
    GuiComponentState::const_iterator componentIterator = m_componentState.find(name);
    return componentIterator != m_componentState.end();
}

/**
 * Finds a component by name.
 */
IGuiComponent* GuiTransaction::FindComponent(const std::wstring& name)
{
    GuiComponentState::iterator componentIterator = m_componentState.find(name);
    return componentIterator != m_componentState.end() ? componentIterator->second.first : nullptr;
}

/**
 * Checks whether a transaction is completed.
 */
bool GuiTransaction::TransactionCompleted() const 
{
    assert(m_counter <= m_componentState.size());
    return m_counter == m_componentState.size();
}
