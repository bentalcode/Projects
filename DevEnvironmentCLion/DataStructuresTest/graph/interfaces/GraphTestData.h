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
                void getGraphsData(std::vector<GraphDataSharedPtr<int, std::string>>& result);

                /**
                 * Gets data of graphs with loops.
                 */
                void getGraphsDataWithLoops(std::vector<GraphDataSharedPtr<int, std::string>>& result);

                /**
                 * Generates a random vertex by integer.
                 */
                IVertexSharedPtr<int, int> nextVertexByInteger();

                /**
                 * Generates a random vertex by double.
                 */
                IVertexSharedPtr<double, double> nextVertexByDouble();

                /**
                 * Generates a random vertex by character.
                 */
                IVertexSharedPtr<char, char> nextVertexByCharacter();

                /**
                 * Generates a random vertex by string.
                 */
                IVertexSharedPtr<std::string, std::string> nextVertexByString();

                /**
                 * Generates a random edge by integer.
                 */
                IEdgeSharedPtr<int, int> nextDirectedEdgeByInteger();

                /**
                 * Generates a random edge by double.
                 */
                IEdgeSharedPtr<double, double> nextDirectedEdgeByDouble();

                /**
                 * Generates a random edge by character.
                 */
                IEdgeSharedPtr<char, char> nextDirectedEdgeByCharacter();

                /**
                 * Generates a random edge by string.
                 */
                IEdgeSharedPtr<std::string, std::string> nextDirectedEdgeByString();

            private:
                /**
                 * Gets data of graph1.
                 */
                GraphDataSharedPtr<int, std::string> getGraphData1();

                /**
                 * Gets data of graph2.
                 */
                GraphDataSharedPtr<int, std::string> getGraphData2();

                /**
                 * Gets data of graph3.
                 */
                GraphDataSharedPtr<int, std::string> getGraphData3();

                /**
                 * Gets data of graph1.
                 */
                GraphDataSharedPtr<int, std::string> getGraphDataWithLoop1();

                /**
                 * Gets the paths data of graph1.
                 */
                void getGraphPathsData1(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices,
                    std::vector<std::pair<IRouteSharedPtr<int, std::string>, std::vector<IWalkSharedPtr<int, std::string>>>>& result);

                /**
                 * Gets the paths data of graph2.
                 */
                void getGraphPathsData2(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices,
                    std::vector<std::pair<IRouteSharedPtr<int, std::string>, std::vector<IWalkSharedPtr<int, std::string>>>>& result);

                /**
                 * Gets the paths data of graph3.
                 */
                void getGraphPathsData3(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices,
                    std::vector<std::pair<IRouteSharedPtr<int, std::string>, std::vector<IWalkSharedPtr<int, std::string>>>>& result);

                /**
                 * Gets the topological search data of graph1.
                 */
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::string>> getGraphTopologicalSearchData1(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices);

                /**
                 * Gets the topological search data of graph2.
                 */
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::string>> getGraphTopologicalSearchData2(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices);

                /**
                 * Gets the topological search data of graph3.
                 */
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::string>> getGraphTopologicalSearchData3(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices);

                /**
                 * Gets the shortest paths of graph1.
                 */
                void getGraphShortestPaths1(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices,
                    GraphShortestPathsMap<int, std::string>& result);

                /**
                 * Gets the shortest paths of graph2.
                 */
                void getGraphShortestPaths2(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices,
                    GraphShortestPathsMap<int, std::string>& result);

                /**
                 * Gets the shortest paths of graph3.
                 */
                void getGraphShortestPaths3(
                    const std::vector<IVertexSharedPtr<int, std::string>>& vertices,
                    GraphShortestPathsMap<int, std::string>& result);

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
