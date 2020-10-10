#include "PreCompiled.h"

#include "LRUCacheUnitTest.h"
#include "UnitTestFunction.h"
#include "LRUCache.h"
#include "CacheProperties.h"

using namespace test::datastructures;
using namespace test::datastructures::cache;

class TestLRUCacheUpdationTestFunction final : public unit_testing::UnitTestFunction<LRUCacheUnitTest>
{
public:
    TestLRUCacheUpdationTestFunction(LRUCacheUnitTest& unitTest) :
        UnitTestFunction("lruCacheUpdationTest", unitTest)
    {
    }

    virtual ~TestLRUCacheUpdationTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().lruCacheUpdationTest();
    }
};

/**
 * The LRUCacheUnitTest constructor.
 */
LRUCacheUnitTest::LRUCacheUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The LRUCacheUnitTest destructor.
 */
LRUCacheUnitTest::~LRUCacheUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void LRUCacheUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestLRUCacheUpdationTestFunction(*this)));
}

/**
 * Tests the updation logic of a least recently used cache.
 */
void LRUCacheUnitTest::lruCacheUpdationTest()
{
    ICachePropertiesPtr properties = CacheProperties::make(3, 1);
    LRUCache<int, std::string> cache(properties);

    std::vector<std::tuple<std::string, IKeyValueNodePtr<int, std::string>, std::vector<IKeyValueNodePtr<int, std::string>>>> data =
        m_testData.getCacheData()->getLruUpdationData();

    for (const std::tuple<std::string, IKeyValueNodePtr<int, std::string>, std::vector<IKeyValueNodePtr<int, std::string>>>& cacheData : data)
    {
        testUpdation(cache, cacheData);
    }
}
