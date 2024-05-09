#ifndef I_MODEL_COLLECTION_0150c6c2_8985_4982_89ee_6c410f2ac57b
#define I_MODEL_COLLECTION_0150c6c2_8985_4982_89ee_6c410f2ac57b

#include "ISizableCollection.h"
#include <list>

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The ICollection interface defines a collection of items in the model.
         */
        template <typename IdType, typename ItemType>
        class IModelCollection : public base::ISizableCollection<std::shared_ptr<ItemType>> {
        public:
            IModelCollection() = default;
            virtual ~IModelCollection() = default;

            //
            // Defines items of the collection.
            //
            using ItemTypeSharedPtr = std::shared_ptr<ItemType>;
            using Items = std::list<ItemTypeSharedPtr>;

            /**
             * Adds an item.
             */
            virtual void AddItem(const ItemTypeSharedPtr item) = 0;

            /**
             * Removes an item.
             * Returns true in case item has been removed, and false in case item has not been found.
             */
            virtual bool RemoveItem(const IdType& id) = 0;

            /**
             * Gets a specific item.
             */
            virtual const ItemTypeSharedPtr GetItem(const IdType& id) const = 0;

            /**
             * Checks whether a specific item exists.
             */
            virtual bool HasItem(const IdType& id) const = 0;
        };

        /**
         * Defines the Shared Ptr of Model Collection.
         */
        template <typename IdType, typename ItemType>
        using IModelCollectionSharedPtr = std::shared_ptr<IModelCollection<IdType, ItemType>>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_MODEL_COLLECTION_0150c6c2_8985_4982_89ee_6c410f2ac57b
