#ifndef LRU_CACHE_UNIT_TEST_H_ebe6facb_b744_48a6_9e40_659e23af8624
#define LRU_CACHE_UNIT_TEST_H_ebe6facb_b744_48a6_9e40_659e23af8624

#include "UnitTestBase.h"
#include "TestData.h"
#include "VectorIterator.h"

namespace test {
    namespace datastructures {
        namespace cache {

            /**
             * The LRUCacheUnitTest class implements the data of the tests of a cache.
             */
            class LRUCacheUnitTest final : public unit_testing::UnitTestBase
            {
            public:
                /**
                 * The LRUCacheUnitTest constructor.
                 */
                explicit LRUCacheUnitTest(const std::string& name);

                /**
                 * The LRUCacheUnitTest destructor.
                 */
                virtual ~LRUCacheUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the updation logic of a least recently used cache.
                 */
                void lruCacheUpdationTest();

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
            void LRUCacheUnitTest::testUpdation(
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
             * Tests the updation logic of a cache.
             */
            template <typename TKey, typename TValue>
            void LRUCacheUnitTest::testUpdation(
                ICache<TKey, TValue>& cache,
                const std::string& operation,
                const IKeyValueNode<TKey, TValue>& item,
                const std::vector<IKeyValueNodePtr<TKey, TValue>>& expectedContent)
            {
                updateCache(cache, operation, item);

                getAssertion().assertEqualsWithDereferenceIterators(
                    *cache.getIterator(),
                    *base::VectorIterator<IKeyValueNodePtr<TKey, TValue>>::make(expectedContent),
                    "Invalid updation logic of a cache.");
            }

            /**
             * Updates the cache.
             */
            template <typename TKey, typename TValue>
            void LRUCacheUnitTest::updateCache(
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

#endif // LRU_CACHE_UNIT_TEST_H_ebe6facb_b744_48a6_9e40_659e23af8624
