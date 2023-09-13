#ifndef I_GRAPH_BUILDER_H_e864f184_241f_4027_aea1_62af2b8f8209
#define I_GRAPH_BUILDER_H_e864f184_241f_4027_aea1_62af2b8f8209

#include "IBuilder.h"
#include "IGraph.h"
#include "IGraphDefinition.h"
#include "IVertex.h"

namespace datastructures {
    namespace graph {

        /**
         * The IGraphBuilder interface defines a builder of a graph.
         */
        template <typename TKey, typename TValue>
        class IGraphBuilder : public base::IBuilder<IGraphSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * The constructor.
             */
            IGraphBuilder() = default;

            /**
             * The destructor.
             */
            virtual ~IGraphBuilder() = default;

            /**
             * The copy/move constructors.
             */
            IGraphBuilder(const IGraphBuilder&) = delete;
            IGraphBuilder(IGraphBuilder&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IGraphBuilder& operator=(const IGraphBuilder&) = delete;
            IGraphBuilder& operator=(IGraphBuilder&&) = delete;

            /**
             * Adds data of a graph.
             */
            virtual IGraphBuilder<TKey, TValue>& addGraphData(
                const IGraphDefinition<TKey, TValue>& graphData) = 0;

            /**
             * Adds a vertex.
             */
            virtual IGraphBuilder<TKey, TValue>& addVertex(
                IVertexSharedPtr<TKey, TValue> vertex) = 0;

            /**
             * Adds vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& addVertices(
                const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices) = 0;

            /**
             * Adds an edge.
             */
            virtual IGraphBuilder<TKey, TValue>& addEdge(
                    IEdgeSharedPtr<TKey, TValue> edge) = 0;

            /**
             * Adds an edge by vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& addEdge(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination) = 0;

            /**
             * Adds a directed edge by vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& addDirectedEdge(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination) = 0;

            /**
             * Adds edges.
             */
            virtual IGraphBuilder<TKey, TValue>& addEdges(
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges) = 0;
        };

    }
}

#endif // I_GRAPH_BUILDER_H_e864f184_241f_4027_aea1_62af2b8f8209
