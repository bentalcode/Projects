#include "RandomGeneratorUnitTest.h"
#include "RandomGenerator.h"
#include "UnitTestFunction.h"

using namespace base;
using namespace test::base;

class RandomBooleanTestFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest>
{
public:
    RandomBooleanTestFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction(L"RandomBooleanTest", unitTest)
    {
    }

    virtual ~RandomBooleanTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().RandomBooleanTest();
    }
};

class RandomIntegerTestFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest>
{
public:
    RandomIntegerTestFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction(L"RandomIntegerTest", unitTest)
    {
    }

    virtual ~RandomIntegerTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().RandomIntegerTest();
    }
};

class RandomSizeTTestFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest>
{
public:
    RandomSizeTTestFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction(L"RandomSizeTTest", unitTest)
    {
    }

    virtual ~RandomSizeTTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().RandomSizeTTest();
    }
};

class RandomFloatTestFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest>
{
public:
    RandomFloatTestFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction(L"randomFloatTTest", unitTest)
    {
    }

    virtual ~RandomFloatTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().RandomFloatTest();
    }
};

class RandomDoubleTestFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest>
{
public:
    RandomDoubleTestFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction(L"RandomDoubleTest", unitTest)
    {
    }

    virtual ~RandomDoubleTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().RandomDoubleTest();
    }
};

/**
 * The RandomGeneratorUnitTest constructor.
 */
RandomGeneratorUnitTest::RandomGeneratorUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The RandomGeneratorUnitTest destructor.
 */
RandomGeneratorUnitTest::~RandomGeneratorUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void RandomGeneratorUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new RandomBooleanTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new RandomIntegerTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new RandomSizeTTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new RandomFloatTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new RandomDoubleTestFunction(*this)));
}

/**
 * Tests the logic of generating a random boolean.
 */
void RandomGeneratorUnitTest::RandomBooleanTest()
{
    for (int from = 0; from < 1000; ++from)
    {
        TestRandomBoolean();
    }
}

/**
 * Tests the logic of generating a random integer.
 */
void RandomGeneratorUnitTest::RandomIntegerTest()
{
    for (int from = 0; from < 1000; ++from)
    {
        for (int to = from; to < 1000; ++to)
        {
            TestRandomInteger(from, to);
        }
    }
}

/**
 * Tests the logic of generating a random size_t.
 */
void RandomGeneratorUnitTest::RandomSizeTTest()
{
    for (size_t from = 0; from < 1000; ++from)
    {
        for (size_t to = from; to < 1000; ++to)
        {
            TestRandomSizeT(from, to);
        }
    }
}

/**
 * Tests the logic of generating a random float.
 */
void RandomGeneratorUnitTest::RandomFloatTest()
{
    for (float from = 0.0; from < 100; from += 0.2)
    {
        for (float to = from; to < 100; to += 0.5)
        {
            TestRandomFloat(from, to);
        }
    }
}

/**
 * Tests the logic of generating a random double.
 */
void RandomGeneratorUnitTest::RandomDoubleTest()
{
    for (double from = 0.0; from < 100; from += 0.2)
    {
        for (double to = from; to < 100; to += 0.5)
        {
            TestRandomDouble(from, to);
        }
    }
}

/**
 * Tests the logic of generating a random boolean.
 */
void RandomGeneratorUnitTest::TestRandomBoolean()
{
    RandomGenerator randomGenerator;
    bool result = randomGenerator.NextBoolean();
}

/**
 * Tests the logic of generating a random integer.
 */
void RandomGeneratorUnitTest::TestRandomInteger(int from, int to)
{
    RandomGenerator randomGenerator;
    int result = randomGenerator.NextInteger();

    GetAssertion().AssertTrue(
        result >= 0 && result <= RAND_MAX,
        L"Invalid logic for generating a random integer.");

    result = randomGenerator.NextInteger(from, to);

    GetAssertion().AssertTrue(
        result >= from && result <= to,
        L"Invalid logic for generating a random integer.");
}

/**
 * Tests the logic of generating a random size_t.
 */
void RandomGeneratorUnitTest::TestRandomSizeT(size_t from, size_t to)
{
    RandomGenerator randomGenerator;
    size_t result = randomGenerator.NextSizeT();

    GetAssertion().AssertTrue(
        result >= 0 && result <= RAND_MAX,
        L"Invalid logic for generating a random size_t.");

    result = randomGenerator.NextSizeT(from, to);

    GetAssertion().AssertTrue(
        result >= from && result <= to,
        L"Invalid logic for generating a random size_t.");
}

/**
 * Tests the logic of generating a random float.
 */
void RandomGeneratorUnitTest::TestRandomFloat(float from, float to)
{
    RandomGenerator randomGenerator;
    float result = randomGenerator.NextFloat();

    GetAssertion().AssertTrue(
        result >= 0 && result <= RAND_MAX,
        L"Invalid logic for generating a random float.");

    result = randomGenerator.NextFloat(from, to);

    GetAssertion().AssertTrue(
        result >= from && result <= to,
        L"Invalid logic for generating a random float.");
}

/**
 * Tests the logic of generating a random double.
 */
void RandomGeneratorUnitTest::TestRandomDouble(double from, double to)
{
    RandomGenerator randomGenerator;
    double result = randomGenerator.NextDouble();

    GetAssertion().AssertTrue(
        result >= 0 && result <= RAND_MAX,
        L"Invalid logic for generating a random double.");

    result = randomGenerator.NextDouble(from, to);

    GetAssertion().AssertTrue(
        result >= from && result <= to,
        L"Invalid logic for generating a random double.");
}
