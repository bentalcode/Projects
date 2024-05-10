#ifndef I_GUI_COMPONENTS_CONFIGURATION_8ce55209_aae4_4898_a14a_32c5e08d8f01
#define I_GUI_COMPONENTS_CONFIGURATION_8ce55209_aae4_4898_a14a_32c5e08d8f01

#include <string>
#include <memory>

namespace GuiConfiguration {

    /**
     * The IGuiComponentsConfiguration class defines an interface of configuration of GUI components.
     */
    template <typename ConfigurationType>
    class IGuiComponentsConfiguration {
    public:
        IGuiComponentsConfiguration() = default;
        virtual ~IGuiComponentsConfiguration() = default;

        //
        // Defines configuration of a component.
        //
        using ConfigurationTypeSharedPtr = std::shared_ptr<ConfigurationType>;

        /**
         * Adds a configuration of a component by path.
         */
        virtual void AddConfiguration(const std::wstring& path, ConfigurationTypeSharedPtr configuration) = 0;

        /**
         * Gets a configuration of a component by path.
         */
        virtual const ConfigurationTypeSharedPtr GetConfiguration(const std::wstring& path) const = 0;

        /**
         * Checks whether a configuration of a component exists.
         */
        virtual bool ConfigurationExists(const std::wstring& path) const = 0;
    };

    //
    // Defines the Shared Ptr of Gui Components Configuration.
    //
    template <typename ConfigurationType>
    using IGuiComponentsConfigurationSharedPtr = std::shared_ptr<IGuiComponentsConfiguration<ConfigurationType>>;

} // namespace GuiConfiguration

#endif // I_GUI_COMPONENTS_CONFIGURATION_8ce55209_aae4_4898_a14a_32c5e08d8f01
