#ifndef EDGE_H_9df01f1b_31d6_400d_b3cb_eefa198ad7a9
#define EDGE_H_9df01f1b_31d6_400d_b3cb_eefa198ad7a9

#include "IEdge.h"
#include "IVertex.h"

namespace datastructures {
    namespace graph {

        /**
         * The Edge class implements an edge of a graph.
         */
        template <typename TKey, typename TValue>
        class Edge final : public IEdge<TKey, TValue>
        {
        public:
            /**
             * Creates a new instance of an edge.
             */
            static IEdgeSharedPtr<TKey, TValue> make(
                    IVertexSharedPtr<TKey, TValue> source,
                    IVertexSharedPtr<TKey, TValue> destination);

            /**
             * Creates a new instance of a directed edge.
             */
            static IEdgeSharedPtr<TKey, TValue> makeDirected(
                    IVertexSharedPtr<TKey, TValue> source,
                    IVertexSharedPtr<TKey, TValue> destination);

            /**
             * The Edge constructor.
             */
            Edge(
                    IVertexSharedPtr<TKey, TValue> source,
                    IVertexSharedPtr<TKey, TValue> destination,
                    bool directed);

            /**
             * The Edge destructor.
             */
            virtual ~Edge();

            /**
             * The copy/move constructors.
             */
            Edge(const Edge&) = delete;
            Edge(Edge&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            Edge& operator=(const Edge&) = delete;
            Edge& operator=(Edge&&) = delete;

            /**
             * Gets a source vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> source() const override;

            /**
             * Gets a destination vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> destination() const override;

            /**
             * returns whether an edge is directed.
             */
            virtual bool directed() const override;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            IVertexSharedPtr<TKey, TValue> m_source;
            IVertexSharedPtr<TKey, TValue> m_destination;
            bool m_directed;
        };

        /**
         * Creates a new instance of an edge.
         */
        template <typename TKey, typename TValue>
        IEdgeSharedPtr<TKey, TValue> Edge<TKey, TValue>::make(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination)
        {
            return std::make_shared<Edge>(
                source,
                destination,
                false);
        }

        /**
         * Creates a new instance of a directed edge.
         */
        template <typename TKey, typename TValue>
        IEdgeSharedPtr<TKey, TValue> Edge<TKey, TValue>::makeDirected(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination)
        {
            return std::make_shared<Edge>(
                source,
                destination,
                true);
        }

        /**
         * The Edge constructor.
         */
        template <typename TKey, typename TValue>
        Edge<TKey, TValue>::Edge(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination,
                bool directed) :
            m_source(source),
            m_destination(destination),
            m_directed(directed)
        {
        }

        /**
         * The Edge destructor.
         */
        template <typename TKey, typename TValue>
        Edge<TKey, TValue>::~Edge()
        {
        }

        /**
         * Gets a source vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Edge<TKey, TValue>::source() const
        {
            return m_source;
        }

        /**
         * Gets a destination vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Edge<TKey, TValue>::destination() const
        {
            return m_destination;
        }

        /**
         * returns whether an edge is directed.
         */
        template <typename TKey, typename TValue>
        bool Edge<TKey, TValue>::directed() const
        {
            return m_directed;
        }

        /**
         * Gets string representation of this instance.
         */
        template <typename TKey, typename TValue>
        std::string Edge<TKey, TValue>::toString() const
        {
            std::stringstream stream;
            stream << *m_source;

            if (m_directed)
            {
                stream << "->";
            }
            else
            {
                stream << "<->";
            }

            stream << *m_destination;

            return stream.str();
        }
    }
}

#endif // EDGE_H_9df01f1b_31d6_400d_b3cb_eefa198ad7a9
