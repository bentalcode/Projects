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
            public base::ISizableCollection,
            public base::IIterable<T>,
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
             * The copy/move constructors.
             */
            IPriorityQueue(const IPriorityQueue&) = delete;
            IPriorityQueue(IPriorityQueue&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IPriorityQueue& operator=(const IPriorityQueue&) = delete;
            IPriorityQueue& operator=(IPriorityQueue&&) = delete;

            /**
             * Offers an element to the priority queue.
            */
            virtual void offer(const T& element) = 0;

            /**
             * Polls the peek element from the priority queue.
             */
            virtual T poll() = 0;

            /**
             * Gets the peek element of the priority queue.
             */
            virtual const T& peek() const = 0;

            /**
             * Clears the priority queue.
             */
            virtual void clear() = 0;

            /**
             * Checks whether the priority queue contains an element.
             */
            virtual bool contains(const T& element) const = 0;

            /**
             * Finds an element in a priority queue.
             * Returns whether an element exist and its result index.
             */
            virtual bool find(T element, size_t& resultIndex) = 0;

            /**
             * Finds an element in a priority queue by a match predicate.
             * Returns whether an element exist and its result index.
             */
            virtual bool find(const base::IMatch<T>& match, size_t& resultIndex) = 0;

            /**
             * Updates a value of a specific element and heapify it up.
             */
            virtual void updateAndHypifyUp(size_t index, const T& element) = 0;

            /**
             * Updates a value of a specific element and heapify it down.
             */
            virtual void updateAndHypifyDown(size_t index, const T& element) = 0;
        };

        template <typename T>
        using IPriorityQueuePtr = std::shared_ptr<IPriorityQueue<T>>;

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

            base::IIteratorPtr<T> leftIterator = left.getIterator();
            base::IIteratorPtr<T> rightIterator = right.getIterator();

            while (leftIterator->hasNext() && rightIterator->hasNext())
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

            assert(!leftIterator->hasNext() && !rightIterator->hasNext());

            return false;
        }
    }
}

#endif // I_PRIORITY_QUEUE_H_fd96ae9b_0fc0_447e_b7c8_8b6250eec84c
