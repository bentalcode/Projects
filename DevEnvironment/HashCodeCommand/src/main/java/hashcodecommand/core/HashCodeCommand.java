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
        List<String> extensions = ArrayLists.of("java");

        List<Path> filePaths = scanner.scan(directory, extensions);

        for (Path filePath : filePaths) {
            processFile(filePath);
        }
    }

    /**
     * Processes a file.
     */
    private boolean processFile(Path filePath) {
        IContentProvider hashCodeProvider = new HashCodeProvider();
        IHashCodeFileUpdater fileUpdater = new HashCodeFileUpdater(filePath, hashCodeProvider);

        long numberOfLinesUpdated = fileUpdater.update();

        if (numberOfLinesUpdated == - 1) {
            String warningMessage =
                "The hash-codes of file: " + filePath + " can not get updated." +
                "; Skipping update of this file header.";

            this.log.warn(warningMessage);

            return false;
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
