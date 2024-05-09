#ifndef DATA_REPOSITORY_f78c94fc_1d4d_45f9_9e34_bbaf2950abd0
#define DATA_REPOSITORY_f78c94fc_1d4d_45f9_9e34_bbaf2950abd0

#include "IDataRepository.h"
#include "IEventLog.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The DataRepository class implements a data repository.
         */
        class DataRepository final : public IDataRepository {
        public:
            /**
             * Creates a data repository.
             */
            static IDataRepositorySharedPtr Make(tabular_data::IEventLogSharedPtr eventLog);

            /**
             * The DataRepository constructor.
             */
            explicit DataRepository(tabular_data::IEventLogSharedPtr eventLog);

            /**
             * The DataRepository destructor.
             */
            virtual ~DataRepository();

            /**
             * Reads from a resource directory.
             */
            virtual void ReadFromResourceDirectory(const std::wstring& path);

            /**
             * Reads from resource directories.
             */
            virtual void ReadFromResourceDirectories(const std::vector<std::wstring>& paths);

            /**
             * Gets Data Model.
             */
            virtual const IDataModelSharedPtr GetDataModel() const override;

            /**
             * Gets Data Query.
             */
            virtual const IDataQuerySharedPtr GetDataQuery() const override;

            /**
             * Gets TLog Statistics Collection.
             */
            virtual tlogging::ITLogStatisticsCollectionSharedPtr GetTLogStatisticsCollection() const override;

        private:
            /**
             * Resets model.
             */
            void ResetModel();

            /**
             * Reads from resource.
             */
            void ReadFromResource(const std::wstring& path);

            /**
             * Updates model.
             */
            void UpdateModel(const std::wstring& path);

            /**
             * Initializes rendering pipelines.
             */
            void InitializeRenderingPipelines();

            /**
             * Creates rendering pipelines.
             */
            static IRenderingPipelineInformationSharedPtr CreateRenderingPipeline1();
            static IRenderingPipelineInformationSharedPtr CreateRenderingPipeline2();
            static IRenderingPipelineInformationSharedPtr CreateRenderingPipeline3();
            static IRenderingPipelineInformationSharedPtr CreateRenderingPipeline4();
            static IRenderingPipelineInformationSharedPtr CreateRenderingPipeline5();

            //
            // The Data Model...
            //
            IDataModelSharedPtr m_dataModel;

            //
            // The Event Log...
            //
            tabular_data::IEventLogSharedPtr m_eventLog;

            //
            // The Tlog Statistics Collection...
            //
            tlogging::ITLogStatisticsCollectionSharedPtr m_tlogsStatistics;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // DATA_REPOSITORY_f78c94fc_1d4d_45f9_9e34_bbaf2950abd0

