#ifndef GRAPH_H_062057a7_d968_4aad_9c99_0af9ecf08fc8
#define GRAPH_H_062057a7_d968_4aad_9c99_0af9ecf08fc8

#include "IGraph.h"
#include "IVertex.h"
#include "IEdge.h"
#include "IAdjacencyMatrix.h"
#include "SetIterator.h"
#include "Collections.h"
#include "SmartPointers.h"
#include "BaseLogic.h"

namespace datastructures {
    namespace graph {

        /**
         * The Graph class implements a builder of a graph.
         */
        template <typename TKey, typename TValue>
        class Graph : public IGraph<TKey, TValue>
        {
        public:
            /**
             * Creates a new graph.
             */
            static IGraphSharedPtr<TKey, TValue> Make(
                const VertexSet<TKey, TValue>& vertices,
                const EdgeSet<TKey, TValue>& edges,
                IAdjacencyMatrixSharedPtr<TKey, TValue> adjacencyMatrix);

            /**
             * The Graph constructor.
             */
            Graph(
                const VertexSet<TKey, TValue>& vertices,
                const EdgeSet<TKey, TValue>& edges,
                IAdjacencyMatrixSharedPtr<TKey, TValue> adjacencyMatrix);

            /**
             * The Graph destructor.
             */
            virtual ~Graph();

            /**
             * Gets the Vertices of the graph.
             */
            virtual const VertexSet<TKey, TValue>& Vertices() const override;

            /**
             * Gets the Edges of the graph.
             */
            virtual const EdgeSet<TKey, TValue>& Edges() const override;

            /**
             * Gets the adjacency matrix.
             */
            virtual const IAdjacencyMatrix<TKey, TValue>& GetAdjacencyMatrix() const override;

            /**
             * Gets the number ofVertices in the graph.
             * The order is equal to |V(G)|.
             */
            virtual size_t GetOrder() const override;

            /**
             * Gets the degree.
             * A vertex degree is the number ofEdges incident to a vertex. Notated as d(V).
             */
            virtual size_t GetDegree(IVertexSharedPtr<TKey, TValue> vertex) const override;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const override;

        private:
            VertexSet<TKey, TValue> m_vertices;
            EdgeSet<TKey, TValue> m_edges;
            IAdjacencyMatrixSharedPtr<TKey, TValue> m_adjacencyMatrix;
        };

        /**
         * Creates a new graph.
         */
        template <typename TKey, typename TValue>
        IGraphSharedPtr<TKey, TValue> Graph<TKey, TValue>::Make(
            const VertexSet<TKey, TValue>& vertices,
            const EdgeSet<TKey, TValue>& edges,
            IAdjacencyMatrixSharedPtr<TKey, TValue> adjacencyMatrix)
        {
            return std::make_shared<Graph<TKey, TValue>>(
                vertices,
                edges,
                adjacencyMatrix);
        }

        /**
         * The Graph constructor.
         */
        template <typename TKey, typename TValue>
        Graph<TKey, TValue>::Graph(
            const VertexSet<TKey, TValue>& vertices,
            const EdgeSet<TKey, TValue>& edges,
            IAdjacencyMatrixSharedPtr<TKey, TValue> adjacencyMatrix) :
            m_vertices(vertices),
            m_edges(edges),
            m_adjacencyMatrix(adjacencyMatrix)
        {
            base::SmartPointers::Validate<IAdjacencyMatrix<TKey, TValue>>(adjacencyMatrix);
        }

        /**
         * The Graph destructor.
         */
        template <typename TKey, typename TValue>
        Graph<TKey, TValue>::~Graph()
        {
        }

        /**
         * Gets the Vertices of the graph.
         */
        template <typename TKey, typename TValue>
        const VertexSet<TKey, TValue>& Graph<TKey, TValue>::Vertices() const
        {
            return m_vertices;
        }

        /**
         * Gets the Edges of the graph.
         */
        template <typename TKey, typename TValue>
        const EdgeSet<TKey, TValue>& Graph<TKey, TValue>::Edges() const
        {
            return m_edges;
        }

        /**
         * Gets the adjacency matrix.
         */
        template <typename TKey, typename TValue>
        const IAdjacencyMatrix<TKey, TValue>& Graph<TKey, TValue>::GetAdjacencyMatrix() const
        {
            return *m_adjacencyMatrix;
        }

        /**
         * Gets the number ofVertices in the graph.
         * The order is equal to |V(G)|.
         */
        template <typename TKey, typename TValue>
        size_t Graph<TKey, TValue>::GetOrder() const
        {
            return m_vertices.size();
        }

        /**
         * Gets the degree.
         * A vertex degree is the number ofEdges incident to a vertex. Notated as d(V).
         */
        template <typename TKey, typename TValue>
        size_t Graph<TKey, TValue>::GetDegree(IVertexSharedPtr<TKey, TValue> vertex) const
        {
            VertexSet<TKey, TValue> adjacentVertices;
            m_adjacencyMatrix->GetAdjacentVertices(vertex, adjacentVertices);
            return adjacentVertices.size();
        }

        /**
         * Gets string representation ofthis instance.
         */
        template <typename TKey, typename TValue>
        std::wstring Graph<TKey, TValue>::ToString() const
        {
            base::IIteratorSharedPtr<IEdgeSharedPtr<TKey, TValue>> edgeIterator =
                base::SetIterator<IEdgeSharedPtr<TKey, TValue>>::Make(Edges());

            std::wstring result = base::Collections::DereferenceIteratorToString(*edgeIterator);

            return result;
        }
    }
}

#endif // GRAPH_H_062057a7_d968_4aad_9c99_0af9ecf08fc8
