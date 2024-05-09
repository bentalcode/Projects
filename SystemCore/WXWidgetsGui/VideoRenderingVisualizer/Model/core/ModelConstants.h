#ifndef MODEL_CONSTANTS_649cc680_59cd_43ad_8696_7aedc57517f5
#define MODEL_CONSTANTS_649cc680_59cd_43ad_8696_7aedc57517f5

#include <string>

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The ModelConstants class implements constants of Model.
         */
        class ModelConstants final {
        public:
            ModelConstants() = delete;
            ~ModelConstants() = delete;


            static const std::wstring IN_PROGRESS;
            static const std::wstring CALL_ID_PROPERTY;

            static const std::wstring COMPOSITOR_ID_PROPERTY;
            static const std::wstring COMPOSITOR_SHORT_ID_PROPERTY;
            static const std::wstring COMPOSITOR_TYPE_PROPERTY;
            static const std::wstring COMPOSITION_TYPE_PROPERTY;
            static const std::wstring COMPOSITOR_REDNDERER_PROPERTY;
            static const std::wstring COMPOSITOR_STATE_PROPERTY;
            static const std::wstring COMPOSITOR_FPS_PROPERTY;
            static const std::wstring COMPOSITOR_HAS_FALLBACK_PROPERTY;

            static const std::wstring START_TIME_PROPERTY;
            static const std::wstring DURATION_PROPERTY;
            static const std::wstring DURATION_TIME_UNIT;
            static const std::wstring DATE_TIME_FORMAT;
            static const std::streamsize DURATION_PRECISION;

            static const std::wstring YES_PROPERTY_VALUE;
            static const std::wstring NO_PROPERTY_VALUE;
            static const std::wstring DELIMITER;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // MODEL_CONSTANTS_649cc680_59cd_43ad_8696_7aedc57517f5
