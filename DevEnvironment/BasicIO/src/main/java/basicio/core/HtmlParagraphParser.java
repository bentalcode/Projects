package basicio.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayLists;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.Dimensions;
import base.core.Doublet;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.HashSets;
import base.core.Pair;
import base.core.Strings;
import base.interfaces.IDoublet;
import base.interfaces.IPair;
import basicio.interfaces.IHtmlParagraphParser;
import basicio.interfaces.IHtmlStatistics;
import basicio.interfaces.ILineReader;
import datastructures.heap.core.Heap;
import datastructures.priorityqueue.interfaces.IPriorityQueue;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The HtmlParagraphParser class implements a parser of html paragraph.
 */
public final class HtmlParagraphParser implements IHtmlParagraphParser {
    private static final int defaultMostlyUsedWordsCapacity = 10;

    private static final String tokenSeparatorRegex = "[( )]";
    private static final String referenceRegex = "(\\[[0-9]+\\])";
    private static final Pattern referencePattern = Pattern.compile(referenceRegex);
    private static final List<Character> sentenceSeparators = ArrayLists.make(',', '.', ';');
    private static final char specialToken = 65533;

    private final int mostlyUsedWordsCapacity;
    private final Set<String> excludedWords;
    private final List<String> words = new ArrayList<>();
    private final Map<String, Integer> wordCounterMap = new TreeMap<>();
    private final IPriorityQueue<IDoublet<String, Integer>> mostlyUsedWordsPriorityQueue;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The HtmlParagraphParser constructor.
     */
    public HtmlParagraphParser() {
        this(
            defaultMostlyUsedWordsCapacity,
            HashSets.make());
    }

    /**
     * The HtmlParagraphParser constructor.
     */
    public HtmlParagraphParser(
        int mostlyUsedWordsCapacity,
        Set<String> excludedWords) {

        Conditions.validate(
            mostlyUsedWordsCapacity >= 0,
            "The capacity of mostly-used words.");

        Conditions.validateNotNull(
            excludedWords,
            "The excluded words set.");

        this.mostlyUsedWordsCapacity = mostlyUsedWordsCapacity;
        this.excludedWords = excludedWords;
        this.mostlyUsedWordsPriorityQueue = Heap.createMinHeap(
            IDoublet.class,
            mostlyUsedWordsCapacity,
            new MostlyUsedWordComparator());
    }

    /**
     * Processes a paragraph.
     */
    @Override
    public void processParagraph(String content) {
        if (Strings.isNullOrEmpty(content)) {
            return;
        }

        ILineReader lineReader = LineReader.createStringLineReader(content);

        while (lineReader.hasNext()) {
            String line = lineReader.next();
            this.processLine(line);
        }
    }

    /**
     * Gets the html statistics.
     */
    @Override
    public IHtmlStatistics getHtmlStatistics() {
        //
        // Create the list of the mostly-used words...
        //
        List<IPair<String, Integer>> mostlyUsedWords = new ArrayList<>(this.mostlyUsedWordsPriorityQueue.size());

        for (IDoublet<String, Integer> element : this.mostlyUsedWordsPriorityQueue) {
            mostlyUsedWords.add(Pair.make(element.first(), element.second()));
        }

        Collections.sort(mostlyUsedWords, new Comparator<IPair<String, Integer>>() {
            @Override
            public int compare(IPair<String, Integer> left, IPair<String, Integer> right) {
                int leftCounter = left.second();
                int rightCounter = right.second();

                if (leftCounter < rightCounter) {
                    return 1;
                }

                if (leftCounter > rightCounter) {
                    return -1;
                }

                String leftWord = left.first();
                String rightWord = right.first();

                return leftWord.compareTo(rightWord);
            }
        });

        //
        // Create the html statistics...
        //
        return new HtmlStatistics(
            this.wordCounterMap,
            mostlyUsedWords);
    }

    /**
     * Processes a line.
     */
    public void processLine(String line) {
        if (Strings.isNullOrEmpty(line)) {
            return;
        }

        String[] tokens = line.split(tokenSeparatorRegex);

        for (String token : tokens) {
            this.processToken(token);
        }
    }

    /**
     * Processes a token.
     */
    private void processToken(String token) {
        if (Strings.isNullOrEmpty(token)) {
            return;
        }

        String subTokenSeparator = "[" + "(" + specialToken + ")" + "]";
        String[] subTokens = token.split(subTokenSeparator);

        for (String subToken : subTokens) {
            processSubToken(subToken);
        }
    }

    /**
     * Processes a sub-token.
     */
    private void processSubToken(String token) {
        if (Strings.isNullOrEmpty(token)) {
            return;
        }

        String word = this.parseWord(token);

        if (word != null) {
            this.processWord(word);
        }
    }

    /**
     * Parses a word.
     */
    private String parseWord(String token) {
        if (Strings.isNullOrEmpty(token)) {
            return null;
        }

        //
        // Remove parentheses...
        // Parentheses are: {(), [], {}}
        //
        String resultantToken = Strings.removeParentheses(token);

        if (Strings.isNullOrEmpty(resultantToken)) {
            return null;
        }

        //
        // Remove an end reference...
        // A reference expression is: (\[[0-9]+\])
        //
        resultantToken = removeReference(resultantToken);

        if (Strings.isNullOrEmpty(resultantToken)) {
            return null;
        }

        //
        // Remove sentence separators from front and end...
        // Sentence separators are: {',', '.', ';'}
        //
        resultantToken = this.removeSentenceSeparators(resultantToken);

        if (Strings.isNullOrEmpty(resultantToken)) {
            return null;
        }

        //
        // Remove parentheses...
        // Parentheses are: {(), [], {}}
        //
        resultantToken = Strings.removeParentheses(resultantToken);

        if (Strings.isNullOrEmpty(resultantToken)) {
            return null;
        }

        //
        // Remove quotation marks...
        // Quotation marks are: {', ""}
        //
        resultantToken = Strings.removeQuotationMarks(resultantToken);

        return resultantToken;
    }

    /**
     * Removes a reference from the end of token.
     */
    private String removeReference(String token) {
        if (Strings.isNullOrEmpty(token)) {
            return token;
        }

        Matcher matcher = referencePattern.matcher(token);

        int referenceStartIndex = - 1;
        int referenceEndIndex = -1;

        int currIndex = 0;
        while (currIndex < token.length() && matcher.find(currIndex)) {
            int groupStartIndex = matcher.start(0);
            int groupEndIndex = matcher.end(0) - 1;

            if (referenceStartIndex == -1) {
                referenceStartIndex = groupStartIndex;
                referenceEndIndex = groupEndIndex;
            }
            else if (groupStartIndex == referenceEndIndex + 1) {
                referenceEndIndex = groupEndIndex;
            }
            else {
                referenceStartIndex = -1;
                referenceEndIndex = -1;
                break;
            }

            currIndex = referenceEndIndex + 1;
        }

        int referenceLength = Dimensions.length(referenceStartIndex, referenceEndIndex);

        if (referenceLength > 0 && referenceEndIndex == token.length() - 1) {
            return token.substring(0, referenceStartIndex);
        }

        return token;
    }

    /**
     * Removes sentence separators from front and end.
     */
    private String removeSentenceSeparators(String token) {
        String resultantToken = Strings.removeFirstCharacter(token, sentenceSeparators);

        if (Strings.isNullOrEmpty(resultantToken)) {
            return null;
        }

        resultantToken = Strings.removeLastCharacter(resultantToken, sentenceSeparators);

        return resultantToken;
    }

    /**
     * Processes a word.
     */
    private void processWord(String word) {
        if (Strings.isNullOrEmpty(word) || this.excludedWords.contains(word)) {
            return;
        }

        //
        // Update the words array for debugging...
        //
        this.words.add(word);

        //
        // Update the word counter map...
        //
        int wordCounter = this.updateWordCounter(word);

        //
        // Update the priority queue of mostly-used words...
        //
        this.updateMostlyUsedWordsPriorityQueue(word, wordCounter);
    }

    /**
     * Updates the word counter.
     */
    private int updateWordCounter(String word) {
        int wordCounter = this.wordCounterMap.getOrDefault(word, 0);
        ++wordCounter;
        this.wordCounterMap.put(word, wordCounter);

        return wordCounter;
    }

    /**
     * Updates the priority queue of the mostly used words.
     */
    private void updateMostlyUsedWordsPriorityQueue(
        String word,
        int wordCounter) {

        //
        // Check whether to update the priority queue of mostly used words...
        //
        if (!this.updateMostlyUsedWordsPriorityQueue(wordCounter)) {
            return;
        }

        //
        // Update the priority queue of mostly used words...
        //
        IDoublet<String, Integer> newWordCounter = Doublet.make(word, wordCounter);

        int index = this.mostlyUsedWordsPriorityQueue.find(element -> element.first().equals(word));

        if (index == -1) {
            if (this.mostlyUsedWordsPriorityQueue.size() >= this.mostlyUsedWordsCapacity) {
                this.mostlyUsedWordsPriorityQueue.poll();
            }

            this.mostlyUsedWordsPriorityQueue.offer(newWordCounter);
        }
        else {
            this.mostlyUsedWordsPriorityQueue.updateAndHypifyDown(index, newWordCounter);
        }
    }

    /**
     * Checks whether to update the priority queue of mostly used words.
     */
    private boolean updateMostlyUsedWordsPriorityQueue(int wordCounter) {
        return
            (this.mostlyUsedWordsPriorityQueue.size() < this.mostlyUsedWordsCapacity) ||
            (!this.mostlyUsedWordsPriorityQueue.empty() && wordCounter > this.mostlyUsedWordsPriorityQueue.peek().second());
    }

    /**
     * The MostlyUsedWordComparator class implements a comparator of a priority queue.
     */
    private static final class MostlyUsedWordComparator extends AbstractBinaryComparator<IDoublet<String, Integer>> {
        /**
         * The MostlyUsedWordComparator constructor.
         */
        public MostlyUsedWordComparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IDoublet<String, Integer> obj) {
            return new HashCodeBuilder(647, 653)
                .withString(obj.first())
                .withInteger(obj.second())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IDoublet<String, Integer> lhs, IDoublet<String, Integer> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.first(), rhs.first())
                .withInteger(lhs.second(), rhs.second())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IDoublet<String, Integer> lhs, IDoublet<String, Integer> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withInteger(lhs.second(), rhs.second())
                .withString(lhs.first(), rhs.first())
                .build();
        }
    }
}
