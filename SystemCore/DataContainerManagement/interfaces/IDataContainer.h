#ifndef I_DATA_CONTAINER_H_f1020e5d_ea77_4fcc_84d9_6bcb0514fd7a
#define I_DATA_CONTAINER_H_f1020e5d_ea77_4fcc_84d9_6bcb0514fd7a

#include "IDataItem.h"
#include <string>
#include <assert.h>

namespace DataContainerManagement {

    class IDataCatalog;

    /**
     * The IDataContainer class defines an interface of a data container.
     */
    class IDataContainer {
    public:
        IDataContainer() = default;
        virtual ~IDataContainer() = default;

        /**
         * Gets name of a data container.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Gets a data catalog.
         */
        virtual IDataCatalog& GetCatalog() = 0;

        /**
         * Gets a data catalog.
         */
        virtual const IDataCatalog& GetCatalog() const = 0;

        /**
         * Sets a data item.
         */
        virtual void SetDataItem(IDataItemSharedPtr dataItem) = 0;

        /**
         * Gets a data item by it's name.
         */
        virtual IDataItem& GetDataItem(const std::wstring& name) = 0;

        /**
         * Gets a data item by it's name.
         */
        virtual const IDataItem& GetDataItem(const std::wstring& name) const = 0;

        /**
         * Checks whether a data item exists.
         */
        virtual bool HasDataItem(const std::wstring& name) const = 0;

        /**
         * Gets a collection of data items.
         */
        virtual DataItemCollectionSharedPtr GetDataItems() const = 0;
    };

    /**
     * Defines an equality operator for Notification Data.
     */
    inline bool operator==(const IDataContainer& left, const IDataContainer& right)
    {
        const DataItemCollectionSharedPtr leftDataItems = left.GetDataItems();
        const DataItemCollectionSharedPtr rightDataItems = right.GetDataItems();

        if (leftDataItems->size() != rightDataItems->size()) {
            return false;
        }

        DataItemCollection::const_iterator leftIterator = leftDataItems->begin();
        DataItemCollection::const_iterator rightIterator = rightDataItems->begin();

        while (leftIterator != leftDataItems->end() && rightIterator != rightDataItems->end()) {
            const IDataItemSharedPtr& leftDataItem = *leftIterator;
            const IDataItemSharedPtr& rightDataItem = *rightIterator;

            if (*leftDataItem != *rightDataItem) {
                return false;
            }

            ++leftIterator;
            ++rightIterator;
        }

        assert(leftIterator == leftDataItems->end() && rightIterator == rightDataItems->end());

        return true;
    }

    /**
     * Defines a not equality operator for Notification Data.
     */
    inline bool operator!=(const IDataContainer& left, const IDataContainer& right)
    {
        return !(left == right);
    }

    //
    // Defines the Shared Ptr of Data Container.
    //
    using IDataContainerSharedPtr = std::shared_ptr<IDataContainer>;

} // namespace DataContainerManagement

#endif // I_DATA_CONTAINER_H_f1020e5d_ea77_4fcc_84d9_6bcb0514fd7a

