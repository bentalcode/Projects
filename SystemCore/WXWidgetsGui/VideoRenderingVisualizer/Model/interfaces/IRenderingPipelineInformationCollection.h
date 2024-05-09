#ifndef I_RENDERING_PIPELINE_INFORMATION_COLLECTION_2aa6e8fd_1720_48e5_bed9_6852d63748c2
#define I_RENDERING_PIPELINE_INFORMATION_COLLECTION_2aa6e8fd_1720_48e5_bed9_6852d63748c2

#include "IModelCollection.h"
#include "IRenderingPipelineInformation.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The IRenderingPipelineInformationCollection interface defines a collection of rendering pipeline information.
         */
        class IRenderingPipelineInformationCollection : public IModelCollection<std::wstring, IRenderingPipelineInformation> {
        public:
            IRenderingPipelineInformationCollection() = default;
            virtual ~IRenderingPipelineInformationCollection() = default;
        };

        /**
         * Defines the Shared Ptr of Rendering Pipeline Information Collection.
         */
        using IRenderingPipelineInformationCollectionSharedPtr = std::shared_ptr<IRenderingPipelineInformationCollection>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_RENDERING_PIPELINE_INFORMATION_COLLECTION_2aa6e8fd_1720_48e5_bed9_6852d63748c2
