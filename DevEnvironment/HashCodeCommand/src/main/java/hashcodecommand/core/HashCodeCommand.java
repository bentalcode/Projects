package hashcodecommand.core;

import base.core.ArrayLists;
import basicio.core.FilePathScanner;
import basicio.interfaces.IContentProvider;
import basicio.interfaces.IFilePathScanner;
import hashcodecommand.interfaces.IHashCodeParameters;
import hashcodecommand.interfaces.IHashCodeFileUpdater;
import command.core.AbstractCommand;
import java.nio.file.Path;
import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CHeaderCommand class implements a command for c-headers.
 */
public final class HashCodeCommand extends AbstractCommand {
    private IHashCodeParameters parameters;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CHeaderCommand constructor.
     */
    public HashCodeCommand() {
    }

    /**
     * Runs the command.
     */
    @Override
    public void run() {
        this.initialize();

        IContentProvider hashCodeProvider = new HashCodeProvider(this.parameters.getInitialPrime());

        if (this.parameters.getDirectoryPath() != null) {
            this.processDirectory(this.parameters.getDirectoryPath(), hashCodeProvider);
        }
        else if (this.parameters.getFilePath() != null) {
            this.processFile(this.parameters.getFilePath(), hashCodeProvider);
        }
    }

    /**
     * Processes a directory.
     */
    private void processDirectory(
        Path directory,
        IContentProvider hashCodeProvider) {

        this.log.info("Processing files at directory: " + directory);

        IFilePathScanner scanner = new FilePathScanner();
        List<String> extensions = ArrayLists.of("java");

        List<Path> filePaths = scanner.scan(directory, extensions);

        for (Path filePath : filePaths) {
            this.processFile(filePath, hashCodeProvider);
        }
    }

    /**
     * Processes a file.
     */
    private boolean processFile(
        Path filePath,
        IContentProvider hashCodeProvider) {

        this.log.info("Processing file: " + filePath);

        IHashCodeFileUpdater fileUpdater = new HashCodeFileUpdater(filePath, hashCodeProvider);

        long numberOfLinesUpdated = fileUpdater.update();

        if (numberOfLinesUpdated == - 1) {
            String warningMessage =
                "The hash-codes of file: " + filePath + " can not get updated." +
                "; Skipping update of this file header.";

            this.log.warn(warningMessage);

            return false;
        }
        else if (numberOfLinesUpdated >= 1) {
            String informationalMessage = "The hash code of file: " + filePath + " got updated.";
            this.log.info(informationalMessage);
        }

        return true;
    }

    /**
     * Initializes the command.
     */
    private void initialize() {
        this.parameters = new HashCodeCommandParameters(this.getInformation().getParameters());
    }
}
