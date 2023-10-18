#include "DoublyLinkedListTestData.h"
#include "DoublyLinkedListData.h"

using namespace test::datastructures;
using namespace test::datastructures::doublylinkedlist;

/**
 * The DoublyLinkedListTestData constructor.
 */
DoublyLinkedListTestData::DoublyLinkedListTestData()
{
}

/**
 * The DoublyLinkedListTestData destructor.
 */
DoublyLinkedListTestData::~DoublyLinkedListTestData()
{
}

/**
 * Gets the data of doubly linked lists.
 */
std::vector<DoublyLinkedListDataSharedPtr<int>> DoublyLinkedListTestData::GetData() const
{
    std::vector<DoublyLinkedListDataSharedPtr<int>> data;

    data.push_back(GetListData(0));
    data.push_back(GetListData(50));
    data.push_back(GetListData(100));

    return data;
}

/**
 * Gets the updation data of a doubly linked list.
 */
std::vector<std::tuple<std::wstring, int, std::vector<int>>> DoublyLinkedListTestData::GetUpdationData() const
{
    std::vector<std::tuple<std::wstring, int, std::vector<int>>> data;

    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToFront", 1, {1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToFront", 2, {2, 1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToFront", 3, {3, 2, 1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveFromFront", -1, {2, 1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveFromFront", -1, {1}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 2, {1, 2}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 3, {1, 2, 3}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 4, {1, 2, 3, 4}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"AddToBack", 5, {1, 2, 3, 4, 5}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveFromBack", -1, {1, 2, 3, 4}));
    data.push_back(std::make_tuple<std::wstring, int, std::vector<int>>(L"RemoveFromBack", -1, {1, 2, 3}));

    return data;
}

/**
 * Gets the data of a list.
 */
DoublyLinkedListDataSharedPtr<int> DoublyLinkedListTestData::GetListData(size_t size) const
{
    std::vector<int> values = CreateListValues(size);
    std::vector<IDoublyLinkedListNodeSharedPtr<int>> nodes = CreateListNodes(values);

    DoublyLinkedListDataSharedPtr<int> data(new DoublyLinkedListData<int>(
        values,
        nodes));

    return data;
}

/**
 * Creates values of a doubly linked list.
 */
std::vector<int> DoublyLinkedListTestData::CreateListValues(size_t size) const
{
    std::vector<int> result(size);

    for (size_t i = 0; i < size; ++i)
    {
        int value = i + 1;
        result[i] = value;
    }

    return result;
}

/**
 * Creates nodes of a doubly linked list.
 */
template <typename T>
std::vector<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedListTestData::CreateListNodes(const std::vector<T>& values) const
{
    std::vector<IDoublyLinkedListNodeSharedPtr<T>> result(values.size());

    for (size_t i = 0; i < values.size(); ++i)
    {
        T value = values[i];
        result[i] = DoublyLinkedListNode<T>::Make(value);
    }

    return result;
}
