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
std::vector<DoublyLinkedListDataPtr<int>> DoublyLinkedListTestData::getData() const
{
    std::vector<DoublyLinkedListDataPtr<int>> data;

    data.push_back(getListData1());
    data.push_back(getListData2());
    data.push_back(getListData3());

    return data;
}

/**
 * Gets the updation data of a doubly linked list.
 */
std::vector<std::tuple<std::string, int, std::vector<int>>> DoublyLinkedListTestData::getUpdationData()
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
 * Gets the data of list1.
 */
DoublyLinkedListDataPtr<int> DoublyLinkedListTestData::getListData1() const
{
    std::vector<int> values = createListValues(0);
    std::vector<IDoublyLinkedListNodePtr<int>> nodes = createListNodes(values);

    DoublyLinkedListDataPtr<int> data(new DoublyLinkedListData<int>(
        values,
        nodes));

    return data;
}

/**
 * Gets the data of list2.
 */
DoublyLinkedListDataPtr<int> DoublyLinkedListTestData::getListData2() const
{
    std::vector<int> values = createListValues(50);
    std::vector<IDoublyLinkedListNodePtr<int>> nodes = createListNodes(values);

    DoublyLinkedListDataPtr<int> data(new DoublyLinkedListData<int>(
        values,
        nodes));

    return data;
}

/**
 * Gets the data of list2.
 */
DoublyLinkedListDataPtr<int> DoublyLinkedListTestData::getListData3() const
{
    std::vector<int> values = createListValues(100);
    std::vector<IDoublyLinkedListNodePtr<int>> nodes = createListNodes(values);

    DoublyLinkedListDataPtr<int> data(new DoublyLinkedListData<int>(
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

    for (size_t i = 0; i < size; ++i) {
        int value = i + 1;
        result[i] = value;
    }

    return result;
}

/**
 * Creates nodes of a doubly linked list.
 */
template <typename T>
std::vector<IDoublyLinkedListNodePtr<T>> DoublyLinkedListTestData::createListNodes(const std::vector<T>& values) const
{
    std::vector<IDoublyLinkedListNodePtr<T>> result(values.size());

    for (size_t i = 0; i < values.size(); ++i)
    {
        T value = values[i];
        result[i] = DoublyLinkedListNode<T>::make(value);
    }

    return result;
}
