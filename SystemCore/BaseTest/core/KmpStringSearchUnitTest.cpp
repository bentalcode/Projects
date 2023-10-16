#include <string>
#include "KmpStringSearchUnitTest.h"
#include "UnitTestFunction.h"
#include "KmpStringSearch.h"

using namespace base;
using namespace test::base;

class FindSubStringTestFunction final : public unit_testing::UnitTestFunction<KmpStringSearchUnitTest> {
public:
    explicit FindSubStringTestFunction(KmpStringSearchUnitTest& unitTest) :
        UnitTestFunction(L"FindSubStringTest", unitTest)
    {
    }

    virtual ~FindSubStringTestFunction()
    {
    }

    virtual void operator()() override 
    {
        GetUnitTest().FindSubStringTest();
    }
};

class FindAllFindSubStringTestFunction final : public unit_testing::UnitTestFunction<KmpStringSearchUnitTest>
{
public:
    explicit FindAllFindSubStringTestFunction(KmpStringSearchUnitTest &unitTest) :
        UnitTestFunction(L"FindAllSubStringTest", unitTest)
    {
    }

    virtual ~FindAllFindSubStringTestFunction()
    {
    }

    virtual void operator()() override 
    {
        GetUnitTest().FindAllSubStringTest();
    }
};

/**
 * The KmpStringSearchUnitTest constructor.
 */
KmpStringSearchUnitTest::KmpStringSearchUnitTest(const std::wstring& name) :
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
void KmpStringSearchUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new FindSubStringTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new FindAllFindSubStringTestFunction(*this)));
}

/**
 * Tests the logic of finding sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::FindSubStringTest()
{
    const std::wstring str1(L"AAACAAAAC");
    std::wstring subString1;
    bool expectedStatus1 = false;
    size_t expectedIndex1 = 0;

    std::wstring str2(L"AAACAAAAC");
    std::wstring subString2;
    bool expectedStatus2 = false;
    size_t expectedIndex2 = 0;

    std::wstring str3(L"AAACAAAAC");
    std::wstring subString3(L"A");
    bool expectedStatus3 = true;
    size_t expectedIndex3 = 0;

    std::wstring str4(L"AAACAAAAC");
    std::wstring subString4(L"AAC");
    bool expectedStatus4 = true;
    size_t expectedIndex4 = 1;

    std::wstring str5(L"AAACAAAAC");
    std::wstring subString5(L"AAAA");
    bool expectedStatus5 = true;
    size_t expectedIndex5 = 4;

    std::wstring str6(L"AAACAAAAC");
    std::wstring subString6(L"AAAE");
    bool expectedStatus6 = false;
    size_t expectedIndex6 = 0;

    std::wstring str7(L"AAACAAAAC");
    std::wstring subString7(L"CA");
    bool expectedStatus7 = true;
    size_t expectedIndex7 = 3;

    std::wstring str8(L"AAACAAAAC");
    std::wstring subString8(L"AAAAA");
    bool expectedStatus8 = false;
    size_t expectedIndex8 = 0;

    std::wstring str9(L"AAACAAAAC");
    std::wstring subString9(L"AAAAC");
    bool expectedStatus9 = true;
    size_t expectedIndex9 = 4;

    TestSubString(str1, subString1, expectedStatus1, expectedIndex1);
    TestSubString(str2, subString2, expectedStatus2, expectedIndex2);
    TestSubString(str3, subString3, expectedStatus3, expectedIndex3);
    TestSubString(str4, subString4, expectedStatus4, expectedIndex4);
    TestSubString(str5, subString5, expectedStatus5, expectedIndex5);
    TestSubString(str6, subString6, expectedStatus6, expectedIndex6);
    TestSubString(str7, subString7, expectedStatus7, expectedIndex7);
    TestSubString(str8, subString8, expectedStatus8, expectedIndex8);
    TestSubString(str9, subString9, expectedStatus9, expectedIndex9);
}

/**
 * Tests the logic of finding all sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::FindAllSubStringTest()
{
    std::wstring str1(L"AAACAAAAC");
    std::wstring subString1;
    std::vector<size_t> expectedResult1;

    std::wstring str2(L"AAACAAAAC");
    std::wstring subString2;
    std::vector<size_t> expectedResult2;

    std::wstring str3(L"AAACAAAAC");
    std::wstring subString3(L"A");
    std::vector<size_t> expectedResult3 = {0, 1, 2, 4, 5, 6, 7};

    std::wstring str4 = L"AAACAAAAC";
    std::wstring subString4 = L"AAC";
    std::vector<size_t> expectedResult4 = {1, 6};

    std::wstring str5 = L"AAACAAAAC";
    std::wstring subString5 = L"AAAA";
    std::vector<size_t> expectedResult5 = {4};

    std::wstring str6(L"AAACAAAAC");
    std::wstring subString6(L"AAAE");
    std::vector<size_t> expectedResult6;

    std::wstring str7(L"AAACAAAAC");
    std::wstring subString7(L"CA");
    std::vector<size_t> expectedResult7 = {3};

    std::wstring str8 = L"AAACAAAAC";
    std::wstring subString8 = L"AAAAA";
    std::vector<size_t> expectedResult8;

    std::wstring str9 = L"AAACAAAAC";
    std::wstring subString9 = L"AAAAC";
    std::vector<size_t> expectedResult9 = {4};

    TestAllSubString(str1, subString1, expectedResult1);
    TestAllSubString(str2, subString2, expectedResult2);
    TestAllSubString(str3, subString3, expectedResult3);
    TestAllSubString(str4, subString4, expectedResult4);
    TestAllSubString(str5, subString5, expectedResult5);
    TestAllSubString(str6, subString6, expectedResult6);
    TestAllSubString(str7, subString7, expectedResult7);
    TestAllSubString(str8, subString8, expectedResult8);
    TestAllSubString(str9, subString9, expectedResult9);
}

/**
 * Tests the logic of finding sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::TestSubString(
    const std::wstring &str,
    const std::wstring &subString,
    bool expectedStatus,
    size_t expectedIndex)
{
    size_t resultIndex = 0;
    bool status = KmpStringSearch::FindSubString(
        str,
        subString,
        resultIndex);

    GetAssertion().AssertTrue(
        status == expectedStatus && resultIndex == expectedIndex,
        L"Incorrect logic of finding sub string with KMP Algorithm.");
}

/**
 * Tests the logic of finding all sub string with KMP Algorithm.
 */
void KmpStringSearchUnitTest::TestAllSubString(
    const std::wstring& str,
    const std::wstring& subString,
    const std::vector<size_t>& expectedResult)
{
    std::vector<size_t> result;
    KmpStringSearch::FindAllSubString(
        str,
        subString,
        result);

    GetAssertion().AssertEquals(
        result,
        expectedResult,
        L"Incorrect logic of finding all sub string with KMP Algorithm.");
}
