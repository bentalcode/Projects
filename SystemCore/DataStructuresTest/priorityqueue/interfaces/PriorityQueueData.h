#ifndef PRIORITY_QUEUE_DATA_H_7063fca5_a364_4130_b63a_2a44177f40f8
#define PRIORITY_QUEUE_DATA_H_7063fca5_a364_4130_b63a_2a44177f40f8

#include "IBinaryComparator.h"
#include <vector>

namespace test {
    namespace datastructures {
        namespace priority_queue {

            /**
             * The PriorityQueueData class implements the data of a priority queue.
             */
            template <typename T>
            class PriorityQueueData final
            {
            public:
                /**
                 * The PriorityQueueData constructor.
                 */
                PriorityQueueData(
                    base::IBinaryComparatorSharedPtr<T> elementComparator,
                    const std::vector<T>& creationData,
                    const std::vector<T>& data);

                /**
                 * The PriorityQueueData destructor.
                 */
                ~PriorityQueueData();

                /**
                 * The copy/move constructors.
                 */
                PriorityQueueData(const PriorityQueueData&) = delete;
                PriorityQueueData(PriorityQueueData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                PriorityQueueData& operator=(const PriorityQueueData&) = delete;
                PriorityQueueData& operator=(PriorityQueueData&&) = delete;

                /**
                 * Gets the comparator of an element.
                 */
                base::IBinaryComparatorSharedPtr<T> GetElementComparator() const;

                /**
                 * Gets the creation data of a priority queue.
                 */
                const std::vector<T>& GetCreationData() const;

                /**
                 * Gets the actual data of a priority queue.
                 */
                const std::vector<T>& GetData() const;

            private:
                base::IBinaryComparatorSharedPtr<T> m_elementComparator;
                std::vector<T> m_creationData;
                std::vector<T> m_data;
            };

            //
            // Defines the SharedPtr of Priority Queue Data...
            //
            template <typename T>
            using PriorityQueueDataSharedPtr = std::shared_ptr<PriorityQueueData<T>>;

            /**
             * The PriorityQueueData constructor.
             */
            template <typename T>
            PriorityQueueData<T>::PriorityQueueData(
                base::IBinaryComparatorSharedPtr<T> elementComparator,
                const std::vector<T>& creationData,
                const std::vector<T>& data) :
                m_elementComparator(elementComparator),
                m_creationData(creationData),
                m_data(data)
            {
            }

            /**
             * The PriorityQueueData destructor.
             */
            template <typename T>
            PriorityQueueData<T>::~PriorityQueueData()
            {
            }

            /**
             * Gets the comparator of an element.
             */
            template <typename T>
            base::IBinaryComparatorSharedPtr<T> PriorityQueueData<T>::GetElementComparator() const
            {
                return m_elementComparator;
            }

            /**
             * Gets the creation data of a priority queue.
             */
            template <typename T>
            const std::vector<T>& PriorityQueueData<T>::GetCreationData() const
            {
                return m_creationData;
            }

            /**
             * Gets the actual data of a priority queue.
             */
            template <typename T>
            const std::vector<T>& PriorityQueueData<T>::GetData() const
            {
                return m_data;
            }

        }
    }
}

#endif // PRIORITY_QUEUE_DATA_H_7063fca5_a364_4130_b63a_2a44177f40f8
