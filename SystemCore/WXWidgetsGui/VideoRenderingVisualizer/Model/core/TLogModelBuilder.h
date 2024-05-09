#ifndef TLOG_MODEL_BUILDER_56272a34_b75a_4569_aa6d_4ba9e5d3412e
#define TLOG_MODEL_BUILDER_56272a34_b75a_4569_aa6d_4ba9e5d3412e

#include "IModelBuilder.h"
#include "EventLog.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        class IDataModel;

        /**
         * The TLogModelBuilder class implements a TLog Model Builder.
         */
        class TLogModelBuilder final : public IModelBuilder {

        public:
            /**
             * Creates a Model Builder.
             */
            static IModelBuilderSharedPtr Make(
                const std::wstring& path,
                IDataModel& model,
                tabular_data::IEventLogSharedPtr eventLog = tabular_data::EventLog::Make());

            /**
             * The TLogModelBuilder constructor.
             */
            TLogModelBuilder(
                const std::wstring& path,
                IDataModel& model,
                tabular_data::IEventLogSharedPtr eventLog);

            /**
             * The TLogModelBuilder destructor.
             */
            virtual ~TLogModelBuilder();

            /**
             * Builds a model.
             */
            virtual void Build() override;

            /**
             * Gets statistics.
             */
            virtual const tlogging::ITLogStatisticsSharedPtr GetStatistics() const override;

        private:
            std::wstring m_path;
            IDataModel& m_model;
            tabular_data::IEventLogSharedPtr m_eventLog;
            tlogging::ITLogStatisticsSharedPtr m_statistics;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // TLOG_MODEL_BUILDER_56272a34_b75a_4569_aa6d_4ba9e5d3412e
