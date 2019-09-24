package testbase.core;

import base.core.ArrayLists;
import base.core.Pair;
import base.core.Paths;
import base.core.ResourcePathBuilder;
import base.interfaces.IPair;
import base.interfaces.ITestData;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DataDirectoryName = "data";
    private static final String PrimesDirectoryName = "primes";
    private static final String PrimesFileName = "primes.txt";

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets path of a primes resource.
     */
    @Override
    public Path getPrimesResourcePath() {
        Path path = this.createResourcePath(
            TestData.DataDirectoryName,
            TestData.PrimesDirectoryName,
            TestData.PrimesFileName);

        return path;
    }

    /**
     * Gets values of integer-string.
     */
    @Override
    public List<IPair<Integer, String>> getIntegerStrings() {
        List<IPair<Integer, String>> values = new ArrayList<>();

        values.add(Pair.of(0, "0"));
        values.add(Pair.of(101, "101"));
        values.add(Pair.of(-2222, "-2222"));
        values.add(Pair.of(2222, "2222"));
        values.add(Pair.of(22222222, "22222222"));

        return values;
    }

    /**
     * Gets all sequence sub strings of a string.
     */
    @Override
    public List<IPair<String, List<List<String>>>> getAllSequenceSubStringsOfString() {
        List<IPair<String, List<List<String>>>> result = new ArrayList<>();

        result.add(this.getAllSequenceSubStringsOfString1());
        result.add(this.getAllSequenceSubStringsOfString2());
        result.add(this.getAllSequenceSubStringsOfString3());

        return result;
    }

    /**
     * Creates a path of a resource.
     */
    private Path createResourcePath(
        String rootDirectory,
        String subDirectory,
        String resourceName) {

        String path = new ResourcePathBuilder()
            .addComponent(rootDirectory)
            .addComponent(subDirectory)
            .addComponent(resourceName)
            .build();

        return Paths.create(path);
    }

    /**
     * Gets all sequence sub strings of a string1.
     */
    private IPair<String, List<List<String>>> getAllSequenceSubStringsOfString1() {
        String input = "";
        return Pair.of(input, new ArrayList<>());
    }

    /**
     * Gets all sequence sub strings of a string2.
     */
    private IPair<String, List<List<String>>> getAllSequenceSubStringsOfString2() {
        String input = "abc";

        List<List<String>> allSequenceSubStrings = new ArrayList<>();
        allSequenceSubStrings.add(ArrayLists.of("abc"));
        allSequenceSubStrings.add(ArrayLists.of("a", "bc"));
        allSequenceSubStrings.add(ArrayLists.of("ab", "c"));
        allSequenceSubStrings.add(ArrayLists.of("a", "b", "c"));

        return Pair.of(input, allSequenceSubStrings);
    }

    /**
     * Gets all sequence sub strings of a string3.
     */
    private IPair<String, List<List<String>>> getAllSequenceSubStringsOfString3() {
        String input = "abcd";

        List<List<String>> allSequenceSubStrings = new ArrayList<>();
        allSequenceSubStrings.add(ArrayLists.of("abcd"));
        allSequenceSubStrings.add(ArrayLists.of("a", "bcd"));
        allSequenceSubStrings.add(ArrayLists.of("ab", "cd"));
        allSequenceSubStrings.add(ArrayLists.of("a", "b", "cd"));
        allSequenceSubStrings.add(ArrayLists.of("abc", "d"));
        allSequenceSubStrings.add(ArrayLists.of("a", "bc", "d"));
        allSequenceSubStrings.add(ArrayLists.of("ab", "c", "d"));
        allSequenceSubStrings.add(ArrayLists.of("a", "b", "c", "d"));

        return Pair.of(input, allSequenceSubStrings);
    }
}
