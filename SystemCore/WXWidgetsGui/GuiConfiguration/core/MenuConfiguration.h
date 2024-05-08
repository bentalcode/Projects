#ifndef MENU_CONFIGURATION_60e28c2d_a819_4b96_955a_7cc74fc18628
#define MENU_CONFIGURATION_60e28c2d_a819_4b96_955a_7cc74fc18628

#include "IMenuConfiguration.h"

namespace GuiConfiguration {

    /**
     * The MenuConfiguration class implements configuration of menu.
     */
    class MenuConfiguration final : public IMenuConfiguration {
    public:
        /**
         * Creates menu configuration.
         */
        static IMenuConfigurationSharedPtr Make(const std::wstring& name);

        /**
         * The MenuConfiguration constructor.
         */
        MenuConfiguration(const std::wstring& name);

        /**
         * The MenuConfiguration destructor.
         */
        virtual ~MenuConfiguration();

        /**
         * Gets name of a menu.
         */
        virtual const std::wstring& GetName() const override;

    private:
        std::wstring m_name;
    };

}  // namespace GuiConfiguration

#endif // MENU_CONFIGURATION_60e28c2d_a819_4b96_955a_7cc74fc18628
