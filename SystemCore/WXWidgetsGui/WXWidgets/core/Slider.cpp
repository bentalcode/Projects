#include "Slider.h"

using namespace wxwidgets;

namespace SliderFunctors {

/**
 * The OnSliderUpdatedFunctor class implements an On Slider Updated functor.
 */
class OnSliderUpdatedFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnSliderUpdatedFunctor(Slider& slider) : 
        m_slider(slider) 
    {
    }

    /**
     * The functor logic.
     */
    void operator()(int value) 
    {
        m_slider.OnSliderUpdated(value); 
    }

private:
    Slider& m_slider;
};

} // namespace SliderFunctors

/**
 * Creates a horizontal slider.
 */
ISliderPtr Slider::MakeHorizontal(
    wxWindow& parent, 
    const wxString& name, 
    int dimensionValue, 
    int dimensionMinValue,
    int dimensionMaxValue,
    long style, 
    wxWindowID id,
    const wxPoint& position, 
    const wxSize& size,
    const wxValidator& validator)
{
    return ISliderPtr::Make(
        new Slider(
            parent, 
            name, 
            dimensionValue, 
            dimensionMinValue, 
            dimensionMaxValue,
            style,
            id, 
            position,
            size, 
            validator));
}

/**
 * Creates a vertical slider.
 */
ISliderPtr Slider::MakeVertical(
    wxWindow& parent, 
    const wxString& name, 
    int dimensionValue, 
    int dimensionMinValue,
    int dimensionMaxValue, 
    long style, 
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    const wxValidator& validator)
{
    return ISliderPtr::Make(
        new Slider(
            parent, 
            name, 
            dimensionValue, 
            dimensionMinValue, 
            dimensionMaxValue, 
            style, 
            id,
            position, 
            size, 
            validator));
}

/**
 * The Slider constructor.
 */
Slider::Slider(
    wxWindow& parent, 
    const wxString& name, 
    int dimensionValue, 
    int dimensionMinValue, 
    int dimensionMaxValue, 
    long style, 
    wxWindowID id,
    const wxPoint& position, 
    const wxSize& size, 
    const wxValidator& validator) : 
        AbstractSlider(
            parent,
            name,
            dimensionValue,
            dimensionMinValue,
            dimensionMaxValue,
            style,
            id,
            position,
            size,
            validator)
{
}

/**
 * The Slider destructor.
 */
Slider::~Slider() 
{
}

/**
 * Initializes a GUI component.
 */
void Slider::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize a slider...
    //
    Slider::IOnSliderUpdatedFunctorSharedPtr onSliderUpdatedFunctor =
        std::make_shared<Slider::IOnSliderUpdatedFunctor>(SliderFunctors::OnSliderUpdatedFunctor{ *this });

    AbstractSlider::Initialize(
        onSliderUpdatedFunctor, 
        guiController);
}
