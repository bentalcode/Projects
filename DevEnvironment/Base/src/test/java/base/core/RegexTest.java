package base.core;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The RegexTest class implements tests for regex.
 */
public final class RegexTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The RegexTest constructor.
     */
    public RegexTest() {
    }

    /**
     * Tests the logic of a regex match.
     */
    @Test
    public void testRegexMatch() {
        String str1 = "            return new HashCodeBuilder1(3, 5)";
        String regex1 = "(.*)(new HashCodeBuilder1)(\\([0-9]*, [0-9]*\\))(.*)";

        String str2 = "             IHashCodeBuilder hashCodeBuilder = new HashCodeBuilder1(3, 5);";
        String regex2 = "(.*)(new HashCodeBuilder1)(\\([0-9]*, [0-9]*\\))(.*)";

        this.testRegexMatch(str1, regex1);
        this.testRegexMatch(str2, regex2);
    }

    /**
     * Tests the logic of finding a reference.
     */
    @Test
    public void referenceFindTest() {
        String str1 = "abc.[12]";
        String regex1 = "(\\[[0-9]+\\])+";

        String str2 = "abc.[12][123]";
        String regex2 = "(\\[[0-9]+\\])";

        String str3 = "abc.[12][123][1234]";
        String regex3 = "(\\[[0-9]+\\])+";

        String str4 = "abc.[12][123][1234]a";
        String regex4 = "(\\[[0-9]+\\])+";

        this.testFindReference(str1, regex1, "[12]");
        this.testFindReference(str2, regex2, "[12][123]");
        this.testFindReference(str3, regex3, "[12][123][1234]");
        this.testFindReference(str4, regex4, null);
    }

    /**
     * Tests the logic of a regex match.
     */
    private void testRegexMatch(String str, String regex) {
        Pattern pattern = Pattern.compile(regex);

        Matcher matcher = pattern.matcher(str);

        if (matcher.matches()) {
            int numberOfGroups = matcher.groupCount();

            for (int i = 0; i < numberOfGroups; ++i) {
                int groupIndex = i + 1;
                String group = matcher.group(groupIndex);

                int groupStartIndex = matcher.start(groupIndex);
                int groupEndIndex = matcher.end(groupIndex) - 1;

                String groupContent = str.substring(groupStartIndex, groupEndIndex + 1);

                this.assertion.assertEquals(
                    group,
                    groupContent,
                    "Incorrect regex match logic.");
            }
        }
    }

    /**
     * Tests the logic of finding a reference.
     */
    private void testFindReference(
        String str,
        String regex,
        String expectedResult) {

        Pattern pattern = Pattern.compile(regex);

        Matcher matcher = pattern.matcher(str);

        int referenceStartIndex = - 1;
        int referenceEndIndex = -1;

        int currIndex = 0;
        while (currIndex < str.length() && matcher.find(currIndex)) {
            int groupStartIndex = matcher.start(0);
            int groupEndIndex = matcher.end(0) - 1;

            if (referenceStartIndex == -1) {
                referenceStartIndex = groupStartIndex;
                referenceEndIndex = groupEndIndex;
            }
            else if (groupStartIndex == referenceEndIndex + 1) {
                referenceEndIndex = groupEndIndex;
            }
            else {
                referenceStartIndex = -1;
                referenceEndIndex = -1;
                break;
            }

            currIndex = referenceEndIndex + 1;
        }

        int referenceLength = Indexes.size(referenceStartIndex, referenceEndIndex);

        String result = null;
        if (referenceLength > 0 && referenceEndIndex == str.length() - 1) {
            result = str.substring(referenceStartIndex, referenceEndIndex + 1);
        }

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect matching logic of a reference.");
    }
}
