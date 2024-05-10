#ifndef I_MENU_CONFIGURATION_c0b7b2f9_3b06_4449_bd3c_00da4617c5cd
#define I_MENU_CONFIGURATION_c0b7b2f9_3b06_4449_bd3c_00da4617c5cd

#include <memory>
#include <string>

namespace GuiConfiguration {

    /**
     * The IMenuConfiguration class defines an interface of configuration of a menu.
     */
    class IMenuConfiguration {
    public:
        IMenuConfiguration() = default;
        virtual ~IMenuConfiguration() = default;

        /**
         * Gets name of a menu.
         */
        virtual const std::wstring& GetName() const = 0;
    };

    //
    // Defines the Shared Ptr of Menu Configuration.
    //
    using IMenuConfigurationSharedPtr = std::shared_ptr<IMenuConfiguration>;

} // namespace GuiConfiguration

#endif // I_MENU_CONFIGURATION_c0b7b2f9_3b06_4449_bd3c_00da4617c5cd
