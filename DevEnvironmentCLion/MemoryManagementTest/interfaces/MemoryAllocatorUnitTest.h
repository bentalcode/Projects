#ifndef MEMORY_ALLOCATOR_UNIT_TEST_H_f6b511e5_efad_4b34_aef2_4e303687ca6b
#define MEMORY_ALLOCATOR_UNIT_TEST_H_f6b511e5_efad_4b34_aef2_4e303687ca6b

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
         * The constructor.
         */
        explicit MemoryAllocatorUnitTest(const std::string& name);

        /**
         * The destructor.
         */
        virtual ~MemoryAllocatorUnitTest();

        /**
         * The copy/move constructors.
         */
        MemoryAllocatorUnitTest(const MemoryAllocatorUnitTest&) = delete;
        MemoryAllocatorUnitTest(MemoryAllocatorUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MemoryAllocatorUnitTest& operator=(const MemoryAllocatorUnitTest&) = delete;
        MemoryAllocatorUnitTest& operator=(MemoryAllocatorUnitTest&&) = delete;

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
        void testMemoryAllocator(unsigned int size);

        /**
         * Test the aligned memory allocator.
         */
        void testAlignedMemoryAllocator(int size, int alignment);
    };
}

#endif // MEMORY_ALLOCATOR_UNIT_TEST_H_f6b511e5_efad_4b34_aef2_4e303687ca6b
