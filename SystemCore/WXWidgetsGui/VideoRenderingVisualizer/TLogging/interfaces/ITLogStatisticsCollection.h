#ifndef I_TLOG_STATISTICS_COLLECTION_H_0d73f0ab_641d_4b20_8df3_96257a6dc688
#define I_TLOG_STATISTICS_COLLECTION_H_0d73f0ab_641d_4b20_8df3_96257a6dc688

#include "ISizableCollection.h"
#include "ITLogStatistics.h"

namespace tlogging {

    /**
     * The ITLogStatisticsCollection interface defines a collection of TLog Statistics.
     */
    class ITLogStatisticsCollection : public base::ISizableCollection<ITLogStatisticsSharedPtr> {
    public:
        ITLogStatisticsCollection() = default;
        virtual ~ITLogStatisticsCollection() = default;

        /**
         * Adds TLog statistics.
         */
        virtual void AddTLogStatistics(const ITLogStatisticsSharedPtr tlogStatistics) = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Statistics Collection.
     */
    using ITLogStatisticsCollectionSharedPtr = std::shared_ptr<ITLogStatisticsCollection>;

} // namespace tlogging

#endif // I_TLOG_STATISTICS_COLLECTION_H_0d73f0ab_641d_4b20_8df3_96257a6dc688
