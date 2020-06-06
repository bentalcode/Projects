#ifndef INTERVAL_MAP_H_82c2a3ba_9919_4f97_a576_f1928362bf93
#define INTERVAL_MAP_H_82c2a3ba_9919_4f97_a576_f1928362bf93

#include <map>
#include <limits>

namespace base {

    /**
     * The IntervalMap class implements an interval map.
     */
    template<typename K, typename V>
    class IntervalMap final {
    public:
        /**
         * The IntervalMap constructor.
         */
        explicit IntervalMap(V const &val);

        /**
         * Assigns value val to interval [keyBegin, keyEnd).
         * If the range is designates as an empty interval: !( keyBegin < keyEnd ), return with doing nothing.
         */
        void assign(const K& keyBegin, const K& keyEnd, const V& value);

        /**
         * Looks-up of the value associated with key.
         */
        const V& operator[](const K& key) const;

    private:
        typedef std::map<K, V> IntervalMap;

        /**
         * Finds the value of an end key.
         * Returns true if found the value in the map.
         */
        bool findEndKeyValue(const K& key, V& result) const;

        /**
         * Finds the next smaller or equal key of a specified key.
         */
        typename IntervalMap::const_iterator findNextSmallerOrEqualKey(const K& key) const;

        /**
         * Removes a key range.
         */
        void removeKeyRange(const K& keyBegin, const K& keyEnd);

        IntervalMap m_map;
    };

    /**
     * The IntervalMap constructor.
     */
    template<typename K, typename V>
    IntervalMap<K, V>::IntervalMap(V const &val) {
        m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

    /**
     * Assigns value val to interval [keyBegin, keyEnd).
     * If the range is designates as an empty interval: !( keyBegin < keyEnd ), return with doing nothing.
     */
    template<typename K, typename V>
    void IntervalMap<K, V>::assign(const K& keyBegin, const K& keyEnd, const V& value) {
        //
        // Return if the range is empty...
        //
        if (keyBegin >= keyEnd) {
            return;
        }

        //
        // Find the value of the end key...
        //
        V keyEndValue;
        if (!findEndKeyValue(keyEnd, keyEndValue)) {
            std::string errorMessage = "The Interval Map failed finding an end key value.";
            throw std::logic_error(errorMessage);
        }

        //
        // Remove the key range...
        //
        removeKeyRange(keyBegin, keyEnd);

        //
        // Set the key begin info...
        //
        m_map.insert(std::pair<K, V>(keyBegin, value));

        //
        // Set the key end info...
        //
        m_map.insert(std::pair<K, V>(keyEnd, keyEndValue));
    }

    /**
     * Looks-ups of the value associated with key.
     */
    template<typename K, typename V>
    const V& IntervalMap<K, V>::operator[](const K& key) const {
        //
        // Finds the value of the key...
        //
        typename IntervalMap::const_iterator iterator = findNextSmallerOrEqualKey(key);

        if (iterator == m_map.end()) {
            std::string errorMessage = "The Interval Map is in invalid state: No intervals were defined.";
            throw std::logic_error(errorMessage);
        }

        return iterator->second;
    }

    /**
     * Finds the value of an end key.
     * Returns true if found the value in the map.
     */
    template<typename K, typename V>
    bool IntervalMap<K, V>::findEndKeyValue(const K& key, V& result) const {
        typename IntervalMap::const_iterator i = findNextSmallerOrEqualKey(key);

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
    template<typename K, typename V>
    typename IntervalMap<K, V>::IntervalMap::const_iterator IntervalMap<K, V>::findNextSmallerOrEqualKey(const K& key) const {
        if (m_map.empty()) {
            return m_map.end();
        }

        //
        // Returns an iterator pointing to the first element in the range [first,last),
        // which does not compare less than key...
        //
        typename IntervalMap::const_iterator iterator = m_map.lower_bound(key);

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
    template<typename K, typename V>
    inline void IntervalMap<K, V>::removeKeyRange(const K& keyBegin, const K& keyEnd) {
        typename IntervalMap::iterator startIterator = m_map.lower_bound(keyBegin);
        typename IntervalMap::iterator endIterator = m_map.upper_bound(keyEnd);

        typename IntervalMap::iterator iterator = startIterator;

        while (iterator != endIterator) {
            m_map.erase(iterator++);
        }
    }
}

#endif // INTERVAL_MAP_H_82c2a3ba_9919_4f97_a576_f1928362bf93
