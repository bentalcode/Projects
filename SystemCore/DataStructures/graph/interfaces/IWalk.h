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
             * Gets string representation Of this instance.
             */
            virtual std::wstring ToString() const = 0;
        };

        /**
         * Defines the SharedPtr Of Walk.
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
                    *rightIterator).Build();

            return status < 0;
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::ostream& operator<<(std::ostream& stream, const IWalk<TKey, TValue>& walk)
        {
            stream << walk.ToString();
            return stream;
        }
    }
}

#endif // I_WALK_H_45407491_d929_4854_a368_e3926f419fe5
