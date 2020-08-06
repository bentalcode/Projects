#include "PreCompiled.h"

#include "BinaryTreeUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures;
using namespace test::datastructures::binarytree;

class TestBinaryTreeCreationFunction : public unit_testing::UnitTestFunction<BinaryTreeUnitTest> {
public:
    TestBinaryTreeCreationFunction(BinaryTreeUnitTest &unitTest) :
        UnitTestFunction("binaryTreeCreationTest", unitTest) {
    }

    virtual ~TestBinaryTreeCreationFunction() {
    }

    virtual void operator()() {
        getUnitTest().binaryTreeCreationTest();
    }
};

/**
 * The BinaryTreeUnitTest constructor.
 */
BinaryTreeUnitTest::BinaryTreeUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The BinaryTreeUnitTest destructor.
 */
BinaryTreeUnitTest::~BinaryTreeUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void BinaryTreeUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBinaryTreeCreationFunction(*this)));
}

/**
 * Tests the creation logic of a binary tree.
 */
void BinaryTreeUnitTest::binaryTreeCreationTest()
{
    std::vector<BinaryTreeDataPtr<int, std::string>> data = m_testData.getBinaryTreeData()->getData();

    for (BinaryTreeDataPtr<int, std::string> treeData : data) {
        testCreation(*treeData);
    }
}
