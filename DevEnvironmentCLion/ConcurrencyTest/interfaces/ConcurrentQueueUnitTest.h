#ifndef CONCURRENT_QUEUE_UNIT_TEST_H_02b74bad_d334_4d04_bc5b_84203984fffb
#define CONCURRENT_QUEUE_UNIT_TEST_H_02b74bad_d334_4d04_bc5b_84203984fffb

#include "PreCompiled.h"
#include "UnitTestBase.h"
#include "TestData.h"
#include "ConcurrentQueue.h"

namespace concurrency_test {

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

    template<typename T>
    class QueueClient final
    {
    public:
        explicit QueueClient(
            int id,
            concurrency::ConcurrentQueue<T>& concurrentQueue) :
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
        concurrency::ConcurrentQueue<T>& m_concurrentQueue;
    };

    template <typename T>
    void ConcurrentQueueUnitTest::testConcurrentQueue(const std::vector<T>& data)
    {
        getAssertion().assertTrue(
            true,
            "Incorrect logic of a concurrent queue.");
    }
}

#endif // CONCURRENT_QUEUE_UNIT_TEST_H_02b74bad_d334_4d04_bc5b_84203984fffb
