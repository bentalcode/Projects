#ifndef I_WALK_H_45407491_d929_4854_a368_e3926f419fe5
#define I_WALK_H_45407491_d929_4854_a368_e3926f419fe5

#include "IIterable.h"
#include "IReverseIterable.h"
#include "ISizableCollection.h"
#include "IVertex.h"
#include "CompareToBuilder.h"

namespace datastructures {
    namespace graph {

        /**
         * The IWalk interface defines an edge of a graph.
         */
        template <typename TKey, typename TValue>
        class IWalk :
            public base::IIterable<IVertexSharedPtr<TKey, TValue>>,
            public base::IReverseIterable<IVertexSharedPtr<TKey, TValue>>,
            public base::ISizableCollection
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
             * The copy/move constructors.
             */
            IWalk(const IWalk&) = delete;
            IWalk(IWalk&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IWalk& operator=(const IWalk&) = delete;
            IWalk& operator=(IWalk&&) = delete;

            /**
             * Adds a vertex.
             */
            virtual void addVertex(IVertexSharedPtr<TKey, TValue> vertex) = 0;

            /**
             * Removes the last vertex.
             */
            virtual void removeLastVertex() = 0;

            /**
             * Gets the vertices.
             */
            virtual const std::list<IVertexSharedPtr<TKey, TValue>>& getVertices() const = 0;

            /**
             * Checks whether a vertex has been visited before.
             */
            virtual bool visited(const IVertex<TKey, TValue>& vertex) const = 0;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        /**
         * Defines the SharedPtr of Walk.
         */
        template <typename TKey, typename TValue>
        using IWalkSharedPtr = std::shared_ptr<IWalk<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IWalk<TKey, TValue>& left, const IWalk<TKey, TValue>& right)
        {
            base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> leftIterator = left.getIterator();
            base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> rightIterator = right.getIterator();

            base::CompareToBuilder compareToBuilder;
            bool status = compareToBuilder.withDereferenceIterator(
                *leftIterator,
                *rightIterator).build();

            return status < 0;
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::ostream& operator<<(std::ostream& stream, const IWalk<TKey, TValue>& walk)
        {
            stream << walk.toString();
            return stream;
        }
    }
}

#endif // I_WALK_H_45407491_d929_4854_a368_e3926f419fe5
