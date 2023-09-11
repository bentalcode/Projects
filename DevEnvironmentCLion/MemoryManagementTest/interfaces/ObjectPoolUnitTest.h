#ifndef OBJECT_POOL_UNIT_TEST_H_062feb78_d531_48ab_99a0_409ece4efc4c
#define OBJECT_POOL_UNIT_TEST_H_062feb78_d531_48ab_99a0_409ece4efc4c

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace memory_management {

    /**
     * The ObjectPoolUnitTest class implements a unit test for an object pool.
     */
    class ObjectPoolUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The constructor.
         */
        explicit ObjectPoolUnitTest(const std::string& name);

        /**
         * The destructor.
         */
        virtual ~ObjectPoolUnitTest();

        /**
         * The copy/move constructors.
         */
        ObjectPoolUnitTest(const ObjectPoolUnitTest&) = delete;
        ObjectPoolUnitTest(ObjectPoolUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ObjectPoolUnitTest& operator=(const ObjectPoolUnitTest&) = delete;
        ObjectPoolUnitTest& operator=(ObjectPoolUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the object pool.
         */
        void objectPoolTest();

    private:
        /**
         * Tests the object pool.
         */
        void testObjectPool(int numberOfElements);
    };
}

#endif // OBJECT_POOL_UNIT_TEST_H_062feb78_d531_48ab_99a0_409ece4efc4c
