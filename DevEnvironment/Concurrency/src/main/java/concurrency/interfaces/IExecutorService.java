package concurrency.interfaces;

import java.util.concurrent.Future;

/**
 * The IExecutorService interface defines an executor service.
 */
public interface IExecutorService {
    /**
     * Executes a new task.
     */
    void execute(Runnable task);

    /**
     * Submits a new task.
     */
    Future<?> submit(Runnable task);

    /**
     * Shutdowns an executor.
     */
    void shutdown();
}
