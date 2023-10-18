#ifndef ABSTRACT_CACHE_H_09bacd72_c96d_47de_b8ed_4933e5722ebc
#define ABSTRACT_CACHE_H_09bacd72_c96d_47de_b8ed_4933e5722ebc

#include "ICacheProperties.h"
#include "DoublyLinkedList.h"
#include "KeyValueNode.h"
#include "DoublyLinkedListKeyValueNodeIterator.h"
#include "DoublyLinkedListKeyValueNodeReverseIterator.h"
#include "KeyIterator.h"
#include "KeyReverseIterator.h"
#include "ValueIterator.h"
#include "ValueReverseIterator.h"
#include "CacheException.h"

namespace datastructures {
    namespace cache {

        /**
         * The AbstractCache class implements an abstract cache.
         */
        template <typename TKey, typename TValue>
        class AbstractCache : public ICache<TKey, TValue>
        {
        public:
            /**
             * The AbstractCache constructor.
             */
            explicit AbstractCache(ICachePropertiesSharedPtr properties);

            /**
             * The AbstractCache destructor.
             */
            virtual ~AbstractCache();

            /**
             * The Copy/move constructors.
             */
            AbstractCache(const AbstractCache&) = delete;
            AbstractCache(AbstractCache&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            AbstractCache& operator=(const AbstractCache&) = delete;
            AbstractCache& operator=(AbstractCache&&) = delete;

            /**
             * Gets properties of a cache.
             */
            virtual const ICacheProperties& GetProperties() const override;

            /**
             * Set a new key in the cache.
             * Complexity: O(1)
             */
            virtual void Set(const TKey& key, const TValue& value) override;

            /**
             * Gets a value of a specific key in the cache.
             * Complexity: O(1)
             */
            virtual const TValue& Get(const TKey& key) override;

            /**
             * Deletes a key and it's associated value from the cache.
             *
             * Returns true if the key Has been removed successfully from the cache.
             * Returns false if the key is not in the cache.
             *
             * Complexity: O(1)
             */
            virtual bool DeleteKey(const TKey& key) override;

            /**
             * Checks whether a key is Set in the cache.
             * Complexity: O(1)
             */
            virtual bool Has(const TKey& key) const override;

            /**
             * Gets the Size of the collection.
             */
            virtual size_t Size() const override;

            /**
             * Checks whether the collection is Empty.
             */
            virtual bool Empty() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> GetIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> GetReverseIterator() const override;

            /**
             * Gets the iterator of keys.
             */
            virtual base::IIteratorSharedPtr<TKey> GetKeyIterator() const override;

            /**
             * Gets the reverse iterator of keys.
             */
            virtual base::IReverseIteratorSharedPtr<TKey> GetKeyReverseIterator() const override;

            /**
             * Gets the iterator of values.
             */
            virtual base::IIteratorSharedPtr<TValue> GetValueIterator() const override;

            /**
             * Gets the reverse iterator of values.
             */
            virtual base::IReverseIteratorSharedPtr<TValue> GetValueReverseIterator() const override;

        protected:

            /**
             * The CacheData class captures the internal data of a cache.
             */
            class CacheData final
            {
            public:
                /**
                 * The CacheData constructor.
                 */
                CacheData();

                /**
                 * The CacheData destructor.
                 */
                ~CacheData();

                /**
                 * Gets the data lookup.
                 */
                const std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& DataLookup() const;
                std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& DataLookup();

                /**
                 * Gets the data lookup.
                 */
                const DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& UsedList() const;
                DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& UsedList();

                /**
                 * Gets the key-value node.
                 */
                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> GetKeyValueNode(const TKey& key) const;

                /**
                 * Removes the key-value node.
                 */
                void RemoveKeyValueNode(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node);

                /**
                 * Checks whether the key exists.
                 */
                bool HasKey(const TKey& key) const;

            private:
                std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> m_dataLookup;
                DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>> m_usedList;
            };

            /**
             * Makes available space for the specified number ofitems.
             */
            virtual void MakeAvailableSpace(
                    AbstractCache<TKey, TValue>::CacheData &cacheData,
                    size_t numberOfItems) = 0;

        private:
            /**
             * Processes accessing a current item.
             */
            void CurrentItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node);

            /**
             * Processes accessing a new item.
             */
            void NewItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node);

            /**
             * Determines whether the used-list Has reached it's maximum capacity.
             */
            bool OverCapacity() const;

            /**
             * Validates a key exists.
             */
            void ValidateKeyExists(const TKey& key) const;

            ICachePropertiesSharedPtr m_properties;
            CacheData m_data;
        };

        /**
         * The AbstractCache constructor.
         */
        template <typename TKey, typename TValue>
        AbstractCache<TKey, TValue>::AbstractCache(ICachePropertiesSharedPtr properties) :
            m_properties(properties)
        {
            base::SmartPointers::Validate<ICacheProperties>(properties);
        }

        /**
         * The AbstractCache destructor.
         */
        template <typename TKey, typename TValue>
        AbstractCache<TKey, TValue>::~AbstractCache()
        {
        }

        /**
         * Gets properties of a cache.
         */
        template <typename TKey, typename TValue>
        const ICacheProperties& AbstractCache<TKey, TValue>::GetProperties() const
        {
            return *m_properties;
        }

        /**
         * Set a new key in the cache.
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::Set(const TKey& key, const TValue& value)
        {
            if (Has(key))
            {
                //
                // If the key is set in the cache, update it's value...
                //
                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> currNode =
                    m_data.GetKeyValueNode(key);

                currNode->GetValue()->SetValue(value);

                CurrentItemAccessed(currNode);
            }
            else
            {
                //
                // If the cache is over it's capacity, then make available space for the new item...
                //
                if (OverCapacity())
                {
                    assert(m_properties->GetNumberOfItemsForMakingAvailableSpace() <= Size());

                    MakeAvailableSpace(
                        m_data,
                        m_properties->GetNumberOfItemsForMakingAvailableSpace());

                    if (OverCapacity())
                    {
                        long statusCode = base::ErrorCodes::OUT_OF_RANGE;
                        std::wstring errorMessage = L"The cache should have an available space.";

                        throw CacheException(statusCode, errorMessage);
                    }
                }

                node::IKeyValueNodeSharedPtr<TKey, TValue> keyValueNode =
                    node::KeyValueNode<TKey, TValue>::Make(key, value);

                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> currNode =
                    DoublyLinkedListNode<node::IKeyValueNodeSharedPtr<TKey, TValue>>::Make(keyValueNode);

                NewItemAccessed(currNode);
            }
        }

        /**
         * Gets a value of a specific key in the cache.
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        const TValue& AbstractCache<TKey, TValue>::Get(const TKey& key)
        {
            //
            // Validate that the key exists...
            //
            ValidateKeyExists(key);

            //
            // Get the current value of the node...
            //
            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> currNode = m_data.GetKeyValueNode(key);
            const TValue& currValue = currNode->GetValue()->GetValue();

            //
            // Mark that the item is accessed...
            //
            CurrentItemAccessed(currNode);

            return currValue;
        }

        /**
         * Deletes a key and it's associated value from the cache.
         *
         * Returns true if the key Has been removed successfully from the cache.
         * Returns false if the key is not in the cache.
         *
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::DeleteKey(const TKey& key)
        {
            if (!Has(key))
            {
                return false;
            }

            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node = m_data.GetKeyValueNode(key);
            m_data.RemoveKeyValueNode(node);

            return true;
        }

        /**
         * Checks whether a key is Set in the cache.
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::Has(const TKey& key) const
        {
            return m_data.HasKey(key);
        }

        /**
         * Gets the Size of the collection.
         */
        template <typename TKey, typename TValue>
        size_t AbstractCache<TKey, TValue>::Size() const
        {
            return m_data.DataLookup().size();
        }

        /**
         * Checks whether the collection is Empty.
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::Empty() const
        {
            return m_data.DataLookup().empty();
        }

        /**
         * Gets the iterator.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> AbstractCache<TKey, TValue>::GetIterator() const
        {
            base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> iterator =
                m_data.UsedList().GetIterator();

            return DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::Make(iterator);
        }

        /**
         * Gets the reverse iterator.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> AbstractCache<TKey, TValue>::GetReverseIterator() const
        {
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> reverseIterator =
                    m_data.UsedList().GetReverseIterator();

            return DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::Make(reverseIterator);
        }

        /**
         * Gets the iterator of keys.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<TKey> AbstractCache<TKey, TValue>::GetKeyIterator() const
        {
            base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeIterator = GetIterator();
            return node::KeyIterator<TKey, TValue>::Make(keyValueNodeIterator);
        }

        /**
         * Gets the reverse iterator of keys.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<TKey> AbstractCache<TKey, TValue>::GetKeyReverseIterator() const
        {
            base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeReverseIterator = GetReverseIterator();
            return node::KeyReverseIterator<TKey, TValue>::Make(keyValueNodeReverseIterator);
        }

        /**
         * Gets the iterator of values.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<TValue> AbstractCache<TKey, TValue>::GetValueIterator() const
        {
            base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeIterator = GetIterator();
            return node::ValueIterator<TKey, TValue>::Make(keyValueNodeIterator);
        }

        /**
         * Gets the reverse iterator of values.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<TValue> AbstractCache<TKey, TValue>::GetValueReverseIterator() const
        {
            base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeReverseIterator = GetReverseIterator();
            return node::ValueReverseIterator<TKey, TValue>::Make(keyValueNodeReverseIterator);
        }

        /**
         * Processes accessing a current item.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::CurrentItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node)
        {
            DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& usedList = m_data.UsedList();

            usedList.Remove(node);
            usedList.AddToBack(node);
        }

        /**
         * Processes accessing a new item.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::NewItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node)
        {
            std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& dataLookup = m_data.DataLookup();

            dataLookup.insert(std::make_pair(node->GetValue()->GetKey(), node));
            m_data.UsedList().AddToBack(node);
        }

        /**
         * Determines whether the used-list Has reached it's maximum capacity.
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::OverCapacity() const
        {
            return Size() >= m_properties->GetCapacity();
        }

        /**
         * Validates that the key exists.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::ValidateKeyExists(const TKey& key) const
        {
            if (!Has(key))
            {
                long statusCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
                std::wstring errorMessage = L"The key: " + std::to_wstring(key) + L" is not defined in the cache.";

                throw CacheException(statusCode, errorMessage);
            }
        }

        /**
         * The CacheData constructor.
         */
        template <typename TKey, typename TValue>
        AbstractCache<TKey, TValue>::CacheData::CacheData()
        {
        }

        /**
         * The CacheData destructor.
         */
        template <typename TKey, typename TValue>
        AbstractCache<TKey, TValue>::CacheData::~CacheData()
        {
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        const std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& AbstractCache<TKey, TValue>::CacheData::DataLookup() const
        {
            return m_dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& AbstractCache<TKey, TValue>::CacheData::DataLookup()
        {
            return m_dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        const DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& AbstractCache<TKey, TValue>::CacheData::UsedList() const
        {
            return m_usedList;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& AbstractCache<TKey, TValue>::CacheData::UsedList()
        {
            return m_usedList;
        }

        /**
         * Gets the key-value node.
         */
        template <typename TKey, typename TValue>
        IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> AbstractCache<TKey, TValue>::CacheData::GetKeyValueNode(const TKey& key) const
        {
            return m_dataLookup.at(key);
        }

        /**
         * Removes the key-value node.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::CacheData::RemoveKeyValueNode(
            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node)
        {
            m_dataLookup.erase(node->GetValue()->GetKey());
            m_usedList.Remove(node);
        }

        /**
         * Checks whether the key exists.
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::CacheData::HasKey(const TKey& key) const {
            return m_dataLookup.find(key) != m_dataLookup.end();
        }

    }
}

#endif // ABSTRACT_CACHE_H_09bacd72_c96d_47de_b8ed_4933e5722ebc
