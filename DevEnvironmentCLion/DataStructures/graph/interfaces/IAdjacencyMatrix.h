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
             * The copy/move constructors.
             */
            IAdjacencyMatrix(const IAdjacencyMatrix&) = delete;
            IAdjacencyMatrix(IAdjacencyMatrix&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IAdjacencyMatrix& operator=(const IAdjacencyMatrix&) = delete;
            IAdjacencyMatrix& operator=(IAdjacencyMatrix&&) = delete;

            /**
             * Gets the connections of an adjacency matrix.
             */
            virtual const std::map<IVertexPtr<TKey, TValue>, std::set<IVertexPtr<TKey, TValue>>>& connections() const = 0;

            /**
             * Checks whether two vertices are connected.
             */
            virtual bool connected(
                const IVertex<TKey, TValue>& sourceVertex,
                const IVertex<TKey, TValue>& destinationVertex) const = 0;

            /**
             * Gets the adjacent vertices of a vertex.
             */
            virtual void getAdjacentVertices(
                const IVertex<TKey, TValue>& vertex,
                std::set<IVertexPtr<TKey, TValue>>& result) const = 0;

            /**
             * Gets the adjacent edges of a vertex.
             */
            virtual void getAdjacentEdges(
                const IVertex<TKey, TValue>& vertex,
                std::set<IEdgePtr<TKey, TValue>>& result) const = 0;
        };

        template <typename TKey, typename TValue>
        using IAdjacencyMatrixPtr = std::shared_ptr<IAdjacencyMatrix<TKey, TValue>>;

        template <typename TKey, typename TValue>
        using VertexSet = std::set<IVertexPtr<TKey, TValue>>;

        template <typename TKey, typename TValue>
        using EdgeSet = std::set<IEdgePtr<TKey, TValue>>;

        template <typename TKey, typename TValue>
        using AdjacencyMap = std::map<IVertexPtr<TKey, TValue>, VertexSet<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IAdjacencyMatrix<TKey, TValue>& left, const IAdjacencyMatrix<TKey, TValue>& right)
        {
            base::ComparableComparator<TKey> keyComparator;

            class ValueComparator final : public base::IComparableComparator<IVertexPtr<TKey, TValue>>
            {
                virtual int compareTo(
                    const IVertexPtr<TKey, TValue>& lhs,
                    const IVertexPtr<TKey, TValue>& rhs) const override
                {
                    base::CompareToBuilder compareToBuilder;
                    return compareToBuilder.withSet(lhs, rhs).build();
                }
            };

            ValueComparator valueComparator;

            base::CompareToBuilder compareToBuilder;
            int status = compareToBuilder.withMap(
                left.connections(),
                right.connections(),
                keyComparator,
                valueComparator).build();

            return status < 0;
        }
    }
}

#endif // I_ADJACENCY_MATRIX_H_0fc06f78_c83a_4cbe_9d46_d622ab261c18
