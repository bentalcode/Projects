#include "PreCompiled.h"

#include "TestData.h"
#include "ClassType.h"
#include "ResourcePaths.h"
#include "ClassType.h"

using namespace test::json;

const std::string TestData::dataDirectoryName = "data";
const std::string TestData::jsonDirectoryName = "json";
std::vector<std::pair<std::string, base::ClassType>> TestData::jsonResourcesInformation =
{
    std::make_pair(
        "colors.json",
        ::base::ClassType("Colors")),
    std::make_pair(
        "fruit.json",
        ::base::ClassType("Fruit")),
    std::make_pair(
        "propertyType.json",
        ::base::ClassType("PropertyType"))
};

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
 * Gets information of json resources.
 */
void TestData::getJsonResourcesInformation(std::vector<std::pair<std::string, ::base::ClassType>>& result)
{
    for (const std::pair<std::string, ::base::ClassType>& resourceInformation : jsonResourcesInformation)
    {
        for (const std::pair<std::string, ::base::ClassType>& resourceInformation : jsonResourcesInformation)
        {
            std::string path = test::base::ResourcePaths::create(
                dataDirectoryName,
                jsonDirectoryName,
                resourceInformation.first);

            const ::base::ClassType& classType = resourceInformation.second;
            result.push_back(std::make_pair(path, classType));
        }
    }
}
