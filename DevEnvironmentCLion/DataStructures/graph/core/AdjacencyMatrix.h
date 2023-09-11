#ifndef ADJACENCY_MATRIX_H_b070a0fc_1721_4015_83dd_ab9234fc87cb
#define ADJACENCY_MATRIX_H_b070a0fc_1721_4015_83dd_ab9234fc87cb

#include "IAdjacencyMatrix.h"
#include "Edge.h"
#include "Vertex.h"
#include "SmartPointers.h"
#include "GraphException.h"

namespace datastructures {
    namespace graph {

        /**
         * The AdjacencyMatrix class implements an adjacency matrix of a graph.
         */
        template <typename TKey, typename TValue>
        class AdjacencyMatrix final : public IAdjacencyMatrix<TKey, TValue>
        {
        public:
            /**
             * Creates a new a adjacency map.
             */
            static IAdjacencyMatrixPtr<TKey, TValue> make(const AdjacencyMap<TKey, TValue>& connections);

            /**
             * The AdjacencyMatrix constructor.
             */
            explicit AdjacencyMatrix(const AdjacencyMap<TKey, TValue>& connections);

            /**
             * The AdjacencyMatrix destructor.
             */
            virtual ~AdjacencyMatrix();

            /**
             * The copy/move constructors.
             */
            AdjacencyMatrix(const AdjacencyMatrix&) = delete;
            AdjacencyMatrix(AdjacencyMatrix&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            AdjacencyMatrix& operator=(const AdjacencyMatrix&) = delete;
            AdjacencyMatrix& operator=(AdjacencyMatrix&&) = delete;

            /**
             * Gets the connections of an adjacency matrix.
             */
            virtual const AdjacencyMap<TKey, TValue>& connections() const override;

            /**
             * Checks whether two vertices are connected.
             */
            virtual bool connected(
                IVertexPtr<TKey, TValue> sourceVertex,
                IVertexPtr<TKey, TValue> destinationVertex) const override;

            /**
             * Gets the adjacent vertices of a vertex.
             */
            virtual void getAdjacentVertices(
                IVertexPtr<TKey, TValue> vertex,
                VertexSet<TKey, TValue>& result) const override;

            /**
             * Gets the adjacent edges of a vertex.
             */
            virtual void getAdjacentEdges(
                IVertexPtr<TKey, TValue> vertex,
                EdgeSet<TKey, TValue>& result) const override;

        private:
            /**
             * Gets the connections of a vertex.
             */
            const VertexSet<TKey, TValue>& getVertexConnections(IVertexPtr<TKey, TValue> vertex) const;

            /**
             * Finds the connections of a vertex.
             */
            const VertexSet<TKey, TValue>* findVertexConnections(IVertexPtr<TKey, TValue> vertex) const;

            AdjacencyMap<TKey, TValue> m_connections;
        };

        /**
         * Creates a new a djacency map.
         */
        template <typename TKey, typename TValue>
        IAdjacencyMatrixPtr<TKey, TValue> AdjacencyMatrix<TKey, TValue>::make(const AdjacencyMap<TKey, TValue>& connections)
        {
            return std::make_shared<AdjacencyMatrix<TKey, TValue>>(connections);
        }

        /**
         * The AdjacencyMatrix constructor.
         */
        template <typename TKey, typename TValue>
        AdjacencyMatrix<TKey, TValue>::AdjacencyMatrix(
            const AdjacencyMap<TKey, TValue>& connections) :
            m_connections(connections)
        {
        }

        /**
         * The AdjacencyMatrix destructor.
         */
        template <typename TKey, typename TValue>
        AdjacencyMatrix<TKey, TValue>::~AdjacencyMatrix()
        {
        }

        /**
         * Gets the connections of an adjacency matrix.
         */
        template <typename TKey, typename TValue>
        const AdjacencyMap<TKey, TValue>& AdjacencyMatrix<TKey, TValue>::connections() const
        {
            return m_connections;
        }

        /**
         * Checks whether two vertices are connected.
         */
        template <typename TKey, typename TValue>
        bool AdjacencyMatrix<TKey, TValue>::connected(
            IVertexPtr<TKey, TValue> sourceVertex,
            IVertexPtr<TKey, TValue> destinationVertex) const
        {
            base::SmartPointers::validate(sourceVertex);
            base::SmartPointers::validate(destinationVertex);

            typename AdjacencyMap<TKey, TValue>::const_iterator sourceVertexIterator = m_connections.find(sourceVertex);

            if (sourceVertexIterator == m_connections.end())
            {
                return false;
            }

            const VertexSet<TKey, TValue>& destinationVertices = sourceVertexIterator->second;

            typename VertexSet<TKey, TValue>::const_iterator destinationVertexIterator =
                destinationVertices.find(destinationVertex);

            return destinationVertexIterator != destinationVertices.end();
        }

        /**
         * Gets the adjacent vertices of a vertex.
         */
        template <typename TKey, typename TValue>
        void AdjacencyMatrix<TKey, TValue>::getAdjacentVertices(
            IVertexPtr<TKey, TValue> vertex,
            VertexSet<TKey, TValue>& result) const
        {
            base::SmartPointers::validate(vertex);

            const VertexSet<TKey, TValue>& connections = getVertexConnections(vertex);
            result = connections;
        }

        /**
         * Gets the adjacent edges of a vertex.
         */
        template <typename TKey, typename TValue>
        void AdjacencyMatrix<TKey, TValue>::getAdjacentEdges(
            IVertexPtr<TKey, TValue> vertex,
            EdgeSet<TKey, TValue>& result) const
        {
            base::SmartPointers::validate(vertex);

            const VertexSet<TKey, TValue>& adjacentVertices = getVertexConnections(vertex);

            for (IVertexPtr<TKey, TValue> destinationVertex : adjacentVertices)
            {
                IEdgePtr<TKey, TValue> edge = connected(vertex, destinationVertex) ?
                    Edge<TKey, TValue>::make(vertex, destinationVertex) :
                    Edge<TKey, TValue>::makeDirected(vertex, destinationVertex);

                result.insert(edge);
            }
        }

        /**
         * Gets the connections of a vertex.
         */
        template <typename TKey, typename TValue>
        const VertexSet<TKey, TValue>& AdjacencyMatrix<TKey, TValue>::getVertexConnections(
            IVertexPtr<TKey, TValue> vertex) const
        {
            const VertexSet<TKey, TValue>* vertexConnections = findVertexConnections(vertex);

            if (vertexConnections == nullptr)
            {
                std::string errorMessage =
                    "The vertex: " + vertex->toString() + " is not defined in the adjacency matrix.";

                throw GraphException(errorMessage);
            }

            return *vertexConnections;
        }

        /**
         * Finds the connections of a vertex.
         */
        template <typename TKey, typename TValue>
        const VertexSet<TKey, TValue>* AdjacencyMatrix<TKey, TValue>::findVertexConnections(
            IVertexPtr<TKey, TValue> vertex) const
        {
            typename AdjacencyMap<TKey, TValue>::const_iterator sourceVertexIterator = m_connections.find(vertex);
            return sourceVertexIterator != m_connections.end() ? &sourceVertexIterator->second : nullptr;
        }

    }
}

#endif // ADJACENCY_MATRIX_H_b070a0fc_1721_4015_83dd_ab9234fc87cb
