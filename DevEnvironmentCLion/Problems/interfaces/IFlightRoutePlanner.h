#ifndef I_FLIGHT_ROUTE_PLANNER_H_2c7a74ff_8eb6_4374_8042_07724ee4d79f
#define I_FLIGHT_ROUTE_PLANNER_H_2c7a74ff_8eb6_4374_8042_07724ee4d79f

namespace problems
{
    /**
     * The IFlightRoutePlanner interface defines a flight route planner.
     */
    class IFlightRoutePlanner
    {
    public:
        /**
         * The constructor.
         */
        IFlightRoutePlanner() = default;

        /**
         * The destructor.
         */
        virtual ~IFlightRoutePlanner() = default;

        /**
         * The copy/move constructors.
         */
        IFlightRoutePlanner(const IFlightRoutePlanner&) = delete;
        IFlightRoutePlanner(IFlightRoutePlanner&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IFlightRoutePlanner& operator=(const IFlightRoutePlanner&) = delete;
        IFlightRoutePlanner& operator=(IFlightRoutePlanner&&) = delete;

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
            double& shortestDistance) = 0;
    };
}

#endif // I_FLIGHT_ROUTE_PLANNER_H_2c7a74ff_8eb6_4374_8042_07724ee4d79f
