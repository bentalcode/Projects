#ifndef RENDERING_PIPELINE_INFORMATION_COLLECTION_0bf6f3a0_1c2e_4e86_9384_aae40dd13d2e
#define RENDERING_PIPELINE_INFORMATION_COLLECTION_0bf6f3a0_1c2e_4e86_9384_aae40dd13d2e

#include "IModelCollection.h"
#include "IRenderingPipelineInformationCollection.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The RenderingPipelineInformationCollection class implements a collection
         * of rendering pipelines information.
         */
        class RenderingPipelineInformationCollection final : public IRenderingPipelineInformationCollection {
        public:
            /**
             * Creates a collection of call information.
             */
            static IRenderingPipelineInformationCollectionSharedPtr Make();

            /**
             * The RenderingPipelineInformationCollection constructor.
             */
            RenderingPipelineInformationCollection();

            /**
             * The RenderingPipelineInformationCollection destructor.
             */
            virtual ~RenderingPipelineInformationCollection();

            /**
             * Adds an item.
             */
            virtual void AddItem(const IRenderingPipelineInformationSharedPtr item) override;

            /**
             * Removes an item.
             * Returns true in case item has been removed, and false in case item has not been found.
             */
            virtual bool RemoveItem(const std::wstring& id) override;

            /**
             * Gets a specific item.
             */
            virtual const IRenderingPipelineInformationSharedPtr GetItem(const std::wstring& id) const override;

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
            virtual base::IIteratorSharedPtr<IRenderingPipelineInformationSharedPtr> GetIterator() const override;

        private:
            IModelCollectionSharedPtr<std::wstring, IRenderingPipelineInformation> m_impl;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // RENDERING_PIPELINE_INFORMATION_COLLECTION_0bf6f3a0_1c2e_4e86_9384_aae40dd13d2e
