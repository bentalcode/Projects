#include "PreCompiled.h"

#include "MatrixFinderUnitTest.h"
#include "UnitTestFunction.h"

using namespace problems_test;

class TestMatrixFinderFunction : public unit_testing::UnitTestFunction<MatrixFinderUnitTest>
{
public:
    TestMatrixFinderFunction(MatrixFinderUnitTest& unitTest) :
        UnitTestFunction("matrixFinderTest", unitTest)
    {
    }

    virtual ~TestMatrixFinderFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().matrixFinderTest();
    }
};

/**
 * The MatrixFinderUnitTest constructor.
 */
MatrixFinderUnitTest::MatrixFinderUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The MatrixFinderUnitTest destructor.
 */
MatrixFinderUnitTest::~MatrixFinderUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void MatrixFinderUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMatrixFinderFunction(*this)));
}

/**
 * Tests the logic of matrix finder.
 */
void MatrixFinderUnitTest::matrixFinderTest()
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    testMatrixFinder<int>(matrix, 6, true);
    testMatrixFinder<int>(matrix, 11, false);
}
