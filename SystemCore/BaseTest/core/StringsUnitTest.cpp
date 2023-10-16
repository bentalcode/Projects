#include "StringsUnitTest.h"
#include "UnitTestFunction.h"
#include "Strings.h"

using namespace base;
using namespace test::base;

class SplitStringTestFunction final : public unit_testing::UnitTestFunction<StringsUnitTest> {
public:
    explicit SplitStringTestFunction(StringsUnitTest& unitTest) :
        UnitTestFunction(L"splitString", unitTest)
    {
    }

    virtual ~SplitStringTestFunction()
    {
    }

    virtual void operator()() override 
    {
        GetUnitTest().SplitStringTest();
    }
};

class SplitStringWithRegexTestFunction final : public unit_testing::UnitTestFunction<StringsUnitTest> {
public:
    explicit SplitStringWithRegexTestFunction(StringsUnitTest& unitTest) :
        UnitTestFunction(L"splitStringWithRegex", unitTest)
    {
    }

    virtual ~SplitStringWithRegexTestFunction()
    {
    }

    virtual void operator()() override
    {
        GetUnitTest().SplitStringWithRegexTest();
    }
};

/**
 * The StringsUnitTest constructor.
 */
StringsUnitTest::StringsUnitTest(const std::wstring& name) :
    UnitTestBase(name)
{
}

/**
 * The StringsUnitTest destructor.
 */
StringsUnitTest::~StringsUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void StringsUnitTest::RegisterTests(unit_testing::ITestRegistration& registration)
{
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new SplitStringTestFunction(*this)));
    registration.RegisterTest(unit_testing::ITestFunctionSharedPtr(new SplitStringWithRegexTestFunction(*this)));
}

/**
 * Tests the logic of splitting a string.
 */
void StringsUnitTest::SplitStringTest()
{
    std::wstring str1 = L" ";
    std::wstring separator1 = L" ";
    std::vector<std::wstring> expectedTokens1 = {L"", L""};

    std::wstring str2 = L"/";
    std::wstring separator2 = L"/";
    std::vector<std::wstring> expectedTokens2 = {L"", L""};

    std::wstring str3 = L"  ";
    std::wstring separator3 = L" ";
    std::vector<std::wstring> expectedTokens3 = {L"", L"", L""};

    std::wstring str4 = L"//";
    std::wstring separator4 = L"/";
    std::vector<std::wstring> expectedTokens4 = {L"", L"", L""};

    std::wstring str5 = L"a,b,c,d,e";
    std::wstring separator5 = L",";
    std::vector<std::wstring> expectedTokens5 = {L"a", L"b", L"c", L"d", L"e"};

    std::wstring str6 = L"a,b,c,d,e,";
    std::wstring separator6 = L",";
    std::vector<std::wstring> expectedTokens6 = {L"a", L"b", L"c", L"d", L"e", L""};

    std::wstring str7 = L"a,b,c,d,e,";
    std::wstring separator7 = L" ";
    std::vector<std::wstring> expectedTokens7 = {L"a,b,c,d,e,"};

    std::wstring str8 = L"a b c d e ";
    std::wstring separator8 = L" ";
    std::vector<std::wstring> expectedTokens8 = {L"a", L"b", L"c", L"d", L"e", L""};

    std::wstring str9 = L"///a///b///c//d//e///";
    std::wstring separator9 = L"/";
    std::vector<std::wstring> expectedTokens9 = {
        L"", L"", L"", L"a", L"", L"", L"b", L"", L"", L"c", L"", L"d", L"", L"e", L"", L"", L""
    };

    std::wstring str10 = L"..a..b..c....d..e..";
    std::wstring separator10 = L"..";
    std::vector<std::wstring> expectedTokens10 = {
        L"", L"a", L"b", L"c", L"", L"d", L"e", L""
    };

    TestSplitString(str1, separator1, expectedTokens1);
    TestSplitString(str2, separator2, expectedTokens2);
    TestSplitString(str3, separator3, expectedTokens3);
    TestSplitString(str4, separator4, expectedTokens4);
    TestSplitString(str5, separator5, expectedTokens5);
    TestSplitString(str6, separator6, expectedTokens6);
    TestSplitString(str7, separator7, expectedTokens7);
    TestSplitString(str8, separator8, expectedTokens8);
    TestSplitString(str9, separator9, expectedTokens9);
    TestSplitString(str10, separator10, expectedTokens10);
}

/**
 * Tests the logic of splitting a string with regex.
 */
void StringsUnitTest::SplitStringWithRegexTest()
{
    std::wstring str1 = L" ";
    std::wstring regexSeparator1 = L" ";
    std::vector<std::wstring> expectedTokens1 = {L"", L""};

    std::wstring str2 = L"/";
    std::wstring regexSeparator2 = L"/";
    std::vector<std::wstring> expectedTokens2 = {L"", L""};

    std::wstring str3 = L"  ";
    std::wstring regexSeparator3 = L" ";
    std::vector<std::wstring> expectedTokens3 = {L"", L"", L""};

    std::wstring str4 = L"//";
    std::wstring regexSeparator4 = L"/";
    std::vector<std::wstring> expectedTokens4 = {L"", L"", L""};

    std::wstring str5 = L"a,b,c,d,e";
    std::wstring regexSeparator5 = L",";
    std::vector<std::wstring> expectedTokens5 = {L"a", L"b", L"c", L"d", L"e"};

    std::wstring str6 = L"a,b,c,d,e,";
    std::wstring regexSeparator6 = L",";
    std::vector<std::wstring> expectedTokens6 = {L"a", L"b", L"c", L"d", L"e", L""};

    std::wstring str7 = L"a,b,c,d,e,";
    std::wstring regexSeparator7 = L"/";
    std::vector<std::wstring> expectedTokens7 = {L"a,b,c,d,e,"};

    std::wstring str8 = L"a b c d e ";
    std::wstring regexSeparator8 = L" ";
    std::vector<std::wstring> expectedTokens8 = {L"a", L"b", L"c", L"d", L"e", L""};

    std::wstring str9 = L"///a///b///c//d//e///";
    std::wstring regexSeparator9 = L"/";
    std::vector<std::wstring> expectedTokens9 = {
        L"", L"", L"", L"a", L"", L"", L"b", L"", L"", L"c", L"", L"d", L"", L"e", L"", L"", L""
    };

    std::wstring str10 = L"This string is splitted by space, period, and comma.";
    std::wstring regexSeparator10 = L"[ ,.]";
    std::vector<std::wstring> expectedTokens10 = {
        L"This", L"string", L"is", L"splitted", L"by", L"space", L"", L"period", L"", L"and", L"comma", L""
    };

    TestSplitStringWithRegex(str1, regexSeparator1, expectedTokens1);
    TestSplitStringWithRegex(str2, regexSeparator2, expectedTokens2);
    TestSplitStringWithRegex(str3, regexSeparator3, expectedTokens3);
    TestSplitStringWithRegex(str4, regexSeparator4, expectedTokens4);
    TestSplitStringWithRegex(str5, regexSeparator5, expectedTokens5);
    TestSplitStringWithRegex(str6, regexSeparator6, expectedTokens6);
    TestSplitStringWithRegex(str7, regexSeparator7, expectedTokens7);
    TestSplitStringWithRegex(str8, regexSeparator8, expectedTokens8);
    TestSplitStringWithRegex(str9, regexSeparator9, expectedTokens9);
    TestSplitStringWithRegex(str10, regexSeparator10, expectedTokens10);
}

/**
 * Tests the logic of splitting a string.
 */
void StringsUnitTest::TestSplitString(
    const std::wstring& str,
    const std::wstring& separator,
    const std::vector<std::wstring>& expectedTokens)
{
    std::vector<std::wstring> tokens;
    Strings::SplitString(str, separator, tokens);

    GetAssertion().AssertTrue(
        std::equal(tokens.begin(), tokens.end(), expectedTokens.begin()),
        L"Invalid logic of splitting strings.");
}

/**
 * Tests the logic of splitting a string with regex.
 */
void StringsUnitTest::TestSplitStringWithRegex(
    const std::wstring& str,
    const std::wstring& regexSeparator,
    const std::vector<std::wstring>& expectedTokens)
{
    std::vector<std::wstring> tokens;
    Strings::SplitStringWithRegex(str, regexSeparator, tokens);

    GetAssertion().AssertTrue(
        std::equal(tokens.begin(), tokens.end(), expectedTokens.begin()),
        L"Invalid logic of splitting strings with regex.");
}
