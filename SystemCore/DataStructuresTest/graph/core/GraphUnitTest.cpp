#include "GraphUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures::graph;

class LoopDetectionTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    LoopDetectionTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction(L"LoopDetectionTest", unitTest)
    {
    }

    virtual ~LoopDetectionTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().LoopDetectionTest();
    }
};

class TopologicalSearchTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    TopologicalSearchTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction(L"TopologicalSearchTest", unitTest)
    {
    }

    virtual ~TopologicalSearchTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().TopologicalSearchTest();
    }
};

class FindPathsWithBreadthFirstSearchTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    FindPathsWithBreadthFirstSearchTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction(L"findPathsWithBreadthFirstSearch", unitTest)
    {
    }

    virtual ~FindPathsWithBreadthFirstSearchTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().FindPathsWithBreadthFirstSearchTest();
    }
};

class FindPathsWithDepthFirstSearchTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    FindPathsWithDepthFirstSearchTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction(L"FindPathsWithDepthFirstSearchTest", unitTest)
    {
    }

    virtual ~FindPathsWithDepthFirstSearchTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().FindPathsWithDepthFirstSearchTest();
    }
};

class FindShortestPathsTestFunction final : public unit_testing::UnitTestFunction<GraphUnitTest>
{
public:
    FindShortestPathsTestFunction(GraphUnitTest& unitTest) :
        UnitTestFunction(L"FindShortestPathsTest", unitTest)
    {
    }

    virtual ~FindShortestPathsTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().FindShortestPathsTest();
    }
};

/**
 * The GraphUnitTest constructor.
 */
GraphUnitTest::GraphUnitTest(const std::wstring& name) :
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
void GraphUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new LoopDetectionTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TopologicalSearchTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new FindPathsWithBreadthFirstSearchTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new FindPathsWithDepthFirstSearchTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new FindShortestPathsTestFunction(*this)));
}

/**
 * Tests whether a graph Has a loop.
 */
void GraphUnitTest::LoopDetectionTest()
{
    std::vector<GraphDataSharedPtr<int, std::wstring>> graphsData;
    m_testData.GetGraphData()->GetGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::wstring> graphData : graphsData)
    {
        TestLoopDetection(*graphData, false);
    }

    std::vector<GraphDataSharedPtr<int, std::wstring>> graphsDataWithLoops;
    m_testData.GetGraphData()->GetGraphsDataWithLoops(graphsDataWithLoops);

    for (GraphDataSharedPtr<int, std::wstring> graphData : graphsDataWithLoops)
    {
        TestLoopDetection(*graphData, true);
    }
}

/**
 * Tests the logic of a topological search of a graph.
 */
void GraphUnitTest::TopologicalSearchTest()
{
    std::vector<GraphDataSharedPtr<int, std::wstring>> graphsData;
    m_testData.GetGraphData()->GetGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::wstring> graphData : graphsData)
    {
        TestTopologicalSearch(*graphData);
    }
}

/**
 * Tests the logic of finding paths in a graph by performing a Breadth-First search.
 */
void GraphUnitTest::FindPathsWithBreadthFirstSearchTest()
{
    std::vector<GraphDataSharedPtr<int, std::wstring>> graphsData;
    m_testData.GetGraphData()->GetGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::wstring> graphData : graphsData)
    {
        TestFindPathsWithBreadthFirstSearch(*graphData);
    }
}

/**
 * Tests the logic of finding paths in a graph by performing a Depth-First search.
 */
void GraphUnitTest::FindPathsWithDepthFirstSearchTest()
{
    std::vector<GraphDataSharedPtr<int, std::wstring>> graphsData;
    m_testData.GetGraphData()->GetGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::wstring> graphData : graphsData)
    {
        TestFindPathsWithDepthFirstSearch(*graphData);
    }
}

/**
 * Tests the logic of finding shortest paths in a graph.
 */
void GraphUnitTest::FindShortestPathsTest()
{
    std::vector<GraphDataSharedPtr<int, std::wstring>> graphsData;
    m_testData.GetGraphData()->GetGraphsData(graphsData);

    for (GraphDataSharedPtr<int, std::wstring> graphData : graphsData)
    {
        TestFindShortestPaths(*graphData);
    }
}
