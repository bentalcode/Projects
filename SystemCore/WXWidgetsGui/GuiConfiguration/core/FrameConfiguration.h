#ifndef FRAME_CONFIGURATION_1d4fa695_b409_4862_99e0_aeb8b20034c8
#define FRAME_CONFIGURATION_1d4fa695_b409_4862_99e0_aeb8b20034c8

#include "IFrameConfiguration.h"

namespace GuiConfiguration {

    /**
     * The FrameConfiguration class implements configuration of frame.
     */
    class FrameConfiguration final : public IFrameConfiguration {
    public:
        /**
         * Creates frame configuration.
         */
        static IFrameConfigurationSharedPtr Make(
            const std::wstring& name,
            const std::wstring& statusText);

        /**
         * The FrameConfiguration constructor.
         */
        FrameConfiguration(
            const std::wstring& name,
            const std::wstring& statusText);

        /**
         * The FrameConfiguration destructor.
         */
        virtual ~FrameConfiguration();

        /**
         * Gets name of a frame.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets status text.
         */
        virtual const std::wstring& GetStatusText() const override;

    private:
        std::wstring m_name;
        std::wstring m_statusText;
    };

} // namespace GuiConfiguration

#endif // FRAME_CONFIGURATION_1d4fa695_b409_4862_99e0_aeb8b20034c8
