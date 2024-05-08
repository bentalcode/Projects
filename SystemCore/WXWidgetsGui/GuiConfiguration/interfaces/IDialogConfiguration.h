#ifndef I_DIALOG_CONFIGURATION_3e02d374_8240_47be_a2c3_03751d60fe0f
#define I_DIALOG_CONFIGURATION_3e02d374_8240_47be_a2c3_03751d60fe0f

#include <memory>
#include <string>

namespace GuiConfiguration {

    /**
     * The IDialogConfiguration class defines an interface of configuration of dialog.
     */
    class IDialogConfiguration {
    public:
        IDialogConfiguration() = default;
        virtual ~IDialogConfiguration() = default;

        /**
         * Gets title of a dialog.
         */
        virtual const std::wstring& GetTitle() const = 0;
    };

    //
    // Defines the Shared Ptr of Dialog Configuration.
    //
    using IDialogConfigurationSharedPtr = std::shared_ptr<IDialogConfiguration>;

}  // namespace GuiConfiguration

#endif // I_DIALOG_CONFIGURATION_3e02d374_8240_47be_a2c3_03751d60fe0f
