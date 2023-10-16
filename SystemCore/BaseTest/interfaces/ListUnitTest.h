#ifndef LIST_UNIT_TEST_H_25e7e522_cd62_4126_ac7d_af33bc12efcc
#define LIST_UNIT_TEST_H_25e7e522_cd62_4126_ac7d_af33bc12efcc

#include "UnitTestBase.h"

namespace test {
    namespace base {

        /**
         * The ListUnitTest class implements a unit test for a list.
         */
        class ListUnitTest final : public unit_testing::UnitTestBase
        {
        public:
            /**
             * The constructor.
             */
            explicit ListUnitTest(const std::wstring& name);

            /**
             * The destructor.
             */
            virtual ~ListUnitTest();

            /**
             * The copy/move constructors.
             */
            ListUnitTest(const ListUnitTest&) = delete;
            ListUnitTest(ListUnitTest&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ListUnitTest& operator=(const ListUnitTest&) = delete;
            ListUnitTest& operator=(ListUnitTest&&) = delete;

            /**
             * Registers tests of the unit test.
             */
            virtual void RegisterTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the list.
             */
            void ListTest();

        private:
            /**
             * Tests the list.
             */
            void TestList(size_t size);
        };
    }
}

#endif // LIST_UNIT_TEST_H_25e7e522_cd62_4126_ac7d_af33bc12efcc
