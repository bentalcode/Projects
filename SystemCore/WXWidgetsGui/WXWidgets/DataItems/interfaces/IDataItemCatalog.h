#ifndef I_DATA_ITEM_CATALOG_18371bc3_4c52_406f_8977_1b7a89029638
#define I_DATA_ITEM_CATALOG_18371bc3_4c52_406f_8977_1b7a89029638

#include "IDataItems.h"

namespace WXWidgets {

    /**
     * The IDataItemCatalog interface defines a catalog of data items.
     */
    class IDataItemCatalog {
    public:
        IDataItemCatalog() = default;
        virtual ~IDataItemCatalog() = default;

        /**
         * Registers data items.
         */
        virtual void RegisterDataItems(IDataItemsSharedPtr dataItems) = 0;

        /**
         * Unregisters data items.
         */
        virtual void UnregisterDataItems(const std::wstring& name) = 0;

        /**
         * Checks whether data items have been registered.
         */
        virtual bool HasDataItems(const std::wstring& name) const = 0;

        /**
         * Gets data items.
         */
        virtual const IDataItems& GetDataItems(const std::wstring& name) const = 0;

        /**
         * Gets data items.
         */
        template <typename T>
        const T& GetDataItems(const std::wstring& name) const
        {
            const IDataItems& dataItems = GetDataItems(name);
            return dynamic_cast<const T&>(dataItems);
        }
    };

    //
    // Defines the Shared Ptr of Data Item Catalog.
    //
    using IDataItemCatalogSharedPtr = std::shared_ptr<IDataItemCatalog>;

} // namespace WXWidgets

#endif // I_DATA_ITEM_CATALOG_18371bc3_4c52_406f_8977_1b7a89029638
