#ifndef LIST_UNIT_TEST_H_25e7e522_cd62_4126_ac7d_af33bc12efcc
#define LIST_UNIT_TEST_H_25e7e522_cd62_4126_ac7d_af33bc12efcc

#include "PreCompiled.h"
#include "UnitTestBase.h"

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
        explicit ListUnitTest(const std::string& name);

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
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the list.
         */
        void listTest();

    private:
        /**
         * Tests the list.
         */
        void testList(int size);
    };
}

#endif // LIST_UNIT_TEST_H_25e7e522_cd62_4126_ac7d_af33bc12efcc
