#ifndef DATA_MODEL_c6a52385_755f_4a81_b613_7e651d0b4b0e
#define DATA_MODEL_c6a52385_755f_4a81_b613_7e651d0b4b0e

#include "IDataModel.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The DataModel class implements a data model of Video Rendering Visualizer.
         */
        class DataModel final : public IDataModel {
        public:
            /**
             * Creates a Data Model.
             */
            static IDataModelSharedPtr Make();

            /**
             * The DataModel constructor.
             */
            DataModel();

            /**
             * The DataModel destructor.
             */
            virtual ~DataModel();

            /**
             * Gets calls information.
             */
            virtual ICallInformationCollectionSharedPtr GetCalls() override;
            virtual const ICallInformationCollectionSharedPtr GetCalls() const override;

            /**
             * Gets compositors information.
             */
            virtual ICompositorInformationCollectionSharedPtr GetCompositors() override;
            virtual const ICompositorInformationCollectionSharedPtr GetCompositors() const override;

            /**
             * Gets rendering pipelines information.
             */
            virtual IRenderingPipelineInformationCollectionSharedPtr GetRenderingPipelines() override;
            virtual const IRenderingPipelineInformationCollectionSharedPtr GetRenderingPipelines() const override;

        private:
            ICallInformationCollectionSharedPtr m_callsInformation;
            ICompositorInformationCollectionSharedPtr m_compositorsInformation;
            IRenderingPipelineInformationCollectionSharedPtr m_renderingPipelinesInformation;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // DATA_MODEL_c6a52385_755f_4a81_b613_7e651d0b4b0e
