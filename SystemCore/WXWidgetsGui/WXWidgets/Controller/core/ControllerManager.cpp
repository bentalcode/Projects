#include "ControllerManager.h"
#include "IGuiController.h"

using namespace wxwidgets;
using namespace wxwidgets::controller;

/**
 * Creates a controller manager.
 */
IControllerManagerSharedPtr ControllerManager::Make(IGuiControllerSharedPtr guiController)
{
    return std::make_shared<ControllerManager>(guiController);
}

/**
 * The ControllerManager constructor.
 */
ControllerManager::ControllerManager(IGuiControllerSharedPtr guiController) :
    m_guiController(guiController)
{
}

/**
 * The ControllerManager destructor.
 */
ControllerManager::~ControllerManager() 
{
}

/**
 * Gets app component.
 */
IGuiComponent& ControllerManager::GetAppComponent()
{
    return m_guiController->GetAppComponent();
}

/**
 * Gets a component by name.
 */
IGuiComponent& ControllerManager::GetComponent(const std::wstring& name)
{
    return m_guiController->GetComponent(name);
}

/**
 * Checks whether a component exists.
 */
bool ControllerManager::HasComponent(const std::wstring& name) const
{
    return m_guiController->HasComponent(name);
}

/**
 * Gets components.
 */
void ControllerManager::GetComponents(IGuiComponentList& components)
{
    return m_guiController->GetComponents(components);
}
