#include "TLogStatisticsCollection.h"
#include "ListIterator.h"
#include "SmartPointers.h"

using namespace tlogging;

/**
 * Creates TLog Statistics Collection.
 */
ITLogStatisticsCollectionSharedPtr TLogStatisticsCollection::Make()
{
    return std::make_shared<TLogStatisticsCollection>();
}

/**
 * The TLogStatisticsCollection constructor.
 */
TLogStatisticsCollection::TLogStatisticsCollection()
{
}

/**
 * The TLogStatisticsCollection destructor.
 */
TLogStatisticsCollection::~TLogStatisticsCollection() 
{
}

/**
 * Adds TLog statistics.
 */
void TLogStatisticsCollection::AddTLogStatistics(const ITLogStatisticsSharedPtr tlogStatistics) 
{
    base::SmartPointers::Validate<ITLogStatistics>(tlogStatistics);
    m_tlogsStatistics.push_back(tlogStatistics);
}

/**
 * Gets size of a collection.
 */
size_t TLogStatisticsCollection::Size() const
{
    return m_tlogsStatistics.size();
}

/**
 * Checks whether a collection is empty.
 */
bool TLogStatisticsCollection::Empty() const
{
    return m_tlogsStatistics.empty();
}

/**
 * Gets an iterator.
 */
base::IIteratorSharedPtr<ITLogStatisticsSharedPtr> TLogStatisticsCollection::GetIterator() const
{
    return base::ListIterator<ITLogStatisticsSharedPtr>::Make(m_tlogsStatistics);
}
