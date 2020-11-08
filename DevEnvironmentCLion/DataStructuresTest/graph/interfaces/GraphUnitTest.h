#ifndef GRAPH_UNIT_TEST_H_2bddf68c_ce8d_4358_87c2_545c69a0edb6
#define GRAPH_UNIT_TEST_H_2bddf68c_ce8d_4358_87c2_545c69a0edb6

#include "UnitTestBase.h"
#include "GraphData.h"
#include "GraphDefinition.h"
#include "TestData.h"
#include "GraphBuilder.h"

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

            private:
                /**
                 * Tests the logic of a loop detection of a graph.
                 */
                template <typename TKey, typename TValue>
                void testLoopDetection(
                    const GraphData<TKey, TValue>& data,
                    bool expectedStatus);

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
            }

            /**
             * Creates a graph.
             */
            template <typename TKey, typename TValue>
            IGraphPtr<TKey, TValue> GraphUnitTest::createGraph(const GraphData<TKey, TValue>& data)
            {
                IGraphDefinitionPtr<TKey, TValue> graphDefinition = GraphDefinition<TKey, TValue>::make(data.vertices(), data.edges());
                IGraphPtr<TKey, TValue> graph = GraphBuilder<TKey, TValue>::make(*graphDefinition);
                return graph;
            }

        }
    }
}

#endif // BINARY_TREE_UNIT_TEST_H_40f4a988_3353_4ccb_a0bd_68fbecc5070f
