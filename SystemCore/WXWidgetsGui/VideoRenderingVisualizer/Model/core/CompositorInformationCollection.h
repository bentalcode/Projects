#ifndef COMPOSITOR_INFORMATION_COLLECTION_39be5542_24cb_41ff_8062_941190c729a2
#define COMPOSITOR_INFORMATION_COLLECTION_39be5542_24cb_41ff_8062_941190c729a2

#include "ICompositorInformationCollection.h"
#include "IModelCollection.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The CompositorInformationCollection class implements a collection of compositors information.
         */
        class CompositorInformationCollection final : public ICompositorInformationCollection {
        public:
            /**
             * Creates a collection of call information.
             */
            static ICompositorInformationCollectionSharedPtr Make();

            /**
             * The CompositorInformationCollection constructor.
             */
            CompositorInformationCollection();

            /**
             * The CompositorInformationCollection destructor.
             */
            virtual ~CompositorInformationCollection();

            /**
             * Adds an item.
             */
            virtual void AddItem(const ICompositorInformationSharedPtr item) override;

            /**
             * Removes an item.
             * Returns true in case item has been removed, and false in case item has not been found.
             */
            virtual bool RemoveItem(const std::wstring& id) override;

            /**
             * Gets a specific item.
             */
            virtual const ICompositorInformationSharedPtr GetItem(const std::wstring& id) const override;

            /**
             * Checks whether a specific item exists.
             */
            virtual bool HasItem(const std::wstring& id) const override;

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
            virtual base::IIteratorSharedPtr<ICompositorInformationSharedPtr> GetIterator() const override;

        private:
            IModelCollectionSharedPtr<std::wstring, ICompositorInformation> m_impl;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // COMPOSITOR_INFORMATION_COLLECTION_39be5542_24cb_41ff_8062_941190c729a2
