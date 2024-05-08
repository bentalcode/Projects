#include "DialogConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates dialog configuration.
 */
IDialogConfigurationSharedPtr DialogConfiguration::Make(const std::wstring& title)
{
    return std::make_shared<DialogConfiguration>(title);
}

/**
 * The DialogConfiguration constructor.
 */
DialogConfiguration::DialogConfiguration(const std::wstring& title) : 
    m_title(title)
{
}

/**
 * The DialogConfiguration destructor.
 */
DialogConfiguration::~DialogConfiguration() 
{
}

/**
 * Gets title of a dialog.
 */
const std::wstring& DialogConfiguration::GetTitle() const
{
    return m_title;
}
