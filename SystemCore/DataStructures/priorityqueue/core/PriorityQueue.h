#ifndef PRIORITY_QUEUE_H_0e8e234c_1fe6_4448_a34a_338b19fbb505
#define PRIORITY_QUEUE_H_0e8e234c_1fe6_4448_a34a_338b19fbb505

#include "AbstractPriorityQueue.h"
#include "Comparator.h"

namespace datastructures {
    namespace priority_queue {

        /**
         * The PriorityQueue class implements a priority queue.
         */
        template <typename T>
        class PriorityQueue final : public AbstractPriorityQueue<T>
        {
        public:
            /**
             * Creates a priority queue.
             */
            static IPriorityQueueSharedPtr<T> Make();

            /**
             * Creates a priority queue and an element comparator.
             */
            static IPriorityQueueSharedPtr<T> Make(base::IBinaryComparatorSharedPtr<T> elementComparator);

            /**
             * Creates a priority queue with an initial data.
             */
            static IPriorityQueueSharedPtr<T> Make(const std::vector<T>& data);

            /**
             * Creates a priority queue with an initial data and an element comparator.
             */
            static IPriorityQueueSharedPtr<T> Make(
                const std::vector<T>& data,
                base::IBinaryComparatorSharedPtr<T> elementComparator);

            /**
             * The PriorityQueue constructor.
             */
            explicit PriorityQueue(base::IBinaryComparatorSharedPtr<T> elementComparator);

            /**
             * The PriorityQueue constructor.
             */
            PriorityQueue(
                const std::vector<T>& data,
                base::IBinaryComparatorSharedPtr<T> elementComparator);

            /**
             * The PriorityQueue destructor.
             */
            virtual ~PriorityQueue();

            /**
             * The Copy/move constructors.
             */
            PriorityQueue(const PriorityQueue&) = delete;
            PriorityQueue(PriorityQueue&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            PriorityQueue& operator=(const PriorityQueue&) = delete;
            PriorityQueue& operator=(PriorityQueue&&) = delete;
        };

        template <typename T>
        using IPriorityQueueSharedPtr = std::shared_ptr<IPriorityQueue<T>>;

        /**
         * Creates a priority queue.
         */
        template <typename T>
        IPriorityQueueSharedPtr<T> PriorityQueue<T>::Make()
        {
            return std::make_shared<PriorityQueue>(base::Comparator<T>::make());
        }

        /**
         * Creates a priority queue and an element comparator.
         */
        template <typename T>
        IPriorityQueueSharedPtr<T> PriorityQueue<T>::Make(base::IBinaryComparatorSharedPtr<T> elementComparator)
        {
            return std::make_shared<PriorityQueue>(elementComparator);
        }

        /**
         * Creates a priority queue with an initial data.
         */
        template <typename T>
        IPriorityQueueSharedPtr<T> PriorityQueue<T>::Make(const std::vector<T>& data)
        {
            return std::make_shared<PriorityQueue>(
                data,
                base::Comparator<T>::make());
        }

        /**
         * Creates a min priority queue with an initial data and an element comparator.
         */
        template <typename T>
        IPriorityQueueSharedPtr<T> PriorityQueue<T>::Make(
            const std::vector<T>& data,
            base::IBinaryComparatorSharedPtr<T> elementComparator)
        {
            return std::make_shared<PriorityQueue>(
                data,
                elementComparator);
        }

        /**
         * The PriorityQueue constructor with an element comparator.
         */
        template <typename T>
        PriorityQueue<T>::PriorityQueue(base::IBinaryComparatorSharedPtr<T> elementComparator) :
            AbstractPriorityQueue<T>(elementComparator)
        {
        }

        /**
         * The PriorityQueue constructor with initial data and an element comparator.
         */
        template <typename T>
        PriorityQueue<T>::PriorityQueue(
            const std::vector<T>& data,
            base::IBinaryComparatorSharedPtr<T> elementComparator) :
            AbstractPriorityQueue<T>(data, elementComparator)
        {
        }

        /**
         * The PriorityQueue destructor.
         */
        template <typename T>
        PriorityQueue<T>::~PriorityQueue()
        {
        }
    }
}

#endif // PRIORITY_QUEUE_H_0e8e234c_1fe6_4448_a34a_338b19fbb505
