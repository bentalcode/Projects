#include "PreCompiled.h"

#include "ObjectPoolUnitTest.h"
#include "ObjectPool.h"
#include "UnitTestFunction.h"

using namespace memory_management;

class TestPoolFunction : public unit_testing::UnitTestFunction<ObjectPoolUnitTest> {
public:
    TestPoolFunction(
        const std::string &name,
        ObjectPoolUnitTest &unitTest) :
        UnitTestFunction(name, unitTest) {
    }

    virtual ~TestPoolFunction() {
    }

    virtual void operator()() {
        getUnitTest().testObjectPool();
    }
};

/**
 * The ObjectPoolUnitTest constructor.
 */
ObjectPoolUnitTest::ObjectPoolUnitTest(const std::string& name) :
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
void ObjectPoolUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(
        new TestPoolFunction("TestObjectPool", *this)));
}

/**
 * Runs the logic the test.
 */
void ObjectPoolUnitTest::testObjectPool()
{
    int numberOfElements = 100;
    processObjectPool(numberOfElements);
}

void ObjectPoolUnitTest::processObjectPool(int numberOfElements) {
    std::vector<int*> elements;
    elements.reserve(numberOfElements);

    ObjectPool<int> objectPool1(numberOfElements);

    std::ostream& stream = getLogStreamWriter().getInformationalStream();
    stream << "Acquiring " << numberOfElements << " objects from the Object Pool:";

    for (int i = 0; i < numberOfElements; ++i) {
        int *elementPtr = objectPool1.acquireElement();
        *elementPtr = i;

        elements.push_back(elementPtr);
        stream << objectPool1;
    }

    stream << "Object Pool Information:" << std::endl
           << objectPool1 << std::endl;

    stream << "Pool Allocation Information:" << std::endl;
    objectPool1.getPoolAllocationInformation(stream);

    stream << "Releasing " << numberOfElements << " objects from the Object Pool:" << std::endl;

    for (std::vector<int *>::const_iterator i = elements.begin(); i != elements.end(); ++i) {
        objectPool1.releaseElement(*i);
        stream << objectPool1;
    }

    stream << std::endl;
    stream << "Object Pool Information:" << std::endl;
    stream << objectPool1 << std::endl;

    stream << "Pool Allocation Information:" << std::endl;
    objectPool1.getPoolAllocationInformation(stream);
    stream << std::endl;
}


