#ifndef I_DATA_ITEMS_a1fbe1c8_4b91_4ee3_acb1_c9e56c711799
#define I_DATA_ITEMS_a1fbe1c8_4b91_4ee3_acb1_c9e56c711799

#include <string>
#include <memory>

namespace wxwidgets {

    /**
     * The IDataItems interface defines data items.
     */
    class IDataItems {
    public:
        IDataItems() = default;
        virtual ~IDataItems() = default;

        /**
         * Gets category name of data items.
         */
        virtual const std::wstring& GetName() const = 0;
    };

    //
    // Defines the Shared Ptr of Data Items.
    //
    using IDataItemsSharedPtr = std::shared_ptr<IDataItems>;

} // namespace wxwidgets

#endif // I_DATA_ITEMS_a1fbe1c8_4b91_4ee3_acb1_c9e56c711799
