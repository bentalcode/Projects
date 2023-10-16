#include "TwoDimensionalVectorUnitTest.h"
#include "UnitTestFunction.h"
#include "TwoDimensionalVector.h"
#include "TwoDimensionalVectorIterator.h"

using namespace base;
using namespace test::base;

class TwoDimensionalVectorCreationTestFunction final : public unit_testing::UnitTestFunction<TwoDimensionalVectorUnitTest> {
public:
    explicit TwoDimensionalVectorCreationTestFunction(TwoDimensionalVectorUnitTest &unitTest) :
        UnitTestFunction(L"twoDimensionalListCreationTest", unitTest) {
    }

    virtual ~TwoDimensionalVectorCreationTestFunction() {
    }

    virtual void operator()() override {
        GetUnitTest().TwoDimensionalVectorCreationTest();
    }
};

class TwoDimensionalVectorIterationTestFunction final : public unit_testing::UnitTestFunction<TwoDimensionalVectorUnitTest> {
public:
    explicit TwoDimensionalVectorIterationTestFunction(TwoDimensionalVectorUnitTest &unitTest) :
        UnitTestFunction(L"TwoDimensionalVectorIterationTest", unitTest) {
    }

    virtual ~TwoDimensionalVectorIterationTestFunction() {
    }

    virtual void operator()() override {
        GetUnitTest().TwoDimensionalVectorIterationTest();
    }
};

/**
 * The TwoDimensionalVectorUnitTest constructor.
 */
TwoDimensionalVectorUnitTest::TwoDimensionalVectorUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The TwoDimensionalVectorUnitTest destructor.
 */
TwoDimensionalVectorUnitTest::~TwoDimensionalVectorUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void TwoDimensionalVectorUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TwoDimensionalVectorCreationTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TwoDimensionalVectorIterationTestFunction(*this)));
}

/**
 * Tests the creation logic of a two dimensional list.
 */
void TwoDimensionalVectorUnitTest::TwoDimensionalVectorCreationTest()
{
    for (size_t row = 1; row <= 10; ++row)
    {
        for (size_t column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.CreateTwoDimensionalVector(row, column, 1);
            TestTwoDimensionalVectorCreation(*data);
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional vector.
 */
void TwoDimensionalVectorUnitTest::TwoDimensionalVectorIterationTest()
{
    for (size_t row = 1; row <= 10; ++row)
    {
        for (size_t column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.CreateTwoDimensionalVector(row, column, 1);
            TestTwoDimensionalVectorIteration(*data);
        }
    }
}

/**
 * Tests the creation logic of a two dimensional vector.
 */
void TwoDimensionalVectorUnitTest::TestTwoDimensionalVectorCreation(const std::vector<std::vector<int>>& data)
{
    TwoDimensionalVector<int> twoDimensionalVector(data);

    for (size_t row = 0; row < data.size(); ++row)
    {
        for (size_t column = 0; column < data[row].size(); ++column)
        {
            int currentValue = twoDimensionalVector[row][column];
            int expectedValue = data[row][column];

            GetAssertion().AssertEquals(
                currentValue,
                expectedValue,
                L"Invalid creation logic a two dimensional vector.");
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional vector.
 */
void TwoDimensionalVectorUnitTest::TestTwoDimensionalVectorIteration(const std::vector<std::vector<int>>& data)
{
    TwoDimensionalVector<int> vector(data);
    TwoDimensionalVectorIterator<int> dataIterator(data);

    GetAssertion().AssertEqualsWithIterators(
        *(vector.GetIterator()),
        dataIterator,
        L"Invalid iteration logic of a two dimensional vector.");
}
