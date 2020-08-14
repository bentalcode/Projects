#include "PreCompiled.h"

#include "MatrixUnitTest.h"
#include "UnitTestFunction.h"
#include "Matrix.h"
#include "TwoDimensionalListIterator.h"

using namespace base;

class TestMatrixFunction final : public unit_testing::UnitTestFunction<MatrixUnitTest> {
public:
    explicit TestMatrixFunction(MatrixUnitTest& unitTest) :
        UnitTestFunction("matrixCreationTest", unitTest) 
    {
    }

    virtual ~TestMatrixFunction() 
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().matrixCreationTest();
    }
};

class TestMatrixIterationFunction final : public unit_testing::UnitTestFunction<MatrixUnitTest> 
{
public:
    explicit TestMatrixIterationFunction(MatrixUnitTest &unitTest) :
        UnitTestFunction("matrixIterationTest", unitTest) 
    {
    }

    virtual ~TestMatrixIterationFunction() 
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().matrixIterationTest();
    }
};

/**
 * The MatrixUnitTest constructor.
 */
MatrixUnitTest::MatrixUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The MatrixUnitTest destructor.
 */
MatrixUnitTest::~MatrixUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void MatrixUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMatrixFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMatrixIterationFunction(*this)));
}

/**
 * Tests the creation logic of a matrix.
 */
void MatrixUnitTest::matrixCreationTest()
{
    for (int row = 1; row <= 10; ++row)
    {
        for (int column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.createTwoDimensionalVector(row, column, 1);
            testMatrixCreation(*data);
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void MatrixUnitTest::matrixIterationTest()
{
    for (int row = 1; row <= 10; ++row)
    {
        for (int column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.createTwoDimensionalVector(row, column, 1);
            testMatrixIteration(*data);
        }
    }
}

/**
 * Tests the creation logic of a matrix.
 */
void MatrixUnitTest::testMatrixCreation(const std::vector<std::vector<int>> &data)
{
    base::Matrix<int> matrix(data);

    for (int row = 0; row < data.size(); ++row)
    {
        for (int column = 0; column < data[row].size(); ++column)
        {
            int currentValue = matrix[row][column];
            int expectedValue = data[row][column];

            getAssertion().assertEquals(
                currentValue,
                expectedValue,
                "Invalid creation logic.");
        }
    }

    base::Matrix<int> matrix1(matrix);
    base::Matrix<int> matrix2(1, 1);
    matrix2 = matrix;

    bool status = matrix1 == matrix2;

    getAssertion().assertTrue(
        status,
        "Invalid creation logic of a matrix.");
}

/**
 * Tests the iteration logic of a matrix.
 */
void MatrixUnitTest::testMatrixIteration(const std::vector<std::vector<int>>& data)
{
    base::Matrix<int> matrix(data);
    base::TwoDimensionalListIterator<int> dataIterator(data);

    getAssertion().assertEqualsWithIterators(
        *(matrix.getIterator()),
        dataIterator,
        "Invalid iteration logic of a matrix.");
}
