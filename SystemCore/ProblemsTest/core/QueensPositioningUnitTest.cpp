#include "QueensPositioningUnitTest.h"
#include "UnitTestFunction.h"
#include "QueensPositioning.h"
#include "TwoDimensionalVector.h"
#include <limits>
#include <stdexcept>

using namespace std;

using namespace problems_test;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        nextPermutation<int>(nums);
    }

private:
    template <typename T>
    static void nextPermutation(vector<T>& values) {
        if (values.empty()) {
            return;
        }

        size_t length = values.size();
        size_t startIndex = 0;
        size_t endIndex = length - 1;
        size_t firstDecreasingIndex = 0;

        bool status = findFirstDecreasingIndex<T>(
            values,
            startIndex,
            endIndex,
            firstDecreasingIndex);

        if (!status) {
            quicksort<T>(values);
            return;
        }

        const T& firstDecreasingValue = values[firstDecreasingIndex];

        size_t swapIndex = 0;
        status = findSwapIndex<T>(
            values,
            firstDecreasingIndex + 1,
            endIndex,
            firstDecreasingValue,
            swapIndex);

        if (!status) {
            throw invalid_argument("Failed finding swap index.");
        }

        swap<T>(values, firstDecreasingIndex, swapIndex);
        quicksort(values, firstDecreasingIndex + 1, endIndex);
    }

    template <typename T>
    static bool findFirstDecreasingIndex(
        const vector<T>& values,
        size_t startIndex,
        size_t endIndex,
        size_t& firstDecreasingIndex) {

        assert(startIndex < values.size());
        assert(endIndex >= startIndex && endIndex < values.size());

        firstDecreasingIndex = 0;

        size_t currLength = indexesSize<size_t>(startIndex, endIndex);

        if (currLength <= 1) {
            return false;
        }

        T prevValue = values[endIndex];
        long long valueStartIndex = startIndex;

        for (long long index = endIndex - 1; index >= valueStartIndex; --index) {
            T currValue = values[index];

            if (currValue < prevValue) {
                firstDecreasingIndex = index;
                return true;
            }

            prevValue = currValue;
        }

        return false;
    }

    template <typename T>
    static bool findSwapIndex(
        const vector<T>& values,
        size_t startIndex,
        size_t endIndex,
        const T& firstDecreasingValue,
        size_t& swapIndex) {

        swapIndex = 0;
        T swapValue = numeric_limits<T>::max();
        bool foundSwapIndex = false;

        for (size_t index = startIndex; index <= endIndex; ++index) {
            const T& currValue = values[index];

            if (currValue > firstDecreasingValue) {
                if (!foundSwapIndex || currValue < swapValue) {
                    swapIndex = index;
                    swapValue = currValue;
                    foundSwapIndex = true;
                }
            }
        }

        return foundSwapIndex;
    }

    template <typename T>
    static void quicksort(vector<T>& values) {
        size_t length = values.size();
        size_t startIndex = 0;
        size_t endIndex = length - 1;

        quicksort(values, startIndex, endIndex);
    }

    template <typename T>
    static void quicksort(vector<T>& values, size_t startIndex, size_t endIndex) {
        assert(startIndex <= endIndex);

        if (startIndex >= endIndex) {
            return;
        }

        size_t pivotIndex = startIndex + ((endIndex - startIndex) >> 1);

        size_t partitionIndex = partition(values, startIndex, endIndex, pivotIndex);

        if (partitionIndex > 0) {
            quicksort(values, startIndex, partitionIndex - 1);
        }

        if (partitionIndex < endIndex) {
            quicksort(values, partitionIndex + 1, endIndex);
        }
    }

    template <typename T>
    static size_t partition(
        vector<T>& values,
        size_t startIndex,
        size_t endIndex,
        size_t pivotIndex) {

        T pivotValue = values[pivotIndex];
        swap<T>(values, pivotIndex, endIndex);

        size_t insertIndex = startIndex;

        for (size_t index = startIndex; index < endIndex; ++index) {
            const T& currValue = values[index];

            if (currValue < pivotValue) {
                swap<T>(values, index, insertIndex);
                ++insertIndex;
            }
        }

        swap<T>(values, endIndex, insertIndex);
        return insertIndex;
    }

    template <typename T>
    static void swap(vector<T>& values, size_t index1, size_t index2) {
        T temp = values[index1];
        values[index1] = values[index2];
        values[index2] = temp;
    }

    template <typename T>
    static size_t indexesSize(const T& startIndex, const T& endIndex) {
        return startIndex <= endIndex ? endIndex - startIndex + 1 : 0;
    }
};

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

    Solution solution;

    vector<int> data = {2,1,3};
    solution.nextPermutation(data);

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
