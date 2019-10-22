#ifndef OBJECT_POOL_UNIT_BASE_H_177ca74f_61c2_4fe2_ab46_9b70c4eba730
#define OBJECT_POOL_UNIT_BASE_H_177ca74f_61c2_4fe2_ab46_9b70c4eba730

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
         * Test the object pool.
         */
        void testObjectPool();

    private:
        /**
         * Processes the object pool.
         */
        void processObjectPool(int numberOfElements);
    };
}

#endif /* OBJECT_POOL_UNIT_BASE_H_177ca74f_61c2_4fe2_ab46_9b70c4eba730 */
