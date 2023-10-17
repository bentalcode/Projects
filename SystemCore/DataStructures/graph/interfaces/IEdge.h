#ifndef I_EDGE_H_ae136689_2087_42e0_970d_4c7537802168
#define I_EDGE_H_ae136689_2087_42e0_970d_4c7537802168

#include "IVertex.h"

namespace datastructures {
    namespace graph {

        /**
         * The IEdge interface defines an edge of a graph.
         */
        template <typename TKey, typename TValue>
        class IEdge
        {
        public:
            /**
             * The constructor.
             */
            IEdge() = default;

            /**
             * The destructor.
             */
            virtual ~IEdge() = default;

            /**
             * The Copy/move constructors.
             */
            IEdge(const IEdge&) = delete;
            IEdge(IEdge&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IEdge& operator=(const IEdge&) = delete;
            IEdge& operator=(IEdge&&) = delete;

            /**
             * Gets a Source vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Source() const = 0;

            /**
             * Gets a Destination vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Destination() const = 0;

            /**
             * returns whether an edge is Directed.
             */
            virtual bool Directed() const = 0;

            /**
             * Gets string representation Of this instance.
             */
            virtual std::wstring ToString() const = 0;
        };

        /**
         * Defines the SharedPtr Of Edge.
         */
        template <typename TKey, typename TValue>
        using IEdgeSharedPtr = std::shared_ptr<IEdge<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IEdge<TKey, TValue>& left, const IEdge<TKey, TValue>& right)
        {
            if (*left.Source() < *right.Source())
            {
                return true;
            }

            if (*left.Source() > *right.Source())
            {
                return false;
            }

            return *left.Destination() < *right.Destination();
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::ostream& operator<<(std::ostream& stream, const IEdge<TKey, TValue>& edge)
        {
            stream << edge.ToString();
            return stream;
        }
    }
}

#endif // I_EDGE_H_ae136689_2087_42e0_970d_4c7537802168
