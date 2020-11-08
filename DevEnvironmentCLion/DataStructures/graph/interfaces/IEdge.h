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
             * The copy/move constructors.
             */
            IEdge(const IEdge&) = delete;
            IEdge(IEdge&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IEdge& operator=(const IEdge&) = delete;
            IEdge& operator=(IEdge&&) = delete;

            /**
             * Gets a source vertex.
             */
            virtual IVertexPtr<TKey, TValue> source() const = 0;

            /**
             * Gets a destination vertex.
             */
            virtual IVertexPtr<TKey, TValue> destination() const = 0;

            /**
             * returns whether an edge is directed.
             */
            virtual bool directed() const = 0;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        template <typename TKey, typename TValue>
        using IEdgePtr = std::shared_ptr<IEdge<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IEdge<TKey, TValue>& left, const IEdge<TKey, TValue>& right)
        {
            if (left.source() < right.source())
            {
                return true;
            }

            if (left.source() > right.source())
            {
                return false;
            }

            return left.destination() < right.destination();
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::ostream& operator<<(std::ostream& stream, const IEdge<TKey, TValue>& edge)
        {
            stream << edge.toString();
            return stream;
        }
    }
}

#endif // I_EDGE_H_ae136689_2087_42e0_970d_4c7537802168
