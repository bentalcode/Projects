#ifndef NUMBER_VALIDATOR_UNIT_TEST_H_e37c065d_6ff9_420e_8ace_267d0895229d
#define NUMBER_VALIDATOR_UNIT_TEST_H_e37c065d_6ff9_420e_8ace_267d0895229d

#include "UnitTestBase.h"
#include "NumberValidator.h"

namespace problems_test {

    /**
     * The NumberValidatorUnitTest class implements a unit test for the number validator problem.
     */
    class NumberValidatorUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The NumberValidatorUnitTest constructor.
         */
        explicit NumberValidatorUnitTest(const std::string& name);

        /**
         * The NumberValidatorUnitTest destructor.
         */
        virtual ~NumberValidatorUnitTest();

        /**
         * The copy/move constructors.
         */
        NumberValidatorUnitTest(const NumberValidatorUnitTest&) = delete;
        NumberValidatorUnitTest(NumberValidatorUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        NumberValidatorUnitTest& operator=(const NumberValidatorUnitTest&) = delete;
        NumberValidatorUnitTest& operator=(NumberValidatorUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of validating a number.
         */
        void numberValidatorTest();

    private:
        /**
         * Tests the logic of validating a number.
         */
        void testNumberValidator(const std::string& str, bool expectedStatus);
    };
}

#endif /* NUMBER_VALIDATOR_UNIT_TEST_H_e37c065d_6ff9_420e_8ace_267d0895229d */
