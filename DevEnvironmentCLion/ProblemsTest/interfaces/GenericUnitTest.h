#ifndef GENERIC_UNIT_TEST_H_621e618f_04b3_4a58_861a_da6a4e5efdce
#define GENERIC_UNIT_TEST_H_621e618f_04b3_4a58_861a_da6a4e5efdce

#include "UnitTestBase.h"

namespace problems_test {

    /**
     * The GenericUnitTest class implements a unit test for a generic problem.
     */
    class GenericUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The GenericUnitTest constructor.
         */
        explicit GenericUnitTest(const std::string& name);

        /**
         * The GenericUnitTest destructor.
         */
        virtual ~GenericUnitTest();

        /**
         * The copy/move constructors.
         */
        GenericUnitTest(const GenericUnitTest&) = delete;
        GenericUnitTest(GenericUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        GenericUnitTest& operator=(const GenericUnitTest&) = delete;
        GenericUnitTest& operator=(GenericUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the generic logic.
         */
        void genericTest();

    private:
        /**
         * Tests the logic.
         */
        void test();
    };

}

#endif // GENERIC_UNIT_TEST_H_621e618f_04b3_4a58_861a_da6a4e5efdce
