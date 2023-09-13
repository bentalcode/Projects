#include "PreCompiled.h"

#include "LinkedListTestData.h"
#include "LinkedListData.h"

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
std::vector<LinkedListDataSharedPtr<int>> LinkedListTestData::getData() const
{
    std::vector<LinkedListDataSharedPtr<int>> data;

    data.push_back(getListData(0));
    data.push_back(getListData(50));
    data.push_back(getListData(100));

    return data;
}

/**
 * Gets the updation data of a linked list.
 */
std::vector<std::tuple<std::string, int, std::vector<int>>> LinkedListTestData::getUpdationData()
{
    std::vector<std::tuple<std::string, int, std::vector<int>>> data;

    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToFront", 1, {1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToFront", 2, {2, 1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToFront", 3, {3, 2, 1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeFromFront", 0, {2, 1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeFromFront", 0, {1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 2, {1, 2}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 3, {1, 2, 3}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 4, {1, 2, 3, 4}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("addToBack", 5, {1, 2, 3, 4, 5}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeAfter", 0, {1, 3, 4, 5}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeAfter", 0, {1, 4, 5}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeAfter", 0, {1, 5}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeAfter", 0, {1}));
    data.push_back(std::make_tuple<std::string, int, std::vector<int>>("removeFromFront", 0, {}));

    return data;
}

/**
 * Gets the data of list.
 */
LinkedListDataSharedPtr<int> LinkedListTestData::getListData(size_t size) const
{
    std::vector<int> values = createListValues(size);
    std::vector<ILinkedListNodeSharedPtr<int>> nodes = createListNodes(values);

    LinkedListDataSharedPtr<int> data(new LinkedListData<int>(
        values,
        nodes));

    return data;
}

/**
 * Creates values of a list.
 */
std::vector<int> LinkedListTestData::createListValues(size_t size) const
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
std::vector<ILinkedListNodeSharedPtr<T>> LinkedListTestData::createListNodes(const std::vector<T>& values) const
{
    std::vector<ILinkedListNodeSharedPtr<T>> result(values.size());

    for (size_t i = 0; i < values.size(); ++i)
    {
        T value = values[i];
        result[i] = LinkedListNode<T>::make(value);
    }

    return result;
}
