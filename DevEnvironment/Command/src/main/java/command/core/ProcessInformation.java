package command.core;

import base.core.Conditions;
import command.interfaces.IProcessInformation;
import java.time.Duration;
import java.time.Instant;
import java.util.Optional;

/**
 * The ProcessInformation class implements an information of a process.
 */
public final class ProcessInformation implements IProcessInformation {
    private final ProcessHandle processHandle;

    /**
     * Gets the current process information.
     */
    public static IProcessInformation current() {
        return new ProcessInformation(ProcessHandle.current());
    }

    /**
     * The ProcessInformation constructor.
     */
    public ProcessInformation(ProcessHandle processHandle) {
        Conditions.validateNotNull(
            processHandle,
            "The process handle.");

        this.processHandle = processHandle;
    }

    /**
     * Gets the processId.
     */
    @Override
    public long processId() {
        return this.processHandle.pid();
    }

    /**
     * Gets the user of the process.
     */
    @Override
    public Optional<String> user() {
        return this.processHandle.info().user();
    }

    /**
     * Gets the arguments of the process.
     */
    @Override
    public Optional<String[]> arguments() {
        return this.processHandle.info().arguments();
    }

    /**
     * Gets the executable pathname of the process.
     */
    @Override
    public Optional<String> command() {
        return this.processHandle.info().command();
    }

    /**
     * Gets the command line of the process.
     */
    @Override
    public Optional<String> commandLine() {
        return this.processHandle.info().commandLine();
    }

    /**
     * Gets the start time of the process.
     */
    @Override
    public Optional<Instant> startTime() {
        return this.processHandle.info().startInstant();
    }

    /**
     * Gets the total cpu time of the process.
     */
    @Override
    public Optional<Duration> totalCpuTime() {
        return this.processHandle.info().totalCpuDuration();
    }
}
