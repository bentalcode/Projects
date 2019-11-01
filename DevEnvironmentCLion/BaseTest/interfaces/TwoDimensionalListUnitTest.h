#ifndef TWO_DIMENSIONAL_LIST_UNIT_TEST_H_e15d9eec_6c6e_45a6_847f_dd8bed89328a
#define TWO_DIMENSIONAL_LIST_UNIT_TEST_H_e15d9eec_6c6e_45a6_847f_dd8bed89328a

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace base {

    /**
     * The TwoDimensionalListUnitTest class implements a unit test for a two dimensional list.
     */
    class TwoDimensionalListUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The TwoDimensionalListUnitTest constructor.
         */
        explicit TwoDimensionalListUnitTest(const std::string& name);

        /**
         * The TwoDimensionalListUnitTest destructor.
         */
        virtual ~TwoDimensionalListUnitTest();

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the two dimensional list.
         */
        void twoDimensionalListTest();

    private:
        /**
         * Tests the two dimensional list.
         */
        void testTwoDimensionalList(int rows, int columns);
    };
}

#endif /* TWO_DIMENSIONAL_LIST_UNIT_TEST_H_e15d9eec_6c6e_45a6_847f_dd8bed89328a */
