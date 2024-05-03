#include "GuiController.h"
#include "IGuiComponent.h"
#include "Loggers.h"
#include "WXWidgetsException.h"
#include <assert.h>

using namespace WXWidgets;

/**
 * Creates a GUI controller.
 */
IGuiControllerSharedPtr GuiController::Create()
{
    return std::make_shared<GuiController>();
}

/**
 * The GuiController constructor.
 */
GuiController::GuiController()
{
}

/**
 * The GuiController destructor.
 */
GuiController::~GuiController() 
{
}

/**
 * Sets app component.
 */
void GuiController::SetAppComponent(IGuiComponent* component)
{
    m_app = component;
}

/**
 * Gets app component.
 */
IGuiComponent& GuiController::GetAppComponent()
{
    if (m_app == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream messageStream;
        messageStream 
            << L"The app has not been set in the Gui Controller" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    return *m_app;
}

/**
 * Adds a new component.
 */
void GuiController::AddComponent(IGuiComponent& component)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    std::wstring name = component.GetName();

    if (name.empty()) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Gui Controller has detected a GUI component being registred with an empty name"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    if (FindComponent(name) != nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Gui Controller already contains a GUI component with name: " << name
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);
        
        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    m_componentMap.insert(std::make_pair(name, &component));
    m_componentList.push_back(&component);
}

/**
 * Removes an existing component by name.
 */
void GuiController::RemoveComponent(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IGuiComponent* component = FindComponent(name);

    if (component == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Gui Controller does not contain a GUI component with name: " << name
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    m_componentList.remove(component);
    m_componentMap.erase(name);
}

/**
 * Sets a component by name.
 */
void GuiController::SetComponent(IGuiComponent& component)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    std::wstring name = component.GetName();
    m_componentMap[name] = &component;
}

/**
 * Gets a component by name.
 */
IGuiComponent& GuiController::GetComponent(const std::wstring& name) 
{
    IGuiComponent* component = nullptr;

    {
        std::lock_guard<std::mutex> lock(m_mutex);

        component = FindComponent(name);
    }

    if (component == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Gui Controller failed finding a GUI component with name: " << name 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    return *component;
}

/**
 * Checks whether a component exists.
 */
bool GuiController::HasComponent(const std::wstring& name) const
{ 
    bool status = false;

    {
        std::lock_guard<std::mutex> lock(m_mutex);

        status = m_componentMap.find(name) != m_componentMap.end();
    }

    return status;
}

/**
 * Gets components.
 */
void GuiController::GetComponents(IGuiComponentList& components)
{
    assert(components.empty());

    std::lock_guard<std::mutex> lock(m_mutex);

    components.insert(components.end(), m_componentList.begin(), m_componentList.end());
}

/**
 * Gets a string of components list.
 */
std::wstring GuiController::GetComponentListString(IGuiComponentList& components) 
{
    std::wstringstream componentListStream;

    bool firstEntry = false;

    size_t size = components.size();
    size_t index = 0;

    for (IGuiComponent* component : components) {
        std::wstring name = component->GetName();

        if (index > 0) {
            componentListStream << L", ";
        }

        componentListStream << name;

        ++index;
    }

    std::wstring componentListString = componentListStream.str();

    return componentListString;
}

/**
 * Finds a component by name.
 */
IGuiComponent* GuiController::FindComponent(const std::wstring& name)
{
    GuiComponentMap::iterator componentIterator = m_componentMap.find(name);
    return componentIterator != m_componentMap.end() ? componentIterator->second : nullptr;
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr GuiController::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(WXWidgets::GuiController));
    return loggers->GetLogger();
}
