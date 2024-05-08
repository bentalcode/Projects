#ifndef I_CONFIGURATION_ITEMS_3bba1549_96b3_4e44_af78_4e086c03a2eb
#define I_CONFIGURATION_ITEMS_3bba1549_96b3_4e44_af78_4e086c03a2eb

#include <string>
#include <memory>

namespace GuiConfiguration {

    /**
     * The IConfigurationItems interface defines configuration items.
     */
    class IConfigurationItems {
    public:
        IConfigurationItems() = default;
        virtual ~IConfigurationItems() = default;

        /**
         * Gets category name of data items.
         */
        virtual const std::wstring& GetName() const = 0;
    };

    //
    // Defines the Shared Ptr of Configuration Items.
    //
    using IConfigurationItemsSharedPtr = std::shared_ptr<IConfigurationItems>;

}  // namespace GuiConfiguration

#endif // I_CONFIGURATION_ITEMS_3bba1549_96b3_4e44_af78_4e086c03a2eb
