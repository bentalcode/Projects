#ifndef INTERVAL_MAP_H_15461bcd_7d91_4092_badf_6c3e23f487c9
#define INTERVAL_MAP_H_15461bcd_7d91_4092_badf_6c3e23f487c9

#include <map>
#include <limits>
#include "IIntervalMap.h"
#include "IntervalMapIterator.h"

namespace base {

    /**
     * The IntervalMap class implements an interval map.
     */
    template <typename Key, typename Value>
    class IntervalMap final : public IIntervalMap<Key, Value> {
    public:
        using KeyValueType = std::pair<Key, Value>;
        using IntervalDataMap = std::map<Key, Value>;

        /**
         * The IntervalMap constructor.
         */
        explicit IntervalMap(const Value &val);

        /**
         * Assigns value val to interval [keyBegin, keyEnd).
         * If the range is designates as an Empty interval: !( keyBegin < keyEnd ), return with doing nothing.
         */
        void Assign(const Key& keyBegin, const Key& keyEnd, const Value& value);

        /**
         * Looks-up of the value associated with key.
         */
        virtual const Value& operator[](const Key& index) const override;

        /**
         * Looks-up of the value associated with key.
         */
        virtual const Value& Get(const Key& index) const override;

        /**
         * Returns whether the collection is Empty.
         */
        virtual bool Empty() const override;

        /**
         * Gets the Size of the collection.
         */
        virtual std::size_t Size() const override;

        /**
         * Gets the iterator.
         */
        virtual IIteratorSharedPtr<Pair<base::Interval<Key>, Value>> GetIterator() const override;

    private:
        /**
         * Finds the value of an end key.
         * Returns true if found the value in the map.
         */
        bool FindEndKeyValue(const Key& key, Value& result) const;

        /**
         * Finds the next smaller or equal key of a specified key.
         */
        typename IntervalDataMap::const_iterator FindNextSmallerOrEqualKey(const Key& key) const;

        /**
         * Removes a key range.
         */
        void RemoveKeyRange(const Key& keyBegin, const Key& keyEnd);

        IntervalDataMap m_map;
    };

    /**
     * The IntervalMap constructor.
     */
    template <typename Key, typename Value>
    IntervalMap<Key, Value>::IntervalMap(const Value &val) {
        m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<Key>::lowest(), val));
    }

    /**
     * Assigns value val to interval [keyBegin, keyEnd).
     * If the range is designates as an Empty interval: !( keyBegin < keyEnd ), return with doing nothing.
     */
    template <typename Key, typename Value>
    void IntervalMap<Key, Value>::Assign(const Key& keyBegin, const Key& keyEnd, const Value& value) {
        //
        // Return if the range is Empty...
        //
        if (keyBegin >= keyEnd) {
            return;
        }

        //
        // Find the value of the end key...
        //
        Value keyEndValue;
        if (!FindEndKeyValue(keyEnd, keyEndValue)) {
            std::string errorMessage = "The Interval Map failed finding an end key value.";
            throw std::logic_error(errorMessage);
        }

        //
        // Remove the key range...
        //
        RemoveKeyRange(keyBegin, keyEnd);

        //
        // Set the key begin info...
        //
        m_map.insert(KeyValueType(keyBegin, value));

        //
        // Set the key end info...
        //
        m_map.insert(KeyValueType(keyEnd, keyEndValue));
    }

    /**
     * Looks-up of the value associated with key.
     */
    template <typename Key, typename Value>
    const Value& IntervalMap<Key, Value>::operator[](const Key& key) const {
        return Get(key);
    }

    /**
     * Looks-up of the value associated with key.
     */
    template <typename Key, typename Value>
    const Value& IntervalMap<Key, Value>::Get(const Key& key) const {
        //
        // Finds the value of the key...
        //
        typename IntervalDataMap::const_iterator iterator = FindNextSmallerOrEqualKey(key);

        if (iterator == m_map.end()) {
            long statusCode = ErrorCodes::FAIL;
            std::wstring errorMessage = L"The Interval Map is in invalid state: No intervals were defined.";

            throw BaseException(statusCode, errorMessage);
        }

        return iterator->second;
    }

    /**
     * Finds the value of an end key.
     * Returns true if found the value in the map.
     */
    template <typename Key, typename Value>
    bool IntervalMap<Key, Value>::FindEndKeyValue(const Key& key, Value& result) const {
        typename IntervalDataMap::const_iterator i = FindNextSmallerOrEqualKey(key);

        if (i == m_map.end()) {
            return false;
        }

        result = i->second;

        return true;
    }

    /**
     * Finds the next smaller or equal key of a specified key.
     * Returns end() if no key was found.
     */
    template <typename Key, typename Value>
    typename IntervalMap<Key, Value>::IntervalDataMap::const_iterator IntervalMap<Key, Value>::FindNextSmallerOrEqualKey(const Key& key) const {
        if (m_map.empty()) {
            return m_map.end();
        }

        //
        // Returns an iterator pointing to the first element in the range [first,last),
        // which does not compare less than key...
        //
        typename IntervalDataMap::const_iterator iterator = m_map.lower_bound(key);

        if (iterator == m_map.end()) {
            --iterator;
            return iterator;
        }

        if (iterator->first == key) {
            return iterator;
        }

        --iterator;
        return iterator;
    }

    /**
     * Removes a key range.
     */
    template <typename Key, typename Value>
    inline void IntervalMap<Key, Value>::RemoveKeyRange(const Key& keyBegin, const Key& keyEnd) {
        typename IntervalDataMap::iterator startIterator = m_map.lower_bound(keyBegin);
        typename IntervalDataMap::iterator endIterator = m_map.upper_bound(keyEnd);

        typename IntervalDataMap::iterator iterator = startIterator;

        while (iterator != endIterator) {
            m_map.erase(iterator++);
        }
    }

    template <typename Key, typename Value>
    bool IntervalMap<Key, Value>::Empty() const
    {
        return m_map.empty();
    }

    template <typename Key, typename Value>
    std::size_t IntervalMap<Key, Value>::Size() const
    {
        return m_map.size();
    }

    template <typename Key, typename Value>
    IIteratorSharedPtr<Pair<base::Interval<Key>, Value>> IntervalMap<Key, Value>::GetIterator() const
    {
        IIteratorSharedPtr<Pair<base::Interval<Key>, Value>> iterator(new IntervalMapIterator<Key, Value>(m_map));
        return iterator;
    }
}

#endif // INTERVAL_MAP_H_15461bcd_7d91_4092_badf_6c3e23f487c9
