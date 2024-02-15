#include "GenericUnitTest.h"
#include "UnitTestFunction.h"

using namespace problems_test;

class TestingFunction : public unit_testing::UnitTestFunction<GenericUnitTest>
{
public:
    TestingFunction(GenericUnitTest& unitTest) :
        UnitTestFunction(L"GenericTest", unitTest)
    {
    }

    virtual ~TestingFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().GenericTest();
    }
};

/**
 * The GenericUnitTest constructor.
 */
GenericUnitTest::GenericUnitTest(const std::wstring& name) :
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
 * Registers tests of the unit Test.
 */
void GenericUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestingFunction(*this)));
}

/**
 * Tests the generic logic.
 */
void GenericUnitTest::GenericTest()
{
    Test();
}

/**
 * Tests the logic.
 */
void GenericUnitTest::Test()
{
}
