#ifndef I_INTERVAL_MAP_H_9141bb26_830a_466a_8f05_d66388d7c125
#define I_INTERVAL_MAP_H_9141bb26_830a_466a_8f05_d66388d7c125

#include "ISizableCollection.h"
#include "IIterable.h"
#include "Interval.h"
#include "Pair.h"

namespace base
{
    /**
     * The IIntervalMap interface defines an interval map.
     */
    template <typename Key, typename Value>
    class IIntervalMap : public ISizableCollection<base::Pair<base::Interval<Key>, Value>>
    {
    public:
        /**
         * The constructor.
         */
        IIntervalMap() = default;

        /**
         * The destructor.
         */
        virtual ~IIntervalMap() = default;

        /**
         * The copy/move constructors.
         */
        IIntervalMap(const IIntervalMap&) = delete;
        IIntervalMap(IIntervalMap&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IIntervalMap& operator=(const IIntervalMap&) = delete;
        IIntervalMap& operator=(IIntervalMap&&) = delete;

        /**
         * Looks-up of the value associated with key.
         */
        virtual const Value& operator[](const Key& key) const = 0;

        /**
         * Looks-up of the value associated with key.
         */
        virtual const Value& Get(const Key& key) const = 0;
    };
}

#endif // I_INTERVAL_MAP_H_9141bb26_830a_466a_8f05_d66388d7c125
