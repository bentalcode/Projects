#include "GuiComponentInformation.h"
#include "SmartPointers.h"

using namespace WXWidgets;

/**
 * Creates a GUI component.
 */
IGuiComponentInformationSharedPtr GuiComponentInformation::Create(
    IGuiComponentSharedPtr component,
    IGuiComponentDataSharedPtr data)
{
    return std::make_shared<GuiComponentInformation>(component, data);
}

/**
 * The GuiComponentInformation constructor.
 */
GuiComponentInformation::GuiComponentInformation(
    IGuiComponentSharedPtr component, 
    IGuiComponentDataSharedPtr data) 
{
    base::SmartPointers::Validate<IGuiComponent>(component);
    base::SmartPointers::Validate<IGuiComponentData>(data);

    m_component = component;
    m_data = data;
}

/**
 * The GuiComponentInformation destructor.
 */
GuiComponentInformation::~GuiComponentInformation() 
{
}

/**
 * Gets a GUI component.
 */
IGuiComponent& GuiComponentInformation::GetComponent()
{
    return *m_component;
}

/**
 * Gets a GUI data.
 */
IGuiComponentData& GuiComponentInformation::GetData()
{
    return *m_data;
}
