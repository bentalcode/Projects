#include "LabelConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates label configuration.
 */
ILabelConfigurationSharedPtr LabelConfiguration::Make(const std::wstring& text)
{
    return std::make_shared<LabelConfiguration>(text);
}

/**
 * The LabelConfiguration constructor.
 */
LabelConfiguration::LabelConfiguration(const std::wstring& text) : 
    m_text(text) 
{
}

/**
 * The LabelConfiguration destructor.
 */
LabelConfiguration::~LabelConfiguration() 
{
}

/**
 * Gets text of a label.
 */
const std::wstring& LabelConfiguration::GetText() const
{
    return m_text;
}
