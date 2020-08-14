#include "PreCompiled.h"

#include "StringsUnitTest.h"
#include "UnitTestFunction.h"
#include "Strings.h"

using namespace base;

class TestSplitStringFunction final : public unit_testing::UnitTestFunction<StringsUnitTest> {
public:
    explicit TestSplitStringFunction(StringsUnitTest& unitTest) :
        UnitTestFunction("splitStringTest", unitTest)
    {
    }

    virtual ~TestSplitStringFunction()
    {
    }

    virtual void operator()() override 
    {
        getUnitTest().splitStringTest();
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
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestSplitStringFunction(*this)));
}

/**
 * Tests the logic of splitting a string.
 */
void StringsUnitTest::splitStringTest()
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
    std::vector<std::string> expectedTokens9 = {"", "", "", "a", "", "", "b", "", "", "c", "", "d", "", "e", "", "", ""};

    testSplitString(str1, regexSeparator1, expectedTokens1);
    testSplitString(str2, regexSeparator2, expectedTokens2);
    testSplitString(str3, regexSeparator3, expectedTokens3);
    testSplitString(str4, regexSeparator4, expectedTokens4);
    testSplitString(str5, regexSeparator5, expectedTokens5);
    testSplitString(str6, regexSeparator6, expectedTokens6);
    testSplitString(str7, regexSeparator7, expectedTokens7);
    testSplitString(str8, regexSeparator8, expectedTokens8);
    testSplitString(str9, regexSeparator9, expectedTokens9);
}

/**
 * Tests the logic of splitting a string.
 */
void StringsUnitTest::testSplitString(
    const std::string& str,
    const std::string& regexSeparator,
    const std::vector<std::string>& expectedTokens)
{
    std::vector<std::string> tokens;
    Strings::splitString(str, regexSeparator, tokens);

    getAssertion().assertTrue(
        tokens == expectedTokens,
        "Invalid logic of splitting strings.");
}
