#include "PreCompiled.h"

#include "MemoryAllocatorUnitTest.h"
#include "MemoryAllocator.h"
#include "UnitTestFunction.h"

using namespace memory_management;

class TestMemoryAllocatorFunction final : public unit_testing::UnitTestFunction<MemoryAllocatorUnitTest> {
public:
    explicit TestMemoryAllocatorFunction(MemoryAllocatorUnitTest &unitTest) :
        UnitTestFunction("memoryAllocatorTest", unitTest) {
    }

    virtual ~TestMemoryAllocatorFunction() {
    }

    virtual void operator()() override {
        getUnitTest().memoryAllocatorTest();
    }
};

class TestAlignedMemoryAllocatorFunction final : public unit_testing::UnitTestFunction<MemoryAllocatorUnitTest> {
public:
    explicit TestAlignedMemoryAllocatorFunction(MemoryAllocatorUnitTest &unitTest) :
        UnitTestFunction("alignedMemoryAllocatorTest", unitTest) {
    }

    virtual ~TestAlignedMemoryAllocatorFunction() {
    }

    virtual void operator()() override {
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
    int alignment = 8;
    for (unsigned int i = 0; i < 100; ++i)
    {
        testAlignedMemoryAllocator(i, alignment);
    }
}

/**
 * Tests the memory allocator.
 */
void MemoryAllocatorUnitTest::testMemoryAllocator(unsigned int size) {
    MemoryAllocator memoryAllocator;

    {
        MemoryPtr memory(memoryAllocator.allocate(size));

        if (size == 0)
        {
            getAssertion().assertTrue(
                memory.get() == nullptr,
                "Invalid allocated memory.");
        }
        else
        {
            getAssertion().assertTrue(
                memory.get() != nullptr,
                "Invalid allocated memory.");
        }
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

        getAssertion().assertTrue(
            rawMemoryAddress % alignment == 0,
            "Invalid alignment allocation logic.");
    }
}


