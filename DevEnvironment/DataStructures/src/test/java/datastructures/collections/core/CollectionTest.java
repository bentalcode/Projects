package datastructures.collections.core;

import base.core.Collections;
import base.core.ThreeDimensionalListIterator;
import base.interfaces.IPair;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;
import org.junit.Test;

/**
 * The CollectionTest class implements tests for collections.
 */
public final class CollectionTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The StringsTest constructor.
     */
    public CollectionTest() {
    }

    /**
     * Tests the logic of calculating all possible sequences of sub collections of a collection.
     */
    @Test
    public void calculateSequenceSubCollectionsOfCollectionTest() {
        List<IPair<List<Character>, List<List<List<Character>>>>> result =
            this.testData.getCollectionData().getAllSequenceSubCollectionsOfCollection();

        for (IPair<List<Character>, List<List<List<Character>>>> sequenceResult : result) {
            List<Character> collection = sequenceResult.first();
            List<List<List<Character>>> expectedResult = sequenceResult.second();

            this.calculateSequenceSubCollectionsOfCollectionTest(
                collection,
                expectedResult);
        }
    }

    /**
     * Tests the logic of calculating all possible sequences of sub collections of a collection.
     */
    private <T extends Comparable<T>> void calculateSequenceSubCollectionsOfCollectionTest(
        List<T> collection,
        List<List<List<T>>> expectedResult) {

        List<List<List<T>>> result = Collections.calculateSequenceSubCollectionsOfCollection(collection);

        this.assertion.assertEqualsWithIterators(
            ThreeDimensionalListIterator.make(result),
            ThreeDimensionalListIterator.make(expectedResult),
            "Incorrect logic for calculating all possible sequences of sub collections of a collection.");
    }
}
