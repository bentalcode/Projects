#ifndef UNIT_TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b
#define UNIT_TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b

#include "IUnitTestRunningResult.h"

namespace unit_testing
{
    /**
     * The UnitTestRunningResult implements running result of a single unit test.
     */
    class UnitTestRunningResult : public IUnitTestRunningResult
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
        virtual ~UnitTestRunningResult();

        /**
         * Gets the name of a unit test.
         */
        virtual const std::string& getName() const;

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
        bool m_resultStatus;
        std::string m_errorMessage;
    };
}

#endif // UNIT_TEST_RUNNING_RESULT_H_4dd37c6f_ab71_4de8_b4e2_40f11822d03b
