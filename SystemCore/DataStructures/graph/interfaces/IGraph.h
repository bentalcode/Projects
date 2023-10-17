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
             * The Copy/move constructors.
             */
            IGraph(const IGraph&) = delete;
            IGraph(IGraph&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IGraph& operator=(const IGraph&) = delete;
            IGraph& operator=(IGraph&&) = delete;

            /**
             * Gets the Vertices of the graph.
             */
            virtual const VertexSet<TKey, TValue>& Vertices() const = 0;

            /**
             * Gets the Edges of the graph.
             */
            virtual const EdgeSet<TKey, TValue>& Edges() const = 0;

            /**
             * Gets the adjacency matrix.
             */
            virtual const IAdjacencyMatrix<TKey, TValue>& GetAdjacencyMatrix() const = 0;

            /**
             * Gets the number Of Vertices in the graph.
             * The order is equal to |V(G)|.
             */
            virtual size_t GetOrder() const = 0;

            /**
             * Gets the degree.
             * A vertex degree is the number Of Edges incident to a vertex. Notated as d(V).
             */
            virtual size_t GetDegree(IVertexSharedPtr<TKey, TValue> vertex) const = 0;

            /**
             * Gets string representation Of this instance.
             */
            virtual std::wstring ToString() const = 0;
        };

        /**
         * Defines the SharedPtr Of Graph.
         */
        template <typename TKey, typename TValue>
        using IGraphSharedPtr = std::shared_ptr<IGraph<TKey, TValue>>;

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
        std::ostream& operator<<(std::ostream& stream, const IGraph<TKey, TValue>& graph)
        {
            stream << graph.ToString();
            return stream;
        }
    }
}

#endif // I_GRAPH_H_3fa1d2e0_eef1_4d7a_9f9c_02cf20acf64e
