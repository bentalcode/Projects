#include "PreCompiled.h"

#include "MemoryAllocatorUnitTest.h"
#include "MemoryAllocator.h"
#include "UnitTestFunction.h"

using namespace memory_management;

class TestMemoryAllocatorFunction : public unit_testing::UnitTestFunction<MemoryAllocatorUnitTest> {
public:
    explicit TestMemoryAllocatorFunction(MemoryAllocatorUnitTest &unitTest) :
        UnitTestFunction("testMemoryAllocator", unitTest) {
    }

    virtual ~TestMemoryAllocatorFunction() {
    }

    virtual void operator()() {
        getUnitTest().memoryAllocatorTest();
    }
};

class TestAlignedMemoryAllocatorFunction : public unit_testing::UnitTestFunction<MemoryAllocatorUnitTest> {
public:
    explicit TestAlignedMemoryAllocatorFunction(MemoryAllocatorUnitTest &unitTest) :
        UnitTestFunction("testAlignedMemoryAllocator", unitTest) {
    }

    virtual ~TestAlignedMemoryAllocatorFunction() {
    }

    virtual void operator()() {
        getUnitTest().alignedMemoryAllocatorTest();
    }
};

/**
 * The MemoryAllocatorUnitTest constructor.
 */
MemoryAllocatorUnitTest::MemoryAllocatorUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The MemoryAllocatorUnitTest destructor.
 */
MemoryAllocatorUnitTest::~MemoryAllocatorUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void MemoryAllocatorUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMemoryAllocatorFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestAlignedMemoryAllocatorFunction(*this)));
}

/**
 * Tests the memory allocator.
 */
void MemoryAllocatorUnitTest::memoryAllocatorTest()
{
    for (int i = 0; i < 100; ++i)
    {
        testMemoryAllocator(i);
    }
}

/**
 * Tests the aligned memory allocator.
 */
void MemoryAllocatorUnitTest::alignedMemoryAllocatorTest()
{
    int alignment = 4;
    for (int i = 0; i < 100; ++i)
    {
        testAlignedMemoryAllocator(i, alignment);
    }
}

/**
 * Tests the memory allocator.
 */
void MemoryAllocatorUnitTest::testMemoryAllocator(int size) {
    MemoryAllocator memoryAllocator;
    void* memory = nullptr;
    {
        MemoryPtr memory(memoryAllocator.allocate(size));
    }
}

/**
 * Tests the aligned memory allocator.
 */
void MemoryAllocatorUnitTest::testAlignedMemoryAllocator(int size, int alignment) {
    MemoryAllocator memoryAllocator;
    {
        AlignedMemoryPtr memory(memoryAllocator.allocateAligned(size, alignment));
        void* memoryPtr = memory.get();
        std::uintptr_t rawMemoryAddress = reinterpret_cast<std::uintptr_t>(memoryPtr);
        assert(rawMemoryAddress % alignment == 0);
    }
}


