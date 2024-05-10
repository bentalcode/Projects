#ifndef ABSTRACT_SPLITTER_0b2e3be7_796e_428c_8650_1f4a5215cdd3
#define ABSTRACT_SPLITTER_0b2e3be7_796e_428c_8650_1f4a5215cdd3

#include "ISlider.h"
#include "Window.h"
#include "IBinaryComparator.h"
#include "wx/slider.h"

namespace wxwidgets {

    /**
     * The AbstractSlider class implements an abstract base class of a slider.
     */
    class AbstractSlider : public ISlider, public Window, public wxSlider {
    public:
        //
        // Defines a SharedPtr of On Slider Updated Functor...
        //
        using IOnSliderUpdatedFunctor = std::function<void(int)>;
        using IOnSliderUpdatedFunctorSharedPtr = std::shared_ptr<IOnSliderUpdatedFunctor>;

        /**
         * The AbstractSlider constructor.
         */
        AbstractSlider(
            wxWindow& parent,
            const wxString& name,
            int dimensionValue,
            int dimensionMinValue,
            int dimensionMaxValue,
            long style,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            const wxValidator& validator,
            double precision = PRECISION);

        /**
         * The AbstractSlider destructor.
         */
        virtual ~AbstractSlider();

        /**
         * Initializes a GUI component.
         * The precision is defined at range: [0-100]
         */
        void Initialize(
            const IOnSliderUpdatedFunctorSharedPtr onSliderUpdatedFunctor,
            IGuiControllerSharedPtr guiController);

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Sets scroll precision.
         */
        virtual void SetScrollPrecision(double precision) override;

        /**
         * Gets value of a dimension.
         */
        virtual int GetDimensionValue() const override;

        /**
         * Sets value of a dimension.
         */
        virtual void SetDimensionValue(int value) override;

        /**
         * Gets value of a min dimension.
         */
        virtual int GetDimensionMinValue() const override;

        /**
         * Sets min value of a dimension.
         */
        virtual void SetDimensionMinValue(int value) override;

        /**
         * Gets value of a max dimension.
         */
        virtual int GetDimensionMaxValue() const override;

        /**
         * Sets max value of a dimension.
         */
        virtual void SetDimensionMaxValue(int value) override;

        /**
         * The On Slider Updated callback.
         */
        virtual void OnSliderUpdated(int value) override;

        /**
         * Updates data container (dimension value).
         */
        static void UpdateDataContainerDimensionValue(
            DataContainerManagement::IDataContainer& data,
            int value);

        /**
         * Updates data container (dimension min value).
         */
        static void UpdateDataContainerDimensionMinValue(
            DataContainerManagement::IDataContainer& data,
            int value);

        /**
         * Updates data container (dimension max value).
         */
        static void UpdateDataContainerDimensionMaxValue(
            DataContainerManagement::IDataContainer& data,
            int value);

    protected:
        /**
         * Updates data from data container.
         * Returns true in case data has been updated.
         */
        virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

        /**
         * Updates component.
         */
        virtual void Update() override;

    private:
        static const double PRECISION;

        /**
         * Resets component.
         */
        void Reset();

        /**
         * Validates precision.
         */
        static void ValidatePrecision(double precision);

        /**
         * The internal On Slider Updated callback.
         */
        void InternalOnSliderUpdated(wxScrollEvent& event);

        //
        // The configured functors...
        //
        IOnSliderUpdatedFunctorSharedPtr m_onSliderUpdatedFunctor;

        //
        // The current data...
        //
        double m_precision;
        int m_dimensionValue;
        int m_dimensionMinValue;
        int m_dimensionMaxValue;

        //
        // The almost comparator of integer dimension values...
        //
        base::IBinaryComparatorSharedPtr<int> m_dimensionValueComparator;
    };

} // namespace wxwidgets

#endif // ABSTRACT_SPLITTER_0b2e3be7_796e_428c_8650_1f4a5215cdd3
