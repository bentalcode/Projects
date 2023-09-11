package urireadercommand.core;

import base.core.ArrayLists;
import base.core.Matrix;
import base.core.TableWriter;
import base.interfaces.IMatrix;
import base.interfaces.IPair;
import base.interfaces.ITableWriter;
import basicio.core.HtmlParagraphReader;
import basicio.core.HtmlParagraphParser;
import basicio.interfaces.IHtmlParagraphParser;
import basicio.interfaces.IHtmlStatistics;
import basicio.interfaces.IParagraphReader;
import command.core.AbstractCommand;
import base.interfaces.IMessageWriter;
import java.util.List;
import java.util.Set;
import urireadercommand.interfaces.IUriReaderCommandParameters;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The UriReaderCommand class implements a command for reading an uri.
 */
public final class UriReaderCommand extends AbstractCommand {
    private IUriReaderCommandParameters parameters;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The UriReaderCommand constructor.
     */
    public UriReaderCommand() {
    }

    /**
     * Runs the command.
     */
    @Override
    public void run() {
        this.initialize();

        this.log.info("Reading from uri: " + this.parameters.getUri());

        IHtmlStatistics statistics = readUri(
            this.parameters.getUri(),
            this.parameters.getNumberOfMostlyUsedWords(),
            this.parameters.getExcludedWords());

        List<IPair<String, Integer>> mostlyUsedWords = statistics.getMostlyUsedWords();

        displayOutput(this.getMessageWriter(), mostlyUsedWords);
    }

    /**
     * Reads the uri.
     */
    private static IHtmlStatistics readUri(
        String uri,
        int mostlyUsedWords,
        Set<String> excludedWords) {

        IHtmlParagraphParser paragraphParser = new HtmlParagraphParser(
            mostlyUsedWords,
            excludedWords);

        IParagraphReader paragraphReader = new HtmlParagraphReader(uri);

        while (paragraphReader.hasNext()) {
            String paragraph = paragraphReader.next();

            paragraphParser.processParagraph(paragraph);
        }

        return paragraphParser.getHtmlStatistics();
    }

    /**
     * Initializes the command.
     */
    private void initialize() {
        this.parameters = new UriReaderCommandParameters(this.getParameters());
    }

    /**
     * Displays the output.
     */
    private static void displayOutput(
        IMessageWriter writer,
        List<IPair<String, Integer>> wordsData) {

        String wordColumn = "Word";
        String counterColumn = "# of occurrences";

        List<String> header = ArrayLists.make(wordColumn, counterColumn);

        int rowsSize = wordsData.size();
        int columnSize = header.size();

        IMatrix<String> data = new Matrix<>(rowsSize, columnSize);

        for (int rowIndex = 0; rowIndex < wordsData.size(); ++rowIndex) {
            IPair<String, Integer> wordData = wordsData.get(rowIndex);

            int columnIndex = 0;
            data.set(rowIndex, columnIndex, wordData.first());

            columnIndex = 1;
            data.set(rowIndex, columnIndex, String.valueOf(wordData.second()));
        }

        ITableWriter tableWriter = new TableWriter(writer.getErrorWriter());
        tableWriter.write(header, data);
    }
}
