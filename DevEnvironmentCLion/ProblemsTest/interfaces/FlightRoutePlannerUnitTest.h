#ifndef FLIGHT_ROUTER_PLANNER_UNIT_TEST_H_d6286820_a2fc_4d94_bb1a_151d377c6302
#define FLIGHT_ROUTER_PLANNER_UNIT_TEST_H_d6286820_a2fc_4d94_bb1a_151d377c6302

#include "UnitTestBase.h"
#include "FlightRoutePlanner.h"
#include "TestData.h"
#include "Assertion.h"

namespace problems_test {

    /**
     * The FlightRoutePlannerUnitTest class implements a unit test for the flight router planner.
     */
    class FlightRoutePlannerUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The FlightRoutePlannerUnitTest constructor.
         */
        explicit FlightRoutePlannerUnitTest(const std::string& name);

        /**
         * The FlightRoutePlannerUnitTest destructor.
         */
        virtual ~FlightRoutePlannerUnitTest();

        /**
         * The copy/move constructors.
         */
        FlightRoutePlannerUnitTest(const FlightRoutePlannerUnitTest&) = delete;
        FlightRoutePlannerUnitTest(FlightRoutePlannerUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        FlightRoutePlannerUnitTest& operator=(const FlightRoutePlannerUnitTest&) = delete;
        FlightRoutePlannerUnitTest& operator=(FlightRoutePlannerUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of finding the shortest flight route.
         */
        void findShortestRouteTest();

    private:
        /**
         * Tests the logic of finding the shortest flight route.
         */
        void testFindShortestRoute(
            const std::string& source,
            const std::string& destination,
            unsigned int numberOfStops,
            bool expectedStatus,
            double expectedShortestDistance,
            const std::list<std::string>& expectedShortestRoute);

        TestData m_testData;
    };
}

#endif // FLIGHT_ROUTER_PLANNER_UNIT_TEST_H_d6286820_a2fc_4d94_bb1a_151d377c6302
