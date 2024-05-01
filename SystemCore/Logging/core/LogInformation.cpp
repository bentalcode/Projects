#include "LogInformation.h"
#include "SmartPointers.h"
#include <assert.h>

using namespace logging;

/**
 * Creates Log Information.
 */
ILogInformationSharedPtr LogInformation::Make(const tabular_data::ITabularFileInformationSharedPtr tabularFileInformation)
{
    return std::make_shared<LogInformation>(tabularFileInformation);
}

/**
 * The Log Information constructor.
 */
LogInformation::LogInformation(const tabular_data::ITabularFileInformationSharedPtr tabularFileInformation)
{
    base::SmartPointers::Validate<tabular_data::ITabularFileInformation>(tabularFileInformation);
    m_tabularFileInformation = tabularFileInformation;
}

/**
 * The LogInformation destructor.
 */
LogInformation::~LogInformation() 
{
}

/**
 * Gets information of a tabular file.
 */
const tabular_data::ITabularFileInformation& LogInformation::GetTabularFileInformation() const
{
    return *m_tabularFileInformation;
}
