#include "PreCompiled.h"

#include "KmpStringSearchUnitTest.h"
#include "UnitTestFunction.h"
#include "KmpStringSearch.h"

using namespace base;

class TestFindSubStringFunction final : public unit_testing::UnitTestFunction<KmpStringSearchUnitTest> {
public:
    explicit TestFindSubStringFunction(KmpStringSearchUnitTest& unitTest) :
        UnitTestFunction("findSubStringTest", unitTest)
    {
    }

    virtual ~TestFindSubStringFunction()
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().findSubStringTest();
    }
};

class TestAllFindSubStringFunction final : public unit_testing::UnitTestFunction<KmpStringSearchUnitTest>
{
public:
    explicit TestAllFindSubStringFunction(KmpStringSearchUnitTest &unitTest) :
        UnitTestFunction("findAllSubStringTest", unitTest)
    {
    }

    virtual ~TestAllFindSubStringFunction()
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().findAllSubStringTest();
    }
};

/**
 * The KmpStringSearchUnitTest constructor.
 */
KmpStringSearchUnitTest::KmpStringSearchUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The KmpStringSearchUnitTest destructor.
 */
KmpStringSearchUnitTest::~KmpStringSearchUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void KmpStringSearchUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestFindSubStringFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestAllFindSubStringFunction(*this)));
}

/**
 * Tests the logic of finding sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::findSubStringTest()
{
    const std::string str1("AAACAAAAC");
    std::string subString1;
    bool expectedStatus1 = false;
    size_t expectedIndex1 = 0;

    std::string str2("AAACAAAAC");
    std::string subString2;
    bool expectedStatus2 = false;
    size_t expectedIndex2 = 0;

    std::string str3("AAACAAAAC");
    std::string subString3("A");
    bool expectedStatus3 = true;
    size_t expectedIndex3 = 0;

    std::string str4("AAACAAAAC");
    std::string subString4("AAC");
    bool expectedStatus4 = true;
    size_t expectedIndex4 = 1;

    std::string str5("AAACAAAAC");
    std::string subString5("AAAA");
    bool expectedStatus5 = true;
    size_t expectedIndex5 = 4;

    std::string str6("AAACAAAAC");
    std::string subString6("AAAE");
    bool expectedStatus6 = false;
    size_t expectedIndex6 = 0;

    std::string str7("AAACAAAAC");
    std::string subString7("CA");
    bool expectedStatus7 = true;
    size_t expectedIndex7 = 3;

    std::string str8("AAACAAAAC");
    std::string subString8("AAAAA");
    bool expectedStatus8 = false;
    size_t expectedIndex8 = 0;

    std::string str9("AAACAAAAC");
    std::string subString9("AAAAC");
    bool expectedStatus9 = true;
    size_t expectedIndex9 = 4;

    testSubString(str1, subString1, expectedStatus1, expectedIndex1);
    testSubString(str2, subString2, expectedStatus2, expectedIndex2);
    testSubString(str3, subString3, expectedStatus3, expectedIndex3);
    testSubString(str4, subString4, expectedStatus4, expectedIndex4);
    testSubString(str5, subString5, expectedStatus5, expectedIndex5);
    testSubString(str6, subString6, expectedStatus6, expectedIndex6);
    testSubString(str7, subString7, expectedStatus7, expectedIndex7);
    testSubString(str8, subString8, expectedStatus8, expectedIndex8);
    testSubString(str9, subString9, expectedStatus9, expectedIndex9);
}

/**
 * Tests the logic of finding all sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::findAllSubStringTest()
{
    std::string str1("AAACAAAAC");
    std::string subString1;
    std::vector<size_t> expectedResult1;

    std::string str2("AAACAAAAC");
    std::string subString2;
    std::vector<size_t> expectedResult2;

    std::string str3("AAACAAAAC");
    std::string subString3("A");
    std::vector<size_t> expectedResult3 = {0, 1, 2, 4, 5, 6, 7};

    std::string str4 = "AAACAAAAC";
    std::string subString4 = "AAC";
    std::vector<size_t> expectedResult4 = {1, 6};

    std::string str5 = "AAACAAAAC";
    std::string subString5 = "AAAA";
    std::vector<size_t> expectedResult5 = {4};

    std::string str6("AAACAAAAC");
    std::string subString6("AAAE");
    std::vector<size_t> expectedResult6;

    std::string str7("AAACAAAAC");
    std::string subString7("CA");
    std::vector<size_t> expectedResult7 = {3};

    std::string str8 = "AAACAAAAC";
    std::string subString8 = "AAAAA";
    std::vector<size_t> expectedResult8;

    std::string str9 = "AAACAAAAC";
    std::string subString9 = "AAAAC";
    std::vector<size_t> expectedResult9 = {4};

    testAllSubString(str1, subString1, expectedResult1);
    testAllSubString(str2, subString2, expectedResult2);
    testAllSubString(str3, subString3, expectedResult3);
    testAllSubString(str4, subString4, expectedResult4);
    testAllSubString(str5, subString5, expectedResult5);
    testAllSubString(str6, subString6, expectedResult6);
    testAllSubString(str7, subString7, expectedResult7);
    testAllSubString(str8, subString8, expectedResult8);
    testAllSubString(str9, subString9, expectedResult9);
}

/**
 * Tests the logic of finding sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::testSubString(
    const std::string& str,
    const std::string& subString,
    bool expectedStatus,
    size_t expectedIndex)
{
    size_t resultIndex = 0;
    bool status = KmpStringSearch::findSubString(
        str,
        subString,
        resultIndex);

    getAssertion().assertTrue(
        status == expectedStatus && resultIndex == expectedIndex,
        "Incorrect logic of finding sub string with KMP Algorithm.");
}

/**
 * Tests the logic of finding all sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::testAllSubString(
    const std::string& str,
    const std::string& subString,
    const std::vector<size_t>& expectedResult)
{
    std::vector<size_t> result;
    KmpStringSearch::findAllSubString(
        str,
        subString,
        result);

    getAssertion().assertEquals(
        result,
        expectedResult,
        "Incorrect logic of finding all sub string with KMP Algorithm.");
}
