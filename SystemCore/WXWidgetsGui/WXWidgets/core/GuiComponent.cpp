#include "GuiComponent.h"

using namespace WXWidgets;

namespace GuiComponentFunctors {

/**
 * The OnTriggerStartRefreshingFunctor class implements an On Trigger Start Refreshing functor.
 */
class OnTriggerStartRefreshingFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnTriggerStartRefreshingFunctor(GuiComponent& component) : 
        m_component(component) 
    {
    }

    /**
     * The functor logic.
     */
    void operator()() 
    { 
        m_component.OnTriggerStartRefreshing(); 
    }

private:
    GuiComponent& m_component;
};

/**
 * The OnTriggerEndRefreshingFunctor class implements an On Trigger End Refreshing functor.
 */
class OnTriggerEndRefreshingFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnTriggerEndRefreshingFunctor(GuiComponent& component) : 
        m_component(component) 
    {
    }

    /**
     * The functor logic.
     */
    void operator()() 
    { 
        m_component.OnTriggerEndRefreshing(); 
    }

private:
    GuiComponent& m_component;
};

} // namespace GuiComponentFunctors

/**
 * The GuiComponent constructor.
 */
GuiComponent::GuiComponent() : 
    AbstractGuiComponent()
{
}

/**
 * The GuiComponent destructor.
 */
GuiComponent::~GuiComponent() 
{
}

/**
 * Initializes a GUI component.
 */
void GuiComponent::Initialize(
    const std::wstring& name, 
    wxEvtHandler& eventHandler, 
    IGuiControllerSharedPtr guiController)
{
    //
    // Initialize a GUI component...
    //
    GuiComponent::IOnTriggerStartRefreshingFunctorSharedPtr onTriggerStartRefreshingFunctor =
        std::make_shared<GuiComponent::IOnTriggerStartRefreshingFunctor>(
            GuiComponentFunctors::OnTriggerStartRefreshingFunctor{ *this });

    GuiComponent::IOnTriggerEndRefreshingFunctorSharedPtr onTriggerEndRefreshingFunctor =
        std::make_shared<GuiComponent::IOnTriggerEndRefreshingFunctor>(
            GuiComponentFunctors::OnTriggerEndRefreshingFunctor{ *this });

    AbstractGuiComponent::Initialize(
        onTriggerStartRefreshingFunctor, 
        onTriggerEndRefreshingFunctor,
        name, 
        eventHandler, 
        guiController);
}
