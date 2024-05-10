#ifndef I_LABELS_CONFIGURATION_0486f9d1_902f_4c50_b978_037e4a6686ff
#define I_LABELS_CONFIGURATION_0486f9d1_902f_4c50_b978_037e4a6686ff

#include "ILabelConfiguration.h"
#include "IGuiComponentsConfiguration.h"

namespace GuiConfiguration {

    /**
     * The ILabelsConfiguration class defines an interface of configuration of labels.
     */
    class ILabelsConfiguration : public IGuiComponentsConfiguration<ILabelConfiguration> {
    public:
        ILabelsConfiguration() = default;
        virtual ~ILabelsConfiguration() = default;
    };

    //
    // Defines the Shared Ptr of Labels Configuration.
    //
    using ILabelsConfigurationSharedPtr = std::shared_ptr<ILabelsConfiguration>;

} // namespace GuiConfiguration

#endif // I_LABELS_CONFIGURATION_0486f9d1_902f_4c50_b978_037e4a6686ff
