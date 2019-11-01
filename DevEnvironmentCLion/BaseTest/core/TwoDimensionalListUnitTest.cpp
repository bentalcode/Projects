#include "PreCompiled.h"

#include "TwoDimensionalListUnitTest.h"
#include "TwoDimensionalList.h"
#include "UnitTestFunction.h"

using namespace base;

class TestTwoDimensionalListFunction final : public unit_testing::UnitTestFunction<TwoDimensionalListUnitTest> {
public:
    explicit TestTwoDimensionalListFunction(TwoDimensionalListUnitTest &unitTest) :
        UnitTestFunction("twoDimensionalListTest", unitTest) {
    }

    virtual ~TestTwoDimensionalListFunction() {
    }

    virtual void operator()() override {
        getUnitTest().twoDimensionalListTest();
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
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestTwoDimensionalListFunction(*this)));
}

/**
 * Tests the two dimensional list.
 */
void TwoDimensionalListUnitTest::twoDimensionalListTest()
{
    for (int row = 1; row <= 100; ++row)
    {
        for (int column = 1; column <= 100; ++column)
        {
            testTwoDimensionalList(row, column);
        }
    }
}

/**
 * Tests the two dimensional list.
 */
void TwoDimensionalListUnitTest::testTwoDimensionalList(int rows, int columns)
{
    TwoDimensionalList<int> list(rows, columns);

    int value = 0;
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            ++value;
            list[row][column] = value;

            int currentValue = list[row][column];
            int expectedValue = value;

            assert(currentValue == expectedValue);
        }
    }

    int index = 0;

    IIteratorPtr<int> iterator = list.getIterator();
    while (iterator->hasNext())
    {
        int rowIndex = index / columns;
        int columnIndex = index % columns;

        int currentValue = iterator->next();
        int expectedValue = list.get(rowIndex, columnIndex);

        assert(currentValue == expectedValue);

        ++index;
    }
}
