#ifndef I_DIALOGS_CONFIGURATION_edc42008_2fef_4372_816c_1ac7af11667d
#define I_DIALOGS_CONFIGURATION_edc42008_2fef_4372_816c_1ac7af11667d

#include "IGuiComponentsConfiguration.h"
#include "IDialogConfiguration.h"

namespace GuiConfiguration {

    /**
     * The IDialogsConfiguration class defines an interface of configuration of dialogs.
     */
    class IDialogsConfiguration : public IGuiComponentsConfiguration<IDialogConfiguration> {
    public:
        IDialogsConfiguration() = default;
        virtual ~IDialogsConfiguration() = default;
    };

    //
    // Defines the Shared Ptr of Dialogs Configuration.
    //
    using IDialogsConfigurationSharedPtr = std::shared_ptr<IDialogsConfiguration>;

} // namespace GuiConfiguration

#endif // I_DIALOGS_CONFIGURATION_edc42008_2fef_4372_816c_1ac7af11667d
