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
            static ICacheSharedPtr<TKey, TValue> Make(ICachePropertiesSharedPtr properties);

            /**
             * The MRUCache constructor.
             */
            explicit MRUCache(ICachePropertiesSharedPtr properties);

            /**
             * The MRUCache destructor.
             */
            virtual ~MRUCache();

            /**
             * The Copy/move constructors.
             */
            MRUCache(const MRUCache&) = delete;
            MRUCache(MRUCache&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            MRUCache& operator=(const MRUCache&) = delete;
            MRUCache& operator=(MRUCache&&) = delete;

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
        ICacheSharedPtr<TKey, TValue> MRUCache<TKey, TValue>::Make(ICachePropertiesSharedPtr properties)
        {
            return std::make_shared<MRUCache<TKey, TValue>>(properties);
        }

        /**
         * The MRUCache constructor.
         */
        template <typename TKey, typename TValue>
        MRUCache<TKey, TValue>::MRUCache(ICachePropertiesSharedPtr properties) :
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
         * Makes available space for the specified number ofitems.
         */
        template <typename TKey, typename TValue>
        void MRUCache<TKey, TValue>::MakeAvailableSpace(
            typename AbstractCache<TKey, TValue>::CacheData& cacheData,
            size_t numberOfItems)
        {
            DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& usedList = cacheData.UsedList();
            std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& dataLookup =
                cacheData.DataLookup();

            for (size_t i = 0; i < numberOfItems; ++i)
            {
                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> itemToRemove = usedList.RemoveFromBack();
                dataLookup.erase(itemToRemove->GetValue()->GetKey());
            }
        }
    }
}

#endif // MRU_CACHE_H_67a56d2c_ed37_408c_8860_cfe4f5f131de
