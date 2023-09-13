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

class FindPathsWithBreadthFirstSearchTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    FindPathsWithBreadthFirstSearchTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction("findPathsWithBreadthFirstSearch", unitTest)
    {
    }

    virtual ~FindPathsWithBreadthFirstSearchTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().findPathsWithBreadthFirstSearchTest();
    }
};

class FindPathsWithDepthFirstSearchTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    FindPathsWithDepthFirstSearchTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction("findPathsWithDepthFirstSearchTest", unitTest)
    {
    }

    virtual ~FindPathsWithDepthFirstSearchTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().findPathsWithDepthFirstSearchTest();
    }
};

class FindShortestPathsTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    FindShortestPathsTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction("findShortestPathsTest", unitTest)
    {
    }

    virtual ~FindShortestPathsTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().findShortestPathsTest();
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
    registration.registerTest(unit_testing::ITestFunctionPtr(new FindPathsWithBreadthFirstSearchTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new FindPathsWithDepthFirstSearchTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new FindShortestPathsTestFunction(*this)));
}

/**
 * Tests whether a graph has a loop.
 */
void GraphUnitTest::loopDetectionTest()
{
    std::vector<GraphDataSharedPtr<int, std::string>> graphsData;
    m_testData.getGraphData()->getGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::string> graphData : graphsData)
    {
        testLoopDetection(*graphData, false);
    }

    std::vector<GraphDataSharedPtr<int, std::string>> graphsDataWithLoops;
    m_testData.getGraphData()->getGraphsDataWithLoops(graphsDataWithLoops);

    for (GraphDataSharedPtr<int, std::string> graphData : graphsDataWithLoops)
    {
        testLoopDetection(*graphData, true);
    }
}

/**
 * Tests the logic of a topological search of a graph.
 */
void GraphUnitTest::topologicalSearchTest()
{
    std::vector<GraphDataSharedPtr<int, std::string>> graphsData;
    m_testData.getGraphData()->getGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::string> graphData : graphsData)
    {
        testTopologicalSearch(*graphData);
    }
}

/**
 * Tests the logic of finding paths in a graph by performing a Breadth-First search.
 */
void GraphUnitTest::findPathsWithBreadthFirstSearchTest()
{
    std::vector<GraphDataSharedPtr<int, std::string>> graphsData;
    m_testData.getGraphData()->getGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::string> graphData : graphsData)
    {
        testFindPathsWithBreadthFirstSearch(*graphData);
    }
}

/**
 * Tests the logic of finding paths in a graph by performing a Depth-First search.
 */
void GraphUnitTest::findPathsWithDepthFirstSearchTest()
{
    std::vector<GraphDataSharedPtr<int, std::string>> graphsData;
    m_testData.getGraphData()->getGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::string> graphData : graphsData)
    {
        testFindPathsWithDepthFirstSearch(*graphData);
    }
}

/**
 * Tests the logic of finding shortest paths in a graph.
 */
void GraphUnitTest::findShortestPathsTest()
{
    std::vector<GraphDataSharedPtr<int, std::string>> graphsData;
    m_testData.getGraphData()->getGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::string> graphData : graphsData)
    {
        testFindShortestPaths(*graphData);
    }
}
