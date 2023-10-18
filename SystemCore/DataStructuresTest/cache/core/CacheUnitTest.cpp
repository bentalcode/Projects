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
        UnitTestFunction(L"LruCacheUpdationTest", unitTest)
    {
    }

    virtual ~TestLruCacheUpdationTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().LruCacheUpdationTest();
    }
};

class TestMruCacheUpdationTestFunction final : public unit_testing::UnitTestFunction<CacheUnitTest>
{
public:
    TestMruCacheUpdationTestFunction(CacheUnitTest& unitTest) :
        UnitTestFunction(L"MruCacheUpdationTest", unitTest)
    {
    }

    virtual ~TestMruCacheUpdationTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().MruCacheUpdationTest();
    }
};

class TestLruCacheIterationTestFunction final : public unit_testing::UnitTestFunction<CacheUnitTest>
{
public:
    TestLruCacheIterationTestFunction(CacheUnitTest& unitTest) :
        UnitTestFunction(L"LruCacheIterationTest", unitTest)
    {
    }

    virtual ~TestLruCacheIterationTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().LruCacheIterationTest();
    }
};

class TestMruCacheIterationTestFunction final : public unit_testing::UnitTestFunction<CacheUnitTest>
{
public:
    TestMruCacheIterationTestFunction(CacheUnitTest& unitTest) :
        UnitTestFunction(L"MruCacheIterationTest", unitTest)
    {
    }

    virtual ~TestMruCacheIterationTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().MruCacheIterationTest();
    }
};

/**
 * The CacheUnitTest constructor.
 */
CacheUnitTest::CacheUnitTest(const std::wstring& name) :
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
void CacheUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestLruCacheUpdationTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestMruCacheUpdationTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestLruCacheIterationTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestMruCacheIterationTestFunction(*this)));
}

/**
 * Tests the updation logic of a least recently used cache.
 */
void CacheUnitTest::LruCacheUpdationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::Make(3, 1);
    LRUCache<int, std::wstring> cache(properties);

    std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> data =
            m_testData.GetCacheData()->GetLruUpdationData();

    for (const std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>& cacheData : data)
    {
        TestUpdation(cache, cacheData);
    }
}

/**
 * Tests the updation logic of a most recently used cache.
 */
void CacheUnitTest::MruCacheUpdationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::Make(3, 1);
    MRUCache<int, std::wstring> cache(properties);

    std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> data =
            m_testData.GetCacheData()->GetMruUpdationData();

    for (const std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>& cacheData : data)
    {
        TestUpdation(cache, cacheData);
    }
}

/**
 * Tests the iteration logic of a least recently used cache.
 */
void CacheUnitTest::LruCacheIterationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::Make(3, 1);
    ICacheSharedPtr<int, std::wstring> cache = LRUCache<int, std::wstring>::Make(properties);

    std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> data =
            m_testData.GetCacheData()->GetLruUpdationData();

    for (const std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>& cacheData : data)
    {
        TestIteration(cache, cacheData);
    }
}

/**
 * Tests the iteration logic of a most recently used cache.
 */
void CacheUnitTest::MruCacheIterationTest()
{
    ICachePropertiesSharedPtr properties = CacheProperties::Make(3, 1);
    ICacheSharedPtr<int, std::wstring> cache = MRUCache<int, std::wstring>::Make(properties);

    std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> data =
            m_testData.GetCacheData()->GetMruUpdationData();

    for (const std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>& cacheData : data)
    {
        TestIteration(cache, cacheData);
    }
}
