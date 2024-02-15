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
std::vector<std::tuple<std::wstring, std::wstring, double>> TestData::GetFlightsInformation() const
{
    std::vector<std::tuple<std::wstring, std::wstring, double>> flightsInformation;
    /*
    {
        std::make_tuple(L"SEA", L"DEN", 1024),
        std::make_tuple(L"SEA", L"LAS", 866),
        std::make_tuple(L"SEA", L"LAX", 954),
        std::make_tuple(L"DEN", L"ORD", 888),
        std::make_tuple(L"LAS", L"ORD", 1514),
        std::make_tuple(L"ORD", L"DFW", 802),
        std::make_tuple(L"LAX", L"DFW", 1235),
        std::make_tuple(L"JFK", L"MIA", 1090),
        std::make_tuple(L"MIA", L"BIS", 1831),
        std::make_tuple(L"SEA", L"ANC", 1448),
        std::make_tuple(L"ANC", L"ORD", 2846),
        std::make_tuple(L"JFK", L"BIS", 1407),
        std::make_tuple(L"DFW", L"SMF", 1431),
        std::make_tuple(L"JFK", L"AUS", 1521),
        std::make_tuple(L"DFW", L"IAH", 140),
        std::make_tuple(L"IAH", L"ANC", 3266)
    };
*/
    return flightsInformation;
}
