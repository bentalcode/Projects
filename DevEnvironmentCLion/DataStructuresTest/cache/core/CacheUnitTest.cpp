#include "PreCompiled.h"

#include "CacheUnitTest.h"
#include "UnitTestFunction.h"
#include "LRUCache.h"
#include "MRUCache.h"
#include "CacheProperties.h"

using namespace test::datastructures;
using namespace test::datastructures::cache;

class TestLruCacheUpdationTestFunction final : public unit_testing::UnitTestFunction<CacheUnitTest>
{
public:
    TestLruCacheUpdationTestFunction(CacheUnitTest& unitTest) :
        UnitTestFunction("lruCacheUpdationTest", unitTest)
    {
    }

    virtual ~TestLruCacheUpdationTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().lruCacheUpdationTest();
    }
};

class TestMruCacheUpdationTestFunction final : public unit_testing::UnitTestFunction<CacheUnitTest>
{
public:
    TestMruCacheUpdationTestFunction(CacheUnitTest& unitTest) :
        UnitTestFunction("mruCacheUpdationTest", unitTest)
    {
    }

    virtual ~TestMruCacheUpdationTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().mruCacheUpdationTest();
    }
};

class TestLruCacheIterationTestFunction final : public unit_testing::UnitTestFunction<CacheUnitTest>
{
public:
    TestLruCacheIterationTestFunction(CacheUnitTest& unitTest) :
        UnitTestFunction("lruCacheIterationTest", unitTest)
    {
    }

    virtual ~TestLruCacheIterationTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().lruCacheIterationTest();
    }
};

class TestMruCacheIterationTestFunction final : public unit_testing::UnitTestFunction<CacheUnitTest>
{
public:
    TestMruCacheIterationTestFunction(CacheUnitTest& unitTest) :
        UnitTestFunction("mruCacheIterationTest", unitTest)
    {
    }

    virtual ~TestMruCacheIterationTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().mruCacheIterationTest();
    }
};

/**
 * The CacheUnitTest constructor.
 */
CacheUnitTest::CacheUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The CacheUnitTest destructor.
 */
CacheUnitTest::~CacheUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void CacheUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestLruCacheUpdationTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestMruCacheUpdationTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestLruCacheIterationTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestMruCacheIterationTestFunction(*this)));
}

/**
 * Tests the updation logic of a least recently used cache.
 */
void CacheUnitTest::lruCacheUpdationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::make(3, 1);
    LRUCache<int, std::string> cache(properties);

    std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> data =
        m_testData.getCacheData()->getLruUpdationData();

    for (const std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>& cacheData : data)
    {
        testUpdation(cache, cacheData);
    }
}

/**
 * Tests the updation logic of a most recently used cache.
 */
void CacheUnitTest::mruCacheUpdationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::make(3, 1);
    MRUCache<int, std::string> cache(properties);

    std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> data =
        m_testData.getCacheData()->getMruUpdationData();

    for (const std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>& cacheData : data)
    {
        testUpdation(cache, cacheData);
    }
}

/**
 * Tests the iteration logic of a least recently used cache.
 */
void CacheUnitTest::lruCacheIterationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::make(3, 1);
    ICacheSharedPtr<int, std::string> cache = LRUCache<int, std::string>::make(properties);

    std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> data =
        m_testData.getCacheData()->getLruUpdationData();

    for (const std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>& cacheData : data)
    {
        testIteration(cache, cacheData);
    }
}

/**
 * Tests the iteration logic of a most recently used cache.
 */
void CacheUnitTest::mruCacheIterationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::make(3, 1);
    ICacheSharedPtr<int, std::string> cache = MRUCache<int, std::string>::make(properties);

    std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> data =
        m_testData.getCacheData()->getMruUpdationData();

    for (const std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>& cacheData : data)
    {
        testIteration(cache, cacheData);
    }
}
