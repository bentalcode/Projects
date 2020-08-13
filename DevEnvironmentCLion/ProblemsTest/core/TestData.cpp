#include "PreCompiled.h"

#include "TestData.h"

using namespace problems_test;

/**
 * The TestData constructor.
 */
TestData::TestData()
{
}

/**
 * The TestData destructor.
 */
TestData::~TestData()
{
}

/**
 * Gets flights information.
 */
std::vector<std::tuple<std::string, std::string, double>> TestData::getFlightsInformation() const
{
    std::vector<std::tuple<std::string, std::string, double>> flightsInformation =
    {
        std::make_tuple("SEA", "DEN", 1024),
        std::make_tuple("SEA", "LAS", 866),
        std::make_tuple("SEA", "LAX", 954),
        std::make_tuple("DEN", "ORD", 888),
        std::make_tuple("LAS", "ORD", 1514),
        std::make_tuple("ORD", "DFW", 802),
        std::make_tuple("LAX", "DFW", 1235),
        std::make_tuple("JFK", "MIA", 1090),
        std::make_tuple("MIA", "BIS", 1831),
        std::make_tuple("SEA", "ANC", 1448),
        std::make_tuple("ANC", "ORD", 2846),
        std::make_tuple("JFK", "BIS", 1407),
        std::make_tuple("DFW", "SMF", 1431),
        std::make_tuple("JFK", "AUS", 1521),
        std::make_tuple("DFW", "IAH", 140),
        std::make_tuple("IAH", "ANC", 3266)
    };

    return flightsInformation;
}
