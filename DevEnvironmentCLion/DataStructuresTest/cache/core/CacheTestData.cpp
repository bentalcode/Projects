#include "PreCompiled.h"

#include "CacheTestData.h"
#include "KeyValueNode.h"

using namespace test::datastructures::cache;


/**
 * The CacheTestData constructor.
 */
CacheTestData::CacheTestData()
{
}

/**
 * The CacheTestData destructor.
 */
CacheTestData::~CacheTestData()
{
}

/**
 * Gets the updation data of a least recently used cache.
 */
std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> CacheTestData::getLruUpdationData() const
{
    std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> data;

    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(1, "a"), {KeyValueNode<int, std::string>::make(1, "a")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(3, "c"), {KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(3, "c")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(3, "c"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(1, "a"), {KeyValueNode<int, std::string>::make(3, "c"), KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(1, "a")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(1, "a"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(1, "a")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("delete", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("delete", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("delete", KeyValueNode<int, std::string>::make(5, "e"), {}));

    return data;
}

/**
 * Gets the updation data of a most recently used cache.
 */
std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> CacheTestData::getMruUpdationData() const
{
    std::vector<std::tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>> data;

    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(1, "a"), {KeyValueNode<int, std::string>::make(1, "a")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(3, "c"), {KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(3, "c")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(1, "a"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(1, "a")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(1, "a"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(1, "a"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(1, "a")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("set", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(2, "b")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(4, "c"), {KeyValueNode<int, std::string>::make(5, "e"), KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("get", KeyValueNode<int, std::string>::make(5, "e"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(4, "d"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("delete", KeyValueNode<int, std::string>::make(4, "d"), {KeyValueNode<int, std::string>::make(2, "b"), KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("delete", KeyValueNode<int, std::string>::make(2, "b"), {KeyValueNode<int, std::string>::make(5, "e")}));
    data.push_back(std::make_tuple<std::string, IKeyValueNodeSharedPtr<int, std::string>, std::vector<IKeyValueNodeSharedPtr<int, std::string>>>("delete", KeyValueNode<int, std::string>::make(5, "e"), {}));

    return data;
}
