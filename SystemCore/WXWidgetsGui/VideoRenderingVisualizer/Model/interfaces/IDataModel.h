#ifndef I_DATA_MODEL_303b39fa_9e64_4b0c_b26f_99cfd4ec9b78
#define I_DATA_MODEL_303b39fa_9e64_4b0c_b26f_99cfd4ec9b78

#include "ICallInformationCollection.h"
#include "ICompositorInformationCollection.h"
#include "IRenderingPipelineInformationCollection.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The IDataModel interface defines a data model of Video Rendering Visualizer.
         */
        class IDataModel {
        public:
            IDataModel() = default;
            virtual ~IDataModel() = default;

            /**
             * Gets calls information.
             */
            virtual ICallInformationCollectionSharedPtr GetCalls() = 0;
            virtual const ICallInformationCollectionSharedPtr GetCalls() const = 0;

            /**
             * Gets compositors information.
             */
            virtual ICompositorInformationCollectionSharedPtr GetCompositors() = 0;
            virtual const ICompositorInformationCollectionSharedPtr GetCompositors() const = 0;

            /**
             * Gets rendering pipelines information.
             */
            virtual IRenderingPipelineInformationCollectionSharedPtr GetRenderingPipelines() = 0;
            virtual const IRenderingPipelineInformationCollectionSharedPtr GetRenderingPipelines() const = 0;
        };

        /**
         * Defines the Shared Ptr of Data Model.
         */
        using IDataModelSharedPtr = std::shared_ptr<IDataModel>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_DATA_MODEL_303b39fa_9e64_4b0c_b26f_99cfd4ec9b78
