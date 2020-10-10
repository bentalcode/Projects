#ifndef CACHE_TEST_DATA_H_44000e0a_120c_4837_b67e_7bfd769b3aae
#define CACHE_TEST_DATA_H_44000e0a_120c_4837_b67e_7bfd769b3aae

#include <vector>
#include <string>
#include "ICache.h"
#include "IKeyValueNode.h"

using namespace datastructures::cache;
using namespace datastructures::node;

namespace test {
    namespace datastructures {
        namespace cache {

            /**
             * The CacheTestData class implements the data of the tests of a cache.
             */
            class CacheTestData final
            {
            public:
                /**
                 * The CacheTestData constructor.
                 */
                CacheTestData();

                /**
                 * The CacheTestData destructor.
                 */
                ~CacheTestData();

                /**
                 * The copy/move constructors.
                 */
                CacheTestData(const CacheTestData&) = delete;
                CacheTestData(CacheTestData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                CacheTestData& operator=(const CacheTestData&) = delete;
                CacheTestData& operator=(CacheTestData&&) = delete;

                /**
                 * Gets the updation data of a least recently used cache.
                 */
                std::vector<std::tuple<std::string, IKeyValueNodePtr<int, std::string>, std::vector<IKeyValueNodePtr<int, std::string>>>> getLruUpdationData() const;

                /**
                 * Gets the updation data of a most recently used cache.
                 */
                std::vector<std::tuple<std::string, IKeyValueNodePtr<int, std::string>, std::vector<IKeyValueNodePtr<int, std::string>>>> getMruUpdationData() const;
            };

            using CacheTestDataPtr = std::shared_ptr<CacheTestData>;
        }
    }
}

#endif // CACHE_TEST_DATA_H_44000e0a_120c_4837_b67e_7bfd769b3aae
