#include "PreCompiled.h"

#include "GraphUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures::graph;

class TestGraphLoopDetectionFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    TestGraphLoopDetectionFunction(GraphUnitTest& unitTest) :
        UnitTestFunction("loopDetectionTest", unitTest)
    {
    }

    virtual ~TestGraphLoopDetectionFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().loopDetectionTest();
    }
};

/**
 * The GraphUnitTest constructor.
 */
GraphUnitTest::GraphUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The GraphUnitTest destructor.
 */
GraphUnitTest::~GraphUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void GraphUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestGraphLoopDetectionFunction(*this)));
}

/**
 * Tests whether a graph has a loop.
 */
void GraphUnitTest::loopDetectionTest()
{
    std::vector<GraphDataPtr<int, std::string>> graphsData;
    m_testData.getGraphData()->getGraphsData(graphsData);

    for (GraphDataPtr<int, std::string> graphData : graphsData)
    {
        testLoopDetection(*graphData, false);
    }

    std::vector<GraphDataPtr<int, std::string>> graphsDataWithLoops;
    m_testData.getGraphData()->getGraphsDataWithLoops(graphsDataWithLoops);

    for (GraphDataPtr<int, std::string> graphData : graphsDataWithLoops)
    {
        testLoopDetection(*graphData, true);
    }
}
