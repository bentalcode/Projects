#ifndef I_GRAPH_H_3fa1d2e0_eef1_4d7a_9f9c_02cf20acf64e
#define I_GRAPH_H_3fa1d2e0_eef1_4d7a_9f9c_02cf20acf64e

#include "ICollection.h"
#include "IAdjacencyMatrix.h"

namespace datastructures {
    namespace graph {

        /**
         * The IGraph interface defines a graph.
         */
        template <typename TKey, typename TValue>
        class IGraph : public base::ICollection
        {
        public:
            /**
             * The constructor.
             */
            IGraph() = default;

            /**
             * The destructor.
             */
            virtual ~IGraph() = default;

            /**
             * The copy/move constructors.
             */
            IGraph(const IGraph&) = delete;
            IGraph(IGraph&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IGraph& operator=(const IGraph&) = delete;
            IGraph& operator=(IGraph&&) = delete;

            /**
             * Gets the vertices of the graph.
             */
            virtual const VertexSet<TKey, TValue>& vertices() const = 0;

            /**
             * Gets the edges of the graph.
             */
            virtual const EdgeSet<TKey, TValue>& edges() const = 0;

            /**
             * Gets the adjacency matrix.
             */
            virtual const IAdjacencyMatrix<TKey, TValue>& getAdjacencyMatrix() const = 0;

            /**
             * Gets the number of vertices in the graph.
             * The order is equal to |V(G)|.
             */
            virtual size_t getOrder() const = 0;

            /**
             * Gets the degree.
             * A vertex degree is the number of edges incident to a vertex. Notated as d(V).
             */
            virtual size_t getDegree(const IVertex<TKey, TValue>& vertex) = 0;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        template <typename TKey, typename TValue>
        using IGraphPtr = std::shared_ptr<IGraph<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IGraph<TKey, TValue>& left, const IGraph<TKey, TValue>& right)
        {
            return true;
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::ostream& operator<<(std::ostream& stream, const IGraph<TKey, TValue>& edge)
        {
            stream << edge.toString();
            return stream;
        }
    }
}

#endif // I_GRAPH_H_3fa1d2e0_eef1_4d7a_9f9c_02cf20acf64e
