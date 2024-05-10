#ifndef LABELE_CONFIGURATION_31315e65_f36e_44af_b061_5fa7488cdeeb
#define LABELE_CONFIGURATION_31315e65_f36e_44af_b061_5fa7488cdeeb

#include "ILabelConfiguration.h"

namespace GuiConfiguration {

    /**
     * The LabelConfiguration class implements configuration of label.
     */
    class LabelConfiguration final : public ILabelConfiguration {
    public:
        /**
         * Creates label configuration.
         */
        static ILabelConfigurationSharedPtr Make(const std::wstring& text);

        /**
         * The LabelConfiguration constructor.
         */
        explicit LabelConfiguration(const std::wstring& text);

        /**
         * The LabelConfiguration destructor.
         */
        virtual ~LabelConfiguration();

        /**
         * Gets text of a label.
         */
        virtual const std::wstring& GetText() const override;

    private:
        std::wstring m_text;
    };

} // namespace GuiConfiguration

#endif // LABELE_CONFIGURATION_31315e65_f36e_44af_b061_5fa7488cdeeb
