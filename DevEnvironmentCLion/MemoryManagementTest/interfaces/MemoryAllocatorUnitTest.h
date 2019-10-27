#ifndef MEMORY_ALLOCATOR_UNIT_TEST_H_7b182ae0_a34f_420d_b31b_347335a80d7b
#define MEMORY_ALLOCATOR_UNIT_TEST_H_7b182ae0_a34f_420d_b31b_347335a80d7b

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace memory_management {

    /**
     * The MemoryAllocatorUnitTest class implements a unit test for a memory allocator.
     */
    class MemoryAllocatorUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The MemoryAllocatorUnitTest constructor.
         */
        explicit MemoryAllocatorUnitTest(const std::string& name);

        /**
         * The MemoryAllocatorUnitTest destructor.
         */
        virtual ~MemoryAllocatorUnitTest();

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Test the memory allocator.
         */
        void memoryAllocatorTest();

        /**
         * Test the aligned memory allocator.
         */
        void alignedMemoryAllocatorTest();

    private:
        /**
         * Test the memory allocator.
         */
        void testMemoryAllocator(int size);

        /**
         * Test the aligned memory allocator.
         */
        void testAlignedMemoryAllocator(int size, int alignment);
    };
}

#endif /* MEMORY_ALLOCATOR_UNIT_TEST_H_7b182ae0_a34f_420d_b31b_347335a80d7b */
