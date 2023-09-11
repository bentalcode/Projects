#include "PreCompiled.h"

#include "BitArrayUnitTest.h"
#include "UnitTestFunction.h"
#include "BitArray.h"
#include "BitArrayData.h"
#include "VectorIterator.h"
#include "VectorReverseIterator.h"
#include "IterationTest.h"
#include "Indexes.h"

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
    for (BitArrayDataPtr data : m_testData.getBitArrayData()->getData()) {
        testCreation(*data);
    }
}

/**
 * Tests the turn on/off logic of a bit array.
 */
void BitArrayUnitTest::bitArrayTurnOnOffTest()
{
    for (BitArrayDataPtr data : m_testData.getBitArrayData()->getData()) {
        testTurnOnOff(*data);
    }
}

/**
 * Tests the iteration logic of a bit array.
 */
void BitArrayUnitTest::bitArrayIterationTest()
{
    for (BitArrayDataPtr data : m_testData.getBitArrayData()->getData()) {
        testIteration(*data);
    }
}

/**
 * Tests the cardinality logic of a bit array.
 */
void BitArrayUnitTest::bitArrayCardinalityTest()
{
    for (BitArrayDataPtr data : m_testData.getBitArrayData()->getData()) {
        testCardinality(*data);
    }
}

/**
 * Tests the clearing logic of a bit array.
 */
void BitArrayUnitTest::bitArrayClearingTest()
{
    for (BitArrayDataPtr data : m_testData.getBitArrayData()->getData()) {
        testClearing(*data);
    }
}

/**
 * Tests the enabling logic of a bit array.
 */
void BitArrayUnitTest::bitArrayEnablingTest()
{
    for (BitArrayDataPtr data : m_testData.getBitArrayData()->getData()) {
        testEnabling(*data);
    }
}

/**
 * Tests the creation logic of a bit array.
 */
void BitArrayUnitTest::testCreation(const BitArrayData& data)
{
    IBitArrayPtr bitArray = createBitArray(data);

    getAssertion().assertEquals(
        bitArray->size(),
        data.getData().size(),
        "Invalid creation logic of a bit array.");

    getAssertion().assertEqualsWithIterators(
        *bitArray->getIterator(),
        *base::VectorIterator<bool>::make(data.getData()),
        "Invalid creation logic of a bit array.");
}

/**
 * Tests the turn on and off logic of a bit array.
 */
void BitArrayUnitTest::testTurnOnOff(const BitArrayData& data)
{
    IBitArrayPtr bitArray = createBitArray(data);
    IBitArrayPtr expectedBitArray = BitArray::copy(*bitArray);
    expectedBitArray->flip();

    for (size_t i = 0; i < bitArray->size(); ++i) {
        if (bitArray->isOn(i)) {
            bitArray->turnOff(i);

            getAssertion().assertTrue(
                bitArray->isOff(i),
                "Invalid turn off logic of a bit array.");
        }
        else
        {
            bitArray->turnOn(i);

            getAssertion().assertTrue(
                bitArray->isOn(i),
                "Invalid turn on logic of a bit array.");
        }
    }

    getAssertion().assertEqualsWithDereference(
        bitArray,
        expectedBitArray,
        "Invalid turn on/off logic of a bit array.");
}

/**
 * Tests the iteration logic of a bit array.
 */
void BitArrayUnitTest::testIteration(const BitArrayData& data)
{
    //
    // Create the container...
    //
    IBitArrayPtr container = createBitArray(data);

    //
    // Test the default iterator of the container...
    //
    base::IIterablePtr<bool> containerIterable = container;
    base::IIteratorPtr<bool> expectedIterator = base::VectorIterator<bool>::make(data.getData());

    test_base::IterationTest iterationTest;
    iterationTest.testForwardIteration(
        containerIterable,
        expectedIterator,
        "BitArray");

    //
    // Test the forward iterator of the container...
    //
    expectedIterator = base::VectorIterator<bool>::make(data.getData());

    iterationTest.testForwardIteration(
        containerIterable,
        expectedIterator,
        "BitArray");

    //
    // Test the reverse iterator of the container...
    //
    base::IReverseIterablePtr<bool> containerReverseIterable = container;
    base::IReverseIteratorPtr<bool> expectedReveseIterator = base::VectorReverseIterator<bool>::make(data.getData());

    iterationTest.testReverseIteration(
        containerReverseIterable,
        expectedReveseIterator,
        "BitArray");
}

/**
 * Tests the clearing logic of a bit array.
 */
void BitArrayUnitTest::testClearing(const BitArrayData& data)
{
    IBitArrayPtr bitArray = createBitArray(data);

    bitArray->clear();
    size_t numberOfOnes = bitArray->cardinality();
    size_t expectedNumberOfOnes = 0;

    getAssertion().assertTrue(
        numberOfOnes == expectedNumberOfOnes,
        "Incorrect logic of clearing a bit array, the number of ones should be: " +
        expectedNumberOfOnes);

    for (size_t startIndex = 0; startIndex < bitArray->size(); ++startIndex) {
        for (size_t endIndex = startIndex; endIndex < bitArray->size(); ++endIndex) {

            bitArray->enable();
            bitArray->clear(startIndex, endIndex);

            numberOfOnes = bitArray->cardinality();
            expectedNumberOfOnes = bitArray->size() - base::Indexes::size(startIndex, endIndex);

            getAssertion().assertTrue(
                numberOfOnes == expectedNumberOfOnes,
                "Incorrect logic of clearing a bit array, the number of ones should be: " +
                expectedNumberOfOnes);
        }
    }
}

/**
 * Tests the enabling logic of a bit array.
 */
void BitArrayUnitTest::testEnabling(const BitArrayData& data)
{
    IBitArrayPtr bitArray = createBitArray(data);

    bitArray->enable();
    size_t numberOfOnes = bitArray->cardinality();
    size_t expectedNumberOfOnes = bitArray->size();

    getAssertion().assertTrue(
        numberOfOnes == expectedNumberOfOnes,
        "Incorrect logic of enabling a bit array, the number of ones should be: " +
        expectedNumberOfOnes);

    for (size_t startIndex = 0; startIndex < bitArray->size(); ++startIndex) {
        for (size_t endIndex = startIndex; endIndex < bitArray->size(); ++endIndex) {

            bitArray->clear();
            bitArray->enable(startIndex, endIndex);

            numberOfOnes = bitArray->cardinality();
            expectedNumberOfOnes = base::Indexes::size(startIndex, endIndex);

            getAssertion().assertTrue(
                numberOfOnes == expectedNumberOfOnes,
                "Incorrect logic of enabling a bit array, the number of ones should be: " +
                expectedNumberOfOnes);
        }
    }
}

/**
 * Tests the cardinality logic of a bit array.
 */
void BitArrayUnitTest::testCardinality(const BitArrayData& data)
{
    IBitArrayPtr bitArray = createBitArray(data);

    size_t result = bitArray->cardinality();

    size_t expectedResult = 0;

    for (int index = 0; index < bitArray->size(); ++index) {
        if (bitArray->isOn(index)) {
            ++expectedResult;
        }
    }

    getAssertion().assertEquals(
        result,
        expectedResult,
        "Incorrect logic of a cardinality logic of a bit array.");
}

/**
 * Creates a bit array.
 */
IBitArrayPtr BitArrayUnitTest::createBitArray(const BitArrayData& data)
{
    IBitArrayPtr bitArray = BitArray::make(data.getData().size());

    for (size_t i = 0; i < bitArray->size(); ++i)
    {
        if (data.getData().at(i))
        {
            bitArray->turnOn(i);
        }
        else
        {
            bitArray->turnOff(i);
        }
    }

    return bitArray;
}
