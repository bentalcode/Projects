#include "MemoryAllocatorUnitTest.h"
#include "MemoryAllocator.h"
#include "UnitTestFunction.h"

using namespace memory_management;

class TestMemoryAllocatorFunction final : public unit_testing::UnitTestFunction<MemoryAllocatorUnitTest> {
public:
    explicit TestMemoryAllocatorFunction(MemoryAllocatorUnitTest &unitTest) :
        UnitTestFunction(L"MemoryAllocatorTest", unitTest) {
    }

    virtual ~TestMemoryAllocatorFunction() {
    }

    virtual void operator()() override {
        GetUnitTest().MemoryAllocatorTest();
    }
};

class TestAlignedMemoryAllocatorFunction final : public unit_testing::UnitTestFunction<MemoryAllocatorUnitTest> {
public:
    explicit TestAlignedMemoryAllocatorFunction(MemoryAllocatorUnitTest &unitTest) :
        UnitTestFunction(L"AlignedMemoryAllocatorTest", unitTest) {
    }

    virtual ~TestAlignedMemoryAllocatorFunction() {
    }

    virtual void operator()() override {
        GetUnitTest().AlignedMemoryAllocatorTest();
    }
};

/**
 * The MemoryAllocatorUnitTest constructor.
 */
MemoryAllocatorUnitTest::MemoryAllocatorUnitTest(const std::wstring& name) :
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
void MemoryAllocatorUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestMemoryAllocatorFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestAlignedMemoryAllocatorFunction(*this)));
}

/**
 * Tests the memory allocator.
 */
void MemoryAllocatorUnitTest::MemoryAllocatorTest()
{
    for (int i = 0; i < 100; ++i)
    {
        TestMemoryAllocator(i);
    }
}

/**
 * Tests the aligned memory allocator.
 */
void MemoryAllocatorUnitTest::AlignedMemoryAllocatorTest()
{
    int alignment = 8;
    for (unsigned int i = 0; i < 100; ++i)
    {
        TestAlignedMemoryAllocator(i, alignment);
    }
}

/**
 * Tests the memory allocator.
 */
void MemoryAllocatorUnitTest::TestMemoryAllocator(unsigned int size) {
    MemoryAllocator memoryAllocator;

    {
        MemoryPtr memory(memoryAllocator.Allocate(size));

        if (size == 0)
        {
            GetAssertion().AssertTrue(
                memory.get() == nullptr,
                L"Invalid allocated memory.");
        }
        else
        {
            GetAssertion().AssertTrue(
                memory.get() != nullptr,
                L"Invalid allocated memory.");
        }
    }
}

/**
 * Tests the aligned memory allocator.
 */
void MemoryAllocatorUnitTest::TestAlignedMemoryAllocator(int size, int alignment) {
    MemoryAllocator memoryAllocator;
    {
        AlignedMemoryPtr memory(memoryAllocator.AllocateAligned(size, alignment));
        void* memoryPtr = memory.get();
        uintptr_t rawMemoryAddress = reinterpret_cast<uintptr_t>(memoryPtr);

        GetAssertion().AssertTrue(
            rawMemoryAddress % alignment == 0,
            L"Invalid alignment allocation logic.");
    }
}
