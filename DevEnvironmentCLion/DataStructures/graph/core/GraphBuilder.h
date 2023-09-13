#ifndef GRAPH_BUILDER_H_69452986_b677_4e14_a299_809976b9c5ae
#define GRAPH_BUILDER_H_69452986_b677_4e14_a299_809976b9c5ae

#include "IGraphBuilder.h"
#include "Edge.h"
#include "GraphException.h"
#include "AdjacencyMatrix.h"
#include "Graph.h"

namespace datastructures {
    namespace graph {

        /**
         * The GraphBuilder class implements a builder for a graph.
         */
        template <typename TKey, typename TValue>
        class GraphBuilder final : public IGraphBuilder<TKey, TValue>
        {
        public:
            /**
             * Creates a new graph from it's data.
             */
            static IGraphSharedPtr<TKey, TValue> make(const IGraphDefinition<TKey, TValue>& graphData);

            /**
             * The GraphBuilder constructor.
             */
            GraphBuilder();

            /**
             * The GraphLogic destructor.
             */
            virtual ~GraphBuilder();

            /**
             * The copy/move constructors.
             */
            GraphBuilder(const GraphBuilder&) = delete;
            GraphBuilder(GraphBuilder&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            GraphBuilder& operator=(const GraphBuilder&) = delete;
            GraphBuilder& operator=(GraphBuilder&&) = delete;

            /**
             * Adds data of a graph.
             */
            virtual IGraphBuilder<TKey, TValue>& addGraphData(const IGraphDefinition<TKey, TValue>& graphData) override;

            /**
             * Adds a vertex.
             */
            virtual IGraphBuilder<TKey, TValue>& addVertex(IVertexSharedPtr<TKey, TValue> vertex) override;

            /**
             * Adds vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& addVertices(const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices) override;

            /**
             * Adds an edge.
             */
            virtual IGraphBuilder<TKey, TValue>& addEdge(IEdgeSharedPtr<TKey, TValue> edge) override;

            /**
             * Adds an edge by vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& addEdge(
                    IVertexSharedPtr<TKey, TValue> source,
                    IVertexSharedPtr<TKey, TValue> destination) override;

            /**
             * Adds a directed edge by vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& addDirectedEdge(
                    IVertexSharedPtr<TKey, TValue> source,
                    IVertexSharedPtr<TKey, TValue> destination) override;

            /**
             * Adds edges.
             */
            virtual IGraphBuilder<TKey, TValue>& addEdges(
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges) override;

            /**
             * Builds the graph.
             */
            virtual IGraphSharedPtr<TKey, TValue> build() override;

        private:
            /**
             * Adds an vertex if not defined.
             */
            void addVertexIfNotExist(IVertexSharedPtr<TKey, TValue> vertex);

            //
            // Adds a connection to the adjacency matrix.
            //
            void addConnection(
                    IVertexSharedPtr<TKey, TValue> sourceVertex,
                    IVertexSharedPtr<TKey, TValue> destinationVertex);

            std::set<IVertexSharedPtr<TKey, TValue>> m_vertices;
            std::set<IEdgeSharedPtr<TKey, TValue>> m_edges;
            std::map<IVertexSharedPtr<TKey, TValue>, std::set<IVertexSharedPtr<TKey, TValue>>> m_connections;
        };

        /**
         * Creates a new graph from it's data.
         */
        template <typename TKey, typename TValue>
        IGraphSharedPtr<TKey, TValue> GraphBuilder<TKey, TValue>::make(const IGraphDefinition<TKey, TValue>& graphData)
        {
            GraphBuilder<TKey, TValue> graphBuilder;
            graphBuilder.addGraphData(graphData);
            IGraphSharedPtr<TKey, TValue> graph = graphBuilder.build();
            return graph;
        }

        /**
         * The GraphBuilder constructor.
         */
        template <typename TKey, typename TValue>
        GraphBuilder<TKey, TValue>::GraphBuilder()
        {
        }

        /**
         * The GraphLogic destructor.
         */
        template <typename TKey, typename TValue>
        GraphBuilder<TKey, TValue>::~GraphBuilder()
        {
        }

        /**
         * Adds data of a graph.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::addGraphData(const IGraphDefinition<TKey, TValue>& graphData)
        {
            addEdges(graphData.edges());
            addVertices(graphData.vertices());

            return *this;
        }

        /**
         * Adds a vertex.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::addVertex(IVertexSharedPtr<TKey, TValue> vertex)
        {
            m_vertices.insert(vertex);
            return *this;
        }

        /**
         * Adds vertices.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::addVertices(const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices)
        {
            for (IVertexSharedPtr<TKey, TValue> vertex : vertices)
            {
                addVertex(vertex);
            }

            return *this;
        }

        /**
         * Adds an edge.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::addEdge(IEdgeSharedPtr<TKey, TValue> edge)
        {
            IVertexSharedPtr<TKey, TValue> sourceVertex = edge->source();
            IVertexSharedPtr<TKey, TValue> destinationVertex = edge->destination();

            //
            // Add the new vertices if required...
            //
            addVertexIfNotExist(sourceVertex);
            addVertexIfNotExist(destinationVertex);

            //
            // Add the new edge...
            //
            m_edges.insert(edge);

            //
            // Add the connections to the adjacency matrix...
            //
            addConnection(sourceVertex, destinationVertex);

            if (!edge->directed())
            {
                addConnection(destinationVertex, sourceVertex);
            }

            return *this;
        }

        /**
         * Adds an edge by vertices.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::addEdge(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination)
        {
            IEdgeSharedPtr<TKey, TValue> edge = Edge<TKey, TValue>::make(source, destination);
            addEdge(edge);

            return *this;
        }

        /**
         * Adds a directed edge by vertices.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::addDirectedEdge(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination)
        {
            IEdgeSharedPtr<TKey, TValue> edge = Edge<TKey, TValue>::make(source, destination);
            addEdge(edge);

            return *this;
        }

        /**
         * Adds edges.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::addEdges(
            const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges)
        {
            for (IEdgeSharedPtr<TKey, TValue> edge : edges)
            {
                addEdge(edge);
            }

            return *this;
        }

        /**
         * Builds the graph.
         */
        template <typename TKey, typename TValue>
        IGraphSharedPtr<TKey, TValue> GraphBuilder<TKey, TValue>::build()
        {
            IAdjacencyMatrixSharedPtr<TKey, TValue> adjacencyMatrix = AdjacencyMatrix<TKey, TValue>::make(m_connections);

            return Graph<TKey, TValue>::make(
                m_vertices,
                m_edges,
                adjacencyMatrix);
        }

        //
        // Add the connections to the adjacency matrix...
        //
        template <typename TKey, typename TValue>
        void GraphBuilder<TKey, TValue>::addConnection(
                IVertexSharedPtr<TKey, TValue> sourceVertex,
                IVertexSharedPtr<TKey, TValue> destinationVertex)
        {
            typename std::map<IVertexSharedPtr<TKey, TValue>, std::set<IVertexSharedPtr<TKey, TValue>>>::iterator vertexIterator =
                m_connections.find(sourceVertex);

            if (vertexIterator == m_connections.end())
            {
                std::string errorMessage = "The source vertex does not exist in the connections of the adjacency matrix.";
                throw GraphException(errorMessage);
            }

            std::set<IVertexSharedPtr<TKey, TValue>>& connections = vertexIterator->second;
            connections.insert(destinationVertex);
        }

        /**
         * Adds an vertex if not defined.
         */
        template <typename TKey, typename TValue>
        void GraphBuilder<TKey, TValue>::addVertexIfNotExist(IVertexSharedPtr<TKey, TValue> vertex)
        {
            typename std::set<IVertexSharedPtr<TKey, TValue>>::iterator vertexIterator = m_vertices.find(vertex);

            if (vertexIterator != m_vertices.end())
            {
                return;
            }

            m_vertices.insert(vertex);
            std::set<IVertexSharedPtr<TKey, TValue>> connections;
            m_connections.insert(std::make_pair(vertex, connections));
        }

    }
}

#endif // GRAPH_BUILDER_H_69452986_b677_4e14_a299_809976b9c5ae
