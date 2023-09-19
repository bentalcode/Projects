#ifndef TIME_UTILS_H_ec231f76_73b4_4db2_a54b_3de1ff1f60ef
#define TIME_UTILS_H_ec231f76_73b4_4db2_a54b_3de1ff1f60ef

#include <string>
#include <chrono>

namespace base {

    /**
     * The TimeUtils class implements generic time utilities.
     */
    class TimeUtils final {
    public:
        TimeUtils() = delete;
        ~TimeUtils() = delete;

        /**
         * Parses a string with format.
         */
        static std::wstring ParseString(
            const std::wstring& str,
            const std::wstring& format);

        /**
         * Parses a string with format to a time point.
         */
        static std::chrono::system_clock::time_point ParseStringToTimePoint(
            const std::wstring str,
            const std::wstring& format);

        /**
         * Converts a struct tm time to a string.
         */
        static std::wstring TmToString(
            const std::tm& time,
            const std::wstring& format);

        /**
         * Gets a string representation of a duration.
         */
        static std::wstring DurationToString(size_t milliseconds);

        /**
         * Parses a duration from string.
         */
        static size_t ParseDuration(const std::wstring& str);

        /**
         * Parses a struct tm time from a string.
         */
        static void ParseTm(
            const std::wstring& str,
            const std::wstring& format,
            std::tm& time);

        /**
         * Converts a struct tm time to time_t.
         */
        static time_t TmToTimeT(std::tm& time);

        /**
         * Converts a time_t to a struct tm.
         */
        static void TimeTToTm(time_t timeT, std::tm& time);

    private:
        static const size_t BUFFER_SIZE;
        static const std::wstring::value_type TIME_SEPARATOR;

        /**
         * Copies a struct tm.
         */
        static void CopyStructTm(const std::tm& src, std::tm& dst);
    };

} // namespace base

#endif // TIME_UTILS_H_ec231f76_73b4_4db2_a54b_3de1ff1f60ef
