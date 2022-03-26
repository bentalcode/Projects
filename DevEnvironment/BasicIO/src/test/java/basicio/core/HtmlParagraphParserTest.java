package basicio.core;

import algorithms.core.Sorting;
import algorithms.interfaces.SortingOrder;
import base.core.ResourceReader;
import base.interfaces.IPair;
import basicio.interfaces.IHtmlParagraphParser;
import basicio.interfaces.IHtmlStatistics;
import basicio.interfaces.ITestData;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The HtmlParagraphParserTest class implements tests for parsing html paragraphs.
 */
public final class HtmlParagraphParserTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The HtmlParagraphParserTest constructor.
     */
    public HtmlParagraphParserTest() {
    }

    /**
     * Tests the logic for parsing html paragraph.
     */
    @Test
    public void parseHtmlParagraphTest() {
        IHtmlParagraphParser paragraphParser = new HtmlParagraphParser();

        for (Path path : this.testData.getParagraphResourcePaths()) {
            String paragraphContent = ResourceReader.loadString(path);

            this.testParseHtmlParagraph(
                paragraphParser,
                paragraphContent);
        }
    }

    /**
     * Tests the logic for parsing html paragraph.
     */
    private void testParseHtmlParagraph(
        IHtmlParagraphParser paragraphParser,
        String paragraphContent) {

        paragraphParser.processParagraph(paragraphContent);

        IHtmlStatistics statistics = paragraphParser.getHtmlStatistics();
        List<IPair<String, Integer>> mostlyUsedWords = statistics.getMostlyUsedWords();

        List<Integer> counters = new ArrayList<>(mostlyUsedWords.size());
        for (IPair<String, Integer> mostlyUsedWord : mostlyUsedWords) {
            counters.add(mostlyUsedWord.second());
        }

        this.assertion.assertTrue(
            Sorting.isSorted(counters, SortingOrder.Descending),
            "The word statistics is invalid.");

        this.assertion.assertTrue(
            statistics != null,
            "Incorrect logic of parsing a html paragraph");
    }
}
