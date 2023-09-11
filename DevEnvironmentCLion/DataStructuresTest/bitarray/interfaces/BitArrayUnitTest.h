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
                explicit BitArrayUnitTest(const std::string& name);

                /**
                 * The BitArrayUnitTest destructor.
                 */
                virtual ~BitArrayUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a bit array.
                 */
                void bitArrayCreationTest();

                /**
                 * Tests the turn on/off logic of a bit array.
                 */
                void bitArrayTurnOnOffTest();

                /**
                 * Tests the iteration logic of a bit array.
                 */
                void bitArrayIterationTest();

                /**
                 * Tests the cardinality logic of a bit array.
                 */
                void bitArrayCardinalityTest();

                /**
                 * Tests the clearing logic of a bit array.
                 */
                void bitArrayClearingTest();

                /**
                 * Tests the enabling logic of a bit array.
                 */
                void bitArrayEnablingTest();

            private:
                /**
                 * Tests the creation logic of a bit array.
                 */
                void testCreation(const BitArrayData& data);

                /**
                 * Tests the turn on and off logic of a bit array.
                 */
                void testTurnOnOff(const BitArrayData& data);

                /**
                 * Tests the iteration logic of a bit array.
                 */
                void testIteration(const BitArrayData& data);

                /**
                 * Tests the clearing logic of a bit array.
                 */
                void testClearing(const BitArrayData& data);

                /**
                 * Tests the enabling logic of a bit array.
                 */
                void testEnabling(const BitArrayData& data);

                /**
                 * Tests the cardinality logic of a bit array.
                 */
                void testCardinality(const BitArrayData& data);

                /**
                 * Creates a bit array.
                 */
                IBitArrayPtr createBitArray(const BitArrayData& data);

                TestData m_testData;
            };
        }
    }
}

#endif // BIT_ARRAY_UNIT_TEST_H_ec32d323_aff2_4ab9_890f_a44f076c7431
