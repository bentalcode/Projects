#ifndef I_GUI_COMPONENT_DATA_c892531c_1231_4287_89ba_a72be31d1d25
#define I_GUI_COMPONENT_DATA_c892531c_1231_4287_89ba_a72be31d1d25

#include <memory>

namespace WXWidgets {

    /**
     * The IGuiComponentData interface defines data of a GUI component.
     */
    class IGuiComponentData {
    public:
        IGuiComponentData() = default;
        virtual ~IGuiComponentData() = default;

        /**
         * Gets a show mode.
         */
        virtual bool GetShowMode() const = 0;
    };

    /**
     * Defines the Shared Ptr of GUI Component Data.
     */
    using IGuiComponentDataSharedPtr = std::shared_ptr<IGuiComponentData>;

}  // namespace WXWidgets

#endif // I_GUI_COMPONENT_DATA_c892531c_1231_4287_89ba_a72be31d1d25
