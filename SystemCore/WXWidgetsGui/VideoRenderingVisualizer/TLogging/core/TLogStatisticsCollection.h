#ifndef TLOG_STATISTICS_COLLECTION_H_fbc355b2_2dde_4262_9142_c671fdc55e12
#define TLOG_STATISTICS_COLLECTION_H_fbc355b2_2dde_4262_9142_c671fdc55e12

#include "ITLogStatisticsCollection.h"
#include <list>

namespace tlogging {

    /**
     * The TLogStatisticsCollection class implements a collection of TLog Statistics.
     */
    class TLogStatisticsCollection final : public ITLogStatisticsCollection {
    public:
        /**
         * Creates TLog Statistics Collection.
         */
        static ITLogStatisticsCollectionSharedPtr Make();

        /**
         * The TLogStatisticsCollection constructor.
         */
        TLogStatisticsCollection();

        /**
         * The TLogStatisticsCollection destructor.
         */
        virtual ~TLogStatisticsCollection();

        /**
         * Adds TLog statistics.
         */
        virtual void AddTLogStatistics(const ITLogStatisticsSharedPtr tlogStatistics) override;

        /**
         * Gets size of a collection.
         */
        virtual size_t Size() const override;

        /**
         * Checks whether a collection is empty.
         */
        virtual bool Empty() const override;

        /**
         * Gets an iterator.
         */
        virtual base::IIteratorSharedPtr<ITLogStatisticsSharedPtr> GetIterator() const override;

    private:
        std::list<ITLogStatisticsSharedPtr> m_tlogsStatistics;
    };

} // namespace tlogging

#endif // TLOG_STATISTICS_COLLECTION_H_fbc355b2_2dde_4262_9142_c671fdc55e12
