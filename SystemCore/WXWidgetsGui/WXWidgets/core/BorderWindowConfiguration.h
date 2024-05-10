#ifndef BORDER_WINDOW_CONFIGURATION_bf04510a_8974_477b_9739_a3b7571efb2a
#define BORDER_WINDOW_CONFIGURATION_bf04510a_8974_477b_9739_a3b7571efb2a

#include "IBorderWindowConfiguration.h"
#include "wx\defs.h"

namespace WXWidgets {

    /**
     * The BorderWindowConfiguration class implements a configuration of a border window.
     */
    class BorderWindowConfiguration final : public IBorderWindowConfiguration {
    public:
        /**
         * Creates a configuration of a border window.
         */
        static IBorderWindowConfigurationSharedPtr Make(
            const std::wstring& label,
            int proportion = 1,
            int flag = wxEXPAND);

        /**
         * Copies a configuration of a border window.
         */
        static IBorderWindowConfigurationSharedPtr Copy(const IBorderWindowConfiguration& configuration);

        /**
         * The BorderWindowConfiguration constructor.
         */
        BorderWindowConfiguration(
            const std::wstring& label,
            int proportion,
            int flag);

        /**
         * The BorderWindowConfiguration destructor.
         */
        virtual ~BorderWindowConfiguration();

        /**
         * Gets a label of a window.
         */
        virtual const std::wstring& GetLabel() const override;

        /**
         * Gets a proportion of a window.
         */
        virtual int GetProportion() const override;

        /**
         * Gets a flag of a window.
         */
        virtual int GetFlag() const override;

    private:
        std::wstring m_label;
        int m_proportion;
        int m_flag;
    };

} // namespace WXWidgets

#endif // BORDER_WINDOW_CONFIGURATION_bf04510a_8974_477b_9739_a3b7571efb2a
