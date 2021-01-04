package concurrency.core;

import base.core.Conditions;
import concurrency.ConcurrencyException;
import concurrency.interfaces.IExecutorService;
import java.time.Duration;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ExecutorService class implements an executor service.
 */
public final class ExecutorService implements IExecutorService {
    private final java.util.concurrent.ExecutorService service;
    private final Duration shutdownTimeout;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * Creates a new single thread executor.
     */
    public static IExecutorService newSingleThreadExecutor(Duration shutdownTimeout) {
        java.util.concurrent.ExecutorService service = Executors.newSingleThreadExecutor();
        return new ExecutorService(service, shutdownTimeout);
    }

    /**
     * Creates a new fixed thread pool.
     */
    public static IExecutorService newFixedThreadPool(int numberOfThreads, Duration shutdownTimeout) {
        java.util.concurrent.ExecutorService service = Executors.newFixedThreadPool(numberOfThreads);
        return new ExecutorService(service, shutdownTimeout);
    }

    /**
     * The ExecutorService constructor.
     */
    private ExecutorService(
        java.util.concurrent.ExecutorService service,
        Duration shutdownTimeout) {

        Conditions.validateNotNull(
            service,
            "The executor service.");

        Conditions.validateNotNull(
            shutdownTimeout,
            "The shutdown timeout.");

        this.service = service;
        this.shutdownTimeout = shutdownTimeout;
    }

    /**
     * Executes a new task.
     */
    @Override
    public void execute(Runnable task) {
        this.service.execute(task);
    }

    /**
     * Submits a new task.
     */
    @Override
    public Future<?> submit(Runnable task) {
        return this.service.submit(task);
    }

    /**
     * Shutdowns an executor service.
     */
    @Override
    public void shutdown() {
        //
        // Shutdown the executor service...
        //
        this.service.shutdown();

        try {
            //
            // Waits for the executor service to terminate during the allowed timeout period...
            //
            if (!this.service.awaitTermination(this.shutdownTimeout.toMillis(), TimeUnit.MILLISECONDS)) {

                if (!service.isTerminated()) {
                    this.service.shutdownNow();
                }
                else {
                    String warningMessage =
                        "The Executor Service failed to shutdown during the shutdown period of: " + this.shutdownTimeout +
                        ", shutting down the executor.";

                    this.log.warn(warningMessage);
                }
            }
        }
        catch (InterruptedException e) {
            String errorMessage =
                "The Executor Service failed to shutdown during the shutdown period of: " + this.shutdownTimeout +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new ConcurrencyException(errorMessage);
        }
    }
}
