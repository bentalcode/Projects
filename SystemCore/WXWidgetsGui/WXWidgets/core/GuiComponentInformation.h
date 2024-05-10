#ifndef GUI_COMPONENT_INFORMATION_78df22a5_6db8_41d5_a3a9_b0b76058d0e4
#define GUI_COMPONENT_INFORMATION_78df22a5_6db8_41d5_a3a9_b0b76058d0e4

#include "IGuiComponentInformation.h"
#include "IGuiComponent.h"
#include "IGuiComponentData.h"

namespace wxwidgets {

    /**
     * The GuiComponentInformation class implements an information of a GUI component.
     */
    class GuiComponentInformation final : public IGuiComponentInformation {
    public:
        /**
         * Creates a GUI component.
         */
        static IGuiComponentInformationSharedPtr Create(
            IGuiComponentSharedPtr component,
            IGuiComponentDataSharedPtr data);

        /**
         * The GuiComponentInformation constructor.
         */
        GuiComponentInformation(
            IGuiComponentSharedPtr component,
            IGuiComponentDataSharedPtr data);

        /**
         * The GuiComponentInformation destructor.
         */
        virtual ~GuiComponentInformation();

        /**
         * Gets a GUI component.
         */
        virtual IGuiComponent& GetComponent() override;

        /**
         * Gets a GUI data.
         */
        virtual IGuiComponentData& GetData() override;

    private:
        IGuiComponentSharedPtr m_component;
        IGuiComponentDataSharedPtr m_data;
    };

} // namespace wxwidgets

#endif // GUI_COMPONENT_INFORMATION_78df22a5_6db8_41d5_a3a9_b0b76058d0e4
