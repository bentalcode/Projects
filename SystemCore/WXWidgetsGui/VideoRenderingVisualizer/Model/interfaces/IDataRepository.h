#ifndef I_DATA_REPOSITORY_14ac5719_8fd0_497d_a74e_895dee24c168
#define I_DATA_REPOSITORY_14ac5719_8fd0_497d_a74e_895dee24c168

#include "IDataModel.h"
#include "IDataQuery.h"
#include "ITLogStatisticsCollection.h"
#include <vector>

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The IDataRepository interface defines a data repository of Video Rendering Visuzlizer.
         */
        class IDataRepository {
        public:
            IDataRepository() = default;
            virtual ~IDataRepository() = default;

            /**
             * Reads from a resource directory.
             */
            virtual void ReadFromResourceDirectory(const std::wstring& path) = 0;

            /**
             * Reads from resource directories.
             */
            virtual void ReadFromResourceDirectories(const std::vector<std::wstring>& paths) = 0;

            /**
             * Gets Data Model.
             */
            virtual const IDataModelSharedPtr GetDataModel() const = 0;

            /**
             * Gets Data Query.
             */
            virtual const IDataQuerySharedPtr GetDataQuery() const = 0;

            /**
             * Gets TLog Statistics Collection.
             */
            virtual tlogging::ITLogStatisticsCollectionSharedPtr GetTLogStatisticsCollection() const = 0;
        };

        /**
         * Defines the Shared Ptr of Data Repository.
         */
        using IDataRepositorySharedPtr = std::shared_ptr<IDataRepository>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_DATA_REPOSITORY_14ac5719_8fd0_497d_a74e_895dee24c168
