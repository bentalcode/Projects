#ifndef I_DATA_CATALOG_H_a07e8344_9a86_4223_8ec1_9db9182b3270
#define I_DATA_CATALOG_H_a07e8344_9a86_4223_8ec1_9db9182b3270

#include <string>
#include <memory>

namespace DataContainerManagement {

    /**
     * The IDataCatalog class defines an interface of a data catalog.
     */
    class IDataCatalog {
    public:
        /**
         * The IDataCatalog constructor.
         */
        IDataCatalog() = default;

        /**
         * The IDataCatalog destructor.
         */
        virtual ~IDataCatalog() = default;

        /**
         * Registers data item.
         */
        virtual void RegisterDataItem(const std::wstring& name) = 0;

        /**
         * Unregisters data item.
         */
        virtual void UnregisterDataItem(const std::wstring& name) = 0;

        /**
         * Checks whether a data item exists.
         */
        virtual bool HasDataItem(const std::wstring& name) const = 0;
    };

    //
    // Defines the Shared Ptr of Data Catalog.
    //
    using IDataCatalogSharedPtr = std::shared_ptr<IDataCatalog>;

} // namespace DataContainerManagement

#endif // I_DATA_CATALOG_H_a07e8344_9a86_4223_8ec1_9db9182b3270
