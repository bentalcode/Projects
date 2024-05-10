#ifndef I_GUI_COMPONENT_INFORMATION_11f7d027_ea09_44a4_a6ea_54c43034f2fa
#define I_GUI_COMPONENT_INFORMATION_11f7d027_ea09_44a4_a6ea_54c43034f2fa

#include <memory>

namespace wxwidgets {

    class IGuiComponent;
    class IGuiComponentData;

    /**
     * The IGuiComponentInformation interface defines an information of a GUI component.
     */
    class IGuiComponentInformation {
    public:
        IGuiComponentInformation() = default;
        virtual ~IGuiComponentInformation() = default;

        /**
         * Gets a GUI component.
         */
        virtual IGuiComponent& GetComponent() = 0;

        /**
         * Gets a GUI data.
         */
        virtual IGuiComponentData& GetData() = 0;
    };

    /**
     * Defines the Shared Ptr of GUI component.
     */
    using IGuiComponentInformationSharedPtr = std::shared_ptr<IGuiComponentInformation>;

} // namespace wxwidgets

#endif // I_GUI_COMPONENT_INFORMATION_11f7d027_ea09_44a4_a6ea_54c43034f2fa
