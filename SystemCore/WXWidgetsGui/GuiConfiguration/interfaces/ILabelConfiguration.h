#ifndef I_LABEL_CONFIGURATION_29ae35f6_8864_4aad_b320_3036a1cfb0a3
#define I_LABEL_CONFIGURATION_29ae35f6_8864_4aad_b320_3036a1cfb0a3

#include <memory>
#include <string>

namespace GuiConfiguration {

    /**
     * The ILabelConfiguration class defines an interface of configuration of label.
     */
    class ILabelConfiguration {
    public:
        ILabelConfiguration() = default;
        virtual ~ILabelConfiguration() = default;

        /**
         * Gets text of a label.
         */
        virtual const std::wstring& GetText() const = 0;
    };

    //
    // Defines the Shared Ptr of Label Configuration.
    //
    using ILabelConfigurationSharedPtr = std::shared_ptr<ILabelConfiguration>;

} // namespace GuiConfiguration

#endif // I_LABEL_CONFIGURATION_29ae35f6_8864_4aad_b320_3036a1cfb0a3
