#include "TLogInformation.h"
#include "SmartPointers.h"

using namespace tlogging;

/**
 * Creates information of Tlog.
 */
ITLogInformationSharedPtr TLogInformation::Make(
    const logging::ILogInformationSharedPtr logInformation,
    const ITLogStatisticsSharedPtr tlogStatistics)
{
    return std::make_shared<TLogInformation>(
        logInformation, 
        tlogStatistics);
}

/**
 * The TLogInformation constructor.
 */
TLogInformation::TLogInformation(
    const logging::ILogInformationSharedPtr logInformation,
    const ITLogStatisticsSharedPtr tlogStatistics)
{
    base::SmartPointers::Validate<logging::ILogInformation>(logInformation);
    base::SmartPointers::Validate<ITLogStatistics>(tlogStatistics);

    m_logInformation = logInformation;
    m_tLogStatistics = tlogStatistics;
}

/**
 * The TLogInformation destructor.
 */
TLogInformation::~TLogInformation() 
{
}

/**
 * Gets information of log.
 */
const logging::ILogInformation& TLogInformation::GetLogInformation() const
{
    return *m_logInformation;
}

/**
 * Gets statistics of tlog.
 */
const ITLogStatistics& TLogInformation::GetTLogStatistics() const 
{
    return *m_tLogStatistics;
}
