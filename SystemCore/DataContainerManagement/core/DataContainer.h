#ifndef DATA_CONTAINER_H_223a093e_ae5c_44f6_9067_e9d81f683a56
#define DATA_CONTAINER_H_223a093e_ae5c_44f6_9067_e9d81f683a56

#include "IDataContainer.h"
#include "IDataCatalog.h"
#include <map>
#include <mutex>
#include "ILogger.h"

namespace DataContainerManagement {

    /**
     * The DataContainer class implements a data container.
     */
    class DataContainer final : public IDataContainer {
    public:
        /**
         * Makes a data container.
         */
        static IDataContainerSharedPtr Make(const std::wstring& name);

        /**
         * The DataContainer constructor.
         */
        explicit DataContainer(const std::wstring& name);

        /**
         * The DataContainer destructor.
         */
        virtual ~DataContainer();

        /**
         * Sets name of a data container.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets a data catalog.
         */
        virtual IDataCatalog& GetCatalog() override;

        /**
         * Gets a data catalog.
         */
        virtual const IDataCatalog& GetCatalog() const override;

        /**
         * Sets a data item.
         */
        virtual void SetDataItem(IDataItemSharedPtr dataItem) override;

        /**
         * Gets a data item by name.
         */
        virtual IDataItem& GetDataItem(const std::wstring& name) override;

        /**
         * Gets a data item by it's name.
         */
        virtual const IDataItem& GetDataItem(const std::wstring& name) const override;

        /**
         * Checks whether a data item exists.
         */
        virtual bool HasDataItem(const std::wstring& name) const override;

        /**
         * Gets a collection of data items.
         */
        virtual DataItemCollectionSharedPtr GetDataItems() const override;

    private:
        /**
         * Finds a data item by name.
         */
        IDataItemSharedPtr FindDataItem(const std::wstring& name);

        /**
         * Finds a data item by name.
         */
        const IDataItemSharedPtr FindDataItem(const std::wstring& name) const;

        /**
         * Verifies data item in catalog.
         */
        void VerifyDataItemInCatalog(const std::wstring& name) const;

        /**
         * Gets a static logger.
         */
        static logging::ILoggerSharedPtr GetSLogger();

        //
        // The mutex of this class...
        //
        mutable std::mutex m_mutex;

        //
        // The name of data container...
        //
        std::wstring m_name;

        //
        // The data catalog...
        //
        IDataCatalogSharedPtr m_dataCatalog;

        //
        // The data items...
        //
        using DataItemMap = std::map<std::wstring, IDataItemSharedPtr>;
        DataItemMap m_dataItems;
    };

} // namespace DataContainerManagement

#endif // DATA_CONTAINER_H_223a093e_ae5c_44f6_9067_e9d81f683a56
