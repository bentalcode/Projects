#ifndef LOG_LEVEL_TRANSFORMER_H_e7da1ce8_073d_4ef4_abaa_a37470eecb93
#define LOG_LEVEL_TRANSFORMER_H_e7da1ce8_073d_4ef4_abaa_a37470eecb93

#include "IValueTransformer.h"
#include "LogLevel.h"

namespace logging {

    /**
     * The LogLevelTransformer class implements a Log Level Transformer.
     */
    class LogLevelTransformer final : public tabular_data::IValueTransformer<LogLevel> {
    public:
        /**
         * Creates a Log Level.
         */
        static tabular_data::IValueTransformerSharedPtr<LogLevel> Make();

        /**
         * The LogLevelTransformer constructor.
         */
        LogLevelTransformer();

        /**
         * The LogLevelTransformer destructor.
         */
        virtual ~LogLevelTransformer();

        /**
         * Transforms a value to a log level.
         */
        virtual LogLevel Transform(const std::wstring& value) const override;

    private:
        static const std::wstring LOG_LEVEL_NONE;
        static const std::wstring LOG_LEVEL_FATAL;
        static const std::wstring LOG_LEVEL_ERROR;
        static const std::wstring LOG_LEVEL_WARNING;
        static const std::wstring LOG_LEVEL_INFORMATIONAL;
        static const std::wstring LOG_LEVEL_VERBOSE;
        static const std::wstring LOG_LEVEL_NOISE;
        static const std::wstring LOG_LEVEL_COMPID;
    };

} // namespace logging

#endif // LOG_LEVEL_TRANSFORMER_H_e7da1ce8_073d_4ef4_abaa_a37470eecb93
