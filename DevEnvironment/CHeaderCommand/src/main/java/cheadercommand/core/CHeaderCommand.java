package cheadercommand.core;

import cheadercommand.interfaces.ICHeaderCommandParameters;
import command.core.AbstractCommand;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CHeaderCommand class implements a command for c-headers.
 */
public final class CHeaderCommand extends AbstractCommand {
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
        ICHeaderCommandParameters parameters = new CHeaderCommandParameters(this.getInformation().getParameters());
    }
}
