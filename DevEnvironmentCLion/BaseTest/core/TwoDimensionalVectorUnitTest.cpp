#include "PreCompiled.h"

#include "TwoDimensionalVectorUnitTest.h"
#include "UnitTestFunction.h"
#include "TwoDimensionalVector.h"
#include "TwoDimensionalVectorIterator.h"

using namespace base;

class TestTwoDimensionalVectorCreationFunction final : public unit_testing::UnitTestFunction<TwoDimensionalVectorUnitTest> {
public:
    explicit TestTwoDimensionalVectorCreationFunction(TwoDimensionalVectorUnitTest &unitTest) :
        UnitTestFunction("twoDimensionalListCreationTest", unitTest) {
    }

    virtual ~TestTwoDimensionalVectorCreationFunction() {
    }

    virtual void operator()() override {
        getUnitTest().twoDimensionalVectorCreationTest();
    }
};

class TestTwoDimensionalVectorIterationFunction final : public unit_testing::UnitTestFunction<TwoDimensionalVectorUnitTest> {
public:
    explicit TestTwoDimensionalVectorIterationFunction(TwoDimensionalVectorUnitTest &unitTest) :
        UnitTestFunction("twoDimensionalVectorIterationTest", unitTest) {
    }

    virtual ~TestTwoDimensionalVectorIterationFunction() {
    }

    virtual void operator()() override {
        getUnitTest().twoDimensionalVectorIterationTest();
    }
};

/**
 * The TwoDimensionalVectorUnitTest constructor.
 */
TwoDimensionalVectorUnitTest::TwoDimensionalVectorUnitTest(const std::string& name) :
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
void TwoDimensionalVectorUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestTwoDimensionalVectorCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestTwoDimensionalVectorIterationFunction(*this)));
}

/**
 * Tests the creation logic of a two dimensional list.
 */
void TwoDimensionalVectorUnitTest::twoDimensionalVectorCreationTest()
{
    for (int row = 1; row <= 10; ++row)
    {
        for (int column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.createTwoDimensionalVector(row, column, 1);
            testTwoDimensionalVectorCreation(*data);
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional vector.
 */
void TwoDimensionalVectorUnitTest::twoDimensionalVectorIterationTest()
{
    for (int row = 1; row <= 10; ++row)
    {
        for (int column = 1; column <= 10; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.createTwoDimensionalVector(row, column, 1);
            testTwoDimensionalVectorIteration(*data);
        }
    }
}

/**
 * Tests the creation logic of a two dimensional vector.
 */
void TwoDimensionalVectorUnitTest::testTwoDimensionalVectorCreation(const std::vector<std::vector<int>>& data)
{
    base::TwoDimensionalVector<int> vector(data);

    for (int row = 0; row < data.size(); ++row)
    {
        for (int column = 0; column < data[row].size(); ++column)
        {
            int currentValue = vector[row][column];
            int expectedValue = data[row][column];

            getAssertion().assertEquals(
                currentValue,
                expectedValue,
                "Invalid creation logic a two dimensional vector.");
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional vector.
 */
void TwoDimensionalVectorUnitTest::testTwoDimensionalVectorIteration(const std::vector<std::vector<int>>& data)
{
    base::TwoDimensionalVector<int> vector(data);
    base::TwoDimensionalVectorIterator<int> dataIterator(data);

    this->getAssertion().assertEqualsWithIterators(
        *(vector.getIterator()),
        dataIterator,
        "Invalid iteration logic of a two dimensional vector.");
}
