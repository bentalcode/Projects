package base.core;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the logic of a regex.
     */
    @Test
    public void testRegex() {
        String str1 = "            return new HashCodeBuilder1(3, 5)";
        String regex1 = "(.*)(new HashCodeBuilder1)(\\([0-9]*, [0-9]*\\))(.*)";

        String str2 = "             IHashCodeBuilder hashCodeBuilder = new HashCodeBuilder1(3, 5);";
        String regex2 = "(.*)(new HashCodeBuilder1)(\\([0-9]*, [0-9]*\\))(.*)";

        this.testRegex(str1, regex1);
        this.testRegex(str2, regex2);
    }

    private void testRegex(String str, String regex) {
        Pattern pattern = Pattern.compile(regex);

        Matcher matcher = pattern.matcher(str);

        if (matcher.matches()) {
            int numberOfGroups = matcher.groupCount();

            for (int i = 0; i < numberOfGroups; ++i) {
                int groupIndex = i + 1;
                String group = matcher.group(groupIndex);

                int groupStartIndex = matcher.start(groupIndex);
                int groupEndIndex = matcher.end(groupIndex);

                String groupContent = str.substring(groupStartIndex, groupEndIndex);

                this.assertion.assertEquals(
                    group,
                    groupContent,
                    "Incorrect regex logic.");
            }
        }
    }
}
