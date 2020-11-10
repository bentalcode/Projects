#ifndef GRAPH_H_062057a7_d968_4aad_9c99_0af9ecf08fc8
#define GRAPH_H_062057a7_d968_4aad_9c99_0af9ecf08fc8

#include "IGraph.h"
#include "IVertex.h"
#include "IEdge.h"
#include "IAdjacencyMatrix.h"
#include "GraphException.h"
#include "SetIterator.h"
#include "Collections.h"

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
            static IGraphPtr<TKey, TValue> make(
                const VertexSet<TKey, TValue>& vertices,
                const EdgeSet<TKey, TValue>& edges,
                IAdjacencyMatrixPtr<TKey, TValue> adjacencyMatrix);

            /**
             * The Graph constructor.
             */
            Graph(
                const VertexSet<TKey, TValue>& vertices,
                const EdgeSet<TKey, TValue>& edges,
                IAdjacencyMatrixPtr<TKey, TValue> adjacencyMatrix);

            /**
             * The Graph destructor.
             */
            virtual ~Graph();

            /**
             * Gets the vertices of the graph.
             */
            virtual const VertexSet<TKey, TValue>& vertices() const override;

            /**
             * Gets the edges of the graph.
             */
            virtual const EdgeSet<TKey, TValue>& edges() const override;

            /**
             * Gets the adjacency matrix.
             */
            virtual const IAdjacencyMatrix<TKey, TValue>& getAdjacencyMatrix() const override;

            /**
             * Gets the number of vertices in the graph.
             * The order is equal to |V(G)|.
             */
            virtual size_t getOrder() const override;

            /**
             * Gets the degree.
             * A vertex degree is the number of edges incident to a vertex. Notated as d(V).
             */
            virtual size_t getDegree(IVertexPtr<TKey, TValue> vertex) const override;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            VertexSet<TKey, TValue> m_vertices;
            EdgeSet<TKey, TValue> m_edges;
            IAdjacencyMatrixPtr<TKey, TValue> m_adjacencyMatrix;
        };

        /**
         * Creates a new graph.
         */
        template <typename TKey, typename TValue>
        IGraphPtr<TKey, TValue> Graph<TKey, TValue>::make(
            const VertexSet<TKey, TValue>& vertices,
            const EdgeSet<TKey, TValue>& edges,
            IAdjacencyMatrixPtr<TKey, TValue> adjacencyMatrix)
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
            IAdjacencyMatrixPtr<TKey, TValue> adjacencyMatrix) :
            m_vertices(vertices),
            m_edges(edges),
            m_adjacencyMatrix(adjacencyMatrix)
        {
            if (!adjacencyMatrix)
            {
                std::string errorMessage = "The adjacency matrix is not defined.";
                throw GraphException(errorMessage);
            }
        }

        /**
         * The Graph destructor.
         */
        template <typename TKey, typename TValue>
        Graph<TKey, TValue>::~Graph()
        {
        }

        /**
         * Gets the vertices of the graph.
         */
        template <typename TKey, typename TValue>
        const VertexSet<TKey, TValue>& Graph<TKey, TValue>::vertices() const
        {
            return m_vertices;
        }

        /**
         * Gets the edges of the graph.
         */
        template <typename TKey, typename TValue>
        const EdgeSet<TKey, TValue>& Graph<TKey, TValue>::edges() const
        {
            return m_edges;
        }

        /**
         * Gets the adjacency matrix.
         */
        template <typename TKey, typename TValue>
        const IAdjacencyMatrix<TKey, TValue>& Graph<TKey, TValue>::getAdjacencyMatrix() const
        {
            return *m_adjacencyMatrix;
        }

        /**
         * Gets the number of vertices in the graph.
         * The order is equal to |V(G)|.
         */
        template <typename TKey, typename TValue>
        size_t Graph<TKey, TValue>::getOrder() const
        {
            return m_vertices.size();
        }

        /**
         * Gets the degree.
         * A vertex degree is the number of edges incident to a vertex. Notated as d(V).
         */
        template <typename TKey, typename TValue>
        size_t Graph<TKey, TValue>::getDegree(IVertexPtr<TKey, TValue> vertex) const
        {
            VertexSet<TKey, TValue> adjacentVertices;
            m_adjacencyMatrix->getAdjacentVertices(vertex, adjacentVertices);
            return adjacentVertices.size();
        }

        /**
         * Gets string representation of this instance.
         */
        template <typename TKey, typename TValue>
        std::string Graph<TKey, TValue>::toString() const
        {
            base::IIteratorPtr<IEdgePtr<TKey, TValue>> edgeIterator = base::SetIterator<IEdgePtr<TKey, TValue>>::make(edges());
            std::string string = base::Collections::dereferenceIteratorToString(*edgeIterator);
            return string;
        }
    }
}

#endif // GRAPH_H_062057a7_d968_4aad_9c99_0af9ecf08fc8
