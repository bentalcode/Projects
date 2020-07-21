package basicio.interfaces;

import base.interfaces.IPair;
import java.util.List;
import java.util.Map;

/**
 * The IHtmlStatistics interface defines statistics of an html.
 */
public interface IHtmlStatistics {
    /**
     * Get the mostly-used words.
     */
    List<IPair<String, Integer>> getMostlyUsedWords();

    /**
     * Get the words usage counter.
     */
    Map<String, Integer> getWordsUsageCounter();
}
