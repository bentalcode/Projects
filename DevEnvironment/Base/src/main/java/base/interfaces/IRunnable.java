package base.interfaces;

/**
 * The IRunnable interface defines a runnable.
 */
public interface IRunnable {
    /**
     * Checks whether an instance is in a running state.
     */
    boolean isRunning();

    /**
     * Checks whether an instance is in a shutdown state.
     */
    boolean isShutdown();

    /**
     * Shutdowns an instance.
     */
    void shutdown();
}
