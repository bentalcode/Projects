#include "ObjectPoolUnitTest.h"
#include "ObjectPool.h"
#include "UnitTestFunction.h"
#include <vector>

using namespace memory_management;

class TestPoolFunction : public unit_testing::UnitTestFunction<ObjectPoolUnitTest> {
public:
    TestPoolFunction(ObjectPoolUnitTest& unitTest) :
        UnitTestFunction(L"ObjectPoolTest", unitTest) {
    }

    virtual ~TestPoolFunction() {
    }

    virtual void operator()() {
        GetUnitTest().objectPoolTest();
    }
};

/**
 * The ObjectPoolUnitTest constructor.
 */
ObjectPoolUnitTest::ObjectPoolUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The ObjectPoolUnitTest destructor.
 */
ObjectPoolUnitTest::~ObjectPoolUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void ObjectPoolUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestPoolFunction(*this)));
}

/**
 * Tests the object pool.
 */
void ObjectPoolUnitTest::objectPoolTest()
{
    int numberOfElements = 100;
    testObjectPool(numberOfElements);
}

/**
 * Tests the object pool.
 */
void ObjectPoolUnitTest::testObjectPool(int numberOfElements) {
    std::vector<int*> elements;
    elements.reserve(numberOfElements);

    ObjectPool<int> objectPool1(numberOfElements);

    std::wstringstream stream;
    stream << "Acquiring " << numberOfElements << " objects from the Object Pool:";

    for (int i = 0; i < numberOfElements; ++i)
    {
        int *elementPtr = objectPool1.AcquireElement();
        *elementPtr = i;

        elements.push_back(elementPtr);
        stream << objectPool1;
    }

    stream << L"Object Pool Information:" << std::endl
           << objectPool1 << std::endl;

    stream << L"Pool Allocation Information:" << std::endl;
    objectPool1.GetPoolAllocationInformation(stream);

    stream << L"Releasing " << numberOfElements << L" objects from the Object Pool:" << std::endl;

    for (std::vector<int *>::const_iterator i = elements.begin(); i != elements.end(); ++i)
    {
        objectPool1.ReleaseElement(*i);
        stream << objectPool1;
    }

    stream << std::endl;
    stream << L"Object Pool Information:" << std::endl;
    stream << objectPool1 << std::endl;

    stream << L"Pool Allocation Information:" << std::endl;
    objectPool1.GetPoolAllocationInformation(stream);
    stream << std::endl;

    base::IMessageWriter& writer1 = GetMessageWriter();

    writer1.WriteInformationalMessage(stream.str());
}


