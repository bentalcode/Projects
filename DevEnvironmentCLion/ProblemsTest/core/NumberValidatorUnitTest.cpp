#include "PreCompiled.h"

#include "NumberValidatorUnitTest.h"
#include "UnitTestFunction.h"
#include "NumberValidator.h"

using namespace problems_test;

class TestNumberValidatorFunction : public unit_testing::UnitTestFunction<NumberValidatorUnitTest>
{
public:
    TestNumberValidatorFunction(NumberValidatorUnitTest& unitTest) :
        UnitTestFunction("numberValidatorTest", unitTest)
    {
    }

    virtual ~TestNumberValidatorFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().numberValidatorTest();
    }
};

/**
 * The NumberValidatorUnitTest constructor.
 */
NumberValidatorUnitTest::NumberValidatorUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The NumberValidatorUnitTest destructor.
 */
NumberValidatorUnitTest::~NumberValidatorUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void NumberValidatorUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestNumberValidatorFunction(*this)));
}

/**
 * Tests the logic of validating a number.
 */
void NumberValidatorUnitTest::numberValidatorTest()
{
    testNumberValidator("0", true);
    testNumberValidator("00", true);
    testNumberValidator("000", true);

    testNumberValidator("0.1", true);
    testNumberValidator(" 0.1", true);
    testNumberValidator("0.1 ", true);
    testNumberValidator(" 0.1 ", true);

    testNumberValidator(".", false);
    testNumberValidator("..", false);
    testNumberValidator(".09", true);
    testNumberValidator(".09.", false);

    testNumberValidator("abc", false);
    testNumberValidator("1a", false);
    testNumberValidator("1 a", false);
    testNumberValidator("a1", false);

    testNumberValidator("-", false);
    testNumberValidator("+", false);
    testNumberValidator("++1", false);
    testNumberValidator("--1", false);
    testNumberValidator(" --6 ", false);
    testNumberValidator("-+3", false);

    testNumberValidator("e", false);
    testNumberValidator("2e10", true);
    testNumberValidator(" -90e3   ", true);
    testNumberValidator(" 1e", false);
    testNumberValidator("e3", false);
    testNumberValidator(" 6e-1", true);
    testNumberValidator(" 99e2.5 ", false);
    testNumberValidator("53.5e93", true);
    testNumberValidator("95a54e53", false);
    testNumberValidator(".9554e53", true);
    testNumberValidator(".9554e5.3", false);
}

/**
 * Tests the logic of validating a number.
 */
void NumberValidatorUnitTest::testNumberValidator(const std::string& str, bool expectedStatus)
{
    std::shared_ptr<base::IValidator> validatorPtr(new problems::NumberValidator(str));
    bool status = validatorPtr->validate();

    getAssertion().assertEquals(
        status,
        expectedStatus,
        "Invalid logic of validating a number.");
}
