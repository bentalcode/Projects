#ifndef TEST_RUNNING_RESULT_H_6793c8a0_6cf1_43c0_a525_d0570910ad62
#define TEST_RUNNING_RESULT_H_6793c8a0_6cf1_43c0_a525_d0570910ad62

#include "ITestRunningResult.h"

namespace unit_testing
{
    /**
     * The TestRunningResult implements running result of a single test.
     */
    class TestRunningResult final : public ITestRunningResult
    {
    public :
        /**
         * The constructor.
         */
        TestRunningResult(
            const std::string& name,
            const base::DateTime& startTime,
            const base::DateTime& endTime,
            bool resultStatus,
            const std::string& errorMessage);

        /**
         * The destructor.
         */
        virtual ~TestRunningResult();

        /**
         * The copy/move constructors.
         */
        TestRunningResult(const TestRunningResult&) = delete;
        TestRunningResult(TestRunningResult&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        TestRunningResult& operator=(const TestRunningResult&) = delete;
        TestRunningResult& operator=(TestRunningResult&&) = delete;

        /**
         * Gets the name of a unit test.
         */
        virtual const std::string& getName() const override;

        /**
         * Gets the start time of a test.
         */
        virtual const base::DateTime& getStartTime() const override;

        /**
         * Gets the end time of a test.
         */
        virtual const base::DateTime& getEndTime() const override;

        /**
         * Gets the duration of a test.
         */
        virtual const base::Duration& getDuration() const override;

        /**
         * Gets the result status of running a unit test.
         */
        virtual bool getResultStatus() const override;

        /**
         * Gets the error message of running a unit test.
         */
        virtual const std::string& getErrorMessage() const override;

        /**
         * Gets the string representation of this instance.
         */
        virtual std::string toString() const override;

    private:
        std::string m_name;
        base::DateTime m_startTime;
        base::DateTime m_endTime;
        base::Duration m_duration;
        bool m_resultStatus;
        std::string m_errorMessage;
    };
}

#endif // TEST_RUNNING_RESULT_H_6793c8a0_6cf1_43c0_a525_d0570910ad62
