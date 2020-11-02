#ifndef CACHE_UNIT_TEST_H_ebe6facb_b744_48a6_9e40_659e23af8624
#define CACHE_UNIT_TEST_H_ebe6facb_b744_48a6_9e40_659e23af8624

#include "UnitTestBase.h"
#include "TestData.h"
#include "IterationTest.h"
#include "VectorIterator.h"
#include "VectorReverseIterator.h"
#include "KeyIterator.h"
#include "KeyReverseIterator.h"
#include "ValueIterator.h"
#include "ValueReverseIterator.h"

using namespace datastructures;

namespace test {
    namespace datastructures {
        namespace cache {

            /**
             * The CacheUnitTest class implements the data of the tests of a cache.
             */
            class CacheUnitTest final : public unit_testing::UnitTestBase
            {
            public:
                /**
                 * The CacheUnitTest constructor.
                 */
                explicit CacheUnitTest(const std::string& name);

                /**
                 * The CacheUnitTest destructor.
                 */
                virtual ~CacheUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the updation logic of a least recently used cache.
                 */
                void lruCacheUpdationTest();

                /**
                 * Tests the updation logic of a most recently used cache.
                 */
                void mruCacheUpdationTest();

                /**
                 * Tests the iteration logic of a least recently used cache.
                 */
                void lruCacheIterationTest();

                /**
                 * Tests the iteration logic of a most recently used cache.
                 */
                void mruCacheIterationTest();

            private:
                /**
                 * Tests the updation logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void testUpdation(
                    ICache<TKey, TValue>& cache,
                    const std::tuple<std::string, IKeyValueNodePtr<TKey, TValue>, std::vector<IKeyValueNodePtr<TKey, TValue>>>& data);

                /**
                 * Tests the updation logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void testUpdation(
                    ICache<TKey, TValue>& cache,
                    const std::string& operation,
                    const IKeyValueNode<TKey, TValue>& item,
                    const std::vector<IKeyValueNodePtr<TKey, TValue>>& expectedContent);

                /**
                 * Tests the iteration logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void testIteration(
                    ICachePtr<TKey, TValue> cache,
                    const std::tuple<std::string, IKeyValueNodePtr<TKey, TValue>, std::vector<IKeyValueNodePtr<TKey, TValue>>>& data);

                /**
                 * Tests the iteration logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void testIteration(
                    ICachePtr<TKey, TValue> cache,
                    const std::string& operation,
                    const IKeyValueNode<TKey, TValue>& item,
                    const std::vector<IKeyValueNodePtr<TKey, TValue>>& expectedContent);

                /**
                 * Updates the cache.
                 */
                template <typename TKey, typename TValue>
                static void updateCache(
                    ICache<TKey, TValue>& cache,
                    const std::string& operation,
                    const IKeyValueNode<TKey, TValue>& item);

                TestData m_testData;
            };

            /**
             * Tests the updation logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::testUpdation(
                ICache<TKey, TValue>& cache,
                const std::tuple<std::string, IKeyValueNodePtr<TKey, TValue>, std::vector<IKeyValueNodePtr<TKey, TValue>>>& data)
            {
                testUpdation<TKey, TValue>(
                    cache,
                    std::get<0>(data),
                    *std::get<1>(data),
                    std::get<2>(data));
            }

            /**
             * Tests the iteration logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::testIteration(
                ICachePtr<TKey, TValue> cache,
                const std::tuple<std::string, IKeyValueNodePtr<TKey, TValue>, std::vector<IKeyValueNodePtr<TKey, TValue>>>& data)
            {
                testIteration<TKey, TValue>(
                    cache,
                    std::get<0>(data),
                    *std::get<1>(data),
                    std::get<2>(data));
            }

            /**
             * Tests the updation logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::testUpdation(
                ICache<TKey, TValue>& cache,
                const std::string& operation,
                const IKeyValueNode<TKey, TValue>& item,
                const std::vector<IKeyValueNodePtr<TKey, TValue>>& expectedContent)
            {
                updateCache(cache, operation, item);

                base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> nodeIterator = cache.getIterator();
                base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> expectedIterator = base::VectorIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent);

                getAssertion().assertEqualsWithDereferenceIterators(
                    *nodeIterator,
                    *expectedIterator,
                    "Invalid updation logic of a cache.");
            }

            /**
             * Tests the iteration logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::testIteration(
                ICachePtr<TKey, TValue> cache,
                const std::string& operation,
                const IKeyValueNode<TKey, TValue>& item,
                const std::vector<IKeyValueNodePtr<TKey, TValue>>& expectedContent)
            {
                //
                // Update the cache with the data...
                //
                updateCache(*cache, operation, item);

                //
                // Test the forward iteration over nodes...
                //
                base::IIterablePtr<IKeyValueNodePtr<TKey, TValue>> containerIterable = cache;
                base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> expectedIterator =
                    base::VectorIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent);

                test_base::IterationTest iterationTest;
                iterationTest.testForwardIterationWithDereference(
                    containerIterable,
                    expectedIterator,
                    "LRUCache");

                //
                // Test the reverse iteration over nodes...
                //
                base::IReverseIterablePtr<IKeyValueNodePtr<TKey, TValue>> containerReverseIterable = cache;
                base::IReverseIteratorPtr<IKeyValueNodePtr<TKey, TValue>> expectedReverseIterator =
                    base::VectorReverseIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent);

                iterationTest.testReverseIterationWithDereference(
                    containerReverseIterable,
                    expectedReverseIterator,
                    "LRUCache");

                //
                // Test the forward iteration over keys...
                //
                base::IKeyIterablePtr<TKey> containerKeyIterable = cache;
                base::IIteratorPtr<TKey> expectedKeyIterator = node::KeyIterator<TKey, TValue>::make(
                    base::VectorIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent));

                iterationTest.testKeyIteration(
                    containerKeyIterable,
                    expectedKeyIterator,
                    "LRUCache");

                //
                // Test the reverse iteration over keys...
                //
                base::IKeyReverseIterablePtr<TKey> containerKeyReverseIterable = cache;
                base::IReverseIteratorPtr<TKey> expectedKeyReverseIterator = node::KeyReverseIterator<TKey, TValue>::make(
                    base::VectorReverseIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent));

                iterationTest.testKeyReverseIteration(
                    containerKeyReverseIterable,
                    expectedKeyReverseIterator,
                    "LRUCache");

                //
                // Test the forward iteration over values...
                //
                base::IValueIterablePtr<TValue> containerValueIterable = cache;
                base::IIteratorPtr<TValue> expectedValueIterator = node::ValueIterator<TKey, TValue>::make(
                    base::VectorIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent));

                iterationTest.testValueIteration(
                    containerValueIterable,
                    expectedValueIterator,
                    "LRUCache");

                //
                // Test the reverse iteration over values...
                //
                base::IValueReverseIterablePtr<TValue> containerValueReverseIterable = cache;
                base::IReverseIteratorPtr<TValue> expectedValueReverseIterator = node::ValueReverseIterator<TKey, TValue>::make(
                        base::VectorReverseIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent));

                iterationTest.testValueReverseIteration(
                    containerValueReverseIterable,
                    expectedValueReverseIterator,
                    "LRUCache");
            }

            /**
             * Updates the cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::updateCache(
                ICache<TKey, TValue>& cache,
                const std::string& operation,
                const IKeyValueNode<TKey, TValue>& item)
            {
                if (operation == "set")
                {
                    cache.set(item.getKey(), item.getValue());
                }
                else if (operation == "get")
                {
                    cache.get(item.getKey());
                }
                else if (operation == "delete")
                {
                    cache.deleteKey(item.getKey());
                }
            }

        }
    }
}

#endif // CACHE_UNIT_TEST_H_ebe6facb_b744_48a6_9e40_659e23af8624
