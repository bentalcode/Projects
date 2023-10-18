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
std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> CacheTestData::GetLruUpdationData() const
{
    std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> data;

    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(1, L"a"), {KeyValueNode<int, std::wstring>::Make(1, L"a")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(3, L"c"), {KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(3, L"c")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(3, L"c"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(1, L"a"), {KeyValueNode<int, std::wstring>::Make(3, L"c"), KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(1, L"a")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(1, L"a"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(1, L"a")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"delete", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"delete", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"delete", KeyValueNode<int, std::wstring>::Make(5, L"e"), {}));

    return data;
}

/**
 * Gets the updation data of a most recently used cache.
 */
std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> CacheTestData::GetMruUpdationData() const
{
    std::vector<std::tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>> data;

    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(1, L"a"), {KeyValueNode<int, std::wstring>::Make(1, L"a")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(3, L"c"), {KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(3, L"c")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(1, L"a"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(1, L"a")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(1, L"a"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(1, L"a"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(1, L"a")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"set", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(2, L"b")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(4, L"c"), {KeyValueNode<int, std::wstring>::Make(5, L"e"), KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"Get", KeyValueNode<int, std::wstring>::Make(5, L"e"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(4, L"d"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"delete", KeyValueNode<int, std::wstring>::Make(4, L"d"), {KeyValueNode<int, std::wstring>::Make(2, L"b"), KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"delete", KeyValueNode<int, std::wstring>::Make(2, L"b"), {KeyValueNode<int, std::wstring>::Make(5, L"e")}));
    data.push_back(std::make_tuple<std::wstring, IKeyValueNodeSharedPtr<int, std::wstring>, std::vector<IKeyValueNodeSharedPtr<int, std::wstring>>>(L"delete", KeyValueNode<int, std::wstring>::Make(5, L"e"), {}));

    return data;
}
