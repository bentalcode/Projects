#ifndef DATE_TIME_H_ca5f50c0_ecf2_435c_b137_480c1d3b2bcb
#define DATE_TIME_H_ca5f50c0_ecf2_435c_b137_480c1d3b2bcb

#include <chrono>
#include <memory>
#include "Duration.h"

namespace base {

    /**
     * Defines the Shared Ptr of Date Time.
     */
    class DateTime;
    using DateTimeSharedPtr = std::shared_ptr<DateTime>;

    /**
     * The DateTime class implements a date time.
     */
    class DateTime final {
    public:
        /**
         * Creates a new date time.
         */
        static DateTimeSharedPtr Make(const std::chrono::system_clock::time_point& timePoint);

        /**
         * Creates a new date time.
         */
        static DateTimeSharedPtr Make(const DateTime& time);

        /**
         * The DateTime Constructor.
         */
        explicit DateTime(const std::chrono::system_clock::time_point& timePoint);

        /**
         * The DateTime Destructor.
         */
        ~DateTime();

        /**
         * The DateTime Copy/Move Constructors.
         */
        DateTime(const DateTime&) = default;
        DateTime(DateTime&&) = default;

        /**
         * The DateTime Copy/Move Assignment Operators.
         */
        DateTime& operator=(const DateTime&) = default;
        DateTime& operator=(DateTime&&) = default;

        /**
         * Gets a time point.
         */
        inline const std::chrono::system_clock::time_point& GetTimePoint() const;

        /**
         * Gets an information of a date time.
         */
        void GetDateTimeInformation(std::wostream& stream) const;

        /**
         * Gets a string representation of a date time.
         */
        std::wstring ToString(const std::wstring& format = L"%FT%TZ") const;

        /**
         * Parses a string with format to a date time.
         */
        static DateTimeSharedPtr Parse(const std::wstring& str, const std::wstring& format);

        /**
         * Adds duration to date time.
         */
        DateTime& Add(const Duration& duration);

        /**
         * Substracts duration from date time.
         */
        DateTime& Substract(const Duration& duration);

        /**
         * Implements an addition operator for date time.
         */
        DateTime& operator+=(const Duration& duration);

        /**
         * Implements a substract operator for date time.
         */
        DateTime& operator-=(const Duration& duration);

        /**
         * Gets current time.
         */
        static DateTimeSharedPtr Now();

        /**
         * Gets current time point.
         */
        static std::chrono::system_clock::time_point GetCurrentTimePoint();

    private:
        std::chrono::system_clock::time_point m_timePoint;
    };

    /**
     * Gets a time point.
     */
    inline const std::chrono::system_clock::time_point& DateTime::GetTimePoint() const
    {
        return m_timePoint;
    }

    /**
     * Writes information of a date time to an output stream.
     */
    inline std::wostream& operator<<(
        std::wostream& stream,
        const DateTime& dateTime)
    {
        dateTime.GetDateTimeInformation(stream);
        return stream;
    }

    /**
     * Implements an operator equal for date time.
     */
    inline bool operator==(
        const DateTime& lhs,
        const DateTime& rhs)
    {
        return lhs.GetTimePoint() == rhs.GetTimePoint();
    }

    /**
     * Implements an operator not equal for date time.
     */
    inline bool operator!=(
        const DateTime& lhs,
        const DateTime& rhs)
    {
        return !(lhs == rhs);
    }

    /**
     * Implements an operator less than for date time.
     */
    inline bool operator<(
        const DateTime& lhs,
        const DateTime& rhs)
    {
        return lhs.GetTimePoint() < rhs.GetTimePoint();
    }

    /**
     * Implements an operator less than or equal for date time.
     */
    inline bool operator<=(
        const DateTime& lhs,
        const DateTime& rhs)
    {
        return !(rhs < lhs);
    }

    /**
     * Implements an operator greater than for date time.
     */
    inline bool operator>(
        const DateTime& lhs,
        const DateTime& rhs)
    {
        return rhs < lhs;
    }

    /**
     * Implements an operator greater than or equal for date time.
     */
    inline bool operator>=(
        const DateTime& lhs,
        const DateTime& rhs)
    {
        return !(lhs < rhs);
    }

    /**
     * Implements an addition operator for date time.
     */
    inline DateTimeSharedPtr operator+(const DateTime& time, const Duration& duration)
    {
        DateTimeSharedPtr result = DateTime::Make(time);
        result->Add(duration);
        return result;
    }

    inline DateTimeSharedPtr operator-(const DateTime& time, const Duration& duration)
    {
        DateTimeSharedPtr result = DateTime::Make(time);
        result->Substract(duration);
        return result;
    }

    /**
     * Implements an operator less than for date time.
     */
    inline DurationSharedPtr operator-(const DateTime& lhs, const DateTime& rhs)
    {
        const std::chrono::system_clock::time_point& lhsTime = lhs.GetTimePoint();
        const std::chrono::system_clock::time_point& rhsTime = rhs.GetTimePoint();
        std::chrono::system_clock::time_point duration = static_cast<std::chrono::system_clock::time_point>(lhsTime - rhsTime);
        return Duration::Make(duration);
    }

} // namespace base

#endif // namespace DATE_TIME_H_ca5f50c0_ecf2_435c_b137_480c1d3b2bcb
