#ifndef I_DATA_QUERY_e9736de7_87a3_487a_ba4c_7ff5163d6532
#define I_DATA_QUERY_e9736de7_87a3_487a_ba4c_7ff5163d6532

#include "ICallInformationCollection.h"
#include "ICompositorInformationCollection.h"
#include "IRenderingPipelineInformationCollection.h"
#include "DateTimeInterval.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        class ICallInformation;

        /**
         * The IDataQuery interface defines a data query.
         */
        class IDataQuery {
        public:
            IDataQuery() = default;
            virtual ~IDataQuery() = default;

            /**
             * Queries calls information.
             */
            virtual ICallInformationCollectionSharedPtr QueryCalls() const = 0;

            /**
             * Queries compositors information.
             */
            virtual ICompositorInformationCollectionSharedPtr QueryCompositors(const std::wstring& callId) const = 0;

            /**
             * Queries rendering pipelines time interval.
             */
            virtual base::DateTimeIntervalSharedPtr QueryRenderingPipelinesTimeInterval(const std::wstring& callId = L"") const = 0;

            /**
             * Queries rendering pipelines.
             */
            virtual Model::IRenderingPipelineInformationCollectionSharedPtr
            QueryRenderingPipelines(const base::DateTimeInterval& intervalTime) const = 0;
        };

        /**
         * Defines the Shared Ptr of Data Query.
         */
        using IDataQuerySharedPtr = std::shared_ptr<IDataQuery>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_DATA_QUERY_e9736de7_87a3_487a_ba4c_7ff5163d6532
