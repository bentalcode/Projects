#include "PreCompiled.h"

#include "FlightRoutePlanner.h"

using namespace problems;

/**
 * The FlightRoutePlanner constructor.
 */
FlightRoutePlanner::FlightRoutePlanner()
{
}

/**
 * The FlightRoutePlanner destructor.
 */
FlightRoutePlanner::~FlightRoutePlanner()
{
}

/**
 * Calculates the shortest path.
 * Returns whether finding a route, and the shortest route information.
 */
bool FlightRoutePlanner::calculateShortestPath(
    const std::string& source,
    const std::string& destination,
    unsigned int numberOfStops,
    const std::vector<std::tuple<std::string, std::string, double>>& flightsInfo,
    std::list<std::string>& shortestRoute,
    double& shortestDistance)
{
    shortestRoute.clear();
    shortestDistance = std::numeric_limits<int>::max();

    FlightsMap flightsMap;
    createFlightsMap(flightsInfo, flightsMap);

    int currStopIndex = -1;

    std::list<std::string> currRoute;
    currRoute.push_back(source);
    double currDistance = 0.0;

    bool status = calculateShortestPath(
        flightsMap,
        source,
        destination,
        numberOfStops,
        currStopIndex,
        currRoute,
        currDistance,
        shortestRoute,
        shortestDistance);

    if (!status)
    {
        assert(shortestRoute.empty());
        shortestDistance = 0.0;
    }

    return status;
}

/**
 * Calculates the shortest path.
 * Returns whether finding a possible route.
 */
bool FlightRoutePlanner::calculateShortestPath(
    const FlightsMap& flightsMap,
    const std::string& source,
    const std::string& destination,
    unsigned int numberOfStops,
    int currStopIndex,
    std::list<std::string>& currRoute,
    double currDistance,
    std::list<std::string>& shortestRoute,
    double& shortestDistance)
{
    if (currStopIndex != -1 && currStopIndex > numberOfStops)
    {
        return false;
    }

    if (source == destination)
    {
        if (currDistance < shortestDistance)
        {
            shortestRoute = currRoute;
            shortestDistance = currDistance;
        }

        return true;
    }

    FlightsMap::const_iterator destinationsInfoIterator = flightsMap.find(source);

    if (destinationsInfoIterator == flightsMap.end())
    {
        return false;
    }

    bool status = false;

    DestinationsInfo destinationsInfo = destinationsInfoIterator->second;
    for (const DestinationInfo& destinationInfo : destinationsInfo)
    {
        const std::string& currDestination = destinationInfo.first;
        double currDestinationDistance = destinationInfo.second;

        if (std::find(currRoute.begin(), currRoute.end(), destination) == currRoute.end())
        {
            currRoute.push_back(currDestination);

            if (calculateShortestPath(
                    flightsMap,
                    currDestination,
                    destination,
                    numberOfStops,
                    currStopIndex + 1,
                    currRoute,
                    currDistance + currDestinationDistance,
                    shortestRoute,
                    shortestDistance))
            {
                status = true;
            }

            currRoute.pop_back();
        }
    }

    return status;
}

/**
 * Creates the flights map.
 */
void FlightRoutePlanner::createFlightsMap(
    const FlightsInfo& flightsInfo,
    FlightsMap& flightsMap)
{
    for (const FlightInfo& flightInfo : flightsInfo)
    {
        processFlightInfo(flightInfo, flightsMap);
    }
}

/**
 * Processes the flights map.
 */
void FlightRoutePlanner::processFlightInfo(
    const FlightInfo& flightInfo,
    FlightsMap& flightsMap)
{
    const std::string& source = std::get<0>(flightInfo);
    const std::string& destination = std::get<1>(flightInfo);
    double distance = std::get<2>(flightInfo);

    FlightsMap::iterator destinationsInfoIterator = flightsMap.find(source);

    if (destinationsInfoIterator == flightsMap.end())
    {
        DestinationsInfo destinationsInfo;
        flightsMap.insert(std::make_pair(source, destinationsInfo));
        destinationsInfoIterator = flightsMap.find(source);
    }

    assert(destinationsInfoIterator != flightsMap.end());
    DestinationsInfo& destinationsInfo = destinationsInfoIterator->second;

    DestinationInfo destinationInfo(std::make_pair(destination, distance));
    destinationsInfo.insert(destinationInfo);
}


