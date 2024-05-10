#ifndef I_FRAME_CONFIGURATION_cd845899_f5cf_4ed8_b8fb_ad012c344a37
#define I_FRAME_CONFIGURATION_cd845899_f5cf_4ed8_b8fb_ad012c344a37

#include <memory>
#include <string>

namespace GuiConfiguration {

    /**
     * The IFrameConfiguration class defines an interface of configuration of frame.
     */
    class IFrameConfiguration {
    public:
        IFrameConfiguration() = default;
        virtual ~IFrameConfiguration() = default;

        /**
         * Gets name of a frame.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Gets status text.
         */
        virtual const std::wstring& GetStatusText() const = 0;
    };

    //
    // Defines the Shared Ptr of Frame Configuration.
    //
    using IFrameConfigurationSharedPtr = std::shared_ptr<IFrameConfiguration>;

} // namespace GuiConfiguration

#endif // I_FRAME_CONFIGURATION_cd845899_f5cf_4ed8_b8fb_ad012c344a37
