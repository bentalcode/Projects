#ifndef CONCURRENT_QUEUE_UNIT_TEST_H_a84422c0_b639_4610_9ba6_8c38b75639ea
#define CONCURRENT_QUEUE_UNIT_TEST_H_a84422c0_b639_4610_9ba6_8c38b75639ea

#include "UnitTestBase.h"
#include "TestData.h"
#include "ConcurrentQueue.h"

using namespace concurrency;

namespace test {
    namespace concurrency {

        /**
         * The ConcurrentQueueUnitTest class implements a unit test
         * for a concurrent queue.
         */
        class ConcurrentQueueUnitTest final : public unit_testing::UnitTestBase
        {
        public:
            /**
             * The ConcurrentQueueUnitTest constructor.
             */
            explicit ConcurrentQueueUnitTest(const std::wstring& name);

            /**
             * The ConcurrentQueueUnitTest destructor.
             */
            virtual ~ConcurrentQueueUnitTest();

            /**
             * Registers tests of the unit test.
             */
            virtual void RegisterTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the concurrent queue.
             */
            void ConcurrentQueueTest();

        private:
            /**
             * Tests the logic of a concurrent queue.
             */
            template <typename T>
            void TestConcurrentQueue(const std::vector<T>& data);

            TestData m_testData;
        };

        template <typename T>
        void ConcurrentQueueUnitTest::TestConcurrentQueue(const std::vector<T>& data)
        {
            ConcurrentQueue<T> concurrentQueue;

            for (const T& item : data)
            {
                concurrentQueue.Push(item);
            }

            while (!concurrentQueue.Empty())
            {
                concurrentQueue.Pop();
            }

            GetAssertion().AssertTrue(
                concurrentQueue.Empty(),
                L"Incorrect logic of a concurrent queue.");
        }
    }
}

#endif // CONCURRENT_QUEUE_UNIT_TEST_H_a84422c0_b639_4610_9ba6_8c38b75639ea
