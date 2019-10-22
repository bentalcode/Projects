#ifndef I_UNIT_TEST_RUNNING_RESULT_H_bdde206b_d4c6_40ce_86e4_6271ed56fc22
#define I_UNIT_TEST_RUNNING_RESULT_H_bdde206b_d4c6_40ce_86e4_6271ed56fc22

namespace unit_testing
{
    class IUnitTestRunningResult;
    typedef std::shared_ptr<IUnitTestRunningResult> IUnitTestRunningResultPtr;

    /**
     * The IUnitTestRunningResult interface defines result of a single unit test.
     */
    class IUnitTestRunningResult
    {
    public :
        /**
         * The IUnitTestRunningResult destructor.
         */
        virtual ~IUnitTestRunningResult();

        /**
         * Gets the name of a unit test.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Gets the result status of running a unit test.
         */
        virtual bool getResultStatus() const = 0;

        /**
         * Gets the error message of running a unit test.
         */
        virtual const std::string& getErrorMessage() const = 0;

        /**
         * Gets the information of the running result.
         */
        virtual void getRunningResultInformation(std::ostream& stream) const = 0;
    };

    /**
     * The IUnitTestRunningResult destructor.
     */
    inline IUnitTestRunningResult::~IUnitTestRunningResult()
    {
    }

    /**
     * Gets the information of the running result.
     */
    inline std::ostream& operator<<(std::ostream& stream, const IUnitTestRunningResult& runningResult)
    {
        runningResult.getRunningResultInformation(stream);
        return stream;
    }
}

#endif // I_UNIT_TEST_RUNNING_RESULT_H_bdde206b_d4c6_40ce_86e4_6271ed56fc22
