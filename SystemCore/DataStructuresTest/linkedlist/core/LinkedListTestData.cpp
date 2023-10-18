#include "LinkedListTestData.h"
#include "LinkedListData.h"
#include <tuple>
#include <string>

using namespace test::datastructures;
using namespace test::datastructures::linkedlist;

/**
 * The LinkedListTestData constructor.
 */
LinkedListTestData::LinkedListTestData()
{
}

/**
 * The LinkedListTestData destructor.
 */
LinkedListTestData::~LinkedListTestData()
{
}

/**
 * Gets the data of linked lists.
 */
std::vector<LinkedListDataSharedPtr<int>> LinkedListTestData::GetData() const
{
    std::vector<LinkedListDataSharedPtr<int>> data;

    data.push_back(GetListData(0));
    data.push_back(GetListData(50));
    data.push_back(GetListData(100));

    return data;
}

/**
 * Gets the updation data of a linked list.
 */
std::vector<std::tuple<std::wstring, int, std::vector<int>>> LinkedListTestData::GetUpdationData()
{
    std::vector<std::tuple<std::wstring, int, std::vector<int>>> data;

    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToFront", 1, {1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToFront", 2, {2, 1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToFront", 3, {3, 2, 1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveFromFront", 0, {2, 1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveFromFront", 0, {1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 2, {1, 2}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 3, {1, 2, 3}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 4, {1, 2, 3, 4}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 5, {1, 2, 3, 4, 5}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveAfter", 0, {1, 3, 4, 5}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveAfter", 0, {1, 4, 5}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveAfter", 0, {1, 5}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveAfter", 0, {1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveFromFront", 0, {}));

    return data;
}

/**
 * Gets the data of list.
 */
LinkedListDataSharedPtr<int> LinkedListTestData::GetListData(size_t size) const
{
    std::vector<int> values = CreateListValues(size);
    std::vector<ILinkedListNodeSharedPtr<int>> nodes = CreateListNodes(values);

    LinkedListDataSharedPtr<int> data(new LinkedListData<int>(
        values,
        nodes));

    return data;
}

/**
 * Creates values of a list.
 */
std::vector<int> LinkedListTestData::CreateListValues(size_t size) const
{
    std::vector<int> result(size);

    for (size_t i = 0; i < size; ++i) {
        int value = i + 1;
        result[i] = value;
    }

    return result;
}

/**
 * Creates nodes of a list.
 */
template <typename T>
std::vector<ILinkedListNodeSharedPtr<T>> LinkedListTestData::CreateListNodes(const std::vector<T>& values) const
{
    std::vector<ILinkedListNodeSharedPtr<T>> result(values.size());

    for (size_t i = 0; i < values.size(); ++i)
    {
        T value = values[i];
        result[i] = LinkedListNode<T>::Make(value);
    }

    return result;
}
