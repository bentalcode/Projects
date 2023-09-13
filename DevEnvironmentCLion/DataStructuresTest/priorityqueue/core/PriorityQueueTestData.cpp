#include "PreCompiled.h"

#include "Comparator.h"
#include "PriorityQueueTestData.h"

using namespace test::datastructures::priority_queue;

/**
 * The PriorityQueueTestData constructor.
 */
PriorityQueueTestData::PriorityQueueTestData()
{
}

/**
 * The PriorityQueueTestData destructor.
 */
PriorityQueueTestData::~PriorityQueueTestData()
{
}

/**
 * Gets data of the tests of a priority queue.
 */
std::vector<PriorityQueueDataSharedPtr<int>> PriorityQueueTestData::getData() const
{
    std::vector<PriorityQueueDataSharedPtr<int>> data;

    //data.push_back(getPriorityQueueData1());
    //data.push_back(getPriorityQueueData2());
    //data.push_back(getPriorityQueueData3());
    data.push_back(getPriorityQueueData4());
    //data.push_back(getPriorityQueueData5());

    return data;
}

/**
 * Gets the data of priority queue1.
 */
PriorityQueueDataSharedPtr<int> PriorityQueueTestData::getPriorityQueueData1()
{
    std::vector<int> data;

    return PriorityQueueDataSharedPtr<int>(new PriorityQueueData<int>(
        base::Comparator<int>::make(),
        data, 
        data));
}

/**
 * Gets the data of priority queue2.
 */
PriorityQueueDataSharedPtr<int> PriorityQueueTestData::getPriorityQueueData2()
{
    std::vector<int> creationData = {14, 10, 5, 9, 6, 3, 2, 1};
    std::vector<int> expectedData = {1, 2, 3, 6, 9, 10, 5, 14};

    return PriorityQueueDataSharedPtr<int>(new PriorityQueueData<int>(
        base::Comparator<int>::make(),
        creationData,
        expectedData));
}

/**
 * Gets the data of priority queue3.
 */
PriorityQueueDataSharedPtr<int> PriorityQueueTestData::getPriorityQueueData3()
{
    std::vector<int> creationData = {14, 6, 5, 9, 1, 3, 2, 10};
    std::vector<int> expectedData = {1, 5, 2, 10, 9, 6, 3, 14};

    return PriorityQueueDataSharedPtr<int>(new PriorityQueueData<int>(
        base::Comparator<int>::make(),
        creationData,
        expectedData));
}

/**
 * Gets the data of priority queue4.
 */
PriorityQueueDataSharedPtr<int> PriorityQueueTestData::getPriorityQueueData4()
{
    std::vector<int> creationData = {2, 20, 5, 20, 19, 15, 50, 30};
    std::vector<int> expectedData = {50, 30, 20, 20, 19, 5, 15, 2};

    return PriorityQueueDataSharedPtr<int>(new PriorityQueueData<int>(
        base::Comparator<int>::makeInvert(),
        creationData,
        expectedData));
}

/**
 * Gets the data of priority queue5.
 */
PriorityQueueDataSharedPtr<int> PriorityQueueTestData::getPriorityQueueData5()
{
    std::vector<int> creationData = {-7, 6, 0, 9, 1, 3, 4, -3, 5, -1};
    std::vector<int> expectedData = {9, 6, 4, 5, 1, 0, 3, -7, -3, -1};

    return PriorityQueueDataSharedPtr<int>(new PriorityQueueData<int>(
        base::Comparator<int>::makeInvert(),
        creationData,
        expectedData));
}
