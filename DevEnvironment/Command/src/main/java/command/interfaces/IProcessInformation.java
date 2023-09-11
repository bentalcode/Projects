package command.interfaces;

import java.time.Duration;
import java.time.Instant;
import java.util.Optional;

/**
 * The IProcessInformation interface defines an information of a process.
 */
public interface IProcessInformation {
    /**
     * Gets the processId.
     */
    long processId();

    /**
     * Gets the user of the process.
     */
    Optional<String> user();

    /**
     * Gets the arguments of the process.
     */
    Optional<String[]> arguments();

    /**
     * Gets the executable pathname of the process.
     */
    Optional<String> command();

    /**
     * Gets the command line of the process.
     */
    Optional<String> commandLine();

    /**
     * Gets the start time of the process.
     */
    Optional<Instant> startTime();

    /**
     * Gets the total cpu time of the process.
     */
    Optional<Duration> totalCpuTime();
}
