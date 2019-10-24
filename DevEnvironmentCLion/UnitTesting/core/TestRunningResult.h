#ifndef TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b
#define TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b

#include "ITestRunningResult.h"

namespace unit_testing
{
    /**
     * The TestRunningResult implements running result of a single test.
     */
    class TestRunningResult : public ITestRunningResult
    {
    public :
        /**
         * The UnitTestRunningResult constructor.
         */
        TestRunningResult(
            const std::string& name,
            const base::DateTime& startTime,
            const base::DateTime& endTime,
            bool resultStatus,
            const std::string& errorMessage);

        /**
         * The UnitTestRunningResult destructor.
         */
        virtual ~TestRunningResult();

        /**
         * Gets the name of a unit test.
         */
        virtual const std::string& getName() const;

        /**
         * Gets the start time of a test.
         */
        virtual const base::DateTime& getStartTime() const;

        /**
         * Gets the end time of a test.
         */
        virtual const base::DateTime& getEndTime() const;

        /**
         * Gets the duration of a test.
         */
        virtual const Duration& getDuration() const;

        /**
         * Gets the result status of running a unit test.
         */
        virtual bool getResultStatus() const;

        /**
         * Gets the error message of running a unit test.
         */
        virtual const std::string& getErrorMessage() const;

        /**
         * Gets the information of the running result.
         */
        virtual void getRunningResultInformation(std::ostream& stream) const;

    private:
        std::string m_name;
        base::DateTime m_startTime;
        base::DateTime m_endTime;
        Duration m_duration;
        bool m_resultStatus;
        std::string m_errorMessage;
    };
}

#endif // TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b
