#include "PreCompiled.h"

#include "RandomGeneratorUnitTest.h"
#include "RandomGenerator.h"
#include "UnitTestFunction.h"

using namespace base;

class TestRandomBooleanFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest> {
public:
    TestRandomBooleanFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction("randomBooleanTest", unitTest) {
    }

    virtual ~TestRandomBooleanFunction() {
    }

    virtual void operator()() {
        getUnitTest().randomBooleanTest();
    }
};

class TestRandomIntegerFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest> {
public:
    TestRandomIntegerFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction("randomIntegerTest", unitTest) {
    }

    virtual ~TestRandomIntegerFunction() {
    }

    virtual void operator()() {
        getUnitTest().randomIntegerTest();
    }
};

class TestRandomSizeTFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest> {
public:
    TestRandomSizeTFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction("randomSizeTTest", unitTest) {
    }

    virtual ~TestRandomSizeTFunction() {
    }

    virtual void operator()() {
        getUnitTest().randomSizeTTest();
    }
};

class TestRandomFloatFunction final : public unit_testing::UnitTestFunction<RandomGeneratorUnitTest> {
public:
    TestRandomFloatFunction(RandomGeneratorUnitTest &unitTest) :
        UnitTestFunction("randomFloatTTest", unitTest) {
    }

    virtual ~TestRandomFloatFunction() {
    }

    virtual void operator()() {
        getUnitTest().randomFloatTest();
    }
};

/**
 * The RandomGeneratorUnitTest constructor.
 */
RandomGeneratorUnitTest::RandomGeneratorUnitTest(const std::string& name) :
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
void RandomGeneratorUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestRandomBooleanFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestRandomIntegerFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestRandomSizeTFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestRandomFloatFunction(*this)));
}

/**
 * Tests the logic of generating a random boolean.
 */
void RandomGeneratorUnitTest::randomBooleanTest()
{
    for (int from = 0; from < 1000; ++from)
    {
        testRandomBoolean();
    }
}

/**
 * Tests the logic of generating a random integer.
 */
void RandomGeneratorUnitTest::randomIntegerTest()
{
    for (int from = 0; from < 1000; ++from)
    {
        for (int to = from; to < 1000; ++to)
        {
            testRandomInteger(from, to);
        }
    }
}

/**
 * Tests the logic of generating a random size_t.
 */
void RandomGeneratorUnitTest::randomSizeTTest()
{
    for (size_t from = 0; from < 1000; ++from)
    {
        for (size_t to = from; to < 1000; ++to)
        {
            testRandomSizeT(from, to);
        }
    }
}

/**
 * Tests the logic of generating a random float.
 */
void RandomGeneratorUnitTest::randomFloatTest()
{
    for (float from = 0.0; from < 100; from += 0.2)
    {
        for (float to = from; to < 100; to += 0.5)
        {
            testRandomFloat(from, to);
        }
    }
}

/**
 * Tests the logic of generating a random boolean.
 */
void RandomGeneratorUnitTest::testRandomBoolean()
{
    RandomGenerator randomGenerator;
    randomGenerator.nextBoolean();
}

/**
 * Tests the logic of generating a random integer.
 */
void RandomGeneratorUnitTest::testRandomInteger(int from, int to)
{
    RandomGenerator randomGenerator;
    int result = randomGenerator.nextInteger();

    getAssertion().assertTrue(
        result >= 0 && result <= RAND_MAX,
        "Invalid logic for generating a random integer.");

    result = randomGenerator.nextInteger(from, to);

    getAssertion().assertTrue(
        result >= from && result <= to,
        "Invalid logic for generating a random integer.");
}

/**
 * Tests the logic of generating a random size_t.
 */
void RandomGeneratorUnitTest::testRandomSizeT(size_t from, size_t to)
{
    RandomGenerator randomGenerator;
    size_t result = randomGenerator.nextSizeT();

    getAssertion().assertTrue(
        result >= 0 && result <= RAND_MAX,
        "Invalid logic for generating a random size_t.");

    result = randomGenerator.nextSizeT(from, to);

    getAssertion().assertTrue(
        result >= from && result <= to,
        "Invalid logic for generating a random size_t.");
}

/**
 * Tests the logic of generating a random float.
 */
void RandomGeneratorUnitTest::testRandomFloat(float from, float to)
{
    RandomGenerator randomGenerator;
    float result = randomGenerator.nextFloat();

    getAssertion().assertTrue(
        result >= 0 && result <= RAND_MAX,
        "Invalid logic for generating a random float.");

    result = randomGenerator.nextFloat(from, to);

    getAssertion().assertTrue(
        result >= from && result <= to,
        "Invalid logic for generating a random float.");
}
