package base.interfaces;

import base.core.Pair;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The IRegexMatcher interface defines a regex matcher.
 */
public interface IRegexMatcher {
    /**
     * Finds a first pattern match.
     */
    Pair<Integer, Matcher> firstMatch(String expression, List<Pattern> patterns);

    /**
     * Tries finding a first pattern match.
     */
    Pair<Integer, Matcher> tryFirstMatch(String expression, List<Pattern> patterns);
}
