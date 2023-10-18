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
                explicit CacheUnitTest(const std::wstring& name);

                /**
                 * The CacheUnitTest destructor.
                 */
                virtual ~CacheUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the updation logic of a least recently used cache.
                 */
                void LruCacheUpdationTest();

                /**
                 * Tests the updation logic of a most recently used cache.
                 */
                void MruCacheUpdationTest();

                /**
                 * Tests the iteration logic of a least recently used cache.
                 */
                void LruCacheIterationTest();

                /**
                 * Tests the iteration logic of a most recently used cache.
                 */
                void MruCacheIterationTest();

            private:
                /**
                 * Tests the updation logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void TestUpdation(
                    ICache<TKey, TValue>& cache,
                    const std::tuple<std::wstring, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data);

                /**
                 * Tests the updation logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void TestUpdation(
                    ICache<TKey, TValue>& cache,
                    const std::wstring& operation,
                    const IKeyValueNode<TKey, TValue>& item,
                    const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent);

                /**
                 * Tests the iteration logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void TestIteration(
                    ICacheSharedPtr<TKey, TValue> cache,
                    const std::tuple<std::wstring, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data);

                /**
                 * Tests the iteration logic of a cache.
                 */
                template <typename TKey, typename TValue>
                void TestIteration(
                    ICacheSharedPtr<TKey, TValue> cache,
                    const std::wstring& operation,
                    const IKeyValueNode<TKey, TValue>& item,
                    const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent);

                /**
                 * Updates the cache.
                 */
                template <typename TKey, typename TValue>
                static void UpdateCache(
                    ICache<TKey, TValue>& cache,
                    const std::wstring& operation,
                    const IKeyValueNode<TKey, TValue>& item);

                TestData m_testData;
            };

            /**
             * Tests the updation logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::TestUpdation(
                ICache<TKey, TValue>& cache,
                const std::tuple<std::wstring, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data)
            {
                TestUpdation<TKey, TValue>(
                    cache,
                    std::get<0>(data),
                    *std::get<1>(data),
                    std::get<2>(data));
            }

            /**
             * Tests the iteration logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::TestIteration(
                ICacheSharedPtr<TKey, TValue> cache,
                const std::tuple<std::wstring, IKeyValueNodeSharedPtr<TKey, TValue>, std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>>& data)
            {
                TestIteration<TKey, TValue>(
                    cache,
                    std::get<0>(data),
                    *std::get<1>(data),
                    std::get<2>(data));
            }

            /**
             * Tests the updation logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::TestUpdation(
                ICache<TKey, TValue>& cache,
                const std::wstring& operation,
                const IKeyValueNode<TKey, TValue>& item,
                const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent)
            {
                UpdateCache(cache, operation, item);

                base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> nodeIterator = cache.GetIterator();
                base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> expectedIterator = base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::Make(expectedContent);

                GetAssertion().AssertEqualsWithDereferenceIterators(
                    *nodeIterator,
                    *expectedIterator,
                    L"Invalid updation logic of a cache.");
            }

            /**
             * Tests the iteration logic of a cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::TestIteration(
                ICacheSharedPtr<TKey, TValue> cache,
                const std::wstring& operation,
                const IKeyValueNode<TKey, TValue>& item,
                const std::vector<IKeyValueNodeSharedPtr<TKey, TValue>>& expectedContent)
            {
                //
                // Update the cache with the data...
                //
                UpdateCache(*cache, operation, item);

                //
                // Test the forward iteration over nodes...
                //
                base::IIterableSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> containerIterable = cache;
                base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> expectedIterator =
                    base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::Make(expectedContent);

                test_base::IterationTest iterationTest;
                iterationTest.TestForwardIterationWithDereference(
                    containerIterable,
                    expectedIterator,
                    L"LRUCache");

                //
                // Test the reverse iteration over nodes...
                //
                base::IReverseIterableSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> containerReverseIterable = cache;
                base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> expectedReverseIterator =
                        base::VectorReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::Make(expectedContent);

                iterationTest.TestReverseIterationWithDereference(
                    containerReverseIterable,
                    expectedReverseIterator,
                    L"LRUCache");

                //
                // Test the forward iteration over keys...
                //
                base::IKeyIterableSharedPtr<TKey> containerKeyIterable = cache;
                base::IIteratorSharedPtr<TKey> expectedKeyIterator = node::KeyIterator<TKey, TValue>::Make(
                    base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::Make(expectedContent));

                iterationTest.TestKeyIteration(
                    containerKeyIterable,
                    expectedKeyIterator,
                    L"LRUCache");

                //
                // Test the reverse iteration over keys...
                //
                base::IKeyReverseIterableSharedPtr<TKey> containerKeyReverseIterable = cache;
                base::IReverseIteratorSharedPtr<TKey> expectedKeyReverseIterator = node::KeyReverseIterator<TKey, TValue>::Make(
                        base::VectorReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::Make(expectedContent));

                iterationTest.TestKeyReverseIteration(
                    containerKeyReverseIterable,
                    expectedKeyReverseIterator,
                    L"LRUCache");

                //
                // Test the forward iteration over values...
                //
                base::IValueIterableSharedPtr<TValue> containerValueIterable = cache;
                base::IIteratorSharedPtr<TValue> expectedValueIterator = node::ValueIterator<TKey, TValue>::Make(
                    base::VectorIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::Make(expectedContent));

                iterationTest.TestValueIteration(
                    containerValueIterable,
                    expectedValueIterator,
                    L"LRUCache");

                //
                // Test the reverse iteration over values...
                //
                base::IValueReverseIterableSharedPtr<TValue> containerValueReverseIterable = cache;
                base::IReverseIteratorSharedPtr<TValue> expectedValueReverseIterator = node::ValueReverseIterator<TKey, TValue>::Make(
                        base::VectorReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>::Make(expectedContent));

                iterationTest.TestValueReverseIteration(
                    containerValueReverseIterable,
                    expectedValueReverseIterator,
                    L"LRUCache");
            }

            /**
             * Updates the cache.
             */
            template <typename TKey, typename TValue>
            void CacheUnitTest::UpdateCache(
                ICache<TKey, TValue>& cache,
                const std::wstring& operation,
                const IKeyValueNode<TKey, TValue>& item)
            {
                if (operation == L"set")
                {
                    cache.Set(item.GetKey(), item.GetValue());
                }
                else if (operation == L"Get")
                {
                    cache.Get(item.GetKey());
                }
                else if (operation == L"delete")
                {
                    cache.DeleteKey(item.GetKey());
                }
            }

        }
    }
}

#endif // CACHE_UNIT_TEST_H_ebe6facb_b744_48a6_9e40_659e23af8624
