#ifndef LIST_UNIT_TEST_H_ae7d5a12_9782_473b_a3e9_da7173f7c07c
#define LIST_UNIT_TEST_H_ae7d5a12_9782_473b_a3e9_da7173f7c07c

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace base_test {

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

#endif /* LIST_UNIT_TEST_H_ae7d5a12_9782_473b_a3e9_da7173f7c07c */
