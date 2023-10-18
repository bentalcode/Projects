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
                explicit PriorityQueueUnitTest(const std::wstring& name);

                /**
                 * The PriorityQueueUnitTest destructor.
                 */
                virtual ~PriorityQueueUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a priority queue.
                 */
                void PriorityQueueCreationTest();

                /**
                 * Tests the peek and poll logic of a priority queue.
                 */
                void PeekAndPollTest();

            private:
                /**
                 * Tests the creation logic of a priority queue.
                 */
                template <typename T>
                void TestCreation(const PriorityQueueData<T>& data);

                /**
                 * Tests the peek and poll logic of a priority queue.
                 */
                template <typename T>
                void TestPeekAndPoll(const PriorityQueueData<T>& data);

                /**
                 * Creates a priority queue.
                 */
                template <typename T>
                static IPriorityQueueSharedPtr<T> CreatePriorityQueue(const PriorityQueueData<T>& data);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a priority queue.
             */
            template <typename T>
            void PriorityQueueUnitTest::TestCreation(const PriorityQueueData<T>& data)
            {
                IPriorityQueueSharedPtr<T> priorityQueue = CreatePriorityQueue(data);

                GetAssertion().AssertEqualsWithIterators(
                    *priorityQueue->GetIterator(),
                    *base::VectorIterator<T>::Make(data.GetData()),
                    L"Invalid creation logic of a priority queue.");
            }

            /**
             * Tests the creation logic of a priority queue.
             */
            template <typename T>
            void PriorityQueueUnitTest::TestPeekAndPoll(const PriorityQueueData<T>& data)
            {
                IPriorityQueueSharedPtr<T> priorityQueue = CreatePriorityQueue(data);

                GetAssertion().AssertEqualsWithIterators(
                    *priorityQueue->GetIterator(),
                    *base::VectorIterator<T>::Make(data.GetData()),
                    L"Invalid creation logic of a priority queue.");

                size_t currSize = priorityQueue->Size();

                while (!priorityQueue->Empty()) {
                    const T& valueToRemove = priorityQueue->Peek();
                    T removedValue = priorityQueue->Poll();
                    --currSize;

                    GetAssertion().AssertEquals(
                        removedValue,
                        valueToRemove,
                        L"Incorrect peak and poll logic of a priority queue: invalid removed value.");

                    GetAssertion().AssertEquals(
                        priorityQueue->Size(),
                        currSize,
                        L"Incorrect peak and poll logic of a priority queue: invalid Size.");
                }
            }

            /**
             * Creates a priority queue.
             */
            template <typename T>
            IPriorityQueueSharedPtr<T> PriorityQueueUnitTest::CreatePriorityQueue(const PriorityQueueData<T>& data)
            {
                IPriorityQueueSharedPtr<T> priorityQueue = PriorityQueue<T>::Make(data.GetElementComparator());

                for (const T& item : data.GetCreationData())
                {
                    priorityQueue->Offer(item);
                }

                return priorityQueue;
            }
        }
    }
}

#endif // PRIORITY_QUEUE_UNIT_TEST_H_c28a9a65_1a69_4329_a83f_52d19b2bebc0
