#ifndef MENU_ITEM_CONFIGURATION_1442bd82_9e91_42a7_b322_ee065b0cd6af
#define MENU_ITEM_CONFIGURATION_1442bd82_9e91_42a7_b322_ee065b0cd6af

#include "IMenuItemConfiguration.h"

namespace GuiConfiguration {

    /**
     * The MenuItemConfiguration class implements configuration of a menu item.
     */
    class MenuItemConfiguration final : public IMenuItemConfiguration {
    public:
        /**
         * Creates a menu item configuration.
         */
        static IMenuItemConfigurationSharedPtr Make(
            int m_id,
            const std::wstring& text,
            const std::wstring& help,
            wxItemKind kind);

        /**
         * The MenuItemConfiguration constructor.
         */
        MenuItemConfiguration(
            int id,
            const std::wstring& text,
            const std::wstring& help,
            wxItemKind kind);

        /**
         * The MenuItemConfiguration destructor.
         */
        virtual ~MenuItemConfiguration();

        /**
         * Gets an item id.
         */
        virtual int GetItemId() const override;

        /**
         * Gets text.
         */
        virtual const std::wstring& GetText() const override;

        /**
         * Gets help.
         */
        virtual const std::wstring& GetHelp() const override;

        /**
         * Gets kind.
         */
        virtual wxItemKind GetKind() const override;

    private:
        int m_id;
        std::wstring m_text;
        std::wstring m_help;
        wxItemKind m_kind;
    };

} // namespace GuiConfiguration

#endif // MENU_ITEM_CONFIGURATION_1442bd82_9e91_42a7_b322_ee065b0cd6af
