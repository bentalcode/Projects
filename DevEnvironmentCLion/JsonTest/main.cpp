#include "UnitTestManager.h"
#include "JsonStreamingUnitTest.h"

using namespace test::json;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;

    IUnitTestPtr jsonStreamingUnitTest(new JsonStreamingUnitTest("JsonStreaming"));
    testManager.registerTest(jsonStreamingUnitTest);

    testManager.run();

    return 0;
}
