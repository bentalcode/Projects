#ifndef FLIGHT_ROUTE_PLANNER_H_c11fd734_ca75_4ab0_b230_de87fb0023e3
#define FLIGHT_ROUTE_PLANNER_H_c11fd734_ca75_4ab0_b230_de87fb0023e3

#include "IFlightRoutePlanner.h"

namespace problems
{
    /**
     * The FlightRoutePlanner class implements a flight route planner.
     */
    class FlightRoutePlanner final : public IFlightRoutePlanner
    {
    public:
        /**
         * The constructor.
         */
        FlightRoutePlanner();

        /**
         * The destructor.
         */
        virtual ~FlightRoutePlanner();

        /**
         * The copy/move constructors.
         */
        FlightRoutePlanner(const FlightRoutePlanner&) = delete;
        FlightRoutePlanner(FlightRoutePlanner&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        FlightRoutePlanner& operator=(const FlightRoutePlanner&) = delete;
        FlightRoutePlanner& operator=(FlightRoutePlanner&&) = delete;

        /**
         * Calculates the shortest path.
         * Returns whether finding a route, and the shortest route information.
         */
        virtual bool calculateShortestPath(
            const std::string& source,
            const std::string& destination,
            unsigned int numberOfStops,
            const std::vector<std::tuple<std::string, std::string, double>>& flights,
            std::list<std::string>& shortestRoute,
            double& shortestDistance);

    private:
        using FlightInfo = std::tuple<std::string, std::string, double>;
        using FlightsInfo = std::vector<FlightInfo>;
        using DestinationInfo = std::pair<std::string, double>;
        using DestinationsInfo = std::set<DestinationInfo>;
        using FlightsMap = std::map<std::string, std::set<std::pair<std::string, double>>>;

        /**
         * Calculates the shortest path.
         * Returns whether finding a possible route.
         */
        static bool calculateShortestPath(
            const FlightsMap& flightsMap,
            const std::string& source,
            const std::string& destination,
            unsigned int numberOfStops,
            int currStopIndex,
            std::list<std::string>& currRoute,
            double currDistance,
            std::list<std::string>& shortestRoute,
            double& shortestDistance);

        /**
         * Creates the flights map.
         */
        static void createFlightsMap(
            const FlightsInfo& flightsInfo,
            FlightsMap& flightsMap);

        /**
         * Processes the flights map.
         */
        static void processFlightInfo(
            const FlightInfo& flightInfo,
            FlightsMap& flightsMap);
    };
}

#endif // FLIGHT_ROUTE_PLANNER_H_c11fd734_ca75_4ab0_b230_de87fb0023e3
