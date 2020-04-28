#include "PreCompiled.h"

#include "TwoDimensionalListUnitTest.h"
#include "UnitTestFunction.h"
#include "TwoDimensionalList.h"
#include "TwoDimensionalListIterator.h"

using namespace base_test;

class TestTwoDimensionalListCreationFunction final : public unit_testing::UnitTestFunction<TwoDimensionalListUnitTest> {
public:
    explicit TestTwoDimensionalListCreationFunction(TwoDimensionalListUnitTest &unitTest) :
        UnitTestFunction("twoDimensionalListCreationTest", unitTest) {
    }

    virtual ~TestTwoDimensionalListCreationFunction() {
    }

    virtual void operator()() override {
        getUnitTest().twoDimensionalListCreationTest();
    }
};

class TestTwoDimensionalListIterationFunction final : public unit_testing::UnitTestFunction<TwoDimensionalListUnitTest> {
public:
    explicit TestTwoDimensionalListIterationFunction(TwoDimensionalListUnitTest &unitTest) :
        UnitTestFunction("twoDimensionalListIterationTest", unitTest) {
    }

    virtual ~TestTwoDimensionalListIterationFunction() {
    }

    virtual void operator()() override {
        getUnitTest().twoDimensionalListIterationTest();
    }
};

/**
 * The TwoDimensionalListUnitTest constructor.
 */
TwoDimensionalListUnitTest::TwoDimensionalListUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The TwoDimensionalListUnitTest destructor.
 */
TwoDimensionalListUnitTest::~TwoDimensionalListUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void TwoDimensionalListUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestTwoDimensionalListCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestTwoDimensionalListIterationFunction(*this)));
}

/**
 * Tests the creation logic of a two dimensional list.
 */
void TwoDimensionalListUnitTest::twoDimensionalListCreationTest()
{
    for (int row = 1; row <= 100; ++row)
    {
        for (int column = 1; column <= 100; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.createTwoDimensionalVector(row, column, 1);
            testTwoDimensionalListCreation(*data);
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void TwoDimensionalListUnitTest::twoDimensionalListIterationTest()
{
    for (int row = 1; row <= 100; ++row)
    {
        for (int column = 1; column <= 100; ++column)
        {
            std::shared_ptr<std::vector<std::vector<int>>> data = m_testData.createTwoDimensionalVector(row, column, 1);
            testTwoDimensionalListIteration(*data);
        }
    }
}

/**
 * Tests the creation logic of a two dimensional list.
 */
void TwoDimensionalListUnitTest::testTwoDimensionalListCreation(const std::vector<std::vector<int>>& data)
{
    base::TwoDimensionalList<int> list(data);

    for (int row = 0; row < data.size(); ++row)
    {
        for (int column = 0; column < data[row].size(); ++column)
        {
            int currentValue = list[row][column];
            int expectedValue = data[row][column];

            getAssertion().assertEquals(
                currentValue,
                expectedValue,
                "Invalid creation logic a two dimensional list.");
        }
    }
}

/**
 * Tests the iteration logic of a two dimensional list.
 */
void TwoDimensionalListUnitTest::testTwoDimensionalListIteration(const std::vector<std::vector<int>>& data)
{
    base::TwoDimensionalList<int> list(data);
    base::TwoDimensionalListIterator<int> dataIterator(data);

    this->getAssertion().assertEqualsWithIterators(
        *(list.getIterator()),
        dataIterator,
        "Invalid iteration logic of a two dimensional list.");
}
