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
        UnitTestFunction(L"BitArrayCreationTest", unitTest)
    {
    }

    virtual ~TestBitArrayCreationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BitArrayCreationTest();
    }
};

class TestBitArrayTurnOnOffFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayTurnOnOffFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction(L"BitArrayTurnOnOffTest", unitTest)
    {
    }

    virtual ~TestBitArrayTurnOnOffFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BitArrayTurnOnOffTest();
    }
};

class TestBitArrayIterationFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayIterationFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction(L"BitArrayIterationTest", unitTest)
    {
    }

    virtual ~TestBitArrayIterationFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BitArrayIterationTest();
    }
};

class TestBitArrayCardinalityTestFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayCardinalityTestFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction(L"BitArrayCardinalityTest", unitTest)
    {
    }

    virtual ~TestBitArrayCardinalityTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BitArrayCardinalityTest();
    }
};

class TestBitArrayClearingTestFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayClearingTestFunction(BitArrayUnitTest& unitTest) :
            UnitTestFunction(L"BitArrayClearingTest", unitTest)
    {
    }

    virtual ~TestBitArrayClearingTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BitArrayClearingTest();
    }
};

class TestBitArrayEnablingTestFunction : public unit_testing::UnitTestFunction<BitArrayUnitTest>
{
public:
    TestBitArrayEnablingTestFunction(BitArrayUnitTest& unitTest) :
        UnitTestFunction(L"BitArrayEnablingTest", unitTest)
    {
    }

    virtual ~TestBitArrayEnablingTestFunction()
    {
    }

    virtual void operator()()
    {
        GetUnitTest().BitArrayEnablingTest();
    }
};

/**
 * The BitArrayUnitTest constructor.
 */
BitArrayUnitTest::BitArrayUnitTest(const std::wstring& name) :
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
void BitArrayUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBitArrayCreationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBitArrayTurnOnOffFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBitArrayIterationFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBitArrayCardinalityTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBitArrayClearingTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new TestBitArrayEnablingTestFunction(*this)));
}

/**
 * Tests the creation logic of a bit array.
 */
void BitArrayUnitTest::BitArrayCreationTest()
{
    for (BitArrayDataSharedPtr data : m_testData.GetBitArrayData()->GetData()) {
        TestCreation(*data);
    }
}

/**
 * Tests the turn on/off logic of a bit array.
 */
void BitArrayUnitTest::BitArrayTurnOnOffTest()
{
    for (BitArrayDataSharedPtr data : m_testData.GetBitArrayData()->GetData()) {
        TestTurnOnOff(*data);
    }
}

/**
 * Tests the iteration logic of a bit array.
 */
void BitArrayUnitTest::BitArrayIterationTest()
{
    for (BitArrayDataSharedPtr data : m_testData.GetBitArrayData()->GetData()) {
        TestIteration(*data);
    }
}

/**
 * Tests the cardinality logic of a bit array.
 */
void BitArrayUnitTest::BitArrayCardinalityTest()
{
    for (BitArrayDataSharedPtr data : m_testData.GetBitArrayData()->GetData()) {
        TestCardinality(*data);
    }
}

/**
 * Tests the clearing logic of a bit array.
 */
void BitArrayUnitTest::BitArrayClearingTest()
{
    for (BitArrayDataSharedPtr data : m_testData.GetBitArrayData()->GetData()) {
        TestClearing(*data);
    }
}

/**
 * Tests the enabling logic of a bit array.
 */
void BitArrayUnitTest::BitArrayEnablingTest()
{
    for (BitArrayDataSharedPtr data : m_testData.GetBitArrayData()->GetData()) {
        TestEnabling(*data);
    }
}

/**
 * Tests the creation logic of a bit array.
 */
void BitArrayUnitTest::TestCreation(const BitArrayData& data)
{
    IBitArraySharedPtr bitArray = CreateBitArray(data);

    GetAssertion().AssertEquals(
        bitArray->Size(),
        data.GetData().size(),
        L"Invalid creation logic of a bit array.");

    GetAssertion().AssertEqualsWithIterators(
        *bitArray->GetIterator(),
        *base::VectorIterator<bool>::Make(data.GetData()),
        L"Invalid creation logic of a bit array.");
}

/**
 * Tests the turn on and off logic of a bit array.
 */
void BitArrayUnitTest::TestTurnOnOff(const BitArrayData& data)
{
    IBitArraySharedPtr bitArray = CreateBitArray(data);
    IBitArraySharedPtr expectedBitArray = BitArray::Copy(*bitArray);
    expectedBitArray->Flip();

    for (size_t i = 0; i < bitArray->Size(); ++i) {
        if (bitArray->IsOn(i)) {
            bitArray->TurnOff(i);

            GetAssertion().AssertTrue(
                bitArray->IsOff(i),
                L"Invalid turn off logic of a bit array.");
        }
        else
        {
            bitArray->TurnOn(i);

            GetAssertion().AssertTrue(
                bitArray->IsOn(i),
                L"Invalid turn on logic of a bit array.");
        }
    }

    GetAssertion().AssertEqualsWithDereference(
        bitArray,
        expectedBitArray,
        L"Invalid turn on/off logic of a bit array.");
}

/**
 * Tests the iteration logic of a bit array.
 */
void BitArrayUnitTest::TestIteration(const BitArrayData& data)
{
    //
    // Create the container...
    //
    IBitArraySharedPtr container = CreateBitArray(data);

    //
    // Test the default iterator of the container...
    //
    base::IIterableSharedPtr<bool> containerIterable = container;
    base::IIteratorSharedPtr<bool> expectedIterator = base::VectorIterator<bool>::Make(data.GetData());

    test_base::IterationTest iterationTest;
    iterationTest.TestForwardIteration(
        containerIterable,
        expectedIterator,
        L"BitArray");

    //
    // Test the forward iterator of the container...
    //
    expectedIterator = base::VectorIterator<bool>::Make(data.GetData());

    iterationTest.TestForwardIteration(
        containerIterable,
        expectedIterator,
        L"BitArray");

    //
    // Test the reverse iterator of the container...
    //
    base::IReverseIterableSharedPtr<bool> containerReverseIterable = container;
    base::IReverseIteratorSharedPtr<bool> expectedReveseIterator = base::VectorReverseIterator<bool>::Make(
        data.GetData());

    iterationTest.TestReverseIteration(
        containerReverseIterable,
        expectedReveseIterator,
        L"BitArray");
}

/**
 * Tests the clearing logic of a bit array.
 */
void BitArrayUnitTest::TestClearing(const BitArrayData& data)
{
    IBitArraySharedPtr bitArray = CreateBitArray(data);

    bitArray->Clear();
    size_t numberOfOnes = bitArray->Cardinality();
    size_t expectedNumberOfOnes = 0;

    GetAssertion().AssertTrue(
        numberOfOnes == expectedNumberOfOnes,
        L"Incorrect logic of clearing a bit array, the number of ones should be: " +
        expectedNumberOfOnes);

    for (size_t startIndex = 0; startIndex < bitArray->Size(); ++startIndex) {
        for (size_t endIndex = startIndex; endIndex < bitArray->Size(); ++endIndex) {

            bitArray->Enable();
            bitArray->Clear(startIndex, endIndex);

            numberOfOnes = bitArray->Cardinality();
            expectedNumberOfOnes = bitArray->Size() - base::Indexes::Size(startIndex, endIndex);

            GetAssertion().AssertTrue(
                numberOfOnes == expectedNumberOfOnes,
                L"Incorrect logic of clearing a bit array, the number of ones should be: " +
                expectedNumberOfOnes);
        }
    }
}

/**
 * Tests the enabling logic of a bit array.
 */
void BitArrayUnitTest::TestEnabling(const BitArrayData& data)
{
    IBitArraySharedPtr bitArray = CreateBitArray(data);

    bitArray->Enable();
    size_t numberOfOnes = bitArray->Cardinality();
    size_t expectedNumberOfOnes = bitArray->Size();

    GetAssertion().AssertTrue(
        numberOfOnes == expectedNumberOfOnes,
        L"Incorrect logic of enabling a bit array, the number of ones should be: " +
        expectedNumberOfOnes);

    for (size_t startIndex = 0; startIndex < bitArray->Size(); ++startIndex) {
        for (size_t endIndex = startIndex; endIndex < bitArray->Size(); ++endIndex) {

            bitArray->Clear();
            bitArray->Enable(startIndex, endIndex);

            numberOfOnes = bitArray->Cardinality();
            expectedNumberOfOnes = base::Indexes::Size(startIndex, endIndex);

            GetAssertion().AssertTrue(
                numberOfOnes == expectedNumberOfOnes,
                L"Incorrect logic of enabling a bit array, the number of ones should be: " +
                expectedNumberOfOnes);
        }
    }
}

/**
 * Tests the cardinality logic of a bit array.
 */
void BitArrayUnitTest::TestCardinality(const BitArrayData& data)
{
    IBitArraySharedPtr bitArray = CreateBitArray(data);

    size_t result = bitArray->Cardinality();

    size_t expectedResult = 0;

    for (int index = 0; index < bitArray->Size(); ++index) {
        if (bitArray->IsOn(index)) {
            ++expectedResult;
        }
    }

    GetAssertion().AssertEquals(
        result,
        expectedResult,
        L"Incorrect logic of a cardinality logic of a bit array.");
}

/**
 * Creates a bit array.
 */
IBitArraySharedPtr BitArrayUnitTest::CreateBitArray(const BitArrayData& data)
{
    IBitArraySharedPtr bitArray = BitArray::Make(data.GetData().size());

    for (size_t i = 0; i < bitArray->Size(); ++i)
    {
        if (data.GetData().at(i))
        {
            bitArray->TurnOn(i);
        }
        else
        {
            bitArray->TurnOff(i);
        }
    }

    return bitArray;
}
