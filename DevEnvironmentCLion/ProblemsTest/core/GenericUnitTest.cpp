#include "PreCompiled.h"

#include "GenericUnitTest.h"
#include "UnitTestFunction.h"

using namespace problems_test;

class TestingFunction : public unit_testing::UnitTestFunction<GenericUnitTest>
{
public:
    TestingFunction(GenericUnitTest& unitTest) :
        UnitTestFunction("genericTest", unitTest)
    {
    }

    virtual ~TestingFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().genericTest();
    }
};

/**
 * The GenericUnitTest constructor.
 */
GenericUnitTest::GenericUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The GenericUnitTest destructor.
 */
GenericUnitTest::~GenericUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void GenericUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestingFunction(*this)));
}

/**
 * Tests the generic logic.
 */
void GenericUnitTest::genericTest()
{
    test();
}

/**
 * Tests the logic.
 */
void GenericUnitTest::test()
{
}
