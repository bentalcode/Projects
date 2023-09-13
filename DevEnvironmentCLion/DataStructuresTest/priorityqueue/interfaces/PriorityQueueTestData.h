#ifndef PRIORITY_QUEUE_TEST_DATA_H_2c897ecb_5e3a_49ad_b5a0_acf20ab9c1ab
#define PRIORITY_QUEUE_TEST_DATA_H_2c897ecb_5e3a_49ad_b5a0_acf20ab9c1ab

#include "PriorityQueueData.h"

namespace test {
    namespace datastructures {
        namespace priority_queue {

            /**
             * The IPriorityQueueTestData interface defines the data of the tests of a priority queue.
             */
            class PriorityQueueTestData final
            {
            public:
                /**
                 * The PriorityQueueTestData constructor.
                 */
                PriorityQueueTestData();

                /**
                 * The PriorityQueueTestData destructor.
                 */
                ~PriorityQueueTestData();

                /**
                 * The copy/move constructors.
                 */
                PriorityQueueTestData(const PriorityQueueTestData&) = delete;
                PriorityQueueTestData(PriorityQueueTestData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                PriorityQueueTestData& operator=(const PriorityQueueTestData&) = delete;
                PriorityQueueTestData& operator=(PriorityQueueTestData&&) = delete;

                /**
                 * Gets data of the tests of a priority queue.
                 */
                std::vector<PriorityQueueDataSharedPtr<int>> getData() const;

            private:
                /**
                 * Gets the data of priority queue1.
                 */
                static PriorityQueueDataSharedPtr<int> getPriorityQueueData1();

                /**
                 * Gets the data of priority queue2.
                 */
                static PriorityQueueDataSharedPtr<int> getPriorityQueueData2();

                /**
                 * Gets the data of priority queue3.
                 */
                static PriorityQueueDataSharedPtr<int> getPriorityQueueData3();

                /**
                 * Gets the data of priority queue4.
                 */
                static PriorityQueueDataSharedPtr<int> getPriorityQueueData4();

                /**
                 * Gets the data of priority queue5.
                 */
                static PriorityQueueDataSharedPtr<int> getPriorityQueueData5();
            };

            //
            // Defines the SharedPtr of Priority Queue Test Data...
            //
            using PriorityQueueTestDataSharedPtr = std::shared_ptr<PriorityQueueTestData>;
        }
    }
}

#endif // PRIORITY_QUEUE_TEST_DATA_H_2c897ecb_5e3a_49ad_b5a0_acf20ab9c1ab
