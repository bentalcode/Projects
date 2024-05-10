#ifndef CONFIGURATION_ITEM_CATALOG_73934096_6eab_4ba7_af33_067440e1b60f
#define CONFIGURATION_ITEM_CATALOG_73934096_6eab_4ba7_af33_067440e1b60f

#include "IConfigurationItemCatalog.h"
#include "ILoggers.h"
#include <mutex>
#include <map>

namespace GuiConfiguration {

    /**
     * The ConfigurationItemCatalog class implements a configuration item catalog.
     */
    class ConfigurationItemCatalog final : public IConfigurationItemCatalog {
    public:
        /**
         * Gets an instance of configuration item catalog.
         */
        static IConfigurationItemCatalogSharedPtr GetInstance();

        /**
         * Creates a configuration item catalog.
         */
        static IConfigurationItemCatalogSharedPtr Make();

        /**
         * The ConfigurationItemCatalog constructor.
         */
        ConfigurationItemCatalog();

        /**
         * The ConfigurationItemCatalog destructor.
         */
        virtual ~ConfigurationItemCatalog();

        /**
         * Registers configuration items.
         */
        virtual void RegisterConfigurationItems(IConfigurationItemsSharedPtr configurationItems) override;

        /**
         * Unregisters configuration items.
         */
        virtual void UnregisterConfigurationItems(const std::wstring& name) override;

        /**
         * Checks whether configuration items have been registered.
         */
        virtual bool HasConfigurationItems(const std::wstring& name) const override;

        /**
         * Gets configuration items.
         */
        virtual const IConfigurationItems& GetConfigurationItems(const std::wstring& name) const override;

    private:
        /**
         * Finds configuration items by name.
         */
        const IConfigurationItemsSharedPtr FindConfigurationItems(const std::wstring& name) const;

        //
        // The Singletone instance and mutex...
        //
        static IConfigurationItemCatalogSharedPtr INSTANCE;
        static std::mutex MUTEX;

        //
        // Defines a mutex of this class...
        //
        mutable std::mutex m_mutex;

        //
        // Defines a configuration items map...
        //
        using ConfigurationItemsMap = std::map<std::wstring, IConfigurationItemsSharedPtr>;
        ConfigurationItemsMap m_configurationItems;

        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace GuiConfiguration

#endif // CONFIGURATION_ITEM_CATALOG_73934096_6eab_4ba7_af33_067440e1b60f
