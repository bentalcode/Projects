#ifndef DIALOG_CONFIGURATION_6c3bb7f3_33a5_44f9_96d7_986d6df994cf
#define DIALOG_CONFIGURATION_6c3bb7f3_33a5_44f9_96d7_986d6df994cf

#include "IDialogConfiguration.h"

namespace GuiConfiguration {

    /**
     * The DialogConfiguration class implements configuration of dialog.
     */
    class DialogConfiguration final : public IDialogConfiguration {
    public:
        /**
         * Creates dialog configuration.
         */
        static IDialogConfigurationSharedPtr Make(const std::wstring& title);

        /**
         * The DialogConfiguration constructor.
         */
        explicit DialogConfiguration(const std::wstring& title);

        /**
         * The DialogConfiguration destructor.
         */
        virtual ~DialogConfiguration();

        /**
         * Gets title of a dialog.
         */
        virtual const std::wstring& GetTitle() const override;

    private:
        std::wstring m_title;
    };

} // namespace GuiConfiguration

#endif // DIALOG_CONFIGURATION_6c3bb7f3_33a5_44f9_96d7_986d6df994cf
