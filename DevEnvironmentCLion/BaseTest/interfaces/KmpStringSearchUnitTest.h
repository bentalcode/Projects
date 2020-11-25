#ifndef KMP_STRING_SEARCH_UNIT_TEST_H_31dd89f0_6411_4ef0_9c41_86ef07758439
#define KMP_STRING_SEARCH_UNIT_TEST_H_31dd89f0_6411_4ef0_9c41_86ef07758439

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace test {
    namespace base {

        /**
         * The KmpStringSearch class implements unit tests for string search
         * by using an algorithm for KMP (Knuth Morris Pratt) Pattern Searching.
         */
        class KmpStringSearchUnitTest final : public unit_testing::UnitTestBase
        {
        public:
            /**
             * The constructor.
             */
            explicit KmpStringSearchUnitTest(const std::string& name);

            /**
             * The destructor.
             */
            virtual ~KmpStringSearchUnitTest();

            /**
             * The copy/move constructors.
             */
            KmpStringSearchUnitTest(const KmpStringSearchUnitTest&) = delete;
            KmpStringSearchUnitTest(KmpStringSearchUnitTest&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            KmpStringSearchUnitTest& operator=(const KmpStringSearchUnitTest&) = delete;
            KmpStringSearchUnitTest& operator=(KmpStringSearchUnitTest&&) = delete;

            /**
             * Registers tests of the unit test.
             */
            virtual void registerTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the logic of finding sub string with KMP Algorithm.
             */
            void findSubStringTest();

            /**
             * Tests the logic of finding all sub string with KMP Algorithm.
             */
            void findAllSubStringTest();

        private:
            /**
             * Tests the logic of finding sub string with KMP Algorithm.
             */
            void testSubString(
                const std::string& str,
                const std::string& subString,
                bool expectedStatus,
                size_t expectedIndex);

            /**
             * Tests the logic of finding all sub string with KMP Algorithm.
             */
            void testAllSubString(
                const std::string& str,
                const std::string& subString,
                const std::vector<size_t>& expectedResult);
        };
    }
}

#endif // KMP_STRING_SEARCH_UNIT_TEST_H_31dd89f0_6411_4ef0_9c41_86ef07758439
