#ifndef I_TLOG_INFORMATION_H_0c0fd82a_7a3d_40b3_8443_e083daddbeeb
#define I_TLOG_INFORMATION_H_0c0fd82a_7a3d_40b3_8443_e083daddbeeb

#include "ITLogStatistics.h"

namespace logging {
   class ILogInformation;
}

namespace tlogging {

    /**
     * The ITLogInformation interface defines information of TLog.
     */
    class ITLogInformation {
    public:
        ITLogInformation() = default;
        virtual ~ITLogInformation() = default;

        /**
         * Gets information of log.
         */
        virtual const logging::ILogInformation& GetLogInformation() const = 0;

        /**
         * Gets statistics of tlog.
         */
        virtual const ITLogStatistics& GetTLogStatistics() const = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Information.
     */
    using ITLogInformationSharedPtr = std::shared_ptr<ITLogInformation>;

} // namespace tlogging

#endif // I_TLOG_INFORMATION_H_0c0fd82a_7a3d_40b3_8443_e083daddbeeb
