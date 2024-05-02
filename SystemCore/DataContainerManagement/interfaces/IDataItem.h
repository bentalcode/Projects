#ifndef I_DATA_ITEM_H_e28ecb41_5cc0_442d_abea_83e0c39246bb
#define I_DATA_ITEM_H_e28ecb41_5cc0_442d_abea_83e0c39246bb

#include "IDataItemValue.h"
#include <list>
#include <memory>

namespace DataContainerManagement {

    /**
     * The IDataItem class defines an interface of a generic data item.
     */
    class IDataItem {
    public:
        /**
         * The IDataItem constructor.
         */
        IDataItem() = default;

        /**
         * The IDataItem destructor.
         */
        virtual ~IDataItem() = default;

        /**
         * Gets the name of a data item.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Gets the value of a data item.
         */
        virtual const IDataItemValueSharedPtr GetValue() const = 0;
    };

    /**
     * Defines an equality operator for Data Items.
     */
    inline bool operator==(const IDataItem& left, const IDataItem& right)
    {
        return left.GetName() == right.GetName() && *(left.GetValue()) == *(right.GetValue());
    }

    /**
     * Defines a not equality operator for Data Items.
     */
    inline bool operator!=(const IDataItem& left, const IDataItem& right)
    {
        return !(left == right);
    }

    //
    // Defines the Shared Ptr of Data Item.
    //
    using IDataItemSharedPtr = std::shared_ptr<IDataItem>;

    //
    // Defines the Shared Ptr of Data Item Collection.
    //
    using DataItemCollection = std::list<IDataItemSharedPtr>;
    using DataItemCollectionSharedPtr = std::shared_ptr<DataItemCollection>;

} // namespace DataContainerManagement

#endif // I_DATA_ITEM_H_e28ecb41_5cc0_442d_abea_83e0c39246bb

