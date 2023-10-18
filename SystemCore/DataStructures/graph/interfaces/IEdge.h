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
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const = 0;
        };

        /**
         * Defines the SharedPtr ofEdge.
         */
        template <typename TKey, typename TValue>
        using IEdgeSharedPtr = std::shared_ptr<IEdge<TKey, TValue>>;

        /**
         * Implements an operator equals for edges.
         */
        template <typename TKey, typename TValue>
        inline bool operator==(
            const IEdge<TKey, TValue>& lhs,
            const IEdge<TKey, TValue>& rhs)
        {
            return
                lhs.Source() == rhs.Source() &&
                lhs.Destination() == rhs.Destination();
        }

        /**
         * Implements an operator not equals for edges.
         */
        template <typename TKey, typename TValue>
        inline bool operator!=(
            const IEdge<TKey, TValue>& lhs,
            const IEdge<TKey, TValue>& rhs)
        {
            return !(lhs == rhs);
        }

        /**
         * Defines an operator less than for edges.
         */
        template <typename TKey, typename TValue>
        bool operator<(
            const IEdge<TKey, TValue>& lhs,
            const IEdge<TKey, TValue>& rhs)
        {
            if (*lhs.Source() < *rhs.Source())
            {
                return true;
            }

            if (*lhs.Source() > *rhs.Source())
            {
                return false;
            }

            return *lhs.Destination() < *rhs.Destination();
        }

        /**
         * Defines an operator less or equal than for edges.
         */
        template <typename TKey, typename TValue>
        bool operator<=(
            const IEdge<TKey, TValue>& lhs,
            const IEdge<TKey, TValue>& rhs)
        {
            return !(rhs.GetKey() < lhs.GetKey());
        }

        /**
         * Defines an operator grater than for edges.
         */
        template <typename TKey, typename TValue>
        bool operator>(
            const IEdge<TKey, TValue>& lhs,
            const IEdge<TKey, TValue>& rhs)
        {
            return rhs.GetKey() < lhs.GetKey();
        }

        /**
         * Defines an operator grater or equal than for edges.
         */
        template <typename TKey, typename TValue>
        bool operator>=(
            const IEdge<TKey, TValue>& lhs,
            const IEdge<TKey, TValue>& rhs)
        {
            return !(lhs.GetKey() < rhs.GetKey());
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::wostream& operator<<(std::wostream& stream, const IEdge<TKey, TValue>& edge)
        {
            stream << edge.ToString();
            return stream;
        }
    }
}

#endif // I_EDGE_H_ae136689_2087_42e0_970d_4c7537802168
