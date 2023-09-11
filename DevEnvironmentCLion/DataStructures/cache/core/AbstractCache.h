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
            explicit AbstractCache(ICachePropertiesPtr properties);

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
            virtual base::IIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> getIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> getReverseIterator() const override;

            /**
             * Gets the iterator of keys.
             */
            virtual base::IIteratorPtr<TKey> getKeyIterator() const override;

            /**
             * Gets the reverse iterator of keys.
             */
            virtual base::IReverseIteratorPtr<TKey> getKeyReverseIterator() const override;

            /**
             * Gets the iterator of values.
             */
            virtual base::IIteratorPtr<TValue> getValueIterator() const override;

            /**
             * Gets the reverse iterator of values.
             */
            virtual base::IReverseIteratorPtr<TValue> getValueReverseIterator() const override;

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
                const std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>>& dataLookup() const;
                std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>>& dataLookup();

                /**
                 * Gets the data lookup.
                 */
                const DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>>& usedList() const;
                DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>>& usedList();

                /**
                 * Gets the key-value node.
                 */
                IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> getKeyValueNode(const TKey& key) const;

                /**
                 * Removes the key-value node.
                 */
                void removeKeyValueNode(IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> node);

                /**
                 * Checks whether the key exists.
                 */
                bool hasKey(const TKey& key) const;

            private:
                std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> m_dataLookup;
                DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>> m_usedList;
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
            void currentItemAccessed(IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> node);

            /**
             * Processes accessing a new item.
             */
            void newItemAccessed(IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> node);

            /**
             * Determines whether the used-list has reached it's maximum capacity.
             */
            bool overCapacity() const;

            /**
             * Validates a key exists.
             */
            void validateKeyExists(const TKey& key) const;

            ICachePropertiesPtr m_properties;
            CacheData m_data;
        };

        /**
         * The AbstractCache constructor.
         */
        template <typename TKey, typename TValue>
        AbstractCache<TKey, TValue>::AbstractCache(ICachePropertiesPtr properties) :
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
                IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> currNode = m_data.getKeyValueNode(key);
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

                node::IKeyValueNodePtr<TKey, TValue> keyValueNode =
                    node::KeyValueNode<TKey, TValue>::make(key, value);

                IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> currNode =
                    DoublyLinkedListNode<node::IKeyValueNodePtr<TKey, TValue>>::make(keyValueNode);

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
            IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> currNode = m_data.getKeyValueNode(key);
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

            IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> node = m_data.getKeyValueNode(key);
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
        base::IIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> AbstractCache<TKey, TValue>::getIterator() const
        {
            base::IIteratorPtr<IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> iterator =
                m_data.usedList().getIterator();

            return DoublyLinkedListKeyValueNodeIterator<TKey, TValue>::make(iterator);
        }

        /**
         * Gets the reverse iterator.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> AbstractCache<TKey, TValue>::getReverseIterator() const
        {
            base::IReverseIteratorPtr<IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>> reverseIterator =
                m_data.usedList().getReverseIterator();

            return DoublyLinkedListKeyValueNodeReverseIterator<TKey, TValue>::make(reverseIterator);
        }

        /**
         * Gets the iterator of keys.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<TKey> AbstractCache<TKey, TValue>::getKeyIterator() const
        {
            base::IIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> keyValueNodeIterator = getIterator();
            return node::KeyIterator<TKey, TValue>::make(keyValueNodeIterator);
        }

        /**
         * Gets the reverse iterator of keys.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorPtr<TKey> AbstractCache<TKey, TValue>::getKeyReverseIterator() const
        {
            base::IReverseIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> keyValueNodeReverseIterator = getReverseIterator();
            return node::KeyReverseIterator<TKey, TValue>::make(keyValueNodeReverseIterator);
        }

        /**
         * Gets the iterator of values.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<TValue> AbstractCache<TKey, TValue>::getValueIterator() const
        {
            base::IIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> keyValueNodeIterator = getIterator();
            return node::ValueIterator<TKey, TValue>::make(keyValueNodeIterator);
        }

        /**
         * Gets the reverse iterator of values.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorPtr<TValue> AbstractCache<TKey, TValue>::getValueReverseIterator() const
        {
            base::IReverseIteratorPtr<node::IKeyValueNodePtr<TKey, TValue>> keyValueNodeReverseIterator = getReverseIterator();
            return node::ValueReverseIterator<TKey, TValue>::make(keyValueNodeReverseIterator);
        }

        /**
         * Processes accessing a current item.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::currentItemAccessed(IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> node)
        {
            DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>>& usedList = m_data.usedList();

            usedList.remove(node);
            usedList.addToBack(node);
        }

        /**
         * Processes accessing a new item.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::newItemAccessed(IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> node)
        {
            std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>>& dataLookup = m_data.dataLookup();

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
        const std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>>& AbstractCache<TKey, TValue>::CacheData::dataLookup() const
        {
            return m_dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        std::map<TKey, IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>>>& AbstractCache<TKey, TValue>::CacheData::dataLookup()
        {
            return m_dataLookup;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        const DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>>& AbstractCache<TKey, TValue>::CacheData::usedList() const
        {
            return m_usedList;
        }

        /**
         * Gets the data lookup.
         */
        template <typename TKey, typename TValue>
        DoublyLinkedList<IKeyValueNodePtr<TKey, TValue>>& AbstractCache<TKey, TValue>::CacheData::usedList()
        {
            return m_usedList;
        }

        /**
         * Gets the key-value node.
         */
        template <typename TKey, typename TValue>
        IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> AbstractCache<TKey, TValue>::CacheData::getKeyValueNode(const TKey& key) const
        {
            return m_dataLookup.at(key);
        }

        /**
         * Removes the key-value node.
         */
        template <typename TKey, typename TValue>
        void AbstractCache<TKey, TValue>::CacheData::removeKeyValueNode(
            IDoublyLinkedListNodePtr<IKeyValueNodePtr<TKey, TValue>> node)
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
