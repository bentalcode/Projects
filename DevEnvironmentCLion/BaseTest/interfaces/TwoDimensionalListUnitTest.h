#ifndef TWO_DIMENSIONAL_LIST_UNIT_TEST_H_e15d9eec_6c6e_45a6_847f_dd8bed89328a
#define TWO_DIMENSIONAL_LIST_UNIT_TEST_H_e15d9eec_6c6e_45a6_847f_dd8bed89328a

#include "UnitTestBase.h"
#include "TwoDimensionalList.h"
#include "TestData.h"

namespace base_test {

    /**
     * The TwoDimensionalListUnitTest class implements a unit test for a two dimensional list.
     */
    class TwoDimensionalListUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The constructor.
         */
        explicit TwoDimensionalListUnitTest(const std::string& name);

        /**
         * The destructor.
         */
        virtual ~TwoDimensionalListUnitTest();

        /**
         * The copy/move constructors.
         */
        TwoDimensionalListUnitTest(const TwoDimensionalListUnitTest&) = delete;
        TwoDimensionalListUnitTest(TwoDimensionalListUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        TwoDimensionalListUnitTest& operator=(const TwoDimensionalListUnitTest&) = delete;
        TwoDimensionalListUnitTest& operator=(TwoDimensionalListUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the creation logic of a two dimensional list.
         */
        void twoDimensionalListCreationTest();

        /**
         * Tests the iteration logic of a two dimensional list.
         */
        void twoDimensionalListIterationTest();

    private:
        /**
         * Tests the creation logic of a two dimensional list.
         */
        void testTwoDimensionalListCreation(const std::vector<std::vector<int>>& data);

        /**
         * Tests the iteration logic of a two dimensional list.
         */
        void testTwoDimensionalListIteration(const std::vector<std::vector<int>>& data);

        TestData m_testData;
    };
}

#endif /* TWO_DIMENSIONAL_LIST_UNIT_TEST_H_e15d9eec_6c6e_45a6_847f_dd8bed89328a */
