#ifndef DATA_QUERY_96f5edc5_582a_46b7_bf11_63145819d316
#define DATA_QUERY_96f5edc5_582a_46b7_bf11_63145819d316

#include "IDataQuery.h"
#include "IDataModel.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The DataQuery class implements a data query.
         */
        class DataQuery final : public IDataQuery {
        public:
            /**
             * Creates a Data Query.
             */
            static IDataQuerySharedPtr Make(Model::IDataModel& dataModel);

            /**
             * The DataQuery constructor.
             */
            explicit DataQuery(Model::IDataModel& dataModel);

            /**
             * The DataQuery destructor.
             */
            virtual ~DataQuery();

            /**
             * Queries calls information.
             */
            virtual ICallInformationCollectionSharedPtr QueryCalls() const override;

            /**
             * Queries compositors information.
             */
            virtual ICompositorInformationCollectionSharedPtr QueryCompositors(const std::wstring& callId) const override;

            /**
             * Queries rendering pipelines time interval.
             */
            virtual base::DateTimeIntervalSharedPtr QueryRenderingPipelinesTimeInterval(const std::wstring& callId) const override;

            /**
             * Queries rendering pipelines.
             */
            virtual IRenderingPipelineInformationCollectionSharedPtr
            QueryRenderingPipelines(const base::DateTimeInterval& intervalTime) const override;

        private:
            Model::IDataModel& m_dataModel;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // DATA_QUERY_96f5edc5_582a_46b7_bf11_63145819d316
