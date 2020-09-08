#include "PreCompiled.h"

#include "BitArrayTestData.h"

using namespace test::datastructures::bitarray;

/**
 * The BitArrayTestData constructor.
 */
BitArrayTestData::BitArrayTestData()
{
}

/**
 * The BitArrayTestData destructor.
 */
BitArrayTestData::~BitArrayTestData()
{
}

/**
 * Gets data of the tests of a bit array.
 */
std::vector<BitArrayDataPtr> BitArrayTestData::getData() const
{
    std::vector<BitArrayDataPtr> data;

    data.push_back(createBitArrayData(5));
    data.push_back(createBitArrayData(32));
    data.push_back(createBitArrayData(50));

    return data;
}

/**
 * Creates data of a bit array.
 */
BitArrayDataPtr BitArrayTestData::createBitArrayData(size_t size) const
{
    std::vector<bool> data = createBitArray(size);
    return BitArrayDataPtr(new BitArrayData(data));
}

/**
 * Creates a bit array.
 */
std::vector<bool> BitArrayTestData::createBitArray(size_t size) const
{
    std::vector<bool> data(size);

    for (int i = 0; i < size; ++i)
    {
        bool currBit = (i % 2) == 0;
        data.push_back(currBit);
    }

    return data;
}
