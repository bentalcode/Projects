#include "PreCompiled.h"

#include "JsonStreamingUnitTest.h"
#include "UnitTestFunction.h"
#include "TestData.h"
#include "ResourceReader.h"

using namespace test::json;

class TestJsonStreamingFunction : public unit_testing::UnitTestFunction<JsonStreamingUnitTest>
{
public:
    TestJsonStreamingFunction(JsonStreamingUnitTest &unitTest) :
        UnitTestFunction("jsonStreamingTest", unitTest)
    {
    }

    virtual ~TestJsonStreamingFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().jsonStreamingTest();
    }
};

/**
 * The JsonStreamingUnitTest constructor.
 */
JsonStreamingUnitTest::JsonStreamingUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The JsonStreamingUnitTest destructor.
 */
JsonStreamingUnitTest::~JsonStreamingUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void JsonStreamingUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestJsonStreamingFunction(*this)));
}

/**
 * Tests the logic of streaming json.
 */
void JsonStreamingUnitTest::jsonStreamingTest()
{
    std::vector<std::pair<std::string, base::ClassType>> resourcesInformation;
    m_testData.getJsonResourcesInformation(resourcesInformation);

    for (const std::pair<std::string, base::ClassType>& resourceInformation : resourcesInformation)
    {
        std::string json = base::ResourceReader::loadString(resourceInformation.first);
        const base::ClassType& classType = resourceInformation.second;

        // m_streamingTest.testStreaming(json, Casting.cast(resourceInformation.second()));
    }
}
