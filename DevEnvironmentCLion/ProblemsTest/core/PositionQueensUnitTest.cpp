#include "PreCompiled.h"

#include "PositionQueensUnitTest.h"
#include "UnitTestFunction.h"
#include "PositionQueens.h"
#include "TwoDimensionalVector.h"

using namespace problems_test;

class TestPositionQueensFunction : public unit_testing::UnitTestFunction<PositionQueensUnitTest>
{
public:
    TestPositionQueensFunction(PositionQueensUnitTest& unitTest) :
        UnitTestFunction("positionQueensTest", unitTest)
    {
    }

    virtual ~TestPositionQueensFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().positionQueensTest();
    }
};

/**
 * The PositionQueensUnitTest constructor.
 */
PositionQueensUnitTest::PositionQueensUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The PositionQueensUnitTest destructor.
 */
PositionQueensUnitTest::~PositionQueensUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void PositionQueensUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestPositionQueensFunction(*this)));
}

/**
 * Tests the logic of position queens.
 */
void PositionQueensUnitTest::positionQueensTest()
{
    int size1 = 1;
    std::vector<std::vector<std::string>> result1 = {};

    int size2 = 2;
    std::vector<std::vector<std::string>> result2 = {};

    int size3 = 3;
    std::vector<std::vector<std::string>> result3 = {};

    int size4 = 4;
    std::vector<std::vector<std::string>> result4 =
    {
        {
            "..Q.",
            "Q...",
            "...Q",
            ".Q.."
        },
        {
            ".Q..",
            "...Q",
            "Q...",
            "..Q."
        }
    };

    int size5 = 5;
    std::vector<std::vector<std::string>> result5 =
    {
        {
            "Q....",
            "...Q.",
            ".Q...",
            "....Q",
            "..Q.."
        },
        {
            "Q....",
            "..Q..",
            "....Q",
            ".Q...",
            "...Q."
        },
        {
            "..Q..",
            "Q....",
            "...Q.",
            ".Q...",
            "....Q"
        },
        {
            "...Q.",
            "Q....",
            "..Q..",
            "....Q",
            ".Q..."
        },
        {
            ".Q...",
            "...Q.",
            "Q....",
            "..Q..",
            "....Q"
        },
        {
            "....Q",
            "..Q..",
            "Q....",
            "...Q.",
            ".Q..."
        },
        {
            ".Q...",
            "....Q",
            "..Q..",
            "Q....",
            "...Q."
        },
        {
            "....Q",
            ".Q...",
            "...Q.",
            "Q....",
            "..Q.."
        },
        {
            "...Q.",
            ".Q...",
            "....Q",
            "..Q..",
            "Q...."
        },
        {
            "..Q..",
            "....Q",
            ".Q...",
            "...Q.",
            "Q...."
        }
    };

    int size6 = 6;
    std::vector<std::vector<std::string>> result6 =
    {
        {
            "...Q..",
            "Q.....",
            "....Q.",
            ".Q....",
            ".....Q",
            "..Q..."
        },
        {
            "....Q.",
            "..Q...",
            "Q.....",
            ".....Q",
            "...Q..",
            ".Q...."
        },
        {
            ".Q....",
            "...Q..",
            ".....Q",
            "Q.....",
            "..Q...",
            "....Q."
        },
        {
            "..Q...",
            ".....Q",
            ".Q....",
            "....Q.",
            "Q.....",
            "...Q.."
        }
    };

    testPositionQueens(size1, result1);
    testPositionQueens(size2, result2);
    testPositionQueens(size3, result3);
    testPositionQueens(size4, result4);
    testPositionQueens(size5, result5);
    testPositionQueens(size6, result6);
}

/**
 * Tests the logic of position queens.
 */
void PositionQueensUnitTest::testPositionQueens(
    int size,
    const std::vector<std::vector<std::string>>& expectedResult)
{
    problems::PositionQueens positionQueens;
    std::vector<std::vector<std::string>> result = positionQueens.positionQueens(size);

    base::TwoDimensionalVector<std::string> resultTwoDimensionalVector(result);
    base::TwoDimensionalVector<std::string> expectedResultTwoDimensionalVector(expectedResult);

    getAssertion().assertEqualsWithIterables(
        resultTwoDimensionalVector,
        expectedResultTwoDimensionalVector,
        "Invalid logic for position queens.");
}
