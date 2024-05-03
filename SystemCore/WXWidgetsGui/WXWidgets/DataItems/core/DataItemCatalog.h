#ifndef DATA_ITEM_CATALOG_bec52654_e62c_4fca_ac78_fe4ee7242c2a
#define DATA_ITEM_CATALOG_bec52654_e62c_4fca_ac78_fe4ee7242c2a

#include "IDataItemCatalog.h"
#include "ILoggers.h"
#include <mutex>
#include <map>

namespace WXWidgets {

    /**
     * The DataItemCatalog class implements a data item catalog.
     */
    class DataItemCatalog final : public IDataItemCatalog {
    public:
        /**
         * Gets an instance of data item catalog.
         */
        static IDataItemCatalogSharedPtr GetInstance();

        /**
         * Creates a data item catalog.
         */
        static IDataItemCatalogSharedPtr Make();

        /**
         * The DataItemCatalog constructor.
         */
        DataItemCatalog();

        /**
         * The DataItemCatalog destructor.
         */
        virtual ~DataItemCatalog();

        /**
         * Registers data items.
         */
        virtual void RegisterDataItems(IDataItemsSharedPtr dataItems) override;

        /**
         * Unregisters data items.
         */
        virtual void UnregisterDataItems(const std::wstring& name) override;

        /**
         * Checks whether data items have been registered.
         */
        virtual bool HasDataItems(const std::wstring& name) const override;

        /**
         * Gets data items.
         */
        virtual const IDataItems& GetDataItems(const std::wstring& name) const override;

    private:
        /**
         * Finds data items by name.
         */
        const IDataItemsSharedPtr FindDataItems(const std::wstring& name) const;

        //
        // The Singletone instance and mutex...
        //
        static IDataItemCatalogSharedPtr INSTANCE;
        static std::mutex MUTEX;

        //
        // Defines a data items map...
        //
        using DataItemsMap = std::map<std::wstring, IDataItemsSharedPtr>;
        DataItemsMap m_dataItems;
        mutable std::mutex m_mutex;

        logging::ILoggersSharedPtr m_loggers;
    };

}  // namespace WXWidgets

#endif // DATA_ITEM_CATALOG_bec52654_e62c_4fca_ac78_fe4ee7242c2a
