#ifndef LRU_CACHE_H_86823880_0333_4243_bbc5_6da7e18e84b3
#define LRU_CACHE_H_86823880_0333_4243_bbc5_6da7e18e84b3

#include "AbstractCache.h"
#include "ICacheProperties.h"

namespace datastructures {
    namespace cache {

        /**
         * The LRUCache class implements a least recently used cache.
         * Discards the least recently used items first.
         */
        template <typename TKey, typename TValue>
        class LRUCache final : public AbstractCache<TKey, TValue>
        {
        public:
            /**
             * Creates a least recently used cache.
             */
            static ICachePtr<TKey, TValue> make(ICachePropertiesPtr properties);

            /**
             * The LRUCache constructor.
             */
            explicit LRUCache(ICachePropertiesPtr properties);

            /**
             * The LRUCache destructor.
             */
            virtual ~LRUCache();

            /**
             * The copy/move constructors.
             */
            LRUCache(const LRUCache&) = delete;
            LRUCache(LRUCache&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            LRUCache& operator=(const LRUCache&) = delete;
            LRUCache& operator=(LRUCache&&) = delete;

        protected:
            /**
             * Makes available space for the specified number of items.
             */
            virtual void makeAvailableSpace(
                typename AbstractCache<TKey, TValue>::CacheData& cacheData,
                size_t numberOfItems) override;
        };

        /**
         * Creates a least recently used cache.
         */
        template <typename TKey, typename TValue>
        ICachePtr<TKey, TValue> LRUCache<TKey, TValue>::make(ICachePropertiesPtr properties)
        {
            return std::make_shared<LRUCache<TKey, TValue>>(properties);
        }

        /**
         * The LRUCache constructor.
         */
        template <typename TKey, typename TValue>
        LRUCache<TKey, TValue>::LRUCache(ICachePropertiesPtr properties) :
            AbstractCache<TKey, TValue>(properties)
        {
        }

        /**
         * The LRUCache destructor.
         */
        template <typename TKey, typename TValue>
        LRUCache<TKey, TValue>::~LRUCache()
        {
        }

        /**
         * Makes available space for the specified number of items.
         */
        template <typename TKey, typename TValue>
        void LRUCache<TKey, TValue>::makeAvailableSpace(
            typename AbstractCache<TKey, TValue>::CacheData& cacheData,
            size_t numberOfItems)
        {
            DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>>& usedList = cacheData.usedList();
            std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>>& dataLookup = cacheData.dataLookup();

            for (size_t i = 0; i < numberOfItems; ++i)
            {
                IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> itemToRemove = usedList.removeFromFront();
                dataLookup.erase(itemToRemove->getValue()->getKey());
            }
        }
    }
}

#endif // LRU_CACHE_H_86823880_0333_4243_bbc5_6da7e18e84b3
