package basicio.core;

import base.core.Conditions;
import base.interfaces.IPair;
import basicio.interfaces.IHtmlStatistics;
import java.util.List;
import java.util.Map;

/**
 * The HtmlStatistics class implements statistics of a html.
 */
public final class HtmlStatistics implements IHtmlStatistics {
    private final Map<String, Integer> wordsUsageCounter;
    private final List<IPair<String, Integer>> mostUsageWords;

    /**
     * The HtmlStatistics constructor.
     */
    public HtmlStatistics(
        Map<String, Integer> wordsUsageCounter,
        List<IPair<String, Integer>> mostUsageWords) {

        Conditions.validateNotNull(
            wordsUsageCounter,
            "The usage counter of words.");

        Conditions.validateNotNull(
            mostUsageWords,
            "The list of most usage words.");

        this.wordsUsageCounter = wordsUsageCounter;
        this.mostUsageWords = mostUsageWords;
    }

    /**
     * Get the words' usage counter.
     */
    @Override
    public Map<String, Integer> getWordsUsageCounter() {
        return this.wordsUsageCounter;
    }

    /**
     * Get the mostly-used words.
     */
    @Override
    public List<IPair<String, Integer>> getMostlyUsedWords() {
        return this.mostUsageWords;
    }
}
