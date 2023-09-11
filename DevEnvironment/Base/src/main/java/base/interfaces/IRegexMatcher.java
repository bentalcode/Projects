package base.interfaces;

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
    IPair<Integer, Matcher> firstMatch(String expression, List<Pattern> patterns);

    /**
     * Tries finding a first pattern match.
     */
    IPair<Integer, Matcher> tryFirstMatch(String expression, List<Pattern> patterns);
}
