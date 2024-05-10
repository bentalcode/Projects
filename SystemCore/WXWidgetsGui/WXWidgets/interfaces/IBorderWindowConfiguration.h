#ifndef I_BORDER_WINDOW_CONFIGURATION_cbfbed9b_f5c7_4e46_b1ec_ca331e3c49ec
#define I_BORDER_WINDOW_CONFIGURATION_cbfbed9b_f5c7_4e46_b1ec_ca331e3c49ec

#include <string>
#include <memory>

namespace WXWidgets {

    /**
     * The IBorderWindowConfiguration interface defines a configuration of a border window.
     */
    class IBorderWindowConfiguration {
    public:
        IBorderWindowConfiguration() = default;
        virtual ~IBorderWindowConfiguration() = default;

        /**
         * Gets a label of a window.
         */
        virtual const std::wstring& GetLabel() const = 0;

        /**
         * Gets a proportion of a window.
         */
        virtual int GetProportion() const = 0;

        /**
         * Gets a flag of a window.
         */
        virtual int GetFlag() const = 0;
    };

    /**
     * Defines the Shared Ptr of Border Window Configuration.
     */
    using IBorderWindowConfigurationSharedPtr = std::shared_ptr<IBorderWindowConfiguration>;

} // namespace WXWidgets

#endif // I_BORDER_WINDOW_CONFIGURATION_cbfbed9b_f5c7_4e46_b1ec_ca331e3c49ec
