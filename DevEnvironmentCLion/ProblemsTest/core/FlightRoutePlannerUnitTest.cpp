#include "PreCompiled.h"

#include "FlightRoutePlannerUnitTest.h"
#include "UnitTestFunction.h"
#include "FlightRoutePlanner.h"

using namespace problems_test;
using namespace std;

class TestFindShortestRouteFunction : public unit_testing::UnitTestFunction<FlightRoutePlannerUnitTest>
{
public:
    TestFindShortestRouteFunction(FlightRoutePlannerUnitTest& unitTest) :
        UnitTestFunction("findShortestRouteFunction", unitTest)
    {
    }

    virtual ~TestFindShortestRouteFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().findShortestRouteTest();
    }
};

/**
 * The FlightRoutePlannerUnitTest constructor.
 */
FlightRoutePlannerUnitTest::FlightRoutePlannerUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The FlightRoutePlannerUnitTest destructor.
 */
FlightRoutePlannerUnitTest::~FlightRoutePlannerUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void FlightRoutePlannerUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionSharedPtr(new TestFindShortestRouteFunction(*this)));
}

/**
 * Tests the logic of finding the shortest flight route.
 */
void FlightRoutePlannerUnitTest::findShortestRouteTest()
{
    std::string source1 = "SEA";
    std::string destination1 = "DEN";
    unsigned int numberOfStops1 = 0;
    bool expectedStatus1 = true;
    double expectedShortestDistance1 = 1024;
    std::list<std::string> expectedShortestRoute1 = {"SEA", "DEN"};

    testFindShortestRoute(
        source1,
        destination1,
        numberOfStops1,
        expectedStatus1,
        expectedShortestDistance1,
        expectedShortestRoute1);

    std::string source2 = "SEA";
    std::string destination2 = "LAS";
    unsigned int numberOfStops2 = 0;
    bool expectedStatus2 = true;
    double expectedShortestDistance2 = 866;
    std::list<std::string> expectedShortestRoute2 = {"SEA", "LAS"};

    testFindShortestRoute(
        source2,
        destination2,
        numberOfStops2,
        expectedStatus2,
        expectedShortestDistance2,
        expectedShortestRoute2);

    std::string source3 = "SEA";
    std::string destination3 = "ORD";
    unsigned int numberOfStops3 = 1;
    bool expectedStatus3 = true;
    double expectedShortestDistance3 = 1912;
    std::list<std::string> expectedShortestRoute3 = {"SEA", "DEN", "ORD"};

    testFindShortestRoute(
        source3,
        destination3,
        numberOfStops3,
        expectedStatus3,
        expectedShortestDistance3,
        expectedShortestRoute3);

    std::string source4 = "SEA";
    std::string destination4 = "DFW";
    unsigned int numberOfStops4 = 2;
    bool expectedStatus4 = true;
    double expectedShortestDistance4 = 2189;
    std::list<std::string> expectedShortestRoute4 = {"SEA", "LAX", "DFW"};

    testFindShortestRoute(
        source4,
        destination4,
        numberOfStops4,
        expectedStatus4,
        expectedShortestDistance4,
        expectedShortestRoute4);

    std::string source5 = "SEA";
    std::string destination5 = "DFW1";
    unsigned int numberOfStops5 = 2;
    bool expectedStatus5 = false;
    double expectedShortestDistance5 = 0.0;
    std::list<std::string> expectedShortestRoute5 = {};

    testFindShortestRoute(
        source5,
        destination5,
        numberOfStops5,
        expectedStatus5,
        expectedShortestDistance5,
        expectedShortestRoute5);
}

/**
 * Tests the logic of finding the shortest flight route.
 */
void FlightRoutePlannerUnitTest::testFindShortestRoute(
    const std::string& source,
    const std::string& destination,
    unsigned int numberOfStops,
    bool expectedStatus,
    double expectedShortestDistance,
    const std::list<std::string>& expectedShortestRoute)
{
    std::vector<std::tuple<std::string, std::string, double>> flightsInfo = m_testData.getFlightsInformation();

    std::list<std::string> shortestRoute;
    double shortestDistance = 0.0;

    problems::FlightRoutePlanner flightRoutePlanner;
    bool status = flightRoutePlanner.calculateShortestPath(
        source,
        destination,
        numberOfStops,
        flightsInfo,
        shortestRoute,
        shortestDistance);

    getAssertion().assertTrue(
        status == expectedStatus &&
        std::equal(shortestRoute.begin(), shortestRoute.end(), expectedShortestRoute.begin()) &&
        shortestDistance == expectedShortestDistance,
        "The logic of finding the shortest result is incorrect.");
}
