#ifndef GUI_COMPONENT_DATA_a1db1430_44f8_47ad_b117_3e68961ad904
#define GUI_COMPONENT_DATA_a1db1430_44f8_47ad_b117_3e68961ad904

#include "IGuiComponentData.h"

namespace wxwidgets {

    /**
     * The GuiComponentData class implements data of a GUI data.
     */
    class GuiComponentData final : public IGuiComponentData {
    public:
        /**
         * Creates a GUI component data.
         */
        static IGuiComponentDataSharedPtr Create(bool showMode = true);

        /**
         * The GuiComponentData constructor.
         */
        explicit GuiComponentData(bool showMode);

        /**
         * The GuiComponentData destructor.
         */
        virtual ~GuiComponentData();

        /**
         * Gets a show mode.
         */
        virtual bool GetShowMode() const override;

    private:
        bool m_showMode;
    };

} // namespace wxwidgets

#endif // GUI_COMPONENT_DATA_a1db1430_44f8_47ad_b117_3e68961ad904
