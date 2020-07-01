package cheadercommand.core;

import cheadercommand.interfaces.ICHeaderCommandParameters;
import cheadercommand.interfaces.IFileUpdater;
import command.core.AbstractCommand;
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

        if (this.parameters.getFilePath() != null) {
            IFileUpdater fileUpdater = new CHeaderFileUpdater(this.parameters.getFilePath());
            fileUpdater.update();
        }
    }

    /**
     * Initializes the command.
     */
    private void initialize() {
        this.parameters = new CHeaderCommandParameters(this.getInformation().getParameters());
    }
}
