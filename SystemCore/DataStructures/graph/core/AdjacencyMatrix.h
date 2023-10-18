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
            static IAdjacencyMatrixSharedPtr<TKey, TValue> Make(const AdjacencyMap<TKey, TValue>& connections);

            /**
             * The AdjacencyMatrix constructor.
             */
            explicit AdjacencyMatrix(const AdjacencyMap<TKey, TValue>& connections);

            /**
             * The AdjacencyMatrix destructor.
             */
            virtual ~AdjacencyMatrix();

            /**
             * The Copy/move constructors.
             */
            AdjacencyMatrix(const AdjacencyMatrix&) = delete;
            AdjacencyMatrix(AdjacencyMatrix&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            AdjacencyMatrix& operator=(const AdjacencyMatrix&) = delete;
            AdjacencyMatrix& operator=(AdjacencyMatrix&&) = delete;

            /**
             * Gets the Connections of an adjacency matrix.
             */
            virtual const AdjacencyMap<TKey, TValue>& Connections() const override;

            /**
             * Checks whether two Vertices are Connected.
             */
            virtual bool Connected(
                IVertexSharedPtr<TKey, TValue> sourceVertex,
                IVertexSharedPtr<TKey, TValue> destinationVertex) const override;

            /**
             * Gets the adjacent Vertices of a vertex.
             */
            virtual void GetAdjacentVertices(
                IVertexSharedPtr<TKey, TValue> vertex,
                VertexSet<TKey, TValue>& result) const override;

            /**
             * Gets the adjacent Edges of a vertex.
             */
            virtual void GetAdjacentEdges(
                IVertexSharedPtr<TKey, TValue> vertex,
                EdgeSet<TKey, TValue>& result) const override;

        private:
            /**
             * Gets the Connections of a vertex.
             */
            const VertexSet<TKey, TValue>& GetVertexConnections(IVertexSharedPtr<TKey, TValue> vertex) const;

            /**
             * Finds the Connections of a vertex.
             */
            const VertexSet<TKey, TValue>* FindVertexConnections(IVertexSharedPtr<TKey, TValue> vertex) const;

            AdjacencyMap<TKey, TValue> m_connections;
        };

        /**
         * Creates a new a djacency map.
         */
        template <typename TKey, typename TValue>
        IAdjacencyMatrixSharedPtr<TKey, TValue> AdjacencyMatrix<TKey, TValue>::Make(const AdjacencyMap<TKey, TValue>& connections)
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
         * Gets the Connections of an adjacency matrix.
         */
        template <typename TKey, typename TValue>
        const AdjacencyMap<TKey, TValue>& AdjacencyMatrix<TKey, TValue>::Connections() const
        {
            return m_connections;
        }

        /**
         * Checks whether two Vertices are Connected.
         */
        template <typename TKey, typename TValue>
        bool AdjacencyMatrix<TKey, TValue>::Connected(
            IVertexSharedPtr<TKey, TValue> sourceVertex,
            IVertexSharedPtr<TKey, TValue> destinationVertex) const
        {
            base::SmartPointers::Validate<IVertex<TKey, TValue>>(sourceVertex);
            base::SmartPointers::Validate<IVertex<TKey, TValue>>(destinationVertex);

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
         * Gets the adjacent Vertices of a vertex.
         */
        template <typename TKey, typename TValue>
        void AdjacencyMatrix<TKey, TValue>::GetAdjacentVertices(
            IVertexSharedPtr<TKey, TValue> vertex,
            VertexSet<TKey, TValue>& result) const
        {
            base::SmartPointers::Validate<IVertex<TKey, TValue>>(vertex);

            const VertexSet<TKey, TValue>& connections = GetVertexConnections(vertex);
            result = connections;
        }

        /**
         * Gets the adjacent Edges of a vertex.
         */
        template <typename TKey, typename TValue>
        void AdjacencyMatrix<TKey, TValue>::GetAdjacentEdges(
                IVertexSharedPtr<TKey, TValue> vertex,
                EdgeSet<TKey, TValue>& result) const
        {
            base::SmartPointers::Validate<IVertex<TKey, TValue>>(vertex);

            const VertexSet<TKey, TValue>& adjacentVertices = GetVertexConnections(vertex);

            for (IVertexSharedPtr<TKey, TValue> destinationVertex : adjacentVertices)
            {
                IEdgeSharedPtr<TKey, TValue> edge = Connected(vertex, destinationVertex) ?
                                                    Edge<TKey, TValue>::Make(vertex, destinationVertex) :
                                                    Edge<TKey, TValue>::MakeDirected(vertex, destinationVertex);

                result.insert(edge);
            }
        }

        /**
         * Gets the Connections of a vertex.
         */
        template <typename TKey, typename TValue>
        const VertexSet<TKey, TValue>& AdjacencyMatrix<TKey, TValue>::GetVertexConnections(
                IVertexSharedPtr<TKey, TValue> vertex) const
        {
            const VertexSet<TKey, TValue>* vertexConnections = FindVertexConnections(vertex);

            if (vertexConnections == nullptr)
            {
                long statusCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

                std::wstring errorMessage =
                    L"The vertex: " + vertex->ToString() + L" is not defined in the adjacency matrix.";

                throw GraphException(statusCode, errorMessage);
            }

            return *vertexConnections;
        }

        /**
         * Finds the Connections of a vertex.
         */
        template <typename TKey, typename TValue>
        const VertexSet<TKey, TValue>* AdjacencyMatrix<TKey, TValue>::FindVertexConnections(
                IVertexSharedPtr<TKey, TValue> vertex) const
        {
            typename AdjacencyMap<TKey, TValue>::const_iterator sourceVertexIterator = m_connections.find(vertex);
            return sourceVertexIterator != m_connections.end() ? &sourceVertexIterator->second : nullptr;
        }

    }
}

#endif // ADJACENCY_MATRIX_H_b070a0fc_1721_4015_83dd_ab9234fc87cb
