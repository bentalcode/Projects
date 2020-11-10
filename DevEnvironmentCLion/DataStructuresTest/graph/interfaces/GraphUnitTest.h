#ifndef GRAPH_UNIT_TEST_H_2bddf68c_ce8d_4358_87c2_545c69a0edb6
#define GRAPH_UNIT_TEST_H_2bddf68c_ce8d_4358_87c2_545c69a0edb6

#include "UnitTestBase.h"
#include "GraphData.h"
#include "GraphDefinition.h"
#include "TestData.h"
#include "GraphBuilder.h"
#include "GraphLogic.h"
#include "ListIterator.h"
#include "Collections.h"

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
                 * Creates a graph.
                 */
                template <typename TKey, typename TValue>
                IGraphPtr<TKey, TValue> createGraph(const GraphData<TKey, TValue>& data);

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
                IGraphPtr<TKey, TValue> graph = createGraph(data);

                GraphLogic<TKey, TValue> graphLogic(graph);
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
                IGraphPtr<TKey, TValue> graph = createGraph(data);
                GraphLogic<TKey, TValue> graphLogic(graph);

                std::list<IVertexPtr<TKey, TValue>> result;
                graphLogic.topologicalSearch(result);

                const base::ITwoDimensionalVector<IVertexPtr<TKey, TValue>>& expectedTopologicalSearch =
                    data.getTopologicalSearch();

                base::IIteratorPtr<IVertexPtr<TKey, TValue>> iterator =
                    base::ListIterator<IVertexPtr<TKey, TValue>>::make(result);

                base::IIteratorPtr<IVertexPtr<TKey, TValue>> expectedIterator =
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
             * Creates a graph.
             */
            template <typename TKey, typename TValue>
            IGraphPtr<TKey, TValue> GraphUnitTest::createGraph(const GraphData<TKey, TValue>& data)
            {
                IGraphDefinitionPtr<TKey, TValue> graphDefinition = GraphDefinition<TKey, TValue>::make(data.vertices(), data.edges());
                IGraphPtr<TKey, TValue> graph = GraphBuilder<TKey, TValue>::make(*graphDefinition);

                std::string informationalMessage = "Created Graph: " + graph->toString();
                getMessageWriter().writeInformationalMessage(informationalMessage);

                return graph;
            }

        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
