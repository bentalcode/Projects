#ifndef MINIMUM_WINDOW_SUBSTRING_UNIT_TEST_H_008867c8_84f0_4cc1_bceb_cd0e9cf5f628
#define MINIMUM_WINDOW_SUBSTRING_UNIT_TEST_H_008867c8_84f0_4cc1_bceb_cd0e9cf5f628

#include "UnitTestBase.h"

namespace problems_test {

    /**
     * The MinimumWindowSubstringUnitTest class implements a unit test for a minimum window substring problem.
     */
    class MinimumWindowSubstringUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The MinimumWindowSubstringUnitTest constructor.
         */
        explicit MinimumWindowSubstringUnitTest(const std::string& name);

        /**
         * The MinimumWindowSubstringUnitTest destructor.
         */
        virtual ~MinimumWindowSubstringUnitTest();

        /**
         * The copy/move constructors.
         */
        MinimumWindowSubstringUnitTest(const MinimumWindowSubstringUnitTest&) = delete;
        MinimumWindowSubstringUnitTest(MinimumWindowSubstringUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MinimumWindowSubstringUnitTest& operator=(const MinimumWindowSubstringUnitTest&) = delete;
        MinimumWindowSubstringUnitTest& operator=(MinimumWindowSubstringUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of a minimum window substring.
         */
        void minimumWindowSubstringTest();

    private:
        /**
         * Tests the logic of a minimum window substring.
         */
        void testMinimumWindowSubstring(
            const std::string& s,
            const std::string& t,
            const std::string& expectedResult,
            bool expectedStatus);
    };
}

#endif /* MINIMUM_WINDOW_SUBSTRING_UNIT_TEST_H_008867c8_84f0_4cc1_bceb_cd0e9cf5f628 */
