package canmessagegeneratorcommand.interfaces;

import base.interfaces.IPair;
import java.time.Duration;
import java.util.List;

/**
 * The ICANMessageGeneratorCommandParameters interface defines parameters of
 * a Controller Area Network message generator command.
 */
public interface ICANMessageGeneratorCommandParameters {
    /**
     * Gets the duration of a drive session.
     */
    Duration getDriveSessionDuration();

    /**
     * Gets the messages frequencies.
     */
    List<IPair<String, Integer>> getMessagesFrequencies();
}
