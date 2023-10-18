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
std::vector<BitArrayDataSharedPtr> BitArrayTestData::GetData() const
{
    std::vector<BitArrayDataSharedPtr> data;

    data.push_back(CreateBitArrayData(5));
    data.push_back(CreateBitArrayData(32));
    data.push_back(CreateBitArrayData(50));

    return data;
}

/**
 * Creates data of a bit array.
 */
BitArrayDataSharedPtr BitArrayTestData::CreateBitArrayData(size_t size) const
{
    std::vector<bool> data = CreateBitArray(size);
    return BitArrayDataSharedPtr(new BitArrayData(data));
}

/**
 * Creates a bit array.
 */
std::vector<bool> BitArrayTestData::CreateBitArray(size_t size) const
{
    std::vector<bool> data(size);

    for (int i = 0; i < size; ++i)
    {
        bool currBit = (i % 2) == 0;
        data.push_back(currBit);
    }

    return data;
}
