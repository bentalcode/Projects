#ifndef OBJECT_POOL_UNIT_TEST_H_177ca74f_61c2_4fe2_ab46_9b70c4eba730
#define OBJECT_POOL_UNIT_TEST_H_177ca74f_61c2_4fe2_ab46_9b70c4eba730

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace memory_management {

    /**
     * The ObjectPoolUnitTest class implements a unit test for an object pool.
     */
    class ObjectPoolUnitTest : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The ObjectPoolUnitTest constructor.
         */
        explicit ObjectPoolUnitTest(const std::string& name);

        /**
         * The ObjectPoolUnitTest destructor.
         */
        virtual ~ObjectPoolUnitTest();

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

#endif /* OBJECT_POOL_UNIT_TEST_H_177ca74f_61c2_4fe2_ab46_9b70c4eba730 */
