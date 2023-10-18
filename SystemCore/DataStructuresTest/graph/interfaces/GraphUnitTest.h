#ifndef GRAPH_UNIT_TEST_H_2bddf68c_ce8d_4358_87c2_545c69a0edb6
#define GRAPH_UNIT_TEST_H_2bddf68c_ce8d_4358_87c2_545c69a0edb6

#include "UnitTestBase.h"
#include "GraphData.h"
#include "GraphDefinition.h"
#include "TestData.h"
#include "GraphBuilder.h"
#include "GraphLogic.h"
#include "IPathFinder.h"
#include "VectorIterator.h"
#include "ListIterator.h"
#include "Collections.h"
#include "Sorting.h"
#include "EqualBuilder.h"

using namespace datastructures::graph;

namespace test {
    namespace datastructures {
        namespace graph {

            /**
             * The GraphUnitTest class implements a unit test of a graph.
             */
            class GraphUnitTest final : public unit_testing::UnitTestBase
            {
            public:
                /**
                 * The GraphUnitTest constructor.
                 */
                explicit GraphUnitTest(const std::wstring& name);

                /**
                 * The GraphUnitTest destructor.
                 */
                virtual ~GraphUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests whether a graph Has a loop.
                 */
                void LoopDetectionTest();

                /**
                 * Tests the logic of a topological search of a graph.
                 */
                void TopologicalSearchTest();

                /**
                 * Tests the logic of finding paths in a graph by performing a Breadth-First search.
                 */
                void FindPathsWithBreadthFirstSearchTest();

                /**
                 * Tests the logic of finding paths in a graph by performing a Depth-First search.
                 */
                void FindPathsWithDepthFirstSearchTest();

                /**
                 * Tests the logic of finding shortest paths in a graph.
                 */
                void FindShortestPathsTest();

            private:
                /**
                 * Tests the logic of a loop detection of a graph.
                 */
                template <typename TKey, typename TValue>
                void TestLoopDetection(
                    const GraphData<TKey, TValue>& data,
                    bool expectedStatus);

                /**
                 * Tests the logic of a topological search of a graph.
                 */
                template <typename TKey, typename TValue>
                void TestTopologicalSearch(const GraphData<TKey, TValue>& data);

                /**
                 * Tests the logic of finding paths in a graph by performing a Breadth-First search.
                 */
                template <typename TKey, typename TValue>
                void TestFindPathsWithBreadthFirstSearch(const GraphData<TKey, TValue>& data);

                /**
                 * Tests the logic of finding paths in a graph by performing a Depth-First search.
                 */
                template <typename TKey, typename TValue>
                void TestFindPathsWithDepthFirstSearch(const GraphData<TKey, TValue>& data);

                /**
                 * Tests the logic of finding paths in a graph.
                 */
                template <typename TKey, typename TValue>
                void TestFindPaths(
                    IPathFinder<TKey, TValue>& pathFinder,
                    const RoutesPaths<TKey, TValue>& routesData,
                    const std::wstring& method);

                /**
                 * Tests the logic of finding shortest paths in a graph.
                 */
                template <typename TKey, typename TValue>
                void TestFindShortestPaths(const GraphData<TKey, TValue>& data);

                /**
                 * Creates a graph.
                 */
                template <typename TKey, typename TValue>
                IGraphSharedPtr<TKey, TValue> CreateGraph(const GraphData<TKey, TValue>& data);

                TestData m_testData;
            };

            /**
             * Tests the logic of a loop detection of a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::TestLoopDetection(
                const GraphData<TKey, TValue>& data,
                bool expectedStatus)
            {
                IGraphSharedPtr<TKey, TValue> graph = CreateGraph(data);

                GraphLogic<TKey, TValue> graphLogic(*graph);
                bool status = graphLogic.DetectLoop();

                GetAssertion().AssertEquals(
                    status,
                    expectedStatus,
                    L"Incorrect logic of a loop detection in a graph.");
            }

            /**
             * Tests the logic of a topological search of a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::TestTopologicalSearch(const GraphData<TKey, TValue>& data)
            {
                IGraphSharedPtr<TKey, TValue> graph = CreateGraph(data);
                GraphLogic<TKey, TValue> graphLogic(*graph);

                std::list<IVertexSharedPtr<TKey, TValue>> result;
                graphLogic.TopologicalSearch(result);

                const base::ITwoDimensionalVector<IVertexSharedPtr<TKey, TValue>>& expectedTopologicalSearch =
                    data.GetTopologicalSearch();

                base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> iterator =
                    base::ListIterator<IVertexSharedPtr<TKey, TValue>>::Make(result);

                base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> expectedIterator =
                    expectedTopologicalSearch.GetIterator();

                std::wstring topologicalSearchResult =
                    L"TopologicalSearch: " + base::Collections::DereferenceIteratorToString(*iterator);

                std::wstring expectedTopologicalSearchResult =
                    L"ExpectedTopologicalSearch: " + base::Collections::DereferenceIteratorToString(*expectedIterator);

                GetMessageWriter().WriteInformationalMessage(topologicalSearchResult);
                GetMessageWriter().WriteInformationalMessage(expectedTopologicalSearchResult);

                GetAssertion().AssertEqualsWithDereferenceIterators(
                    *iterator,
                    *expectedIterator,
                    L"Incorrect logic of a topological search in a graph.");
            }

            /**
             * Tests the logic of finding paths in a graph by performing a Breadth-First search.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::TestFindPathsWithBreadthFirstSearch(const GraphData<TKey, TValue>& data)
            {
                class PathFinder final : public IPathFinder<TKey, TValue>
                {
                public:
                    PathFinder(const IGraph<TKey, TValue>& graph) : m_graph(graph)
                    {
                    }

                    virtual ~PathFinder()
                    {
                    }

                    /**
                     * Finds paths.
                     */
                    virtual void FindPaths(
                        const IRoute<TKey, TValue>& route,
                        std::list<IWalkSharedPtr<TKey, TValue>>& result) override
                    {
                        GraphLogic<TKey, TValue> graphLogic(m_graph);
                        graphLogic.FindPathsWithBreadthFirstSearch(route, result);
                    }

                private:
                    const IGraph<TKey, TValue>& m_graph;
                };

                IGraphSharedPtr<TKey, TValue> graph = CreateGraph(data);
                PathFinder pathFinder(*graph);
                std::wstring method(L"Breadth First Search");

                TestFindPaths(
                    pathFinder,
                    data.GetPaths(),
                    method);
            }

            /**
             * Tests the logic of finding paths in a graph by performing a Depth-First search.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::TestFindPathsWithDepthFirstSearch(const GraphData<TKey, TValue>& data)
            {
                class PathFinder final : public IPathFinder<TKey, TValue>
                {
                public:
                    PathFinder(const IGraph<TKey, TValue>& graph) : m_graph(graph)
                    {
                    }

                    virtual ~PathFinder()
                    {
                    }

                    /**
                     * Finds paths.
                     */
                    virtual void FindPaths(
                        const IRoute<TKey, TValue>& route,
                        std::list<IWalkSharedPtr<TKey, TValue>>& result) override
                    {
                        GraphLogic<TKey, TValue> graphLogic(m_graph);
                        graphLogic.FindPathsWithDepthFirstSearch(route, result);
                    }

                private:
                    const IGraph<TKey, TValue>& m_graph;
                };

                IGraphSharedPtr<TKey, TValue> graph = CreateGraph(data);
                PathFinder pathFinder(*graph);
                std::wstring method(L"Breadth First Search");

                TestFindPaths(
                        pathFinder,
                        data.GetPaths(),
                        method);
            }

            /**
             * Tests the logic of finding paths in a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::TestFindPaths(
                IPathFinder<TKey, TValue>& pathFinder,
                const RoutesPaths<TKey, TValue>& routesData,
                const std::wstring& method)
            {
                for (const std::pair<IRouteSharedPtr<TKey, TValue>, std::vector<IWalkSharedPtr<TKey, TValue>>>& routeData : routesData)
                {
                    IRouteSharedPtr<TKey, TValue> route = routeData.first;
                    const std::vector<IWalkSharedPtr<TKey, TValue>>& expectedPaths = routeData.second;

                    std::list<IWalkSharedPtr<TKey, TValue>> paths;
                    pathFinder.FindPaths(*route, paths);

                    paths.sort();

                    base::IIteratorSharedPtr<IWalkSharedPtr<TKey, TValue>> pathIterator =
                    base::ListIterator<IWalkSharedPtr<TKey, TValue>>::Make(paths);

                    base::IIteratorSharedPtr<IWalkSharedPtr<TKey, TValue>> expectedPathIterator =
                    base::VectorIterator<IWalkSharedPtr<TKey, TValue>>::Make(expectedPaths);

                    GetAssertion().AssertEqualsWithDereferenceIterators(
                        *pathIterator,
                        *expectedPathIterator,
                        L"Incorrect logic of finding paths with a " + method + L" in a graph.");
                }
            }

            /**
             * Tests the logic of finding shortest paths in a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::TestFindShortestPaths(const GraphData<TKey, TValue>& data)
            {
                IGraphSharedPtr<TKey, TValue> graph = CreateGraph(data);
                GraphLogic<TKey, TValue> graphLogic(*graph);

                const EdgeWeightMap<TKey, TValue>& weights = data.GetWeights();
                const GraphShortestPathsMap<TKey, TValue>& graphShortestPaths = data.GetShortestPaths();

                for (IVertexSharedPtr<TKey, TValue> vertex : data.Vertices())
                {
                    VertexShortestPathsMap<TKey, TValue> result;
                    graphLogic.FindShortestPaths(
                        vertex,
                        weights,
                        result);

                    typename GraphShortestPathsMap<TKey, TValue>::const_iterator vertexShortestPathsIterator =
                        graphShortestPaths.find(vertex);

                    const VertexShortestPathsMap<TKey, TValue>& expectedResult = vertexShortestPathsIterator->second;

                    IEquatableComparatorSharedPtr<IVertexSharedPtr<TKey, TValue>> keyComparator =
                        DereferenceEquatableComparator<IVertexSharedPtr<TKey, TValue>>::Make();

                    IEquatableComparatorSharedPtr<long> valueComparator = EquatableComparator<long>::Make();

                    base::EqualBuilder equalBuilder;
                    bool status = equalBuilder.WithMap(
                        result,
                        expectedResult,
                        *keyComparator,
                        *valueComparator).Build();

                    GetAssertion().AssertTrue(
                        true,
                        L"Incorrect logic of calculating shortest paths in a graph.");
                }
            }

            /**
             * Creates a graph.
             */
            template <typename TKey, typename TValue>
            IGraphSharedPtr<TKey, TValue> GraphUnitTest::CreateGraph(const GraphData<TKey, TValue>& data)
            {
                IGraphDefinitionSharedPtr<TKey, TValue> graphDefinition = GraphDefinition<TKey, TValue>::Make(
                        data.Vertices(), data.Edges());
                IGraphSharedPtr<TKey, TValue> graph = GraphBuilder<TKey, TValue>::Make(*graphDefinition);

                std::wstring informationalMessage = L"Created Graph: " + graph->ToString();
                GetMessageWriter().WriteInformationalMessage(informationalMessage);

                return graph;
            }

        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
