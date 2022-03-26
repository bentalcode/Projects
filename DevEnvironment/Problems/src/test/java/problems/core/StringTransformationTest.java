package problems.core;

import base.core.ArrayLists;
import base.core.ListIterator;
import java.util.List;
import problems.interfaces.IEditInformation;
import problems.interfaces.IStringTransformation;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The StringTransformationTest class implements tests for a string transformation.
 */
public final class StringTransformationTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The StringTransformationTest constructor.
     */
    public StringTransformationTest() {
    }

    /**
     * Tests the logic of counting edits.
     */
    @Test
    public void countEditsTest() {
        String src1 = "success";
        String dest1 = "access";

        String src2 = "write";
        String dest2 = "read";

        String src3 = "calculator";
        String dest3 = "computer";

        this.testCountEdits(src1, dest1, 2);
        this.testCountEdits(src2, dest2, 4);
        this.testCountEdits(src3, dest3, 6);
    }

    /**
     * Tests the logic of calculating edits.
     */
    @Test
    public void calculateEditsTest() {
        String src1 = "success";
        String dest1 = "access";
        List<IEditInformation<Character>> result1 = ArrayLists.make(
            EditInformation.createReplace('s', 'a'),
            EditInformation.createRemove('u'),
            null,
            null,
            null,
            null,
            null);

        String src2 = "write";
        String dest2 = "read";
        List<IEditInformation<Character>> result2 = ArrayLists.make(
            EditInformation.createRemove('w'),
            null,
            EditInformation.createReplace('i', 'e'),
            EditInformation.createReplace('t', 'a'),
            EditInformation.createReplace('e', 'd'));

        String src3 = "calculator";
        String dest3 = "computer";
        List<IEditInformation<Character>> result3 = ArrayLists.make(
            null,
            EditInformation.createReplace('a', 'o'),
            EditInformation.createReplace('l', 'm'),
            EditInformation.createReplace('c', 'p'),
            null,
            EditInformation.createRemove('l'),
            EditInformation.createRemove('a'),
            null,
            EditInformation.createReplace('o', 'e'),
            null);

        this.testCalculateEdits(src1, dest1, result1);
        this.testCalculateEdits(src2, dest2, result2);
        this.testCalculateEdits(src3, dest3, result3);
    }

    /**
     * Tests the logic of counting edits.
     */
    private void testCountEdits(
        String src,
        String dest,
        int expectedResult) {

        IStringTransformation stringTransformation = new StringTransformation();
        int result = stringTransformation.countEdits(
            src,
            dest);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Invalid logic of counting edits.");
    }

    /**
     * Tests the logic of calculating edits.
     */
    private void testCalculateEdits(
        String src,
        String dest,
        List<IEditInformation<Character>> expectedEdits) {

        IStringTransformation stringTransformation = new StringTransformation();
        List<IEditInformation<Character>> edits = stringTransformation.calculateEdits(
            src,
            dest);

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(edits),
            ListIterator.make(expectedEdits),
            "Invalid logic of calculating edits.");
    }
}
