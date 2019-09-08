package alphabeticalordercommand.core;

import alphabeticalordercommand.interfaces.ITestData;
import base.core.Pair;
import base.interfaces.IPair;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets the data of an alphabetical order.
     */
    @Override
    public List<IPair<List<String>, List<Character>>> getAlphabeticalOrderData() {
        List<IPair<List<String>, List<Character>>> result = new ArrayList<>();

        result.add(this.generateAlphabeticalOrderData3());

        return result;
    }

    /**
     * Gets alphabetical order strings.
     */
    private IPair<List<String>, List<Character>> generateAlphabeticalOrderData1() {
        List<String> alphabeticalStrings = new ArrayList<>();

        alphabeticalStrings.add("bca");
        alphabeticalStrings.add("aaa");
        alphabeticalStrings.add("acb");

        List<Character> alphabeticalOrder = List.of('b', 'a', 'c');

        return Pair.of(alphabeticalStrings, alphabeticalOrder);
    }

    /**
     * Gets alphabetical order strings.
     */
    private IPair<List<String>, List<Character>> generateAlphabeticalOrderData2() {
        List<String> alphabeticalStrings = new ArrayList<>();

        alphabeticalStrings.add("aab");
        alphabeticalStrings.add("aac");
        alphabeticalStrings.add("abc");

        List<Character> alphabeticalOrder = List.of('a', 'b', 'c');

        return Pair.of(alphabeticalStrings, alphabeticalOrder);
    }

    /**
     * Gets alphabetical order strings.
     */
    private IPair<List<String>, List<Character>> generateAlphabeticalOrderData3() {
        List<String> alphabeticalStrings = new ArrayList<>();

        alphabeticalStrings.add("aab");
        alphabeticalStrings.add("aac");
        alphabeticalStrings.add("bbb");
        alphabeticalStrings.add("bcb");
        alphabeticalStrings.add("bcd");
        alphabeticalStrings.add("bce");
        alphabeticalStrings.add("bde");

        List<Character> alphabeticalOrder = List.of('a', 'b', 'c', 'd', 'e');

        return Pair.of(alphabeticalStrings, alphabeticalOrder);
    }
}
