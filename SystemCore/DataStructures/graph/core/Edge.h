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
            static IEdgeSharedPtr<TKey, TValue> Make(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination);

            /**
             * Creates a new instance of a Directed edge.
             */
            static IEdgeSharedPtr<TKey, TValue> MakeDirected(
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
             * The Copy/move constructors.
             */
            Edge(const Edge&) = delete;
            Edge(Edge&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            Edge& operator=(const Edge&) = delete;
            Edge& operator=(Edge&&) = delete;

            /**
             * Gets a Source vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Source() const override;

            /**
             * Gets a Destination vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Destination() const override;

            /**
             * returns whether an edge is Directed.
             */
            virtual bool Directed() const override;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const override;

        private:
            IVertexSharedPtr<TKey, TValue> m_source;
            IVertexSharedPtr<TKey, TValue> m_destination;
            bool m_directed;
        };

        /**
         * Creates a new instance of an edge.
         */
        template <typename TKey, typename TValue>
        IEdgeSharedPtr<TKey, TValue> Edge<TKey, TValue>::Make(
            IVertexSharedPtr<TKey, TValue> source,
            IVertexSharedPtr<TKey, TValue> destination)
        {
            return std::make_shared<Edge>(
                source,
                destination,
                false);
        }

        /**
         * Creates a new instance of a Directed edge.
         */
        template <typename TKey, typename TValue>
        IEdgeSharedPtr<TKey, TValue> Edge<TKey, TValue>::MakeDirected(
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
         * Gets a Source vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Edge<TKey, TValue>::Source() const
        {
            return m_source;
        }

        /**
         * Gets a Destination vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Edge<TKey, TValue>::Destination() const
        {
            return m_destination;
        }

        /**
         * returns whether an edge is Directed.
         */
        template <typename TKey, typename TValue>
        bool Edge<TKey, TValue>::Directed() const
        {
            return m_directed;
        }

        /**
         * Gets string representation ofthis instance.
         */
        template <typename TKey, typename TValue>
        std::wstring Edge<TKey, TValue>::ToString() const
        {
            std::wstringstream stream;
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
