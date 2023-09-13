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
             * The copy/move constructors.
             */
            AbstractCache(const AbstractCache&) = delete;
            AbstractCache(AbstractCache&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            AbstractCache& operator=(const AbstractCache&) = delete;
            AbstractCache& operator=(AbstractCache&&) = delete;

            /**
             * Gets properties of a cache.
             */
            virtual const ICacheProperties& getProperties() const override;

            /**
             * Set a new key in the cache.
             * Complexity: O(1)
             */
            virtual void set(const TKey& key, const TValue& value) override;

            /**
             * Gets a value of a specific key in the cache.
             * Complexity: O(1)
             */
            virtual const TValue& get(const TKey& key) override;

            /**
             * Deletes a key and it's associated value from the cache.
             *
             * Returns true if the key has been removed successfully from the cache.
             * Returns false if the key is not in the cache.
             *
             * Complexity: O(1)
             */
            virtual bool deleteKey(const TKey& key) override;

            /**
             * Checks whether a key is set in the cache.
             * Complexity: O(1)
             */
            virtual bool has(const TKey& key) const override;

            /**
             * Gets the size of the collection.
             */
            virtual size_t size() const override;

            /**
             * Checks whether the collection is empty.
             */
            virtual bool empty() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> getIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> getReverseIterator() const override;

            /**
             * Gets the iterator of keys.
             */
            virtual base::IIteratorSharedPtr<TKey> getKeyIterator() const override;

            /**
             * Gets the reverse iterator of keys.
             */
            virtual base::IReverseIteratorSharedPtr<TKey> getKeyReverseIterator() const override;

            /**
             * Gets the iterator of values.
             */
            virtual base::IIteratorSharedPtr<TValue> getValueIterator() const override;

            /**
             * Gets the reverse iterator of values.
             */
            virtual base::IReverseIteratorSharedPtr<TValue> getValueReverseIterator() const override;

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
                const std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& dataLookup() const;
                std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& dataLookup();

                /**
                 * Gets the data lookup.
                 */
                const DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& usedList() const;
                DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& usedList();

                /**
                 * Gets the key-value node.
                 */
                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> getKeyValueNode(const TKey& key) const;

                /**
                 * Removes the key-value node.
                 */
                void removeKeyValueNode(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node);

                /**
                 * Checks whether the key exists.
                 */
                bool hasKey(const TKey& key) const;

            private:
                std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> m_dataLookup;
                DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>> m_usedList;
            };

            /**
             * Makes available space for the specified number of items.
             */
            virtual void makeAvailableSpace(
                CacheData& cacheData,
                size_t numberOfItems) = 0;

        private:
            /**
             * Processes accessing a current item.
             */
            void currentItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node);

            /**
             * Processes accessing a new item.
             */
            void newItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node);

            /**
             * Determines whether the used-list has reached it's maximum capacity.
             */
            bool overCapacity() const;

            /**
             * Validates a key exists.
             */
            void validateKeyExists(const TKey& key) const;

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
            if (!properties)
            {
                std::string errorMessage = "The properties of the cache are not defined.";
                throw CacheException(errorMessage);
            }
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
        const ICacheProperties& AbstractCache<TKey, TValue>::getProperties() const
        {
            return *m_properties;
        }

        /**
         * Set a new key in the cache.
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::set(const TKey& key, const TValue& value)
        {
            if (has(key))
            {
                //
                // If the key is set in the cache, update it's value...
                //
                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> currNode = m_data.getKeyValueNode(key);
                currNode->getValue()->setValue(value);

                currentItemAccessed(currNode);
            }
            else
            {
                //
                // If the cache is over it's capacity, then make available space for the new item...
                //
                if (overCapacity())
                {
                    assert(m_properties->getNumberOfItemsForMakingAvailableSpace() <= size());

                    makeAvailableSpace(
                        m_data,
                        m_properties->getNumberOfItemsForMakingAvailableSpace());

                    if (overCapacity())
                    {
                        std::string errorMessage = "The cache should have an available space.";
                        throw CacheException(errorMessage);
                    }
                }

                node::IKeyValueNodeSharedPtr<TKey, TValue> keyValueNode =
                    node::KeyValueNode<TKey, TValue>::make(key, value);

                IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> currNode =
                    DoublyLinkedListNode<node::IKeyValueNodeSharedPtr<TKey, TValue>>::make(keyValueNode);

                newItemAccessed(currNode);
            }
        }

        /**
         * Gets a value of a specific key in the cache.
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        const TValue& AbstractCache<TKey, TValue>::get(const TKey& key)
        {
            //
            // Validate that the key exists...
            //
            validateKeyExists(key);

            //
            // Get the current value of the node...
            //
            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> currNode = m_data.getKeyValueNode(key);
            const TValue& currValue = currNode->getValue()->getValue();

            //
            // Mark that the item is accessed...
            //
            currentItemAccessed(currNode);

            return currValue;
        }

        /**
         * Deletes a key and it's associated value from the cache.
         *
         * Returns true if the key has been removed successfully from the cache.
         * Returns false if the key is not in the cache.
         *
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::deleteKey(const TKey& key)
        {
            if (!has(key))
            {
                return false;
            }

            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node = m_data.getKeyValueNode(key);
            m_data.removeKeyValueNode(node);

            return true;
        }

        /**
         * Checks whether a key is set in the cache.
         * Complexity: O(1)
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::has(const TKey& key) const
        {
            return m_data.hasKey(key);
        }

        /**
         * Gets the size of the collection.
         */
        template <typename TKey, typename TValue>
        size_t AbstractCache<TKey, TValue>::size() const
        {
            return m_data.dataLookup().size();
        }

        /**
         * Checks whether the collection is empty.
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::empty() const
        {
            return m_data.dataLookup().empty();
        }

        /**
         * Gets the iterator.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> AbstractCache<TKey, TValue>::getIterator() const
        {
            base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> iterator =
                m_data.usedList().getIterator();

            return DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::make(iterator);
        }

        /**
         * Gets the reverse iterator.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> AbstractCache<TKey, TValue>::getReverseIterator() const
        {
            base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>> reverseIterator =
                m_data.usedList().getReverseIterator();

            return DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::make(reverseIterator);
        }

        /**
         * Gets the iterator of keys.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<TKey> AbstractCache<TKey, TValue>::getKeyIterator() const
        {
            base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeIterator = getIterator();
            return node::KeyIterator<TKey, TValue>::make(keyValueNodeIterator);
        }

        /**
         * Gets the reverse iterator of keys.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<TKey> AbstractCache<TKey, TValue>::getKeyReverseIterator() const
        {
            base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeReverseIterator = getReverseIterator();
            return node::KeyReverseIterator<TKey, TValue>::make(keyValueNodeReverseIterator);
        }

        /**
         * Gets the iterator of values.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<TValue> AbstractCache<TKey, TValue>::getValueIterator() const
        {
            base::IIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeIterator = getIterator();
            return node::ValueIterator<TKey, TValue>::make(keyValueNodeIterator);
        }

        /**
         * Gets the reverse iterator of values.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<TValue> AbstractCache<TKey, TValue>::getValueReverseIterator() const
        {
            base::IReverseIteratorSharedPtr<node::IKeyValueNodeSharedPtr<TKey, TValue>> keyValueNodeReverseIterator = getReverseIterator();
            return node::ValueReverseIterator<TKey, TValue>::make(keyValueNodeReverseIterator);
        }

        /**
         * Processes accessing a current item.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::currentItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node)
        {
            DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& usedList = m_data.usedList();

            usedList.remove(node);
            usedList.addToBack(node);
        }

        /**
         * Processes accessing a new item.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::newItemAccessed(IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node)
        {
            std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& dataLookup = m_data.dataLookup();

            dataLookup.insert(std::make_pair(node->getValue()->getKey(), node));
            m_data.usedList().addToBack(node);
        }

        /**
         * Determines whether the used-list has reached it's maximum capacity.
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::overCapacity() const
        {
            return size() >= m_properties->getCapacity();
        }

        /**
         * Validates that the key exists.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::validateKeyExists(const TKey& key) const
        {
            if (!has(key))
            {
                std::string errorMessage = "The key: " + std::to_string(key) + " is not defined in the cache.";
                throw CacheException(errorMessage);
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
        const std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& AbstractCache<TKey, TValue>::CacheData::dataLookup() const
        {
            return m_dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        std::map<TKey, IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>>>& AbstractCache<TKey, TValue>::CacheData::dataLookup()
        {
            return m_dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        const DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& AbstractCache<TKey, TValue>::CacheData::usedList() const
        {
            return m_usedList;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedList<IKeyValueNodeSharedPtr<TKey, TValue>>& AbstractCache<TKey, TValue>::CacheData::usedList()
        {
            return m_usedList;
        }

        /**
         * Gets the key-value node.
         */
        template <typename TKey, typename TValue>
        IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> AbstractCache<TKey, TValue>::CacheData::getKeyValueNode(const TKey& key) const
        {
            return m_dataLookup.at(key);
        }

        /**
         * Removes the key-value node.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::CacheData::removeKeyValueNode(
            IDoublyLinkedListNodeSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> node)
        {
            m_dataLookup.erase(node->getValue()->getKey());
            m_usedList.remove(node);
        }

        /**
         * Checks whether the key exists.
         */
        template <typename TKey, typename TValue>
        bool AbstractCache<TKey, TValue>::CacheData::hasKey(const TKey& key) const {
            return m_dataLookup.find(key) != m_dataLookup.end();
        }

    }
}

#endif // ABSTRACT_CACHE_H_09bacd72_c96d_47de_b8ed_4933e5722ebc
