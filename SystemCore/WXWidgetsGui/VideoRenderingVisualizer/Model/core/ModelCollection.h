#ifndef MODEL_COLLECTION_573951fe_2471_41b6_aff4_ffe5383fc245
#define MODEL_COLLECTION_573951fe_2471_41b6_aff4_ffe5383fc245

#include "IModelCollection.h"
#include "ListIterator.h"
#include "SmartPointers.h"
#include "Loggers.h"
#include <mutex>
#include <map>

#include "VideoRenderingVisualizerModelException.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The ModelCollection class implements an abstract collection base class for collections in the model.
         */
        template <typename IdType, typename ItemType>
        class ModelCollection : public IModelCollection<IdType, ItemType> {
        public:
            /**
             * The ModelCollection constructor.
             */
            ModelCollection();

            /**
             * The ModelCollection destructor.
             */
            virtual ~ModelCollection();

            /**
             * Adds an item.
             */
            virtual void AddItem(const typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr item) override;

            /**
             * Removes an item.
             * Returns true in case item has been removed, and false in case item has not been found.
             */
            virtual bool RemoveItem(const IdType& id) override;

            /**
             * Gets a specific item.
             */
            virtual const typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr GetItem(const IdType& id) const override;

            /**
             * Checks whether a specific item exists.
             */
            virtual bool HasItem(const IdType& id) const override;

            /**
             * Gets size of a collection.
             */
            virtual size_t Size() const override;

            /**
             * Checks whether a collection is empty.
             */
            virtual bool Empty() const override;

            /**
             * Gets an iterator.
             */
            virtual base::IIteratorSharedPtr<typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr> GetIterator() const override;

        private:
            /**
             * The MatchingItemPredicate inner class defines a predicate of a matching item.
             */
            class MatchingItemPredicate final {
            public:
                /**
                 * The MatchingItemPredicate constructor.
                 */
                explicit MatchingItemPredicate(const IdType& id) :
                    m_id(id)
                {
                }

                /**
                 * The predicate logic.
                 */
                bool operator()(const typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr item) const
                {
                    return item->GetId() == m_id;
                }

            private:
                IdType m_id;
            };

            /**
             * Finds a specific item.
             */
            const typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr FindItem(const IdType& id) const;

            //
            // The mutex of this class...
            //
            mutable std::mutex m_mutex;

            //
            // The list of items...
            //
            typename IModelCollection<IdType, ItemType>::Items m_items;

            /**
             * Gets a static logger.
             */
            static logging::ILoggerSharedPtr GetSLogger();

            //
            // The mappings between an id to item...
            //
            using IdToItemMap = std::map<IdType, typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr>;
            IdToItemMap m_idToItemMap;
        };

        /**
         * The ModelCollection constructor.
         */
        template <typename IdType, typename ItemType>
        ModelCollection<IdType, ItemType>::ModelCollection()
        {
        }

        /**
         * The ModelCollection destructor.
         */
        template <typename IdType, typename ItemType>
        ModelCollection<IdType, ItemType>::~ModelCollection()
        {
        }

        /**
         * Adds an item.
         */
        template <typename IdType, typename ItemType>
        void ModelCollection<IdType, ItemType>::AddItem(const typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr item)
        {
            base::SmartPointers::Validate<ItemType>(item);

            const IdType& id = item->GetId();

            std::lock_guard<std::mutex> lock(m_mutex);

            if (FindItem(id) != nullptr) {
                long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"Data Collection already has an item with id: " << id
                    << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();

                LOG_ERROR(GetSLogger(), errorMessage);
                throw VideoRenderingVisualizerModelException(errorCode, errorMessage);
            }

            m_items.push_back(item);
            m_idToItemMap.insert(std::make_pair(id, item));
        }

        /**
         * Removes an item.
         * Returns true in case item has been removed, and false in case item has not been found.
         */
        template <typename IdType, typename ItemType>
        bool ModelCollection<IdType, ItemType>::RemoveItem(const IdType& id)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr item = FindItem(id);

            if (item == nullptr) {
                return false;
            }

            m_items.remove_if(MatchingItemPredicate(id));
            m_idToItemMap.erase(id);

            return true;
        }

        /**
         * Gets a specific item.
         */
        template <typename IdType, typename ItemType>
        const typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr
        ModelCollection<IdType, ItemType>::GetItem(const IdType& id) const
        {
            typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr item = nullptr;

            {
                std::lock_guard<std::mutex> lock(m_mutex);

                item = FindItem(id);
            }

            if (item == nullptr) {
                long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"Data Collection does not contain an item with id: " << id
                    << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();

                LOG_ERROR(GetSLogger(), errorMessage);
                throw VideoRenderingVisualizerModelException(errorCode, errorMessage);
            }

            return item;
        }

        /**
         * Checks whether a specific item exists.
         */
        template <typename IdType, typename ItemType>
        bool ModelCollection<IdType, ItemType>::HasItem(const IdType& id) const
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr item = FindItem(id);
            return item != nullptr;
        }

        /**
         * Gets size of a collection.
         */
        template <typename IdType, typename ItemType>
        size_t ModelCollection<IdType, ItemType>::Size() const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_items.size();
        }

        /**
         * Checks whether a collection is empty.
         */
        template <typename IdType, typename ItemType>
        bool ModelCollection<IdType, ItemType>::Empty() const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_items.empty();
        }

        /**
         * Gets an iterator.
         */
        template <typename IdType, typename ItemType>
        base::IIteratorSharedPtr<typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr>
        ModelCollection<IdType, ItemType>::GetIterator() const
        {
            return base::ListIterator<std::shared_ptr<ItemType>>::Make(m_items);
        }

        /**
         * Finds a specific item.
         */
        template <typename IdType, typename ItemType>
        const typename IModelCollection<IdType, ItemType>::ItemTypeSharedPtr
        ModelCollection<IdType, ItemType>::FindItem(const IdType& id) const
        {
            typename IdToItemMap::const_iterator itemIterator = m_idToItemMap.find(id);
            return itemIterator != m_idToItemMap.end() ? itemIterator->second : nullptr;
        }

        /**
         * Gets a static logger.
         */
        template <typename IdType, typename ItemType>
        logging::ILoggerSharedPtr ModelCollection<IdType, ItemType>::GetSLogger()
        {
            static logging::ILoggersSharedPtr loggers =
                logging::Loggers::Make(typeid(ModelCollection<IdType, ItemType>));

            return loggers->GetLogger();
        }

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // MODEL_COLLECTION_573951fe_2471_41b6_aff4_ffe5383fc245
