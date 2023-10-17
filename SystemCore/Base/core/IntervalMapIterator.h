#ifndef INTERVAL_MAP_ITERATOR_H_0fb64af4_e028_43e2_ad83_d36cafde355e
#define INTERVAL_MAP_ITERATOR_H_0fb64af4_e028_43e2_ad83_d36cafde355e

#include "IIterator.h"
#include "IIntervalMap.h"
#include "Pair.h"
#include "Interval.h"
#include "IntervalMap.h"
#include <assert.h>

namespace base
{
    /**
     * The IntervalMapIterator class implements an iterator of an interval map.
     */
    template <typename Key, typename Value>
    class IntervalMapIterator final : public IIterator<Pair<Interval<Key>, Value>>
    {
    public:
        using IntervalDataMap = std::map<Key, Value>;

        /**
         * The constructor.
         */
        explicit IntervalMapIterator(const IntervalDataMap& data);

        /**
         * The destructor.
         */
        virtual ~IntervalMapIterator();

        /**
         * The Copy/move constructors.
         */
        IntervalMapIterator(const IntervalMapIterator&) = delete;
        IntervalMapIterator(IntervalMapIterator&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        IntervalMapIterator& operator=(const IntervalMapIterator&) = delete;
        IntervalMapIterator& operator=(IntervalMapIterator&&) = delete;

        /**
         * Checks whether there is a Next element.
         */
        virtual bool HasNext() const override;

        /**
         * Gets the Next element.
         */
        virtual Pair<Interval<Key>, Value> Next() override;

        /**
         * Resets the iterator.
         */
        virtual void Reset() override;

    private:
        const IntervalDataMap& m_data;

        size_t m_index;
        typename IntervalDataMap::const_iterator m_iterator;
    };

    /**
     * The IntervalMapIterator constructor.
     */
    template <typename Key, typename Value>
    IntervalMapIterator<Key, Value>::IntervalMapIterator(const IntervalDataMap& data) :
        m_data(data),
        m_iterator(data.end())
    {
        Reset();
    }

    /**
     * The IntervalMapIterator destructor.
     */
    template <typename Key, typename Value>
    IntervalMapIterator<Key, Value>::~IntervalMapIterator()
    {
    }

    /**
     * Checks whether there is a Next element.
     */
    template <typename Key, typename Value>
    bool IntervalMapIterator<Key, Value>::HasNext() const
    {
        return m_index < m_data.size() - 1;
    }

    /**
     * Gets the Next element.
     */
    template <typename Key, typename Value>
    Pair<Interval<Key>, Value> IntervalMapIterator<Key, Value>::Next()
    {
        assert(HasNext());

        Key currIntervalStart = m_iterator->first;
        Value currValue = m_iterator->second;

        ++m_iterator;
        ++m_index;

        Key currIntervalEnd = m_iterator != m_data.end() ?
            m_iterator->first :
            std::numeric_limits<Key>::max();

        Interval<Key> currInterval(currIntervalStart, currIntervalEnd);
        Pair<Interval<Key>, Value> currElement(currInterval, currValue);

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    template <typename Key, typename Value>
    void IntervalMapIterator<Key, Value>::Reset()
    {
        m_iterator = m_data.begin();
        m_index = 0;
    }
}

#endif // INTERVAL_MAP_ITERATOR_H_0fb64af4_e028_43e2_ad83_d36cafde355e
