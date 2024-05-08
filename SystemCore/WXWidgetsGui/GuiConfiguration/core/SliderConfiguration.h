#ifndef SLIDER_CONFIGURATION_97c1f56f_1f81_471b_b6eb_88f18ed5ad42
#define SLIDER_CONFIGURATION_97c1f56f_1f81_471b_b6eb_88f18ed5ad42

#include "ISliderConfiguration.h"

namespace GuiConfiguration {

    /**
     * The SliderConfiguration class implements configuration of slider.
     */
    class SliderConfiguration final : public ISliderConfiguration {
    public:
        /**
         * Creates slider configuration.
         */
        static ISliderConfigurationSharedPtr Make(
            unsigned int minNumberOfUnits,
            unsigned int maxNumberOfUnits);

        /**
         * The SliderConfiguration constructor.
         */
        SliderConfiguration(
            unsigned int minNumberOfUnits,
            unsigned int maxNumberOfUnits);

        /**
         * The SliderConfiguration destructor.
         */
        virtual ~SliderConfiguration();

        /**
         * Gets minimum number of units.
         */
        virtual unsigned int GetMinNumberOfUnits() const override;

        /**
         * Gets maximum number of units.
         */
        virtual unsigned int GetMaxNumberOfUnits() const override;

    private:
        unsigned int m_minNumberOfUnits;
        unsigned int m_maxNumberOfUnits;
    };

}  // namespace GuiConfiguration

#endif // SLIDER_CONFIGURATION_97c1f56f_1f81_471b_b6eb_88f18ed5ad42
