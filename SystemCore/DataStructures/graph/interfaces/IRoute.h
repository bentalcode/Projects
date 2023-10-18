#ifndef I_ROUTE_H_e80cd9e8_3ab0_4470_bd95_fb04db460186
#define I_ROUTE_H_e80cd9e8_3ab0_4470_bd95_fb04db460186

#include "IVertex.h"

namespace datastructures {
    namespace graph {

        /**
         * The IRoute interface defines a way or course taken in getting
         * from a starting vertex to a Destination vertex in a graph.
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
             * The Copy/move constructors.
             */
            IRoute(const IRoute&) = delete;
            IRoute(IRoute&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IRoute& operator=(const IRoute&) = delete;
            IRoute& operator=(IRoute&&) = delete;

            /**
             * Gets the Source vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Source() const = 0;

            /**
             * Gets the Destination vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Destination() const = 0;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const = 0;
        };

        /**
         * Defines the SharedPtr ofRoute.
         */
        template <typename TKey, typename TValue>
        using IRouteSharedPtr = std::shared_ptr<IRoute<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IRoute<TKey, TValue>& left, const IRoute<TKey, TValue>& right)
        {
            if (left.Source() < right.Source())
            {
                return true;
            }

            if (left.Source() > right.Source())
            {
                return false;
            }

            return left.Destination() < right.Destination();
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::ostream& operator<<(std::ostream& stream, const IRoute<TKey, TValue>& route)
        {
            stream << route.ToString();
            return stream;
        }
    }
}

#endif // I_ROUTE_H_e80cd9e8_3ab0_4470_bd95_fb04db460186
