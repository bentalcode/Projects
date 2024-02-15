#include "QueensPositioningUnitTest.h"
#include "UnitTestFunction.h"
#include "QueensPositioning.h"
#include "TwoDimensionalVector.h"

using namespace problems_test;

class TestQueensPositioningFunction : public unit_testing::UnitTestFunction<QueensPositioningUnitTest>
{
public:
    TestQueensPositioningFunction(QueensPositioningUnitTest& unitTest) :
        UnitTestFunction(L"queensPositioningTest", unitTest)
    {
    }

    virtual ~TestQueensPositioningFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().PositionQueensTest();
    }
};

/**
 * The QueensPositioningUnitTest constructor.
 */
QueensPositioningUnitTest::QueensPositioningUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The QueensPositioningUnitTest destructor.
 */
QueensPositioningUnitTest::~QueensPositioningUnitTest()
{
}

/**
 * Registers tests of the unit Test.
 */
void QueensPositioningUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestQueensPositioningFunction(*this)));
}

/**
 * Tests the logic of position queens.
 */
void QueensPositioningUnitTest::PositionQueensTest()
{
    int size1 = 1;
    std::vector<std::vector<std::wstring>> result1 = {};

    int size2 = 2;
    std::vector<std::vector<std::wstring>> result2 = {};

    int size3 = 3;
    std::vector<std::vector<std::wstring>> result3 = {};

    int size4 = 4;
    std::vector<std::vector<std::wstring>> result4 =
    {
        {
            L"..Q.",
            L"Q...",
            L"...Q",
            L".Q.."
        },
        {
            L".Q..",
            L"...Q",
            L"Q...",
            L"..Q."
        }
    };

    int size5 = 5;
    std::vector<std::vector<std::wstring>> result5 =
    {
        {
            L"Q....",
            L"...Q.",
            L".Q...",
            L"....Q",
            L"..Q.."
        },
        {
            L"Q....",
            L"..Q..",
            L"....Q",
            L".Q...",
            L"...Q."
        },
        {
            L"..Q..",
            L"Q....",
            L"...Q.",
            L".Q...",
            L"....Q"
        },
        {
            L"...Q.",
            L"Q....",
            L"..Q..",
            L"....Q",
            L".Q..."
        },
        {
            L".Q...",
            L"...Q.",
            L"Q....",
            L"..Q..",
            L"....Q"
        },
        {
            L"....Q",
            L"..Q..",
            L"Q....",
            L"...Q.",
            L".Q..."
        },
        {
            L".Q...",
            L"....Q",
            L"..Q..",
            L"Q....",
            L"...Q."
        },
        {
            L"....Q",
            L".Q...",
            L"...Q.",
            L"Q....",
            L"..Q.."
        },
        {
            L"...Q.",
            L".Q...",
            L"....Q",
            L"..Q..",
            L"Q...."
        },
        {
            L"..Q..",
            L"....Q",
            L".Q...",
            L"...Q.",
            L"Q...."
        }
    };

    int size6 = 6;
    std::vector<std::vector<std::wstring>> result6 =
    {
        {
            L"...Q..",
            L"Q.....",
            L"....Q.",
            L".Q....",
            L".....Q",
            L"..Q..."
        },
        {
            L"....Q.",
            L"..Q...",
            L"Q.....",
            L".....Q",
            L"...Q..",
            L".Q...."
        },
        {
            L".Q....",
            L"...Q..",
            L".....Q",
            L"Q.....",
            L"..Q...",
            L"....Q."
        },
        {
            L"..Q...",
            L".....Q",
            L".Q....",
            L"....Q.",
            L"Q.....",
            L"...Q.."
        }
    };

    TestQueensPositioning(size1, result1);
    TestQueensPositioning(size2, result2);
    TestQueensPositioning(size3, result3);
    TestQueensPositioning(size4, result4);
    TestQueensPositioning(size5, result5);
    TestQueensPositioning(size6, result6);
}

/**
 * Tests the logic of position queens.
 */
void QueensPositioningUnitTest::TestQueensPositioning(
    int size,
    const std::vector<std::vector<std::wstring>>& expectedResult)
{
    problems::QueensPositioning positionQueens;
    std::vector<std::vector<std::wstring>> result = positionQueens.PositionQueens(size);

    base::TwoDimensionalVector<std::wstring> resultTwoDimensionalVector(result);
    base::TwoDimensionalVector<std::wstring> expectedResultTwoDimensionalVector(expectedResult);

    GetAssertion().AssertEqualsWithIterables(
        resultTwoDimensionalVector,
        expectedResultTwoDimensionalVector,
        L"Invalid logic for position queens.");
}
