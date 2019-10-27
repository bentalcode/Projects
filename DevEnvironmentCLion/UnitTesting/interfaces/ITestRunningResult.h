#ifndef I_TEST_RUNNING_RESULT_H_bdde206b_d4c6_40ce_86e4_6271ed56fc22
#define I_TEST_RUNNING_RESULT_H_bdde206b_d4c6_40ce_86e4_6271ed56fc22

#include "DateTime.h"

namespace unit_testing
{
    class ITestRunningResult;
    typedef std::shared_ptr<ITestRunningResult> ITestRunningResultPtr;

    typedef base::Duration<double> Duration;
    typedef std::shared_ptr<Duration> DurationPtr;

    /**
     * The ITestRunningResult interface defines result of a single test.
     */
    class ITestRunningResult
    {
    public :
        /**
         * The ITestRunningResult constructor.
         */
        ITestRunningResult() = default;

        /**
         * The ITestRunningResult destructor.
         */
        virtual ~ITestRunningResult() = default;

        /**
         * Gets the name of a test.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Gets the start time of a test.
         */
        virtual const base::DateTime& getStartTime() const = 0;

        /**
         * Gets the end time of a test.
         */
        virtual const base::DateTime& getEndTime() const = 0;

        /**
         * Gets the duration of a test.
         */
        virtual const Duration& getDuration() const = 0;

        /**
         * Gets the result status of running a test.
         */
        virtual bool getResultStatus() const = 0;

        /**
         * Gets the error message of running a test.
         */
        virtual const std::string& getErrorMessage() const = 0;

        /**
         * Gets the information of the running result.
         */
        virtual void getRunningResultInformation(std::ostream& stream) const = 0;
    };

    /**
     * Gets the information of the running result.
     */
    inline std::ostream& operator<<(std::ostream& stream, const ITestRunningResult& runningResult)
    {
        runningResult.getRunningResultInformation(stream);
        return stream;
    }
}

#endif // I_TEST_RUNNING_RESULT_H_bdde206b_d4c6_40ce_86e4_6271ed56fc22
