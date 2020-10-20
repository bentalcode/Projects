#include "PreCompiled.h"

#include "WordFinderUnitTest.h"
#include "UnitTestFunction.h"
#include "WordFinder.h"
#include "TwoDimensionalVectorIterator.h"

using namespace problems_test;

class TestWordFinderFunction : public unit_testing::UnitTestFunction<WordFinderUnitTest>
{
public:
    TestWordFinderFunction(WordFinderUnitTest& unitTest) :
        UnitTestFunction("wordFinderTest", unitTest)
    {
    }

    virtual ~TestWordFinderFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().wordFinderTest();
    }
};

/**
 * The WordFinderUnitTest constructor.
 */
WordFinderUnitTest::WordFinderUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The WordFinderUnitTest destructor.
 */
WordFinderUnitTest::~WordFinderUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void WordFinderUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestWordFinderFunction(*this)));
}

/**
 * Tests the logic of a word finder.
 */
void WordFinderUnitTest::wordFinderTest()
{
    base::Matrix<char> matrix =
    {
        {'a', 'b', 'c'},
        {'b', 'a', 'b'},
        {'a', 'b', 'a'}
    };

    std::vector<std::vector<base::Position>> paths =
    {
        {base::Position(0, 0), base::Position(0, 1)},
        {base::Position(0, 0), base::Position(1, 0)},
        {base::Position(1, 1), base::Position(1, 0)},
        {base::Position(1, 1), base::Position(1, 2)},
        {base::Position(1, 1), base::Position(0, 1)},
        {base::Position(1, 1), base::Position(2, 1)},
        {base::Position(2, 0), base::Position(2, 1)},
        {base::Position(2, 0), base::Position(1, 0)},
        {base::Position(2, 2), base::Position(2, 1)},
        {base::Position(2, 2), base::Position(1, 2)}
    };

    testWordFinder(matrix, "ab", paths);
}

/**
 * Tests the logic of a word finder.
 */
void WordFinderUnitTest::testWordFinder(
    const base::Matrix<char>& matrix,
    const std::string& word,
    std::vector<std::vector<base::Position>> expectedResult)
{
    base::IFinderPtr<std::vector<std::vector<base::Position>>> finderPtr(new problems::WordFinder(matrix, word));

    std::vector<std::vector<base::Position>> result = finderPtr->find();

    base::IIteratorPtr<base::Position> resultIterator(new base::TwoDimensionalListIterator<base::Position>(result));
    base::IIteratorPtr<base::Position> expectedResultIterator(new base::TwoDimensionalListIterator<base::Position>(result));

    getAssertion().assertEqualsWithIterators(
        *resultIterator,
        *expectedResultIterator,
        "Incorrect logic for finding all paths of a word.");
}
