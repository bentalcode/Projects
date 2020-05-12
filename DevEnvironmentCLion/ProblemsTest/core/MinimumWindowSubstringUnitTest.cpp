#include "PreCompiled.h"

#include "MinimumWindowSubstringUnitTest.h"
#include "UnitTestFunction.h"
#include "MinimumWindowSubstring.h"

using namespace problems_test;

class TestMinimumWindowSubstringFunction : public unit_testing::UnitTestFunction<MinimumWindowSubstringUnitTest>
{
public:
    TestMinimumWindowSubstringFunction(MinimumWindowSubstringUnitTest& unitTest) :
        UnitTestFunction("minimumWindowSubstringTest", unitTest)
    {
    }

    virtual ~TestMinimumWindowSubstringFunction()
    {
    }

    virtual void operator()()
    {
        getUnitTest().minimumWindowSubstringTest();
    }
};

/**
 * The MinimumWindowSubstringUnitTest constructor.
 */
MinimumWindowSubstringUnitTest::MinimumWindowSubstringUnitTest(const std::string& name) :
    UnitTestBase(name)
{
}

/**
 * The MinimumWindowSubstringUnitTest destructor.
 */
MinimumWindowSubstringUnitTest::~MinimumWindowSubstringUnitTest()
{
}

/**
 * Registers tests of the unit test.
 */
void MinimumWindowSubstringUnitTest::registerTests(unit_testing::ITestRegistration& registration)
{
    registration.registerTest(unit_testing::ITestFunctionPtr(new TestMinimumWindowSubstringFunction(*this)));
}

/**
 * Tests the logic of a minimum window substring.
 */
void MinimumWindowSubstringUnitTest::minimumWindowSubstringTest()
{
    std::string s1;
    std::string t1("a");
    std::string result1;
    bool status1 = false;

    std::string s2("a");
    std::string t2("b");
    std::string result2;
    bool status2 = false;

    std::string s3("a");
    std::string t3;
    std::string result3;
    bool status3 = false;

    std::string s4("hashtable");
    std::string t4("hash");
    std::string result4("has");
    bool status4 = true;

    std::string s5("hashtable");
    std::string t5("hash");
    std::string result5("has");
    bool status5 = true;

    std::string s6("datastructures");
    std::string t6("struct");
    std::string result6("struc");
    bool status6 = true;

    std::string s7("transformation");
    std::string t7("on");
    std::string result7("on");
    bool status7 = true;

    std::string s8("abdefbcdad");
    std::string t8("abc");
    std::string result8("bcda");
    bool status8 = true;

    std::string s9("dataandmusic");
    std::string t9("musicand");
    std::string result9("andmusic");
    bool status9 = true;

    testMinimumWindowSubstring(s1, t1, result1, status1);
    testMinimumWindowSubstring(s2, t2, result2, status2);
    testMinimumWindowSubstring(s3, t3, result3, status3);
    testMinimumWindowSubstring(s4, t4, result4, status4);
    testMinimumWindowSubstring(s5, t5, result5, status5);
    testMinimumWindowSubstring(s6, t6, result6, status6);
    testMinimumWindowSubstring(s7, t7, result7, status7);
    testMinimumWindowSubstring(s8, t8, result8, status8);
    testMinimumWindowSubstring(s9, t9, result9, status9);
}

/**
 * Tests the logic of minimum window substring.
 */
void MinimumWindowSubstringUnitTest::testMinimumWindowSubstring(
    const std::string& s,
    const std::string& t,
    const std::string& expectedResult,
    bool expectedStatus)
{
    problems::MinimumWindowSubstring minimumWindowSubstring(s, t);
    std::string result;
    bool status = minimumWindowSubstring.findMinimumWindow(result);

    getAssertion().assertTrue(
        status == expectedStatus && result == expectedResult,
        "Incorrect logic for calculating a minimum window substring.");
}
