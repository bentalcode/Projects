#ifndef I_CONFIGURATION_ITEM_CATALOG_20137e61_c7e8_45e3_ad31_52fc2553230d
#define I_CONFIGURATION_ITEM_CATALOG_20137e61_c7e8_45e3_ad31_52fc2553230d

#include "IConfigurationItems.h"
#include <string>

namespace GuiConfiguration {

    /**
     * The IConfigurationItemCatalog interface defines a catalog of configuration items.
     */
    class IConfigurationItemCatalog {
    public:
        IConfigurationItemCatalog() = default;
        virtual ~IConfigurationItemCatalog() = default;

        /**
         * Registers configuration items.
         */
        virtual void RegisterConfigurationItems(IConfigurationItemsSharedPtr configurationItems) = 0;

        /**
         * Unregisters configuration items.
         */
        virtual void UnregisterConfigurationItems(const std::wstring& name) = 0;

        /**
         * Checks whether configuration items have been registered.
         */
        virtual bool HasConfigurationItems(const std::wstring& name) const = 0;

        /**
         * Gets configuration items.
         */
        virtual const IConfigurationItems& GetConfigurationItems(const std::wstring& name) const = 0;

        /**
         * Gets configuration items.
         */
        template <typename T>
        const T& GetConfigurationItems(const std::wstring& name) const
        {
            const IConfigurationItems& configurationItems = GetConfigurationItems(name);
            return dynamic_cast<const T&>(configurationItems);
        }
    };

    //
    // Defines the Shared Ptr of Configuration Item Catalog.
    //
    using IConfigurationItemCatalogSharedPtr = std::shared_ptr<IConfigurationItemCatalog>;

} // namespace GuiConfiguration

#endif // I_CONFIGURATION_ITEM_CATALOG_20137e61_c7e8_45e3_ad31_52fc2553230d
