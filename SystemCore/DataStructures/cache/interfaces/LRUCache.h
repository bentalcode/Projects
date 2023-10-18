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
            static ICacheSharedPtr<TKey, TValue> Make(ICachePropertiesSharedPtr properties);

            /**
             * The LRUCache constructor.
             */
            explicit LRUCache(ICachePropertiesSharedPtr properties);

            /**
             * The LRUCache destructor.
             */
            virtual ~LRUCache();

            /**
             * The Copy/move constructors.
             */
            LRUCache(const LRUCache&) = delete;
            LRUCache(LRUCache&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            LRUCache& operator=(const LRUCache&) = delete;
            LRUCache& operator=(LRUCache&&) = delete;

        protected:
            /**
             * Makes available space for the specified number ofitems.
             */
            virtual void MakeAvailableSpace(
                typename AbstractCache<TKey, TValue>::CacheData& cacheData,
                size_t numberOfItems) override;
        };

        /**
         * Creates a least recently used cache.
         */
        template <typename TKey, typename TValue>
        ICacheSharedPtr<TKey, TValue> LRUCache<TKey, TValue>::Make(ICachePropertiesSharedPtr properties)
        {
            return std::make_shared<LRUCache<TKey, TValue>>(properties);
        }

        /**
         * The LRUCache constructor.
         */
        template <typename TKey, typename TValue>
        LRUCache<TKey, TValue>::LRUCache(ICachePropertiesSharedPtr properties) :
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
         * Makes available space for the specified number ofitems.
         */
        template <typename TKey, typename TValue>
        void LRUCache<TKey, TValue>::MakeAvailableSpace(
            typename AbstractCache<TKey, TValue>::CacheData& cacheData,
            size_t numberOfItems)
        {
            DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& usedList = cacheData.UsedList();
            std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& dataLookup =
                cacheData.DataLookup();

            for (size_t i = 0; i < numberOfItems; ++i)
            {
                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> itemToRemove = usedList.RemoveFromFront();
                dataLookup.erase(itemToRemove->GetValue()->GetKey());
            }
        }
    }
}

#endif // LRU_CACHE_H_86823880_0333_4243_bbc5_6da7e18e84b3
