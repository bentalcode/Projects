#ifndef STRINGS_UNIT_TEST_H_2b6cb64c_d633_4dcc_bb36_04fb9f23a588
#define STRINGS_UNIT_TEST_H_2b6cb64c_d633_4dcc_bb36_04fb9f23a588

#include "UnitTestBase.h"
#include "Strings.h"

namespace base {

    /**
     * The StringsUnitTest class implements a unit test for strings.
     */
    class StringsUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The constructor.
         */
        explicit StringsUnitTest(const std::string& name);

        /**
         * The destructor.
         */
        virtual ~StringsUnitTest();

        /**
         * The copy/move constructors.
         */
        StringsUnitTest(const StringsUnitTest&) = delete;
        StringsUnitTest(StringsUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        StringsUnitTest& operator=(const StringsUnitTest&) = delete;
        StringsUnitTest& operator=(StringsUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of splitting a string.
         */
        void splitStringTest();

    private:
        /**
         * Tests the logic of splitting a string.
         */
        void testSplitString(
            const std::string& str,
            const std::string& regexSeparator,
            const std::vector<std::string>& expectedTokens);
    };
}

#endif // STRINGS_UNIT_TEST_H_2b6cb64c_d633_4dcc_bb36_04fb9f23a588
