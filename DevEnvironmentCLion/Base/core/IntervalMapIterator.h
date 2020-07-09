#ifndef INTERVAL_MAP_ITERATOR_H_0fb64af4_e028_43e2_ad83_d36cafde355e
#define INTERVAL_MAP_ITERATOR_H_0fb64af4_e028_43e2_ad83_d36cafde355e

#include "IIterator.h"
#include "IIntervalMap.h"
#include "Pair.h"
#include "Interval.h"
#include "IntervalMap.h"

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
         * The copy/move constructors.
         */
        IntervalMapIterator(const IntervalMapIterator&) = delete;
        IntervalMapIterator(IntervalMapIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IntervalMapIterator& operator=(const IntervalMapIterator&) = delete;
        IntervalMapIterator& operator=(IntervalMapIterator&&) = delete;

        /**
         * Checks whether there is a next element.
         */
        virtual bool hasNext() const override;

        /**
         * Gets the next element.
         */
        virtual Pair<Interval<Key>, Value> next() override;

        /**
         * Resets the iterator.
         */
        virtual void reset() override;

    private:
        const IntervalDataMap& m_data;

        size_t m_index;
        typename IntervalDataMap::const_iterator m_iterator;
    };

    template <typename Key, typename Value>
    IntervalMapIterator<Key, Value>::IntervalMapIterator(const IntervalDataMap& data) :
        m_data(data),
        m_iterator(data.end())
    {
        reset();
    }

    template <typename Key, typename Value>
    IntervalMapIterator<Key, Value>::~IntervalMapIterator()
    {
    }

    template <typename Key, typename Value>
    bool IntervalMapIterator<Key, Value>::hasNext() const
    {
        return m_index < m_data.size() - 1;
    }

    template <typename Key, typename Value>
    Pair<Interval<Key>, Value> IntervalMapIterator<Key, Value>::next()
    {
        assert(hasNext());

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

    template <typename Key, typename Value>
    void IntervalMapIterator<Key, Value>::reset()
    {
        m_iterator = m_data.begin();
        m_index = 0;
    }
}

#endif // INTERVAL_MAP_ITERATOR_H_0fb64af4_e028_43e2_ad83_d36cafde355e
