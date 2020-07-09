#ifndef POSITION_QUEENS_UNIT_TEST_H_0f2f88e6_2e88_4cd2_881d_1a428239f86c
#define POSITION_QUEENS_UNIT_TEST_H_0f2f88e6_2e88_4cd2_881d_1a428239f86c

#include "UnitTestBase.h"
#include "PositionQueens.h"
#include "TestData.h"
#include "Assertion.h"

namespace problems_test {

    /**
     * The PositionQueensUnitTest class implements a unit test for the position queens problem.
     */
    class PositionQueensUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The PositionQueensUnitTest constructor.
         */
        explicit PositionQueensUnitTest(const std::string& name);

        /**
         * The PositionQueensUnitTest destructor.
         */
        virtual ~PositionQueensUnitTest();

        /**
         * The copy/move constructors.
         */
        PositionQueensUnitTest(const PositionQueensUnitTest&) = delete;
        PositionQueensUnitTest(PositionQueensUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        PositionQueensUnitTest& operator=(const PositionQueensUnitTest&) = delete;
        PositionQueensUnitTest& operator=(PositionQueensUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of position queens.
         */
        void positionQueensTest();

    private:
        /**
         * Tests the logic of position queens.
         */
        void testPositionQueens(
            int size,
            const std::vector<std::vector<std::string>>& expectedResults);
    };
}

#endif // POSITION_QUEENS_UNIT_TEST_H_0f2f88e6_2e88_4cd2_881d_1a428239f86c
