#ifndef I_ADJACENCY_MATRIX_H_0fc06f78_c83a_4cbe_9d46_d622ab261c18
#define I_ADJACENCY_MATRIX_H_0fc06f78_c83a_4cbe_9d46_d622ab261c18

#include "IVertex.h"
#include "CompareToBuilder.h"
#include "Comparator.h"
#include "IComparableComparator.h"

namespace datastructures {
    namespace graph {

        /**
         * The IAdjacencyMatrix interface defines an adjacency matrix of a graph.
         */
        template <typename TKey, typename TValue>
        class IAdjacencyMatrix
        {
        public:
            /**
             * The constructor.
             */
            IAdjacencyMatrix() = default;

            /**
             * The destructor.
             */
            virtual ~IAdjacencyMatrix() = default;

            /**
             * The Copy/move constructors.
             */
            IAdjacencyMatrix(const IAdjacencyMatrix&) = delete;
            IAdjacencyMatrix(IAdjacencyMatrix&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IAdjacencyMatrix& operator=(const IAdjacencyMatrix&) = delete;
            IAdjacencyMatrix& operator=(IAdjacencyMatrix&&) = delete;

            /**
             * Gets the Connections of an adjacency matrix.
             */
            virtual const std::map<IVertexSharedPtr<TKey, TValue>, std::set<IVertexSharedPtr<TKey, TValue>>>& Connections() const = 0;

            /**
             * Checks whether two Vertices are Connected.
             */
            virtual bool Connected(
                IVertexSharedPtr<TKey, TValue> sourceVertex,
                IVertexSharedPtr<TKey, TValue> destinationVertex) const = 0;

            /**
             * Gets the adjacent Vertices of a vertex.
             */
            virtual void GetAdjacentVertices(
                IVertexSharedPtr<TKey, TValue> vertex,
                std::set<IVertexSharedPtr<TKey, TValue>>& result) const = 0;

            /**
             * Gets the adjacent Edges of a vertex.
             */
            virtual void GetAdjacentEdges(
                IVertexSharedPtr<TKey, TValue> vertex,
                std::set<IEdgeSharedPtr<TKey, TValue>>& result) const = 0;
        };

        /**
         * Defines the SharedPtr ofAdjacency Matrix.
         */
        template <typename TKey, typename TValue>
        using IAdjacencyMatrixSharedPtr = std::shared_ptr<IAdjacencyMatrix<TKey, TValue>>;

        /**
         * Defines Vertex Set.
         */
        template <typename TKey, typename TValue>
        using VertexSet = std::set<IVertexSharedPtr<TKey, TValue>>;

        /**
         * Defines Edge Set.
         */
        template <typename TKey, typename TValue>
        using EdgeSet = std::set<IEdgeSharedPtr<TKey, TValue>>;

        /**
         * Defines Adjacency Map.
         */
        template <typename TKey, typename TValue>
        using AdjacencyMap = std::map<IVertexSharedPtr<TKey, TValue>, VertexSet<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IAdjacencyMatrix<TKey, TValue>& left, const IAdjacencyMatrix<TKey, TValue>& right)
        {
            base::ComparableComparator<TKey> keyComparator;

            class ValueComparator final : public base::IComparableComparator<IVertexSharedPtr<TKey, TValue>>
            {
                virtual int CompareTo(
                    const IVertexSharedPtr<TKey, TValue>& lhs,
                    const IVertexSharedPtr<TKey, TValue>& rhs) const override
                {
                    base::CompareToBuilder compareToBuilder;
                    return compareToBuilder.WithSet(lhs, rhs).Build();
                }
            };

            ValueComparator valueComparator;

            base::CompareToBuilder compareToBuilder;
            int status = compareToBuilder.WithMap(
                left.Connections(),
                right.Connections(),
                keyComparator,
                valueComparator).Build();

            return status < 0;
        }
    }
}

#endif // I_ADJACENCY_MATRIX_H_0fc06f78_c83a_4cbe_9d46_d622ab261c18
