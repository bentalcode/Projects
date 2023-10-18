#ifndef I_PRIORITY_QUEUE_H_fd96ae9b_0fc0_447e_b7c8_8b6250eec84c
#define I_PRIORITY_QUEUE_H_fd96ae9b_0fc0_447e_b7c8_8b6250eec84c

#include "ISizableCollection.h"
#include "IIterable.h"
#include "IReverseIterable.h"
#include "IMatch.h"

namespace datastructures {
    namespace priority_queue {

        /**
         * The IPriorityQueue interface defines a priority queue.
         */
        template <typename T>
        class IPriorityQueue :
            public base::ISizableCollection<T>,
            public base::IReverseIterable<T>
        {
        public:
            /**
             * The IPriorityQueue constructor.
             */
            IPriorityQueue() = default;

            /**
             * The IPriorityQueue destructor.
             */
            virtual ~IPriorityQueue() = default;

            /**
             * The Copy/move constructors.
             */
            IPriorityQueue(const IPriorityQueue&) = delete;
            IPriorityQueue(IPriorityQueue&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IPriorityQueue& operator=(const IPriorityQueue&) = delete;
            IPriorityQueue& operator=(IPriorityQueue&&) = delete;

            /**
             * Offers an element to the priority queue.
            */
            virtual void Offer(const T& element) = 0;

            /**
             * Polls the Peek element from the priority queue.
             */
            virtual T Poll() = 0;

            /**
             * Gets the Peek element of the priority queue.
             */
            virtual const T& Peek() const = 0;

            /**
             * Clears the priority queue.
             */
            virtual void Clear() = 0;

            /**
             * Checks whether the priority queue Contains an element.
             */
            virtual bool Contains(const T& element) const = 0;

            /**
             * Finds an element in a priority queue.
             * Returns whether an element exist and its result index.
             */
            virtual bool Find(T element, size_t& resultIndex) = 0;

            /**
             * Finds an element in a priority queue by a match predicate.
             * Returns whether an element exist and its result index.
             */
            virtual bool Find(const base::IMatch<T>& match, size_t& resultIndex) = 0;

            /**
             * Updates a value of a specific element and heapify it up.
             */
            virtual void UpdateAndHypifyUp(size_t index, const T& element) = 0;

            /**
             * Updates a value of a specific element and heapify it down.
             */
            virtual void UpdateAndHypifyDown(size_t index, const T& element) = 0;
        };

        /**
         * Defines the SharedPtr ofPriority Queue.
         */
        template <typename T>
        using IPriorityQueueSharedPtr = std::shared_ptr<IPriorityQueue<T>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename T>
        inline bool operator<(const IPriorityQueue<T>& left, const IPriorityQueue<T>& right)
        {
            if (left.size() < right.size())
            {
                return true;
            }

            if (left.size() > right.size())
            {
                return false;
            }

            base::IIteratorSharedPtr<T> leftIterator = left.GetIterator();
            base::IIteratorSharedPtr<T> rightIterator = right.GetIterator();

            while (leftIterator->HasNext() && rightIterator->HasNext())
            {
                const T& leftValue = leftIterator->next();
                const T& rightValue = rightIterator->next();

                if (leftValue < rightValue)
                {
                    return true;
                }

                if (leftValue > rightValue)
                {
                    return false;
                }
            }

            assert(!leftIterator->HasNext() && !rightIterator->HasNext());

            return false;
        }
    }
}

#endif // I_PRIORITY_QUEUE_H_fd96ae9b_0fc0_447e_b7c8_8b6250eec84c
