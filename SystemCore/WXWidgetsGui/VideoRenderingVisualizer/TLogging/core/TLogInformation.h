#ifndef TLOG_INFORMATION_H_ed559f9e_4c2a_4fce_8891_abd7f5c28719
#define TLOG_INFORMATION_H_ed559f9e_4c2a_4fce_8891_abd7f5c28719

#include "ITLogInformation.h"
#include "ILogInformation.h"

namespace tlogging {

    /**
     * The TLogInformation class implements information of TLog.
     */
    class TLogInformation final : public ITLogInformation {
    public:
        /**
         * Creates TLog Information.
         */
        static ITLogInformationSharedPtr Make(
            const logging::ILogInformationSharedPtr logInformation,
            const ITLogStatisticsSharedPtr tlogStatistics);

        /**
         * The TLogInformation constructor.
         */
        TLogInformation(
            const logging::ILogInformationSharedPtr logInformation,
            const ITLogStatisticsSharedPtr tlogStatistics);

        /**
         * The TLogInformation destructor.
         */
        virtual ~TLogInformation();

        /**
         * Gets information of log.
         */
        virtual const logging::ILogInformation& GetLogInformation() const override;

        /**
         * Gets statistics of tlog.
         */
        virtual const ITLogStatistics& GetTLogStatistics() const override;

    private:
        logging::ILogInformationSharedPtr m_logInformation;
        ITLogStatisticsSharedPtr m_tLogStatistics;
    };

} // namespace tlogging

#endif // TLOG_INFORMATION_H_ed559f9e_4c2a_4fce_8891_abd7f5c28719

