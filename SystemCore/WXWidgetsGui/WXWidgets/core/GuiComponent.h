#ifndef GUI_COMPONENT_dcdfcda4_ebd8_4fbd_a739_bb13f99abf2c
#define GUI_COMPONENT_dcdfcda4_ebd8_4fbd_a739_bb13f99abf2c

#include "AbstractGuiComponent.h"

namespace WXWidgets {

    /**
     * The GuiComponent class implements a GUI component.
     */
    class GuiComponent : public AbstractGuiComponent {
    public:
        /**
         * The GuiComponent constructor.
         */
        GuiComponent();

        /**
         * The GuiComponent destructor.
         */
        virtual ~GuiComponent();

        /**
         * Initializes a GUI component.
         */
        void Initialize(
            const std::wstring& name,
            wxEvtHandler& eventHandler,
            IGuiControllerSharedPtr guiController);
    };

}  // namespace WXWidgets

#endif // GUI_COMPONENT_dcdfcda4_ebd8_4fbd_a739_bb13f99abf2c
