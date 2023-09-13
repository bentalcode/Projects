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
                    const std::tuple<std::string, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data);

                /**
                 * Tests the updation logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void testUpdation(
                    ICache<TKey, TValue>& cache,
                    const std::string& operation,
                    const IKeyValueNode<TKey, TValue>& item,
                    const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent);

                /**
                 * Tests the iteration logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void testIteration(
                    ICacheSharedPtr<TKey, TValue> cache,
                    const std::tuple<std::string, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data);

                /**
                 * Tests the iteration logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void testIteration(
                    ICacheSharedPtr<TKey, TValue> cache,
                    const std::string& operation,
                    const IKeyValueNode<TKey, TValue>& item,
                    const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent);

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
                const std::tuple<std::string, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data)
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
                ICacheSharedPtr<TKey, TValue> cache,
                const std::tuple<std::string, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data)
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
                const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent)
            {
                updateCache(cache, operation, item);

                base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> nodeIterator = cache.getIterator();
                base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> expectedIterator = base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::make(expectedContent);

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
                ICacheSharedPtr<TKey, TValue> cache,
                const std::string& operation,
                const IKeyValueNode<TKey, TValue>& item,
                const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent)
            {
                //
                // Update the cache with the data...
                //
                updateCache(*cache, operation, item);

                //
                // Test the forward iteration over nodes...
                //
                base::IIterableSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> containerIterable = cache;
                base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> expectedIterator =
                    base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::make(expectedContent);

                test_base::IterationTest iterationTest;
                iterationTest.testForwardIterationWithDereference(
                    containerIterable,
                    expectedIterator,
                    "LRUCache");

                //
                // Test the reverse iteration over nodes...
                //
                base::IReverseIterableSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> containerReverseIterable = cache;
                base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> expectedReverseIterator =
                    base::VectorReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::make(expectedContent);

                iterationTest.testReverseIterationWithDereference(
                    containerReverseIterable,
                    expectedReverseIterator,
                    "LRUCache");

                //
                // Test the forward iteration over keys...
                //
                base::IKeyIterableSharedPtr<TKey> containerKeyIterable = cache;
                base::IIteratorSharedPtr<TKey> expectedKeyIterator = node::KeyIterator<TKey, TValue>::make(
                    base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::make(expectedContent));

                iterationTest.testKeyIteration(
                    containerKeyIterable,
                    expectedKeyIterator,
                    "LRUCache");

                //
                // Test the reverse iteration over keys...
                //
                base::IKeyReverseIterableSharedPtr<TKey> containerKeyReverseIterable = cache;
                base::IReverseIteratorSharedPtr<TKey> expectedKeyReverseIterator = node::KeyReverseIterator<TKey, TValue>::make(
                    base::VectorReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::make(expectedContent));

                iterationTest.testKeyReverseIteration(
                    containerKeyReverseIterable,
                    expectedKeyReverseIterator,
                    "LRUCache");

                //
                // Test the forward iteration over values...
                //
                base::IValueIterableSharedPtr<TValue> containerValueIterable = cache;
                base::IIteratorSharedPtr<TValue> expectedValueIterator = node::ValueIterator<TKey, TValue>::make(
                    base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::make(expectedContent));

                iterationTest.testValueIteration(
                    containerValueIterable,
                    expectedValueIterator,
                    "LRUCache");

                //
                // Test the reverse iteration over values...
                //
                base::IValueReverseIterableSharedPtr<TValue> containerValueReverseIterable = cache;
                base::IReverseIteratorSharedPtr<TValue> expectedValueReverseIterator = node::ValueReverseIterator<TKey, TValue>::make(
                        base::VectorReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::make(expectedContent));

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
