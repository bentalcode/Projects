#ifndef DATE_TIME_H_957e9bc5_2a3e_4fa5_bf16_c0e55f226c9b
#define DATE_TIME_H_957e9bc5_2a3e_4fa5_bf16_c0e55f226c9b

#include "Duration.h"

namespace base
{
    class DateTime;
    typedef std::shared_ptr<DateTime> DateTimePtr;

    /**
     * The DateTime class template implements a date time.
     */
    class DateTime final
    {
    public:
        explicit DateTime(const std::chrono::system_clock::time_point& timePoint);
        ~DateTime();

        /**
         * Gets the time point.
         */
        inline const std::chrono::system_clock::time_point& getTimePoint() const;

        /**
         * Gets the information of the date-time.
         */
        void getDateTimeInformation(std::ostream& stream) const;

        /**
         * Gets the current time.
         */
        static DateTime now();

        /**
         * Gets the current time point.
         */
        static std::chrono::system_clock::time_point currentTimePoint();

    private:
        std::chrono::system_clock::time_point m_timePoint;
    };

    inline const std::chrono::system_clock::time_point& DateTime::getTimePoint() const
    {
        return m_timePoint;
    }

    inline std::ostream& operator<<(std::ostream& stream, const DateTime& dateTime)
    {
        dateTime.getDateTimeInformation(stream);
        return stream;
    }
}

#endif // DATE_TIME_H_957e9bc5_2a3e_4fa5_bf16_c0e55f226c9b
