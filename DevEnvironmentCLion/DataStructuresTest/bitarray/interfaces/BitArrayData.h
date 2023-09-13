#ifndef BIT_ARRAY_DATA_H_7063fca5_a364_4130_b63a_2a44177f40f8
#define BIT_ARRAY_DATA_H_7063fca5_a364_4130_b63a_2a44177f40f8

namespace test {
    namespace datastructures {
        namespace bitarray {

            /**
             * The BitArrayData class implements the data of a bit array.
             */
            class BitArrayData final {
            public:
                /**
                 * The BitArrayData constructor.
                 */
                explicit BitArrayData(const std::vector<bool>& data);

                /**
                 * The BitArrayData destructor.
                 */
                ~BitArrayData();

                /**
                 * The copy/move constructors.
                 */
                BitArrayData(const BitArrayData&) = delete;
                BitArrayData(BitArrayData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                BitArrayData& operator=(const BitArrayData&) = delete;
                BitArrayData& operator=(BitArrayData&&) = delete;

                /**
                 * Gets the data of a bit array.
                 */
                inline const std::vector<bool>& getData() const;

            private:
                std::vector<bool> m_data;
            };

            //
            // Defines the SharedPtr of Bit Array...
            //
            using BitArrayDataSharedPtr = std::shared_ptr<BitArrayData>;

            /**
             * Gets the data of a bit array.
             */
            const std::vector<bool>& BitArrayData::getData() const
            {
                return m_data;
            }
        }
    }
}

#endif // BIT_ARRAY_DATA_H_7063fca5_a364_4130_b63a_2a44177f40f8
