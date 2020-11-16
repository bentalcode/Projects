#ifndef ROUTE_H_5c2ac7da_e388_4658_87c0_517fef72d6c4
#define ROUTE_H_5c2ac7da_e388_4658_87c0_517fef72d6c4

#include "IRoute.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace graph {

        /**
         * The Route class implements a way or course taken in getting
         * from a starting vertex to a destination vertex in a graph.
         */
        template <typename TKey, typename TValue>
        class Route final : public IRoute<TKey, TValue>
        {
        public:
            /**
             * Creates a new instance of a route.
             */
            static IRoutePtr<TKey, TValue> make(
                IVertexPtr<TKey, TValue> source,
                IVertexPtr<TKey, TValue> destination);

            /**
             * The Route constructor.
             */
            Route(
                IVertexPtr<TKey, TValue> source,
                IVertexPtr<TKey, TValue> destination);

            /**
             * The Route destructor.
             */
            virtual ~Route();

            /**
             * The copy/move constructors.
             */
            Route(const Route&) = delete;
            Route(Route&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            Route& operator=(const Route&) = delete;
            Route& operator=(Route&&) = delete;

            /**
             * Gets the source vertex.
             */
            virtual IVertexPtr<TKey, TValue> source() const override;

            /**
             * Gets the destination vertex.
             */
            virtual IVertexPtr<TKey, TValue> destination() const override;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            IVertexPtr<TKey, TValue> m_source;
            IVertexPtr<TKey, TValue> m_destination;
        };

        template <typename TKey, typename TValue>
        using IRoutePtr = std::shared_ptr<IRoute<TKey, TValue>>;

        /**
         * Creates a new instance of a route.
         */
        template <typename TKey, typename TValue>
        IRoutePtr<TKey, TValue> Route<TKey, TValue>::make(
            IVertexPtr<TKey, TValue> source,
            IVertexPtr<TKey, TValue> destination)
        {
            return std::make_shared<Route<TKey, TValue>>(source, destination);
        }

        /**
         * The Route constructor.
         */
        template <typename TKey, typename TValue>
        Route<TKey, TValue>::Route(
            IVertexPtr<TKey, TValue> source,
            IVertexPtr<TKey, TValue> destination) :
            m_source(source),
            m_destination(destination)
        {
            base::SmartPointers::validate(source);
            base::SmartPointers::validate(destination);
        }

        /**
         * The Route destructor.
         */
        template <typename TKey, typename TValue>
        Route<TKey, TValue>::~Route()
        {
        }

        /**
         * Gets the source vertex.
         */
        template <typename TKey, typename TValue>
        IVertexPtr<TKey, TValue> Route<TKey, TValue>::source() const
        {
            return m_source;
        }

        /**
         * Gets the destination vertex.
         */
        template <typename TKey, typename TValue>
        IVertexPtr<TKey, TValue> Route<TKey, TValue>::destination() const
        {
            return m_destination;
        }

        /**
         * Gets string representation of this instance.
         */
        template <typename TKey, typename TValue>
        std::string Route<TKey, TValue>::toString() const
        {
            std::stringstream stream;
            stream << m_source << "->" << m_destination;
            return stream.str();
        }
    }
}

#endif // ROUTE_H_5c2ac7da_e388_4658_87c0_517fef72d6c4
