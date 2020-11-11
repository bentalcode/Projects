#ifndef GRAPH_DATA_H_2139e609_e701_44db_a65b_d5c8af8009a3
#define GRAPH_DATA_H_2139e609_e701_44db_a65b_d5c8af8009a3

#include "IVertex.h"
#include "IEdge.h"
#include "IRoute.h"
#include "IWalk.h"
#include "ITwoDimensionalVector.h"

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
                static std::shared_ptr<GraphData<TKey, TValue>> make(
                    const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                    const std::vector<IEdgePtr<TKey, TValue>>& edges);

                /**
                 * Creates a new graph data.
                 */
                static std::shared_ptr<GraphData<TKey, TValue>> make(
                    const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                    const std::vector<IEdgePtr<TKey, TValue>>& edges,
                    const std::map<IEdgePtr<TKey, TValue>, int>& weights,
                    const std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>>& paths,
                    base::ITwoDimensionalVectorPtr<IVertexPtr<TKey, TValue>> topologicalSearch,
                    const std::map<IVertexPtr<TKey, TValue>, std::map<IVertexPtr<TKey, TValue>, size_t>>& shortestPaths);

                /**
                 * The GraphData constructor.
                 */
                GraphData(
                        const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                        const std::vector<IEdgePtr<TKey, TValue>>& edges);

                /**
                 * The GraphData constructor.
                 */
                GraphData(
                    const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                    const std::vector<IEdgePtr<TKey, TValue>>& edges,
                    const std::map<IEdgePtr<TKey, TValue>, int>& weights,
                    const std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>>& paths,
                    base::ITwoDimensionalVectorPtr<IVertexPtr<TKey, TValue>> topologicalSearch,
                    const std::map<IVertexPtr<TKey, TValue>, std::map<IVertexPtr<TKey, TValue>, size_t>>& shortestPaths);

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
                 * Gets the vertices of the graph.
                 */
                const std::vector<IVertexPtr<TKey, TValue>>& vertices() const;

                /**
                 * Gets the edges of the graph.
                 */
                const std::vector<IEdgePtr<TKey, TValue>>& edges() const;

                /**
                 * Gets the weights of the graph.
                 */
                const std::map<IEdgePtr<TKey, TValue>, int>& getWeights() const;

                /**
                 * Gets the paths for the defined routes in the graph.
                 */
                const std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>>& getPaths() const;

                /**
                 * Gets the topological search of the graph.
                 */
                const base::ITwoDimensionalVector<IVertexPtr<TKey, TValue>>& getTopologicalSearch() const;

                /**
                 * Gets the shortest paths in the graph.
                 */
                const std::map<IVertexPtr<TKey, TValue>, std::map<IVertexPtr<TKey, TValue>, size_t>>& getShortestPaths() const;

            private:
                std::vector<IVertexPtr<TKey, TValue>> m_vertices;
                std::vector<IEdgePtr<TKey, TValue>> m_edges;
                std::map<IEdgePtr<TKey, TValue>, int> m_weights;
                std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>> m_paths;
                base::ITwoDimensionalVectorPtr<IVertexPtr<TKey, TValue>> m_topologicalSearch;
                std::map<IVertexPtr<TKey, TValue>, std::map<IVertexPtr<TKey, TValue>, size_t>> m_shortestPaths;
            };

            template <typename TKey, typename TValue>
            using GraphDataPtr = std::shared_ptr<GraphData<TKey, TValue>>;

            /**
             * Creates a new graph data.
             */
            template <typename TKey, typename TValue>
            std::shared_ptr<GraphData<TKey, TValue>> GraphData<TKey, TValue>::make(
                const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgePtr<TKey, TValue>>& edges)
            {
                return std::make_shared<GraphData<TKey, TValue>>(
                    vertices,
                    edges);
            }

            /**
             * Creates a new graph data.
             */
            template <typename TKey, typename TValue>
            std::shared_ptr<GraphData<TKey, TValue>> GraphData<TKey, TValue>::make(
                const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgePtr<TKey, TValue>>& edges,
                const std::map<IEdgePtr<TKey, TValue>, int>& weights,
                const std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>>& paths,
                base::ITwoDimensionalVectorPtr<IVertexPtr<TKey, TValue>> topologicalSearch,
                const std::map<IVertexPtr<TKey, TValue>, std::map<IVertexPtr<TKey, TValue>, size_t>>& shortestPaths)
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
                const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgePtr<TKey, TValue>>& edges) :
                m_vertices(vertices),
                m_edges(edges)
            {
            }

            /**
             * The GraphData constructor.
             */
            template <typename TKey, typename TValue>
            GraphData<TKey, TValue>::GraphData(
                const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgePtr<TKey, TValue>>& edges,
                const std::map<IEdgePtr<TKey, TValue>, int>& weights,
                const std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>>& paths,
                const base::ITwoDimensionalVectorPtr<IVertexPtr<TKey, TValue>> topologicalSearch,
                const std::map<IVertexPtr<TKey, TValue>, std::map<IVertexPtr<TKey, TValue>, size_t>>& shortestPaths) :
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
             * Gets the vertices of the graph.
             */
            template <typename TKey, typename TValue>
            const std::vector<IVertexPtr<TKey, TValue>>& GraphData<TKey, TValue>::vertices() const
            {
                return m_vertices;
            }

            /**
             * Gets the edges of the graph.
             */
            template <typename TKey, typename TValue>
            const std::vector<IEdgePtr<TKey, TValue>>& GraphData<TKey, TValue>::edges() const
            {
                return m_edges;
            }

            /**
             * Gets the weights of the graph.
             */
            template <typename TKey, typename TValue>
            const std::map<IEdgePtr<TKey, TValue>, int>& GraphData<TKey, TValue>::getWeights() const
            {
                return m_weights;
            }

            /**
             * Gets the paths for the defined routes in the graph.
             */
            template <typename TKey, typename TValue>
            const std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>>& GraphData<TKey, TValue>::getPaths() const
            {
                return m_paths;
            }

            /**
             * Gets the topological search of the graph.
             */
            template <typename TKey, typename TValue>
            const base::ITwoDimensionalVector<IVertexPtr<TKey, TValue>>& GraphData<TKey, TValue>::getTopologicalSearch() const
            {
                return *m_topologicalSearch;
            }

            /**
             * Gets the shortest paths in the graph.
             */
            template <typename TKey, typename TValue>
            const std::map<IVertexPtr<TKey, TValue>, std::map<IVertexPtr<TKey, TValue>, size_t>>& GraphData<TKey, TValue>::getShortestPaths() const
            {
                return m_shortestPaths;
            }

        }
    }
}

#endif // GRAPH_DATA_H_2139e609_e701_44db_a65b_d5c8af8009a3
