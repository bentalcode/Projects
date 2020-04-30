package problems.core;

import base.core.ArrayLists;
import base.core.ListIterator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.ITextAlignment;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The TextAlignmentTest class implements tests for a text alignment problem.
 */
public final class TextAlignmentTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The TextAlignmentTest constructor.
     */
    public TextAlignmentTest() {
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
     * Tests the logic of a text alignment.
     */
    @Test
    public void textAlignmentTest() {
        String[] words1 = {"This", "is", "an", "example", "of", "text", "alignment."};
        int maxWidth1 = 16;
        List<String> result1 = ArrayLists.of(
            "This    is    an",
            "example  of text",
            "alignment.      ");

        String[] words2 = {"This", "is", "a", "unit", "test", "for", "a", "text", "alignment."};
        int maxWidth2 = 16;
        List<String> result2 = ArrayLists.of(
            "This  is  a unit",
            "test  for a text",
            "alignment.      ");

        String[] words3 = {"This", "is", "another", "unit", "test", "for", "a", "text", "alignment."};
        int maxWidth3 = 16;
        List<String> result3 = ArrayLists.of(
            "This  is another",
            "unit  test for a",
            "text alignment. ");

        this.testTextAlignment(
            words1,
            maxWidth1,
            result1);

        this.testTextAlignment(
            words2,
            maxWidth2,
            result2);

        this.testTextAlignment(
            words3,
            maxWidth3,
            result3);
    }

    /**
     * Tests the logic of a text alignment.
     */
    private void testTextAlignment(
        String[] words,
        int maxWidth,
        List<String> expectedResult) {

        ITextAlignment textAlignment = new TextAlignment();
        List<String> result = textAlignment.align(words, maxWidth);

        this.assertion.assertEqualsWithIterators(
            ListIterator.of(result),
            ListIterator.of(expectedResult),
            "Incorrect logic for aligning text.");
    }
}
