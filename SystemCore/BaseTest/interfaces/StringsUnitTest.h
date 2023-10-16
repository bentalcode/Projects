#ifndef STRINGS_UNIT_TEST_H_2b6cb64c_d633_4dcc_bb36_04fb9f23a588
#define STRINGS_UNIT_TEST_H_2b6cb64c_d633_4dcc_bb36_04fb9f23a588

#include "UnitTestBase.h"
#include <vector>

namespace test {
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
            explicit StringsUnitTest(const std::wstring& name);

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
            virtual void RegisterTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the logic of splitting a string.
             */
            void SplitStringTest();

            /**
             * Tests the logic of splitting a string with regex.
             */
            void SplitStringWithRegexTest();

        private:
            /**
             * Tests the logic of splitting a string.
             */
            void TestSplitString(
                const std::wstring& str,
                const std::wstring& separator,
                const std::vector<std::wstring>& expectedTokens);

            /**
             * Tests the logic of splitting a string with regex.
             */
            void TestSplitStringWithRegex(
                const std::wstring& str,
                const std::wstring& regexSeparator,
                const std::vector<std::wstring>& expectedTokens);
        };
    }
}

#endif // STRINGS_UNIT_TEST_H_2b6cb64c_d633_4dcc_bb36_04fb9f23a588
