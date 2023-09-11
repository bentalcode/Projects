#ifndef BIT_ARRAY_TEST_DATA_H_ea6d4d3a_efa7_4922_9e23_6c887179f4af
#define BIT_ARRAY_TEST_DATA_H_ea6d4d3a_efa7_4922_9e23_6c887179f4af

#include "BitArrayData.h"

namespace test {
    namespace datastructures {
        namespace bitarray {

            /**
             * The BitArrayTestData class implements the data of the tests of a bit array.
             */
            class BitArrayTestData final
            {
            public:
                /**
                 * The BitArrayTestData constructor.
                 */
                BitArrayTestData();

                /**
                 * The BitArrayTestData destructor.
                 */
                ~BitArrayTestData();

                /**
                 * The copy/move constructors.
                 */
                BitArrayTestData(const BitArrayTestData&) = delete;
                BitArrayTestData(BitArrayTestData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                BitArrayTestData& operator=(const BitArrayTestData&) = delete;
                BitArrayTestData& operator=(BitArrayTestData&&) = delete;

                /**
                 * Gets data of the tests of a bit array.
                 */
                std::vector<BitArrayDataPtr> getData() const;

            private:
                /**
                 * Creates data of a bit array.
                 */
                BitArrayDataPtr createBitArrayData(size_t size) const;

                /**
                 * Creates a bit array.
                 */
                std::vector<bool> createBitArray(size_t size) const;
            };

            using BitArrayTestDataPtr = std::shared_ptr<BitArrayTestData>;
        }
    }
}

#endif // BIT_ARRAY_TEST_DATA_H_ea6d4d3a_efa7_4922_9e23_6c887179f4af
