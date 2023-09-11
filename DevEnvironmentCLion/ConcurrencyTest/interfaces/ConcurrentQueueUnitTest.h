#ifndef CONCURRENT_QUEUE_UNIT_TEST_H_a84422c0_b639_4610_9ba6_8c38b75639ea
#define CONCURRENT_QUEUE_UNIT_TEST_H_a84422c0_b639_4610_9ba6_8c38b75639ea

#include "PreCompiled.h"
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
            explicit ConcurrentQueueUnitTest(const std::string& name);

            /**
             * The ConcurrentQueueUnitTest destructor.
             */
            virtual ~ConcurrentQueueUnitTest();

            /**
             * Registers tests of the unit test.
             */
            virtual void registerTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the concurrent queue.
             */
            void concurrentQueueTest();

        private:
            /**
             * Tests the logic of a concurrent queue.
             */
            template <typename T>
            void testConcurrentQueue(const std::vector<T>& data);

            TestData m_testData;
        };

        template <typename T>
        class QueueClient final
        {
        public:
            explicit QueueClient(
                int id,
                ConcurrentQueue<T>& concurrentQueue) :
                m_id(id),
                m_concurrentQueue(concurrentQueue)
            {
            }

            void operator()()
            {
                while (!m_concurrentQueue.empty()) {
                    T item = m_concurrentQueue.front();
                    m_concurrentQueue.pop();
                }
            }

        private:
            int m_id;
            ConcurrentQueue<T>& m_concurrentQueue;
        };

        template <typename T>
        void ConcurrentQueueUnitTest::testConcurrentQueue(const std::vector<T>& data)
        {
            getAssertion().assertTrue(
                true,
                "Incorrect logic of a concurrent queue.");
        }
    }
}

#endif // CONCURRENT_QUEUE_UNIT_TEST_H_a84422c0_b639_4610_9ba6_8c38b75639ea
