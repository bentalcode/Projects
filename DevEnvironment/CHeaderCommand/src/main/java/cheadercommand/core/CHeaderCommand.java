package cheadercommand.core;

import base.core.ArrayLists;
import basicio.core.FilePathScanner;
import basicio.interfaces.IFilePathScanner;
import cheadercommand.interfaces.ICHeaderCommandParameters;
import cheadercommand.interfaces.IFileUpdater;
import command.core.AbstractCommand;
import java.nio.file.Path;
import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CHeaderCommand class implements a command for c-headers.
 */
public final class CHeaderCommand extends AbstractCommand {
    private ICHeaderCommandParameters parameters;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CHeaderCommand constructor.
     */
    public CHeaderCommand() {
    }

    /**
     * Runs the command.
     */
    @Override
    public void run() {
        this.initialize();

        if (this.parameters.getDirectoryPath() != null) {
            this.log.info("Processing files at directory: " + this.parameters.getDirectoryPath());
            this.processDirectory(this.parameters.getDirectoryPath());
        }
        else if (this.parameters.getFilePath() != null) {
            this.log.info("Processing file: " + this.parameters.getFilePath());
            this.processFile(this.parameters.getFilePath());
        }
    }

    /**
     * Processes a directory.
     */
    private void processDirectory(Path directory) {
        IFilePathScanner scanner = new FilePathScanner();
        List<String> extensions = ArrayLists.make("h", "hpp");

        List<Path> filePaths = scanner.scan(directory, extensions);

        for (Path filePath : filePaths) {
            processFile(filePath);
        }
    }

    /**
     * Processes a file.
     */
    private void processFile(Path filePath) {
        IFileUpdater fileUpdater = new CHeaderFileUpdater(filePath);

        long numberOfLinesUpdated = fileUpdater.update();

        if (numberOfLinesUpdated == - 1) {
            String warningMessage =
                "The header of file: " + filePath + " can not get updated." +
                "; Skipping update of this file header.";

            this.log.warn(warningMessage);
        }
    }

    /**
     * Initializes the command.
     */
    private void initialize() {
        this.parameters = new CHeaderCommandParameters(this.getParameters());
    }
}
