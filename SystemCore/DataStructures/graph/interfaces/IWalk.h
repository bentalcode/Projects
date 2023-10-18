#ifndef I_WALK_H_45407491_d929_4854_a368_e3926f419fe5
#define I_WALK_H_45407491_d929_4854_a368_e3926f419fe5

#include "IIterable.h"
#include "IReverseIterable.h"
#include "ISizableCollection.h"
#include "IVertex.h"
#include "EqualBuilder.h"
#include "CompareToBuilder.h"
#include <list>

namespace datastructures {
    namespace graph {

        /**
         * The IWalk interface defines an edge of a graph.
         */
        template <typename TKey, typename TValue>
        class IWalk :
            public base::ISizableCollection<IVertexSharedPtr<TKey, TValue>>,
            public base::IReverseIterable<IVertexSharedPtr<TKey, TValue>>
        {
        public:
            /**
             * The constructor.
             */
            IWalk() = default;

            /**
             * The destructor.
             */
            virtual ~IWalk() = default;

            /**
             * The Copy/move constructors.
             */
            IWalk(const IWalk&) = delete;
            IWalk(IWalk&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IWalk& operator=(const IWalk&) = delete;
            IWalk& operator=(IWalk&&) = delete;

            /**
             * Adds a vertex.
             */
            virtual void AddVertex(IVertexSharedPtr<TKey, TValue> vertex) = 0;

            /**
             * Removes the last vertex.
             */
            virtual void RemoveLastVertex() = 0;

            /**
             * Gets the Vertices.
             */
            virtual const std::list<IVertexSharedPtr<TKey, TValue>>& GetVertices() const = 0;

            /**
             * Checks whether a vertex Has been Visited before.
             */
            virtual bool Visited(const IVertex<TKey, TValue>& vertex) const = 0;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const = 0;
        };

        /**
         * Defines the SharedPtr ofWalk.
         */
        template <typename TKey, typename TValue>
        using IWalkSharedPtr = std::shared_ptr<IWalk<TKey, TValue>>;

        /**
         * Implements an operator equals for walks.
         */
        template <typename TKey, typename TValue>
        inline bool operator==(
            const IWalk<TKey, TValue>& lhs,
            const IWalk<TKey, TValue>& rhs)
        {
            base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> lhsIterator = lhs.GetIterator();
            base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> rhsIterator = rhs.GetIterator();

            base::EqualBuilder equalBuilder;
            bool status = equalBuilder.WithDereferenceIterator(
                *lhsIterator,
                *rhsIterator).Build();

            return status;
        }

        /**
         * Implements an operator not equals for walks.
         */
        template <typename TKey, typename TValue>
        inline bool operator!=(
            const IWalk<TKey, TValue>& lhs,
            const IWalk<TKey, TValue>& rhs)
        {
            return !(lhs == rhs);
        }

        /**
         * Defines an operator less than for walks.
         */
        template <typename TKey, typename TValue>
        bool operator<(
            const IWalk<TKey, TValue>& lhs,
            const IWalk<TKey, TValue>& rhs)
        {
            base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> lhsIterator = lhs.GetIterator();
            base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> rhsIterator = rhs.GetIterator();

            base::CompareToBuilder compareToBuilder;
            int status = compareToBuilder.WithDereferenceIterator(
                *lhsIterator,
                *rhsIterator).Build();

            return status < 0;
        }

        /**
         * Defines an operator less or equal than for walks.
         */
        template <typename TKey, typename TValue>
        bool operator<=(
            const IWalk<TKey, TValue>& lhs,
            const IWalk<TKey, TValue>& rhs)
        {
            return !(rhs.GetKey() < lhs.GetKey());
        }

        /**
         * Defines an operator grater than for walks.
         */
        template <typename TKey, typename TValue>
        bool operator>(
            const IWalk<TKey, TValue>& lhs,
            const IWalk<TKey, TValue>& rhs)
        {
            return rhs.GetKey() < lhs.GetKey();
        }

        /**
         * Defines an operator grater or equal than for walks.
         */
        template <typename TKey, typename TValue>
        bool operator>=(
            const IWalk<TKey, TValue>& lhs,
            const IWalk<TKey, TValue>& rhs)
        {
            return !(lhs.GetKey() < rhs.GetKey());
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::wostream& operator<<(std::wostream& stream, const IWalk<TKey, TValue>& walk)
        {
            stream << walk.ToString();
            return stream;
        }
    }
}

#endif // I_WALK_H_45407491_d929_4854_a368_e3926f419fe5
