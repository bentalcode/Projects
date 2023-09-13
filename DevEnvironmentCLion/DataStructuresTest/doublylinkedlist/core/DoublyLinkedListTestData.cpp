#include "PreCompiled.h"

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
std::vector<DoublyLinkedListDataSharedPtr<int>> DoublyLinkedListTestData::getData() const
{
    std::vector<DoublyLinkedListDataSharedPtr<int>> data;

    data.push_back(getListData(0));
    data.push_back(getListData(50));
    data.push_back(getListData(100));

    return data;
}

/**
 * Gets the updation data of a doubly linked list.
 */
std::vector<std::tuple<std::string, int, std::vector<int>>> DoublyLinkedListTestData::getUpdationData() const
{
    std::vector<std::tuple<std::string, int, std::vector<int>>> data;

    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToFront", 1, {1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToFront", 2, {2, 1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToFront", 3, {3, 2, 1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeFromFront", -1, {2, 1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeFromFront", -1, {1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 2, {1, 2}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 3, {1, 2, 3}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 4, {1, 2, 3, 4}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 5, {1, 2, 3, 4, 5}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeFromBack", -1, {1, 2, 3, 4}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeFromBack", -1, {1, 2, 3}));

    return data;
}

/**
 * Gets the data of a list.
 */
DoublyLinkedListDataSharedPtr<int> DoublyLinkedListTestData::getListData(size_t size) const
{
    std::vector<int> values = createListValues(size);
    std::vector<IDoublyLinkedListNodeSharedPtr<int>> nodes = createListNodes(values);

    DoublyLinkedListDataSharedPtr<int> data(new DoublyLinkedListData<int>(
        values,
        nodes));

    return data;
}

/**
 * Creates values of a doubly linked list.
 */
std::vector<int> DoublyLinkedListTestData::createListValues(size_t size) const
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
std::vector<IDoublyLinkedListNodeSharedPtr<T>> DoublyLinkedListTestData::createListNodes(const std::vector<T>& values) const
{
    std::vector<IDoublyLinkedListNodeSharedPtr<T>> result(values.size());

    for (size_t i = 0; i < values.size(); ++i)
    {
        T value = values[i];
        result[i] = DoublyLinkedListNode<T>::make(value);
    }

    return result;
}
