#ifndef BIT_ARRAY_UNIT_TEST_H_ec32d323_aff2_4ab9_890f_a44f076c7431
#define BIT_ARRAY_UNIT_TEST_H_ec32d323_aff2_4ab9_890f_a44f076c7431

#include "UnitTestBase.h"
#include "BitArray.h"
#include "TestData.h"

using namespace datastructures::bitarray;

namespace test {
    namespace datastructures {
        namespace bitarray {

            class BitArrayData;

            /**
             * The BitArrayUnitTest class implements tests for a bit array.
             */
            class BitArrayUnitTest final : public unit_testing::UnitTestBase
            {
            public:
                /**
                 * The BitArrayUnitTest constructor.
                 */
                explicit BitArrayUnitTest(const std::wstring& name);

                /**
                 * The BitArrayUnitTest destructor.
                 */
                virtual ~BitArrayUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a bit array.
                 */
                void BitArrayCreationTest();

                /**
                 * Tests the turn on/off logic of a bit array.
                 */
                void BitArrayTurnOnOffTest();

                /**
                 * Tests the iteration logic of a bit array.
                 */
                void BitArrayIterationTest();

                /**
                 * Tests the cardinality logic of a bit array.
                 */
                void BitArrayCardinalityTest();

                /**
                 * Tests the clearing logic of a bit array.
                 */
                void BitArrayClearingTest();

                /**
                 * Tests the enabling logic of a bit array.
                 */
                void BitArrayEnablingTest();

            private:
                /**
                 * Tests the creation logic of a bit array.
                 */
                void TestCreation(const BitArrayData& data);

                /**
                 * Tests the turn on and off logic of a bit array.
                 */
                void TestTurnOnOff(const BitArrayData& data);

                /**
                 * Tests the iteration logic of a bit array.
                 */
                void TestIteration(const BitArrayData& data);

                /**
                 * Tests the clearing logic of a bit array.
                 */
                void TestClearing(const BitArrayData& data);

                /**
                 * Tests the enabling logic of a bit array.
                 */
                void TestEnabling(const BitArrayData& data);

                /**
                 * Tests the cardinality logic of a bit array.
                 */
                void TestCardinality(const BitArrayData& data);

                /**
                 * Creates a bit array.
                 */
                IBitArraySharedPtr CreateBitArray(const BitArrayData& data);

                TestData m_testData;
            };
        }
    }
}

#endif // BIT_ARRAY_UNIT_TEST_H_ec32d323_aff2_4ab9_890f_a44f076c7431
