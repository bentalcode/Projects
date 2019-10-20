#ifndef UNIT_TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b
#define UNIT_TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b

namespace test_base
{
    class UnitTestRunningResult;
    typedef std::shared_ptr<UnitTestRunningResult> UnitTestRunningResultPtr;

    /**
     * The UnitTestRunningResult implements a running results of a unit test.
     */
    class UnitTestRunningResult
    {
    public :
        /**
         * The UnitTestRunningResult constructor.
         */
        UnitTestRunningResult(
            const std::string& name,
            bool resultStatus,
            const std::string& errorMessage);

        /**
         * The UnitTestRunningResult destructor.
         */
        ~UnitTestRunningResult();

        /**
         * Gets the name of a unit test.
         */
        inline const std::string& getName() const;

        /**
         * Gets the result status of running a unit test.
         */
        inline bool getResultStatus() const;

        /**
         * Gets the error message of running a unit test.
         */
        inline const std::string& getErrorMessage() const;

        /**
         * Gets the information of the running result.
         */
        void getRunningResultInformation(std::ostream& stream) const;

    private:
        std::string m_name;
        bool m_resultStatus;
        std::string m_errorMessage;
    };

    inline const std::string& UnitTestRunningResult::getName() const
    {
        return m_name;
    }

    inline bool UnitTestRunningResult::getResultStatus() const
    {
        return m_resultStatus;
    }

    inline const std::string& UnitTestRunningResult::getErrorMessage() const
    {
        return m_errorMessage;
    }

    /**
     * Gets the information of the running result.
     */
    std::ostream& operator<<(std::ostream& stream, const UnitTestRunningResult& runningResult);
}

#endif // UNIT_TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b
