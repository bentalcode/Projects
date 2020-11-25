#include "PreCompiled.h"

#include "StringsUnitTest.h"
#include "UnitTestFunction.h"
#include "Strings.h"

using namespace base;
using namespace test::base;

class SplitStringTestFunction final : public unit_testing::UnitTestFunction<StringsUnitTest> {
public:
    explicit SplitStringTestFunction(StringsUnitTest& unitTest) :
        UnitTestFunction("splitString", unitTest)
    {
    }

    virtual ~SplitStringTestFunction()
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().splitStringTest();
    }
};

class SplitStringWithRegexTestFunction final : public unit_testing::UnitTestFunction<StringsUnitTest> {
public:
    explicit SplitStringWithRegexTestFunction(StringsUnitTest& unitTest) :
        UnitTestFunction("splitStringWithRegex", unitTest)
    {
    }

    virtual ~SplitStringWithRegexTestFunction()
    {
    }

    virtual void operator()() override
    {
        getUnitTest().splitStringWithRegexTest();
    }
};

/**
 * The StringsUnitTest constructor.
 */
StringsUnitTest::StringsUnitTest(const std::string& name) :
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
void StringsUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new SplitStringTestFunction(*this)));
    registration.registerTest(unit_testing::ITestFunctionPtr(new SplitStringWithRegexTestFunction(*this)));
}

/**
 * Tests the logic of splitting a string.
 */
void StringsUnitTest::splitStringTest()
{
    std::string str1 = " ";
    std::string separator1 = " ";
    std::vector<std::string> expectedTokens1 = {"", ""};

    std::string str2 = "/";
    std::string separator2 = "/";
    std::vector<std::string> expectedTokens2 = {"", ""};

    std::string str3 = "  ";
    std::string separator3 = " ";
    std::vector<std::string> expectedTokens3 = {"", "", ""};

    std::string str4 = "//";
    std::string separator4 = "/";
    std::vector<std::string> expectedTokens4 = {"", "", ""};

    std::string str5 = "a,b,c,d,e";
    std::string separator5 = ",";
    std::vector<std::string> expectedTokens5 = {"a", "b", "c", "d", "e"};

    std::string str6 = "a,b,c,d,e,";
    std::string separator6 = ",";
    std::vector<std::string> expectedTokens6 = {"a", "b", "c", "d", "e", ""};

    std::string str7 = "a,b,c,d,e,";
    std::string separator7 = " ";
    std::vector<std::string> expectedTokens7 = {"a,b,c,d,e,"};

    std::string str8 = "a b c d e ";
    std::string separator8 = " ";
    std::vector<std::string> expectedTokens8 = {"a", "b", "c", "d", "e", ""};

    std::string str9 = "///a///b///c//d//e///";
    std::string separator9 = "/";
    std::vector<std::string> expectedTokens9 = {
        "", "", "", "a", "", "", "b", "", "", "c", "", "d", "", "e", "", "", ""
    };

    std::string str10 = "..a..b..c....d..e..";
    std::string separator10 = "..";
    std::vector<std::string> expectedTokens10 = {
        "", "a", "b", "c", "", "d", "e", ""
    };

    testSplitString(str1, separator1, expectedTokens1);
    testSplitString(str2, separator2, expectedTokens2);
    testSplitString(str3, separator3, expectedTokens3);
    testSplitString(str4, separator4, expectedTokens4);
    testSplitString(str5, separator5, expectedTokens5);
    testSplitString(str6, separator6, expectedTokens6);
    testSplitString(str7, separator7, expectedTokens7);
    testSplitString(str8, separator8, expectedTokens8);
    testSplitString(str9, separator9, expectedTokens9);
    testSplitString(str10, separator10, expectedTokens10);
}

/**
 * Tests the logic of splitting a string with regex.
 */
void StringsUnitTest::splitStringWithRegexTest()
{
    std::string str1 = " ";
    std::string regexSeparator1 = " ";
    std::vector<std::string> expectedTokens1 = {"", ""};

    std::string str2 = "/";
    std::string regexSeparator2 = "/";
    std::vector<std::string> expectedTokens2 = {"", ""};

    std::string str3 = "  ";
    std::string regexSeparator3 = " ";
    std::vector<std::string> expectedTokens3 = {"", "", ""};

    std::string str4 = "//";
    std::string regexSeparator4 = "/";
    std::vector<std::string> expectedTokens4 = {"", "", ""};

    std::string str5 = "a,b,c,d,e";
    std::string regexSeparator5 = ",";
    std::vector<std::string> expectedTokens5 = {"a", "b", "c", "d", "e"};

    std::string str6 = "a,b,c,d,e,";
    std::string regexSeparator6 = ",";
    std::vector<std::string> expectedTokens6 = {"a", "b", "c", "d", "e", ""};

    std::string str7 = "a,b,c,d,e,";
    std::string regexSeparator7 = "/";
    std::vector<std::string> expectedTokens7 = {"a,b,c,d,e,"};

    std::string str8 = "a b c d e ";
    std::string regexSeparator8 = " ";
    std::vector<std::string> expectedTokens8 = {"a", "b", "c", "d", "e", ""};

    std::string str9 = "///a///b///c//d//e///";
    std::string regexSeparator9 = "/";
    std::vector<std::string> expectedTokens9 = {
        "", "", "", "a", "", "", "b", "", "", "c", "", "d", "", "e", "", "", ""
    };

    std::string str10 = "This string is splitted by space, period, and comma.";
    std::string regexSeparator10 = "[ ,.]";
    std::vector<std::string> expectedTokens10 = {
        "This", "string", "is", "splitted", "by", "space", "", "period", "", "and", "comma", ""
    };

    testSplitStringWithRegex(str1, regexSeparator1, expectedTokens1);
    testSplitStringWithRegex(str2, regexSeparator2, expectedTokens2);
    testSplitStringWithRegex(str3, regexSeparator3, expectedTokens3);
    testSplitStringWithRegex(str4, regexSeparator4, expectedTokens4);
    testSplitStringWithRegex(str5, regexSeparator5, expectedTokens5);
    testSplitStringWithRegex(str6, regexSeparator6, expectedTokens6);
    testSplitStringWithRegex(str7, regexSeparator7, expectedTokens7);
    testSplitStringWithRegex(str8, regexSeparator8, expectedTokens8);
    testSplitStringWithRegex(str9, regexSeparator9, expectedTokens9);
    testSplitStringWithRegex(str10, regexSeparator10, expectedTokens10);
}

/**
 * Tests the logic of splitting a string.
 */
void StringsUnitTest::testSplitString(
    const std::string& str,
    const std::string& separator,
    const std::vector<std::string>& expectedTokens)
{
    std::vector<std::string> tokens;
    Strings::splitString(str, separator, tokens);

    getAssertion().assertTrue(
        std::equal(tokens.begin(), tokens.end(), expectedTokens.begin()),
        "Invalid logic of splitting strings.");
}

/**
 * Tests the logic of splitting a string with regex.
 */
void StringsUnitTest::testSplitStringWithRegex(
    const std::string& str,
    const std::string& regexSeparator,
    const std::vector<std::string>& expectedTokens)
{
    std::vector<std::string> tokens;
    Strings::splitStringWithRegex(str, regexSeparator, tokens);

    getAssertion().assertTrue(
        std::equal(tokens.begin(), tokens.end(), expectedTokens.begin()),
        "Invalid logic of splitting strings with regex.");
}
