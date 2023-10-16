#include "MatrixUnitTest.h"
#include "UnitTestFunction.h"
#include "Matrix.h"
#include "TwoDimensionalVectorIterator.h"

using namespace base;
using namespace test::base;

class MatrixTestFunction final : public unit_testing::UnitTestFunction<MatrixUnitTest> {
public:
    explicit MatrixTestFunction(MatrixUnitTest& unitTest) :
        UnitTestFunction(L"MatrixCreationTest", unitTest)
    {
    }

    virtual ~MatrixTestFunction() 
    {
    }

    virtual void operator()() override 
    {
        GetUnitTest().MatrixCreationTest();
    }
};

class MatrixIterationTestFunction final : public unit_testing::UnitTestFunction<MatrixUnitTest> 
{
public:
    explicit MatrixIterationTestFunction(MatrixUnitTest &unitTest) :
        UnitTestFunction(L"MatrixIterationTest", unitTest)
    {
    }

    virtual ~MatrixIterationTestFunction() 
    {
    }

    virtual void operator()() override 
    {
        GetUnitTest().MatrixIterationTest();
    }
};

/**
 * The MatrixUnitTest constructor.
 */
MatrixUnitTest::MatrixUnitTest(const std::wstring& name) :
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
void MatrixUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new MatrixTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new MatrixIterationTestFunction(*this)));
}

/**
 * Tests the creation logic of a matrix.
 */
void MatrixUnitTest::MatrixCreationTest()
{
    for (int row = 1; row <= 10; ++row)
    {
        for (int column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.CreateTwoDimensionalVector(row, column, 1);
            TestMatrixCreation(*data);
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void MatrixUnitTest::MatrixIterationTest()
{
    for (int row = 1; row <= 10; ++row)
    {
        for (int column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.CreateTwoDimensionalVector(row, column, 1);
            TestMatrixIteration(*data);
        }
    }
}

/**
 * Tests the creation logic of a matrix.
 */
void MatrixUnitTest::TestMatrixCreation(const std::vector<std::vector<int>> &data)
{
    Matrix<int> matrix(data);

    for (int row = 0; row < data.size(); ++row)
    {
        for (int column = 0; column < data[row].size(); ++column)
        {
            int currentValue = matrix[row][column];
            int expectedValue = data[row][column];

            GetAssertion().AssertEquals(
                currentValue,
                expectedValue,
                L"Invalid creation logic.");
        }
    }

    Matrix<int> matrix1(matrix);
    Matrix<int> matrix2(1, 1);
    matrix2 = matrix;

    bool status = matrix1 == matrix2;

    GetAssertion().AssertTrue(
        status,
        L"Invalid creation logic of a matrix.");
}

/**
 * Tests the iteration logic of a matrix.
 */
void MatrixUnitTest::TestMatrixIteration(const std::vector<std::vector<int>>& data)
{
    Matrix<int> matrix(data);
    TwoDimensionalVectorIterator<int> dataIterator(data);

    GetAssertion().AssertEqualsWithIterators(
        *(matrix.GetIterator()),
        dataIterator,
        L"Invalid iteration logic of a matrix.");
}
