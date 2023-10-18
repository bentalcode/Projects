#ifndef GRAPH_TEST_DATA_H_3ec5746a_bd3a_4413_b759_493d014b5dda
#define GRAPH_TEST_DATA_H_3ec5746a_bd3a_4413_b759_493d014b5dda

#include "GraphData.h"
#include "RandomGenerator.h"

using namespace datastructures::graph;

namespace test {
    namespace datastructures {
        namespace graph {

            /**
             * The GraphTestData class implements the data of the tests of a graph.
             */
            class GraphTestData final
            {
            public:
                /**
                 * The GraphTestData constructor.
                 */
                GraphTestData();

                /**
                 * The GraphTestData destructor.
                 */
                ~GraphTestData();

                /**
                 * The copy/move constructors.
                 */
                GraphTestData(const GraphTestData&) = delete;
                GraphTestData(GraphTestData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                GraphTestData& operator=(const GraphTestData&) = delete;
                GraphTestData& operator=(GraphTestData&&) = delete;

                /**
                 * Gets data of graphs.
                 */
                void GetGraphsData(std::vector<GraphDataSharedPtr<int, std::wstring>>& result);

                /**
                 * Gets data of graphs with loops.
                 */
                void GetGraphsDataWithLoops(std::vector<GraphDataSharedPtr<int, std::wstring>>& result);

                /**
                 * Generates a random vertex by integer.
                 */
                IVertexSharedPtr<int, int> NextVertexByInteger();

                /**
                 * Generates a random vertex by double.
                 */
                IVertexSharedPtr<double, double> NextVertexByDouble();

                /**
                 * Generates a random vertex by character.
                 */
                IVertexSharedPtr<char, char> NextVertexByCharacter();

                /**
                 * Generates a random vertex by string.
                 */
                IVertexSharedPtr<std::wstring, std::wstring> NextVertexByString();

                /**
                 * Generates a random edge by integer.
                 */
                IEdgeSharedPtr<int, int> NextDirectedEdgeByInteger();

                /**
                 * Generates a random edge by double.
                 */
                IEdgeSharedPtr<double, double> NextDirectedEdgeByDouble();

                /**
                 * Generates a random edge by character.
                 */
                IEdgeSharedPtr<char, char> NextDirectedEdgeByCharacter();

                /**
                 * Generates a random edge by string.
                 */
                IEdgeSharedPtr<std::wstring, std::wstring> NextDirectedEdgeByString();

            private:
                /**
                 * Gets data of graph1.
                 */
                GraphDataSharedPtr<int, std::wstring> GetGraphData1();

                /**
                 * Gets data of graph2.
                 */
                GraphDataSharedPtr<int, std::wstring> GetGraphData2();

                /**
                 * Gets data of graph3.
                 */
                GraphDataSharedPtr<int, std::wstring> GetGraphData3();

                /**
                 * Gets data of graph1.
                 */
                GraphDataSharedPtr<int, std::wstring> GetGraphDataWithLoop1();

                /**
                 * Gets the paths data of graph1.
                 */
                void GetGraphPathsData1(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
                    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>>& result);

                /**
                 * Gets the paths data of graph2.
                 */
                void GetGraphPathsData2(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
                    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>>& result);

                /**
                 * Gets the paths data of graph3.
                 */
                void GetGraphPathsData3(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
                    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>>& result);

                /**
                 * Gets the topological search data of graph1.
                 */
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> GetGraphTopologicalSearchData1(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices);

                /**
                 * Gets the topological search data of graph2.
                 */
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> GetGraphTopologicalSearchData2(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices);

                /**
                 * Gets the topological search data of graph3.
                 */
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> GetGraphTopologicalSearchData3(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices);

                /**
                 * Gets the shortest paths of graph1.
                 */
                void GetGraphShortestPaths1(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
                    GraphShortestPathsMap<int, std::wstring>& result);

                /**
                 * Gets the shortest paths of graph2.
                 */
                void GetGraphShortestPaths2(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
                    GraphShortestPathsMap<int, std::wstring>& result);

                /**
                 * Gets the shortest paths of graph3.
                 */
                void GetGraphShortestPaths3(
                    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
                    GraphShortestPathsMap<int, std::wstring>& result);

                base::RandomGenerator m_randomGenerator;
            };

            //
            // Defines the Shared Ptr of Graph Test Data...
            //
            using GraphTestDataSharedPtr = std::shared_ptr<GraphTestData>;
        }
    }
}

#endif // GRAPH_TEST_DATA_H_3ec5746a_bd3a_4413_b759_493d014b5dda
