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
                explicit GraphUnitTest(const std::string& name);

                /**
                 * The GraphUnitTest destructor.
                 */
                virtual ~GraphUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests whether a graph has a loop.
                 */
                void loopDetectionTest();

                /**
                 * Tests the logic of a topological search of a graph.
                 */
                void topologicalSearchTest();

                /**
                 * Tests the logic of finding paths in a graph by performing a Breadth-First search.
                 */
                void findPathsWithBreadthFirstSearchTest();

                /**
                 * Tests the logic of finding paths in a graph by performing a Depth-First search.
                 */
                void findPathsWithDepthFirstSearchTest();

                /**
                 * Tests the logic of finding shortest paths in a graph.
                 */
                void findShortestPathsTest();

            private:
                /**
                 * Tests the logic of a loop detection of a graph.
                 */
                template <typename TKey, typename TValue>
                void testLoopDetection(
                    const GraphData<TKey, TValue>& data,
                    bool expectedStatus);

                /**
                 * Tests the logic of a topological search of a graph.
                 */
                template <typename TKey, typename TValue>
                void testTopologicalSearch(const GraphData<TKey, TValue>& data);

                /**
                 * Tests the logic of finding paths in a graph by performing a Breadth-First search.
                 */
                template <typename TKey, typename TValue>
                void testFindPathsWithBreadthFirstSearch(const GraphData<TKey, TValue>& data);

                /**
                 * Tests the logic of finding paths in a graph by performing a Depth-First search.
                 */
                template <typename TKey, typename TValue>
                void testFindPathsWithDepthFirstSearch(const GraphData<TKey, TValue>& data);

                /**
                 * Tests the logic of finding paths in a graph.
                 */
                template <typename TKey, typename TValue>
                void testFindPaths(
                    IPathFinder<TKey, TValue>& pathFinder,
                    const RoutesPaths<TKey, TValue>& routesData,
                    const std::string& method);

                /**
                 * Tests the logic of finding shortest paths in a graph.
                 */
                template <typename TKey, typename TValue>
                void testFindShortestPaths(const GraphData<TKey, TValue>& data);

                /**
                 * Creates a graph.
                 */
                template <typename TKey, typename TValue>
                IGraphSharedPtr<TKey, TValue> createGraph(const GraphData<TKey, TValue>& data);

                TestData m_testData;
            };

            /**
             * Tests the logic of a loop detection of a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::testLoopDetection(
                const GraphData<TKey, TValue>& data,
                bool expectedStatus)
            {
                IGraphSharedPtr<TKey, TValue> graph = createGraph(data);

                GraphLogic<TKey, TValue> graphLogic(*graph);
                bool status = graphLogic.detectLoop();

                getAssertion().assertEquals(
                    status,
                    expectedStatus,
                    "Incorrect logic of a loop detection in a graph.");
            }

            /**
             * Tests the logic of a topological search of a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::testTopologicalSearch(const GraphData<TKey, TValue>& data)
            {
                IGraphSharedPtr<TKey, TValue> graph = createGraph(data);
                GraphLogic<TKey, TValue> graphLogic(*graph);

                std::list<IVertexSharedPtr<TKey, TValue>> result;
                graphLogic.topologicalSearch(result);

                const base::ITwoDimensionalVector<IVertexSharedPtr<TKey, TValue>>& expectedTopologicalSearch =
                    data.getTopologicalSearch();

                base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> iterator =
                    base::ListIterator<IVertexSharedPtr<TKey, TValue>>::make(result);

                base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> expectedIterator =
                    expectedTopologicalSearch.getIterator();

                std::string topologicalSearchResult =
                    "TopologicalSearch: " + base::Collections::dereferenceIteratorToString(*iterator);

                std::string expectedTopologicalSearchResult =
                    "ExpectedTopologicalSearch: " + base::Collections::dereferenceIteratorToString(*expectedIterator);

                getMessageWriter().writeInformationalMessage(topologicalSearchResult);
                getMessageWriter().writeInformationalMessage(expectedTopologicalSearchResult);

                getAssertion().assertEqualsWithDereferenceIterators(
                    *iterator,
                    *expectedIterator,
                    "Incorrect logic of a topological search in a graph.");
            }

            /**
             * Tests the logic of finding paths in a graph by performing a Breadth-First search.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::testFindPathsWithBreadthFirstSearch(const GraphData<TKey, TValue>& data)
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
                    virtual void findPaths(
                        const IRoute<TKey, TValue>& route,
                        std::list<IWalkSharedPtr<TKey, TValue>>& result) override
                    {
                        GraphLogic<TKey, TValue> graphLogic(m_graph);
                        graphLogic.findPathsWithBreadthFirstSearch(route, result);
                    }

                private:
                    const IGraph<TKey, TValue>& m_graph;
                };

                IGraphSharedPtr<TKey, TValue> graph = createGraph(data);
                PathFinder pathFinder(*graph);
                std::string method("Breadth First Search");

                testFindPaths(
                    pathFinder,
                    data.getPaths(),
                    method);
            }

            /**
             * Tests the logic of finding paths in a graph by performing a Depth-First search.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::testFindPathsWithDepthFirstSearch(const GraphData<TKey, TValue>& data)
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
                    virtual void findPaths(
                        const IRoute<TKey, TValue>& route,
                        std::list<IWalkSharedPtr<TKey, TValue>>& result) override
                    {
                        GraphLogic<TKey, TValue> graphLogic(m_graph);
                        graphLogic.findPathsWithDepthFirstSearch(route, result);
                    }

                private:
                    const IGraph<TKey, TValue>& m_graph;
                };

                IGraphSharedPtr<TKey, TValue> graph = createGraph(data);
                PathFinder pathFinder(*graph);
                std::string method("Breadth First Search");

                testFindPaths(
                    pathFinder,
                    data.getPaths(),
                    method);
            }

            /**
             * Tests the logic of finding paths in a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::testFindPaths(
                IPathFinder<TKey, TValue>& pathFinder,
                const RoutesPaths<TKey, TValue>& routesData,
                const std::string& method)
            {
                for (const std::pair<IRouteSharedPtr<TKey, TValue>, std::vector<IWalkSharedPtr<TKey, TValue>>>& routeData : routesData)
                {
                    IRouteSharedPtr<TKey, TValue> route = routeData.first;
                    const std::vector<IWalkSharedPtr<TKey, TValue>>& expectedPaths = routeData.second;

                    std::list<IWalkSharedPtr<TKey, TValue>> paths;
                    pathFinder.findPaths(*route, paths);

                    paths.sort();

                    base::IIteratorSharedPtr<IWalkSharedPtr<TKey, TValue>> pathIterator =
                    base::ListIterator<IWalkSharedPtr<TKey, TValue>>::make(paths);

                    base::IIteratorSharedPtr<IWalkSharedPtr<TKey, TValue>> expectedPathIterator =
                    base::VectorIterator<IWalkSharedPtr<TKey, TValue>>::make(expectedPaths);

                    getAssertion().assertEqualsWithDereferenceIterators(
                        *pathIterator,
                        *expectedPathIterator,
                        "Incorrect logic of finding paths with a " + method + " in a graph.");
                }
            }

            /**
             * Tests the logic of finding shortest paths in a graph.
             */
            template <typename TKey, typename TValue>
            void GraphUnitTest::testFindShortestPaths(const GraphData<TKey, TValue>& data)
            {
                IGraphSharedPtr<TKey, TValue> graph = createGraph(data);
                GraphLogic<TKey, TValue> graphLogic(*graph);

                const EdgeWeightMap<TKey, TValue>& weights = data.getWeights();
                const GraphShortestPathsMap<TKey, TValue>& graphShortestPaths = data.getShortestPaths();

                for (IVertexSharedPtr<TKey, TValue> vertex : data.vertices())
                {
                    VertexShortestPathsMap<TKey, TValue> result;
                    graphLogic.findShortestPaths(
                        vertex,
                        weights,
                        result);

                    typename GraphShortestPathsMap<TKey, TValue>::const_iterator vertexShortestPathsIterator =
                        graphShortestPaths.find(vertex);

                    const VertexShortestPathsMap<TKey, TValue>& expectedResult = vertexShortestPathsIterator->second;

                    IEquatableComparatorSharedPtr<IVertexSharedPtr<TKey, TValue>> keyComparator =
                        DereferenceEquatableComparator<IVertexSharedPtr<TKey, TValue>>::make();

                    IEquatableComparatorSharedPtr<long> valueComparator = EquatableComparator<long>::make();

                    base::EqualBuilder equalBuilder;
                    bool status = equalBuilder.withMap(
                        result,
                        expectedResult,
                        *keyComparator,
                        *valueComparator).build();

                    getAssertion().assertTrue(
                        true,
                        "Incorrect logic of calculating shortest paths in a graph.");
                }
            }

            /**
             * Creates a graph.
             */
            template <typename TKey, typename TValue>
            IGraphSharedPtr<TKey, TValue> GraphUnitTest::createGraph(const GraphData<TKey, TValue>& data)
            {
                IGraphDefinitionSharedPtr<TKey, TValue> graphDefinition = GraphDefinition<TKey, TValue>::make(data.vertices(), data.edges());
                IGraphSharedPtr<TKey, TValue> graph = GraphBuilder<TKey, TValue>::make(*graphDefinition);

                std::string informationalMessage = "Created Graph: " + graph->toString();
                getMessageWriter().writeInformationalMessage(informationalMessage);

                return graph;
            }

        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
