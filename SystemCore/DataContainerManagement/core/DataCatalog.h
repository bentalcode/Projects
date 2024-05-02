#ifndef DATA_CATALOG_H_3eabfda9_c66f_4611_a5db_4da4d6096608
#define DATA_CATALOG_H_3eabfda9_c66f_4611_a5db_4da4d6096608

#include "IDataCatalog.h"
#include <mutex>
#include <set>
#include "ILogger.h"

namespace DataContainerManagement {

    /**
     * The DataCatalog class implements a data catalog.
     */
    class DataCatalog final : public IDataCatalog {
    public:
        /**
         * Creates data catalog.
         */
        static IDataCatalogSharedPtr Make();

        /**
         * The DataCatalog constructor.
         */
        DataCatalog();

        /**
         * The DataCatalog destructor.
         */
        virtual ~DataCatalog();

        /**
         * Registers data item.
         */
        virtual void RegisterDataItem(const std::wstring& name) override;

        /**
         * Unregisters data item.
         */
        virtual void UnregisterDataItem(const std::wstring& name) override;

        /**
         * Checks whether a data item exists.
         */
        virtual bool HasDataItem(const std::wstring& name) const override;

    private:
        //
        // The mutex of this class...
        //
        mutable std::mutex m_mutex;

        /**
         * Checks whether a data item exists.
         */
        bool Exists(const std::wstring& name) const;

        /**
         * Gets a static logger.
         */
        static logging::ILoggerSharedPtr GetSLogger();

        //
        // Defines a Data Item Name Set...
        //
        using DataItemSet = std::set<std::wstring>;
        DataItemSet m_dataItems;
    };

} // namespace DataContainerManagement

#endif // DATA_CATALOG_H_3eabfda9_c66f_4611_a5db_4da4d6096608
