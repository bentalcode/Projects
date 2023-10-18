#ifndef ROUTE_H_5c2ac7da_e388_4658_87c0_517fef72d6c4
#define ROUTE_H_5c2ac7da_e388_4658_87c0_517fef72d6c4

#include "IRoute.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace graph {

        /**
         * The Route class implements a way or course taken in getting
         * from a starting vertex to a Destination vertex in a graph.
         */
        template <typename TKey, typename TValue>
        class Route final : public IRoute<TKey, TValue>
        {
        public:
            /**
             * Creates a new instance of a route.
             */
            static IRouteSharedPtr<TKey, TValue> Make(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination);

            /**
             * The Route constructor.
             */
            Route(
                IVertexSharedPtr<TKey, TValue> source,
                IVertexSharedPtr<TKey, TValue> destination);

            /**
             * The Route destructor.
             */
            virtual ~Route();

            /**
             * The Copy/move constructors.
             */
            Route(const Route&) = delete;
            Route(Route&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            Route& operator=(const Route&) = delete;
            Route& operator=(Route&&) = delete;

            /**
             * Gets the Source vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Source() const override;

            /**
             * Gets the Destination vertex.
             */
            virtual IVertexSharedPtr<TKey, TValue> Destination() const override;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const override;

        private:
            IVertexSharedPtr<TKey, TValue> m_source;
            IVertexSharedPtr<TKey, TValue> m_destination;
        };

        template <typename TKey, typename TValue>
        using IRouteSharedPtr = std::shared_ptr<IRoute<TKey, TValue>>;

        /**
         * Creates a new instance of a route.
         */
        template <typename TKey, typename TValue>
        IRouteSharedPtr<TKey, TValue> Route<TKey, TValue>::Make(
            IVertexSharedPtr<TKey, TValue> source,
            IVertexSharedPtr<TKey, TValue> destination)
        {
            return std::make_shared<Route<TKey, TValue>>(source, destination);
        }

        /**
         * The Route constructor.
         */
        template <typename TKey, typename TValue>
        Route<TKey, TValue>::Route(
            IVertexSharedPtr<TKey, TValue> source,
            IVertexSharedPtr<TKey, TValue> destination) :
            m_source(source),
            m_destination(destination)
        {
            base::SmartPointers::Validate<IVertex<TKey, TValue>>(source);
            base::SmartPointers::Validate<IVertex<TKey, TValue>>(destination);
        }

        /**
         * The Route destructor.
         */
        template <typename TKey, typename TValue>
        Route<TKey, TValue>::~Route()
        {
        }

        /**
         * Gets the Source vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Route<TKey, TValue>::Source() const
        {
            return m_source;
        }

        /**
         * Gets the Destination vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Route<TKey, TValue>::Destination() const
        {
            return m_destination;
        }

        /**
         * Gets string representation ofthis instance.
         */
        template <typename TKey, typename TValue>
        std::wstring Route<TKey, TValue>::ToString() const
        {
            std::wstringstream stream;
            stream << m_source << L"->" << m_destination;
            return stream.str();
        }
    }
}

#endif // ROUTE_H_5c2ac7da_e388_4658_87c0_517fef72d6c4
