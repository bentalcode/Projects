#ifndef PRIORITY_QUEUE_UNIT_TEST_H_c28a9a65_1a69_4329_a83f_52d19b2bebc0
#define PRIORITY_QUEUE_UNIT_TEST_H_c28a9a65_1a69_4329_a83f_52d19b2bebc0

#include "UnitTestBase.h"
#include "PriorityQueue.h"
#include "PriorityQueueData.h"
#include "TestData.h"

using namespace datastructures::priority_queue;

namespace test {
    namespace datastructures {
        namespace priority_queue {

            /**
             * The PriorityQueueUnitTest class implements tests for a priority queue.
             */
            class PriorityQueueUnitTest final : public unit_testing::UnitTestBase
            {
            public:
                /**
                 * The PriorityQueueUnitTest constructor.
                 */
                explicit PriorityQueueUnitTest(const std::string& name);

                /**
                 * The PriorityQueueUnitTest destructor.
                 */
                virtual ~PriorityQueueUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a priority queue.
                 */
                void priorityQueueCreationTest();

                /**
                 * Tests the peek and poll logic of a priority queue.
                 */
                void peekAndPollTest();

            private:
                /**
                 * Tests the creation logic of a priority queue.
                 */
                template <typename T>
                void testCreation(const PriorityQueueData<T>& data);

                /**
                 * Tests the peek and poll logic of a priority queue.
                 */
                template <typename T>
                void testPeekAndPoll(const PriorityQueueData<T>& data);

                /**
                 * Creates a priority queue.
                 */
                template <typename T>
                static IPriorityQueuePtr<T> createPriorityQueue(const PriorityQueueData<T>& data);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a priority queue.
             */
            template <typename T>
            void PriorityQueueUnitTest::testCreation(const PriorityQueueData<T>& data)
            {
                IPriorityQueuePtr<T> priorityQueue = createPriorityQueue(data);

                getAssertion().assertEqualsWithIterators(
                    *priorityQueue->getIterator(),
                    *base::VectorIterator<T>::make(data.getData()),
                    "Invalid creation logic of a priority queue.");
            }

            /**
             * Tests the creation logic of a priority queue.
             */
            template <typename T>
            void PriorityQueueUnitTest::testPeekAndPoll(const PriorityQueueData<T>& data)
            {
                IPriorityQueuePtr<T> priorityQueue = createPriorityQueue(data);

                getAssertion().assertEqualsWithIterators(
                    *priorityQueue->getIterator(),
                    *base::VectorIterator<T>::make(data.getData()),
                    "Invalid creation logic of a priority queue.");

                size_t currSize = priorityQueue->size();

                while (!priorityQueue->empty()) {
                    const T& valueToRemove = priorityQueue->peek();
                    T removedValue = priorityQueue->poll();
                    --currSize;

                    getAssertion().assertEquals(
                        removedValue,
                        valueToRemove,
                        "Incorrect peak and poll logic of a priority queue: invalid removed value.");

                    getAssertion().assertEquals(
                        priorityQueue->size(),
                        currSize,
                        "Incorrect peak and poll logic of a priority queue: invalid size.");
                }
            }

            /**
             * Creates a priority queue.
             */
            template <typename T>
            IPriorityQueuePtr<T> PriorityQueueUnitTest::createPriorityQueue(const PriorityQueueData<T>& data)
            {
                IPriorityQueuePtr<T> priorityQueue = PriorityQueue<T>::make(data.getElementComparator());

                for (const T& item : data.getCreationData())
                {
                    priorityQueue->offer(item);
                }

                return priorityQueue;
            }
        }
    }
}

#endif // PRIORITY_QUEUE_UNIT_TEST_H_c28a9a65_1a69_4329_a83f_52d19b2bebc0
