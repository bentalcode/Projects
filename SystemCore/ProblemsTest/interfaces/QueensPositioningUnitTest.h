#ifndef QUEENS_POSITIONING_UNIT_TEST_H_0f2f88e6_2e88_4cd2_881d_1a428239f86c
#define QUEENS_POSITIONING_UNIT_TEST_H_0f2f88e6_2e88_4cd2_881d_1a428239f86c

#include "UnitTestBase.h"
#include "QueensPositioning.h"
#include "TestData.h"
#include "Assertion.h"

namespace problems_test {

    /**
     * The QueensPositioningUnitTest class implements a unit Test for the queens positioning problem.
     */
    class QueensPositioningUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The QueensPositioningUnitTest constructor.
         */
        explicit QueensPositioningUnitTest(const std::wstring& name);

        /**
         * The QueensPositioningUnitTest destructor.
         */
        virtual ~QueensPositioningUnitTest();

        /**
         * The copy/move constructors.
         */
        QueensPositioningUnitTest(const QueensPositioningUnitTest&) = delete;
        QueensPositioningUnitTest(QueensPositioningUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        QueensPositioningUnitTest& operator=(const QueensPositioningUnitTest&) = delete;
        QueensPositioningUnitTest& operator=(QueensPositioningUnitTest&&) = delete;

        /**
         * Registers tests of the unit Test.
         */
        virtual void RegisterTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of position queens.
         */
        void PositionQueensTest();

    private:
        /**
         * Tests the logic of position queens.
         */
        void TestQueensPositioning(
            int size,
            const std::vector<std::vector<std::wstring>>& expectedResults);
    };
}

#endif // QUEENS_POSITIONING_UNIT_TEST_H_0f2f88e6_2e88_4cd2_881d_1a428239f86c
