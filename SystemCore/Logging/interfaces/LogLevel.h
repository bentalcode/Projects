#ifndef I_LOG_LEVEL_H_722b7ebf_e052_401f_8785_b2243e2f5128
#define I_LOG_LEVEL_H_722b7ebf_e052_401f_8785_b2243e2f5128

#include <string>

namespace logging {

    /**
     * The LogLevel class defines various levels of logging.
     */
    enum class LogLevel {
        NONE,
        FATAL_LEVEL,
	    ERROR_LEVEL,
        WARNING_LEVEL,
        INFORMATIONAL_LEVEL,
        VERBOSE_LEVEL,
        NOISE_LEVEL,
        COMPID_LEVEL
    };

    /**
     * Translates a LogLevel to a String.
     */
    inline static std::wstring LogLevelToString(LogLevel level)
    {
        std::wstring result;

        if (level == LogLevel::NONE) {
            return L"None";
        } else if (level == LogLevel::FATAL_LEVEL) {
            return L"Fatal";
        } else if (level == LogLevel::ERROR_LEVEL) {
            return L"Error";
        } else if (level == LogLevel::WARNING_LEVEL) {
            return L"Warning";
        } else if (level == LogLevel::INFORMATIONAL_LEVEL) {
            return L"Informational";
        } else if (level == LogLevel::VERBOSE_LEVEL) {
            return L"Verbose";
        } else if (level == LogLevel::NOISE_LEVEL) {
            return L"Noise";
        } else if (level == LogLevel::COMPID_LEVEL) {
            return L"ComponentId";
        }

        return result;
    }

    /**
     * Translates a LogLevel to an Internal String.
     */
    inline static std::wstring LogLevelToInternalString(LogLevel level)
    {
        std::wstring result;

        if (level == LogLevel::NONE) {
            return L"TL_NONE";
        } else if (level == LogLevel::FATAL_LEVEL) {
            return L"TL_FATAL";
        } else if (level == LogLevel::ERROR_LEVEL) {
            return L"TL_ERROR";
        } else if (level == LogLevel::WARNING_LEVEL) {
            return L"TL_WARN";
        } else if (level == LogLevel::INFORMATIONAL_LEVEL) {
            return L"TL_INFO";
        } else if (level == LogLevel::VERBOSE_LEVEL) {
            return L"TL_VERBOSE";
        } else if (level == LogLevel::NOISE_LEVEL) {
            return L"TL_NOISE";
        } else if (level == LogLevel::COMPID_LEVEL) {
            return L"TL_COMPID";
        }

        return result;
    }

} // namespace logging

#endif // I_LOG_LEVEL_H_722b7ebf_e052_401f_8785_b2243e2f5128
