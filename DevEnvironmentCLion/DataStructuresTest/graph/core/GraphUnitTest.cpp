#include "PreCompiled.h"

#include "GraphUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures::graph;

class LoopDetectionTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    LoopDetectionTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction("loopDetectionTest", unitTest)
    {
    }

    virtual ~LoopDetectionTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().loopDetectionTest();
    }
};

class TopologicalSearchTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    TopologicalSearchTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction("topologicalSearchTest", unitTest)
    {
    }

    virtual ~TopologicalSearchTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().topologicalSearchTest();
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
    registration.registerTest(unit_testing::ITestFunctionPtr(new LoopDetectionTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TopologicalSearchTestFunction(*this)));
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

/**
 * Tests the logic of a topological search of a graph.
 */
void GraphUnitTest::topologicalSearchTest()
{
    std::vector<GraphDataPtr<int, std::string>> graphsData;
    m_testData.getGraphData()->getGraphsData(graphsData);

    for (GraphDataPtr<int, std::string> graphData : graphsData)
    {
        testTopologicalSearch(*graphData);
    }
}
