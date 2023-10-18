#ifndef GRAPH_DATA_H_2139e609_e701_44db_a65b_d5c8af8009a3
#define GRAPH_DATA_H_2139e609_e701_44db_a65b_d5c8af8009a3

#include "IVertex.h"
#include "IEdge.h"
#include "IRoute.h"
#include "IWalk.h"
#include "ITwoDimensionalVector.h"
#include "IGraphLogic.h"

using namespace datastructures::graph;

namespace test {
    namespace datastructures {
        namespace graph {

            /**
             * The GraphData class implements test data of a graph.
             */
            template <typename TKey, typename TValue>
            class GraphData final
            {
            public:
                /**
                 * Creates a new graph data.
                 */
                static std::shared_ptr<GraphData<TKey, TValue>> Make(
                    const std::vector<IVertexSharedPtr<TKey, TValue>>& Vertices,
                    const std::vector<IEdgeSharedPtr<TKey, TValue>>& Edges);

                /**
                 * Creates a new graph data.
                 */
                static std::shared_ptr<GraphData<TKey, TValue>> Make(
                    const std::vector<IVertexSharedPtr<TKey, TValue>>& Vertices,
                    const std::vector<IEdgeSharedPtr<TKey, TValue>>& Edges,
                    const EdgeWeightMap<TKey, TValue>& weights,
                    const RoutesPaths<TKey, TValue>& paths,
                    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<TKey, TValue>> topologicalSearch,
                    const GraphShortestPathsMap<TKey, TValue>& result);

                /**
                 * The GraphData constructor.
                 */
                GraphData(
                    const std::vector<IVertexSharedPtr<TKey, TValue>>& Vertices,
                    const std::vector<IEdgeSharedPtr<TKey, TValue>>& Edges);

                /**
                 * The GraphData constructor.
                 */
                GraphData(
                    const std::vector<IVertexSharedPtr<TKey, TValue>>& Vertices,
                    const std::vector<IEdgeSharedPtr<TKey, TValue>>& Edges,
                    const EdgeWeightMap<TKey, TValue>& weights,
                    const RoutesPaths<TKey, TValue>& paths,
                    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<TKey, TValue>> topologicalSearch,
                    const GraphShortestPathsMap<TKey, TValue>& shortestPaths);

                /**
                 * The GraphData destructor.
                 */
                ~GraphData();

                /**
                 * The copy/move constructors.
                 */
                GraphData(const GraphData&) = delete;
                GraphData(GraphData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                GraphData& operator=(const GraphData&) = delete;
                GraphData& operator=(GraphData&&) = delete;

                /**
                 * Gets the Vertices of the graph.
                 */
                const std::vector<IVertexSharedPtr<TKey, TValue>>& Vertices() const;

                /**
                 * Gets the Edges of the graph.
                 */
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& Edges() const;

                /**
                 * Gets the weights of the graph.
                 */
                const EdgeWeightMap<TKey, TValue>& GetWeights() const;

                /**
                 * Gets the paths for the defined routes in the graph.
                 */
                const RoutesPaths<TKey, TValue>& GetPaths() const;

                /**
                 * Gets the topological search of the graph.
                 */
                const base::ITwoDimensionalVector<IVertexSharedPtr<TKey, TValue>>& GetTopologicalSearch() const;

                /**
                 * Gets the shortest paths in the graph.
                 */
                const GraphShortestPathsMap<TKey, TValue>& GetShortestPaths() const;

            private:
                std::vector<IVertexSharedPtr<TKey, TValue>> m_vertices;
                std::vector<IEdgeSharedPtr<TKey, TValue>> m_edges;
                EdgeWeightMap<TKey, TValue> m_weights;
                RoutesPaths<TKey, TValue> m_paths;
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<TKey, TValue>> m_topologicalSearch;
                GraphShortestPathsMap<TKey, TValue> m_shortestPaths;
            };

            //
            // Defines the SharedPtr of Graph Data...
            //
            template <typename TKey, typename TValue>
            using GraphDataSharedPtr = std::shared_ptr<GraphData<TKey, TValue>>;

            /**
             * Creates a new graph data.
             */
            template <typename TKey, typename TValue>
            std::shared_ptr<GraphData<TKey, TValue>> GraphData<TKey, TValue>::Make(
                const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges)
            {
                return std::make_shared<GraphData<TKey, TValue>>(
                    vertices,
                    edges);
            }

            /**
             * Creates a new graph data.
             */
            template <typename TKey, typename TValue>
            std::shared_ptr<GraphData<TKey, TValue>> GraphData<TKey, TValue>::Make(
                const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges,
                const EdgeWeightMap<TKey, TValue>& weights,
                const RoutesPaths<TKey, TValue>& paths,
                base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<TKey, TValue>> topologicalSearch,
                const GraphShortestPathsMap<TKey, TValue>& shortestPaths)
            {
                return std::make_shared<GraphData<TKey, TValue>>(
                    vertices,
                    edges,
                    weights,
                    paths,
                    topologicalSearch,
                    shortestPaths);
            }

            /**
             * The GraphData constructor.
             */
            template <typename TKey, typename TValue>
            GraphData<TKey, TValue>::GraphData(
                const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges) :
                m_vertices(vertices),
                m_edges(edges)
            {
            }

            /**
             * The GraphData constructor.
             */
            template <typename TKey, typename TValue>
            GraphData<TKey, TValue>::GraphData(
                const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges,
                const EdgeWeightMap<TKey, TValue>& weights,
                const RoutesPaths<TKey, TValue>& paths,
                const base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<TKey, TValue>> topologicalSearch,
                const GraphShortestPathsMap<TKey, TValue>& shortestPaths) :
                m_vertices(vertices),
                m_edges(edges),
                m_weights(weights),
                m_paths(paths),
                m_topologicalSearch(topologicalSearch),
                m_shortestPaths(shortestPaths)
            {
            }

            /**
             * The GraphData destructor.
             */
            template <typename TKey, typename TValue>
            GraphData<TKey, TValue>::~GraphData()
            {
            }

            /**
             * Gets the Vertices of the graph.
             */
            template <typename TKey, typename TValue>
            const std::vector<IVertexSharedPtr<TKey, TValue>>& GraphData<TKey, TValue>::Vertices() const
            {
                return m_vertices;
            }

            /**
             * Gets the Edges of the graph.
             */
            template <typename TKey, typename TValue>
            const std::vector<IEdgeSharedPtr<TKey, TValue>>& GraphData<TKey, TValue>::Edges() const
            {
                return m_edges;
            }

            /**
             * Gets the weights of the graph.
             */
            template <typename TKey, typename TValue>
            const EdgeWeightMap<TKey, TValue>& GraphData<TKey, TValue>::GetWeights() const
            {
                return m_weights;
            }

            /**
             * Gets the paths for the defined routes in the graph.
             */
            template <typename TKey, typename TValue>
            const RoutesPaths<TKey, TValue>& GraphData<TKey, TValue>::GetPaths() const
            {
                return m_paths;
            }

            /**
             * Gets the topological search of the graph.
             */
            template <typename TKey, typename TValue>
            const base::ITwoDimensionalVector<IVertexSharedPtr<TKey, TValue>>& GraphData<TKey, TValue>::GetTopologicalSearch() const
            {
                return *m_topologicalSearch;
            }

            /**
             * Gets the shortest paths in the graph.
             */
            template <typename TKey, typename TValue>
            const GraphShortestPathsMap<TKey, TValue>& GraphData<TKey, TValue>::GetShortestPaths() const
            {
                return m_shortestPaths;
            }

        }
    }
}

#endif // GRAPH_DATA_H_2139e609_e701_44db_a65b_d5c8af8009a3
