#include "GuiComponentData.h"

using namespace WXWidgets;

/**
 * Creates a GUI component data.
 */
IGuiComponentDataSharedPtr GuiComponentData::Create(bool showMode)
{
    return std::make_shared<GuiComponentData>(showMode);
}

/**
 * The GuiComponentData constructor.
 */
GuiComponentData::GuiComponentData(bool showMode) : 
    m_showMode(showMode) 
{
}

/**
 * The GuiComponentData destructor.
 */
GuiComponentData::~GuiComponentData() 
{
}

/**
 * Gets a show mode.
 */
bool GuiComponentData::GetShowMode() const
{
    return m_showMode;
}
