#ifndef TWO_DIMENSIONAL_VECTOR_UNIT_TEST_H_0424810f_54ae_409b_9b0b_95796c33f6b5
#define TWO_DIMENSIONAL_VECTOR_UNIT_TEST_H_0424810f_54ae_409b_9b0b_95796c33f6b5

#include "UnitTestBase.h"
#include "TwoDimensionalVector.h"
#include "TestData.h"

namespace base {

    /**
     * The TwoDimensionalVectorUnitTest class implements a unit test for a two dimensional vector.
     */
    class TwoDimensionalVectorUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The constructor.
         */
        explicit TwoDimensionalVectorUnitTest(const std::string& name);

        /**
         * The destructor.
         */
        virtual ~TwoDimensionalVectorUnitTest();

        /**
         * The copy/move constructors.
         */
        TwoDimensionalVectorUnitTest(const TwoDimensionalVectorUnitTest&) = delete;
        TwoDimensionalVectorUnitTest(TwoDimensionalVectorUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        TwoDimensionalVectorUnitTest& operator=(const TwoDimensionalVectorUnitTest&) = delete;
        TwoDimensionalVectorUnitTest& operator=(TwoDimensionalVectorUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the creation logic of a two dimensional vector.
         */
        void twoDimensionalVectorCreationTest();

        /**
         * Tests the iteration logic of a two dimensional vector.
         */
        void twoDimensionalVectorIterationTest();

    private:
        /**
         * Tests the creation logic of a two dimensional vector.
         */
        void testTwoDimensionalVectorCreation(const std::vector<std::vector<int>>& data);

        /**
         * Tests the iteration logic of a two dimensional vector.
         */
        void testTwoDimensionalVectorIteration(const std::vector<std::vector<int>>& data);

        TestData m_testData;
    };
}

#endif // TWO_DIMENSIONAL_VECTOR_UNIT_TEST_H_0424810f_54ae_409b_9b0b_95796c33f6b5
