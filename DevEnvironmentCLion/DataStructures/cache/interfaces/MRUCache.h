#ifndef MRU_CACHE_H_67a56d2c_ed37_408c_8860_cfe4f5f131de
#define MRU_CACHE_H_67a56d2c_ed37_408c_8860_cfe4f5f131de

#include "AbstractCache.h"
#include "ICacheProperties.h"

namespace datastructures {
    namespace cache {

        /**
         * The MRUCache class implements a most recently used cache.
         * Discards the most recently used items first.
         */
        template <typename TKey, typename TValue>
        class MRUCache final : public AbstractCache<TKey, TValue>
        {
        public:
            /**
             * Creates a most recently used cache.
             */
            static ICachePtr<TKey, TValue> make(ICachePropertiesPtr properties);

            /**
             * The MRUCache constructor.
             */
            explicit MRUCache(ICachePropertiesPtr properties);

            /**
             * The MRUCache destructor.
             */
            virtual ~MRUCache();

            /**
             * The copy/move constructors.
             */
            MRUCache(const MRUCache&) = delete;
            MRUCache(MRUCache&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            MRUCache& operator=(const MRUCache&) = delete;
            MRUCache& operator=(MRUCache&&) = delete;

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
        ICachePtr<TKey, TValue> MRUCache<TKey, TValue>::make(ICachePropertiesPtr properties)
        {
            return std::make_shared<MRUCache<TKey, TValue>>(properties);
        }

        /**
         * The MRUCache constructor.
         */
        template <typename TKey, typename TValue>
        MRUCache<TKey, TValue>::MRUCache(ICachePropertiesPtr properties) :
            AbstractCache<TKey, TValue>(properties)
        {
        }

        /**
         * The MRUCache destructor.
         */
        template <typename TKey, typename TValue>
        MRUCache<TKey, TValue>::~MRUCache()
        {
        }

        /**
         * Makes available space for the specified number of items.
         */
        template <typename TKey, typename TValue>
        void MRUCache<TKey, TValue>::makeAvailableSpace(
            typename AbstractCache<TKey, TValue>::CacheData& cacheData,
            size_t numberOfItems)
        {
            DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>>& usedList = cacheData.usedList();
            std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>>& dataLookup = cacheData.dataLookup();

            for (size_t i = 0; i < numberOfItems; ++i)
            {
                IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> itemToRemove = usedList.removeFromBack();
                dataLookup.erase(itemToRemove->getValue()->getKey());
            }
        }
    }
}

#endif // MRU_CACHE_H_67a56d2c_ed37_408c_8860_cfe4f5f131de
