#include "PreCompiled.h"

#include "BitArrayUnitTest.h"
#include "UnitTestFunction.h"

using namespace test::datastructures::bitarray;

class TestBitArrayCreationFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayCreationFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction("bitArrayCreationTest", unitTest)
    {
    }

    virtual ~TestBitArrayCreationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().bitArrayCreationTest();
    }
};

class TestBitArrayTurnOnOffFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayTurnOnOffFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction("bitArrayTurnOnOffTest", unitTest)
    {
    }

    virtual ~TestBitArrayTurnOnOffFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().bitArrayTurnOnOffTest();
    }
};

class TestBitArrayIterationFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayIterationFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction("bitArrayIterationTest", unitTest)
    {
    }

    virtual ~TestBitArrayIterationFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().bitArrayIterationTest();
    }
};

class TestBitArrayCardinalityTestFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayCardinalityTestFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction("bitArrayCardinalityTest", unitTest)
    {
    }

    virtual ~TestBitArrayCardinalityTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().bitArrayCardinalityTest();
    }
};

class TestBitArrayClearingTestFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayClearingTestFunction(BitArrayUnitTest& unitTest) :
            UnitTestFunction("bitArrayClearingTest", unitTest)
    {
    }

    virtual ~TestBitArrayClearingTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().bitArrayClearingTest();
    }
};

class TestBitArrayEnablingTestFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayEnablingTestFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction("bitArrayEnablingTest", unitTest)
    {
    }

    virtual ~TestBitArrayEnablingTestFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().bitArrayEnablingTest();
    }
};

/**
 * The BitArrayUnitTest constructor.
 */
BitArrayUnitTest::BitArrayUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The BitArrayUnitTest destructor.
 */
BitArrayUnitTest::~BitArrayUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void BitArrayUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBitArrayCreationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBitArrayTurnOnOffFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBitArrayIterationFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBitArrayCardinalityTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBitArrayClearingTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestBitArrayEnablingTestFunction(*this)));
}

/**
 * Tests the creation logic of a bit array.
 */
void BitArrayUnitTest::bitArrayCreationTest()
{
}

/**
 * Tests the turn on/off logic of a bit array.
 */
void BitArrayUnitTest::bitArrayTurnOnOffTest()
{
}

/**
 * Tests the iteration logic of a bit array.
 */
void BitArrayUnitTest::bitArrayIterationTest()
{
}

/**
 * Tests the cardinality logic of a bit array.
 */
void BitArrayUnitTest::bitArrayCardinalityTest()
{
}

/**
 * Tests the clearing logic of a bit array.
 */
void BitArrayUnitTest::bitArrayClearingTest()
{
}

/**
 * Tests the enabling logic of a bit array.
 */
void BitArrayUnitTest::bitArrayEnablingTest()
{
}

/**
 * Tests the creation logic of a bit array.
 */
void BitArrayUnitTest::testCreation(const BitArrayData& data)
{
}

/**
 * Tests the turn on and off logic of a bit array.
 */
void BitArrayUnitTest::testTurnOnOff(const BitArrayData& data)
{
}

/**
 * Tests the iteration logic of a bit array.
 */
void BitArrayUnitTest::testIteration(const BitArrayData& data)
{
}

/**
 * Tests the clearing logic of a bit array.
 */
void BitArrayUnitTest::testClearing(const BitArrayData& data)
{
}

/**
 * Tests the enabling logic of a bit array.
 */
void BitArrayUnitTest::testEnabling(const BitArrayData& data)
{
}

/**
 * Tests the cardinality logic of a bit array.
 */
void BitArrayUnitTest::testCardinality(const BitArrayData& data)
{
}

/**
 * Creates a bit array.
 */
IBitArrayPtr BitArrayUnitTest::createBitArray(const BitArrayData& data)
{
    IBitArrayPtr bitArray;
    return bitArray;
}
