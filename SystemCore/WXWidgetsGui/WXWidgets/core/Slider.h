#ifndef SLIDER_5f42c772_ab4d_4905_8108_74a4f99447f1
#define SLIDER_5f42c772_ab4d_4905_8108_74a4f99447f1

#include "AbstractSlider.h"
#include "WXObjectId.h"

namespace wxwidgets {

    /**
     * The Slider class implements a slider.
     */
    class Slider : public AbstractSlider {
    public:
        /**
         * Creates a horizontal slider.
         */
        static ISliderPtr MakeHorizontal(
            wxWindow& parent,
            const wxString& name,
            int dimensionValue = 0,
            int dimensionMinValue = 0,
            int dimensionMaxValue = 100,
            long style = wxSL_HORIZONTAL | wxSL_AUTOTICKS | wxSL_LABELS,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * Creates a vertical slider.
         */
        static ISliderPtr MakeVertical(
            wxWindow& parent,
            const wxString& name,
            int dimensionValue = 0,
            int dimensionMinValue = 0,
            int dimensionMaxValue = 100,
            long style = wxSL_VERTICAL | wxSL_AUTOTICKS | wxSL_LABELS,
            wxWindowID id = WXObjectId::NextId(), const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The Slider constructor.
         */
        Slider(
            wxWindow& parent,
            const wxString& name,
            int dimensionValue = 0,
            int dimensionMinValue = 0,
            int dimensionMaxValue = 100,
            long style = wxSL_HORIZONTAL | wxSL_AUTOTICKS | wxSL_LABELS,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The Slider destructor.
         */
        virtual ~Slider();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;
    };

} // namespace wxwidgets

#endif // SLIDER_5f42c772_ab4d_4905_8108_74a4f99447f1
