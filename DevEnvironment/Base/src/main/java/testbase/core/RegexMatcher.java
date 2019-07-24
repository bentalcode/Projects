package testbase.core;

import base.interfaces.IRegexMatcher;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The RegexMatcher class implements regex matcher.
 */
public final class RegexMatcher implements IRegexMatcher {
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The RegexMatcher constructor.
     */
    public RegexMatcher() {
    }

    /**
     * Finds a first pattern match.
     */
    @Override
    public Pair<Integer, Matcher> firstMatch(String expression, List<Pattern> patterns) {
        Pair<Integer, Matcher> result = this.tryFirstMatch(expression, patterns);

        if (result == null) {
            String errorMessage = "No pattern was found for matching an expression: " + expression;

            log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return result;
    }

    /**
     * Tries finding a first pattern match.
     */
    @Override
    public Pair<Integer, Matcher> tryFirstMatch(String expression, List<Pattern> patterns) {
        Conditions.validateNotNull(
            expression,
            "The expression.");

        Conditions.validateNotNull(
            patterns,
            "The list of patterns to match.");

        int index = 0;
        for (Pattern pattern : patterns) {
            Matcher matcher = pattern.matcher(expression);

            if (matcher.matches()) {
                return new Pair<>(index, matcher);
            }

            ++index;
        }

        return null;
    }
}
