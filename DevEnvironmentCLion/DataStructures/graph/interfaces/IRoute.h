#ifndef I_ROUTE_H_e80cd9e8_3ab0_4470_bd95_fb04db460186
#define I_ROUTE_H_e80cd9e8_3ab0_4470_bd95_fb04db460186

#include "IVertex.h"

namespace datastructures {
    namespace graph {

        /**
         * The IRoute interface defines a way or course taken in getting
         * from a starting vertex to a destination vertex in a graph.
         */
        template <typename TKey, typename TValue>
        class IRoute
        {
        public:
            /**
             * The constructor.
             */
            IRoute() = default;

            /**
             * The destructor.
             */
            virtual ~IRoute() = default;

            /**
             * The copy/move constructors.
             */
            IRoute(const IRoute&) = delete;
            IRoute(IRoute&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IRoute& operator=(const IRoute&) = delete;
            IRoute& operator=(IRoute&&) = delete;

            /**
             * Gets the source vertex.
             */
            virtual IVertexPtr<TKey, TValue> source() const = 0;

            /**
             * Gets the destination vertex.
             */
            virtual IVertexPtr<TKey, TValue> destination() const = 0;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        template <typename TKey, typename TValue>
        using IRoutePtr = std::shared_ptr<IRoute<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IRoute<TKey, TValue>& left, const IRoute<TKey, TValue>& right)
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
        std::ostream& operator<<(std::ostream& stream, const IRoute<TKey, TValue>& route)
        {
            stream << route.toString();
            return stream;
        }
    }
}

#endif // I_ROUTE_H_e80cd9e8_3ab0_4470_bd95_fb04db460186
