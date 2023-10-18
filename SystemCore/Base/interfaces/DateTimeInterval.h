#ifndef DATE_TIME_INTERVAL_H_68a16f40_57d1_11ee_8c99_0242ac120002
#define DATE_TIME_INTERVAL_H_68a16f40_57d1_11ee_8c99_0242ac120002

#include "DateTime.h"

namespace base {

    /**
     * The DateTimeInterval class implements a datetime interval.
     */
    class DateTimeInterval final {
    public:
        /**
         * Creates a datetime interval.
         */
        static std::shared_ptr<DateTimeInterval> Make(
            const DateTimeSharedPtr startTime = nullptr,
            const DateTimeSharedPtr endTime = nullptr);

        /**
         * The DateTimeInterval Constructor.
         */
        DateTimeInterval(
            const DateTimeSharedPtr startTime,
            const DateTimeSharedPtr endTime);

        /**
         * The DateTimeInterval Destructor.
         */
        ~DateTimeInterval();

        /**
         * Sets a start time of an interval.
         */
        void SetStartIntervalTime(DateTimeSharedPtr time);

        /**
         * Gets a start time of an interval.
         */
        DateTimeSharedPtr GetStartTime();

        /**
         * Gets a start time of an interval.
         */
        const DateTimeSharedPtr GetStartTime() const;

        /**
         * Sets an End time of an interval.
         */
        void SetEndTime(DateTimeSharedPtr time);

        /**
         * Gets an End time of an interval.
         */
        DateTimeSharedPtr GetEndTime();

        /**
         * Gets an End time of an interval.
         */
        const DateTimeSharedPtr GetEndTime() const;

        /**
         * Gets duration of an interval.
         */
        const DurationSharedPtr GetDuration() const;

    private:
        /**
         * Validates an interval.
         */
        static void Validate(
            const DateTimeSharedPtr startTime,
            const DateTimeSharedPtr endTime);

        DateTimeSharedPtr m_startTime;
        DateTimeSharedPtr m_endTime;
    };

    /**
     * Defines the Shared Ptr of a Date Time Interval.
     */
    using DateTimeIntervalSharedPtr = std::shared_ptr<DateTimeInterval>;

}  // namespace base

#endif // DATE_TIME_INTERVAL_H_68a16f40_57d1_11ee_8c99_0242ac120002
