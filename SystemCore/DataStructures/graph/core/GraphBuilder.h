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
            static IGraphSharedPtr<TKey, TValue> Make(const IGraphDefinition<TKey, TValue>& graphData);

            /**
             * The GraphBuilder constructor.
             */
            GraphBuilder();

            /**
             * The GraphLogic destructor.
             */
            virtual ~GraphBuilder();

            /**
             * The Copy/move constructors.
             */
            GraphBuilder(const GraphBuilder&) = delete;
            GraphBuilder(GraphBuilder&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            GraphBuilder& operator=(const GraphBuilder&) = delete;
            GraphBuilder& operator=(GraphBuilder&&) = delete;

            /**
             * Adds data of a graph.
             */
            virtual IGraphBuilder<TKey, TValue>& AddGraphData(const IGraphDefinition<TKey, TValue>& graphData) override;

            /**
             * Adds a vertex.
             */
            virtual IGraphBuilder<TKey, TValue>& AddVertex(IVertexSharedPtr<TKey, TValue> vertex) override;

            /**
             * Adds Vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& AddVertices(const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices) override;

            /**
             * Adds an edge.
             */
            virtual IGraphBuilder<TKey, TValue>& AddEdge(IEdgeSharedPtr<TKey, TValue> edge) override;

            /**
             * Adds an edge by Vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& AddEdge(
                    IVertexSharedPtr<TKey, TValue> source,
                    IVertexSharedPtr<TKey, TValue> destination) override;

            /**
             * Adds a Directed edge by Vertices.
             */
            virtual IGraphBuilder<TKey, TValue>& AddDirectedEdge(
                    IVertexSharedPtr<TKey, TValue> source,
                    IVertexSharedPtr<TKey, TValue> destination) override;

            /**
             * Adds Edges.
             */
            virtual IGraphBuilder<TKey, TValue>& AddEdges(
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges) override;

            /**
             * Builds the graph.
             */
            virtual IGraphSharedPtr<TKey, TValue> Build() override;

        private:
            /**
             * Adds an vertex if not defined.
             */
            void AddVertexIfNotExist(IVertexSharedPtr<TKey, TValue> vertex);

            //
            // Adds a connection to the adjacency matrix.
            //
            void AddConnection(
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
        IGraphSharedPtr<TKey, TValue> GraphBuilder<TKey, TValue>::Make(const IGraphDefinition<TKey, TValue>& graphData)
        {
            GraphBuilder<TKey, TValue> graphBuilder;
            graphBuilder.AddGraphData(graphData);
            IGraphSharedPtr<TKey, TValue> graph = graphBuilder.Build();
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
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::AddGraphData(const IGraphDefinition<TKey, TValue>& graphData)
        {
            AddEdges(graphData.Edges());
            AddVertices(graphData.Vertices());

            return *this;
        }

        /**
         * Adds a vertex.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::AddVertex(IVertexSharedPtr<TKey, TValue> vertex)
        {
            m_vertices.insert(vertex);
            return *this;
        }

        /**
         * Adds Vertices.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::AddVertices(const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices)
        {
            for (IVertexSharedPtr<TKey, TValue> vertex : vertices)
            {
                AddVertex(vertex);
            }

            return *this;
        }

        /**
         * Adds an edge.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::AddEdge(IEdgeSharedPtr<TKey, TValue> edge)
        {
            IVertexSharedPtr<TKey, TValue> sourceVertex = edge->Source();
            IVertexSharedPtr<TKey, TValue> destinationVertex = edge->Destination();

            //
            // Add the new vertices if required...
            //
            AddVertexIfNotExist(sourceVertex);
            AddVertexIfNotExist(destinationVertex);

            //
            // Add the new edge...
            //
            m_edges.insert(edge);

            //
            // Add the connections to the adjacency matrix...
            //
            AddConnection(sourceVertex, destinationVertex);

            if (!edge->Directed())
            {
                AddConnection(destinationVertex, sourceVertex);
            }

            return *this;
        }

        /**
         * Adds an edge by Vertices.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::AddEdge(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination)
        {
            IEdgeSharedPtr<TKey, TValue> edge = Edge<TKey, TValue>::Make(source, destination);
            AddEdge(edge);

            return *this;
        }

        /**
         * Adds a Directed edge by Vertices.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::AddDirectedEdge(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination)
        {
            IEdgeSharedPtr<TKey, TValue> edge = Edge<TKey, TValue>::Make(source, destination);
            AddEdge(edge);

            return *this;
        }

        /**
         * Adds Edges.
         */
        template <typename TKey, typename TValue>
        IGraphBuilder<TKey, TValue>& GraphBuilder<TKey, TValue>::AddEdges(
            const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges)
        {
            for (IEdgeSharedPtr<TKey, TValue> edge : edges)
            {
                AddEdge(edge);
            }

            return *this;
        }

        /**
         * Builds the graph.
         */
        template <typename TKey, typename TValue>
        IGraphSharedPtr<TKey, TValue> GraphBuilder<TKey, TValue>::Build()
        {
            IAdjacencyMatrixSharedPtr<TKey, TValue> adjacencyMatrix = AdjacencyMatrix<TKey, TValue>::Make(m_connections);

            return Graph<TKey, TValue>::Make(
                m_vertices,
                m_edges,
                adjacencyMatrix);
        }

        //
        // Add the connections to the adjacency matrix...
        //
        template <typename TKey, typename TValue>
        void GraphBuilder<TKey, TValue>::AddConnection(
                IVertexSharedPtr<TKey, TValue> sourceVertex,
                IVertexSharedPtr<TKey, TValue> destinationVertex)
        {
            typename std::map<IVertexSharedPtr<TKey, TValue>, std::set<IVertexSharedPtr<TKey, TValue>>>::iterator vertexIterator =
                    m_connections.find(sourceVertex);

            if (vertexIterator == m_connections.end())
            {
                long statusCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
                std::wstring errorMessage = L"The Source vertex does not exist in the Connections of the adjacency matrix.";

                throw GraphException(statusCode, errorMessage);
            }

            std::set<IVertexSharedPtr<TKey, TValue>>& connections = vertexIterator->second;
            connections.insert(destinationVertex);
        }

        /**
         * Adds an vertex if not defined.
         */
        template <typename TKey, typename TValue>
        void GraphBuilder<TKey, TValue>::AddVertexIfNotExist(IVertexSharedPtr<TKey, TValue> vertex)
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
