package concurrency.core.lockfreequeue;

import base.core.AbstractRunnable;
import base.core.Conditions;
import base.interfaces.IIterator;
import base.interfaces.IReceiver;
import concurrency.core.ExecutorService;
import concurrency.interfaces.IConcurrentQueue;
import concurrency.interfaces.IExecutorService;
import concurrency.interfaces.IMessageQueueTrackingInformation;
import java.time.Duration;

/**
 * The ConcurrentSingleProducerConsumerLockFreeQueue class implements a
 * concurrent single producer consumer lock free queue.
 */
public final class ConcurrentSingleProducerConsumerLockFreeQueue<T> extends AbstractRunnable {
    private static final Duration defaultShutdownTimeout = Duration.ofSeconds(60);
    private static final Duration defaultShutdownPollingDuration = Duration.ofSeconds(1);

    private final IConcurrentQueue<T> queue;
    private final IExecutorService executorService;
    private final Object eventMessagePublished = new Object();
    private final Object eventMessageReceived = new Object();
    private final IMessageQueueTrackingInformation messageQueueTrackingInformation;
    private final Duration shutdownPollingDuration;

    /**
     * Creates a new concurrent single producer consumer lock free queue.
     */
    public static <T> ConcurrentSingleProducerConsumerLockFreeQueue<T> make(IConcurrentQueue<T> queue) {

        return new ConcurrentSingleProducerConsumerLockFreeQueue<>(
            queue,
            defaultShutdownTimeout,
            defaultShutdownPollingDuration,
            null);
    }

    /**
     * Creates a new concurrent single producer consumer lock free queue.
     */
    public static <T> ConcurrentSingleProducerConsumerLockFreeQueue<T> make(
        IConcurrentQueue<T> queue,
        IMessageQueueTrackingInformation messageQueueTrackingInformation) {

        return new ConcurrentSingleProducerConsumerLockFreeQueue<>(
            queue,
            defaultShutdownTimeout,
            defaultShutdownPollingDuration,
            messageQueueTrackingInformation);
    }

    /**
     * The ConcurrentSingleProducerConsumerLockFreeQueue constructor.
     */
    public ConcurrentSingleProducerConsumerLockFreeQueue(
        IConcurrentQueue<T> queue,
        Duration shutdownTimeout,
        Duration shutdownPollingDuration,
        IMessageQueueTrackingInformation messageQueueTrackingInformation) {

        Conditions.validateNotNull(
            queue,
            "The concurrent queue.");

        Conditions.validateNotNull(
            shutdownTimeout,
            "The shutdown timeout.");

        Conditions.validateNotNull(
            shutdownPollingDuration,
            "The shutdown polling duration.");

        this.queue = queue;
        this.executorService = ExecutorService.newFixedThreadPool(2, shutdownTimeout);
        this.shutdownPollingDuration = shutdownPollingDuration;
        this.messageQueueTrackingInformation = messageQueueTrackingInformation;
    }

    /**
     * Publishes data.
     */
    public void publish(IIterator<T> dataIterator) {
        Conditions.validateNotNull(
            dataIterator,
            "The data iterator.");

        Runnable task = new ProducerQueueTask<>(
            this,
            this.queue,
            dataIterator,
            this.eventMessagePublished,
            this.eventMessageReceived,
            this.shutdownPollingDuration,
            this.messageQueueTrackingInformation);

        this.executorService.execute(task);
    }

    /**
     * Subscribes for data.
     */
    public void subscribe(IReceiver<T> receiver) {

        Conditions.validateNotNull(
            receiver,
            "The data receiver.");

        Runnable task = new ConsumerQueueTask<>(
            this,
            this.queue,
            receiver,
            this.eventMessagePublished,
            this.eventMessageReceived,
            this.shutdownPollingDuration,
            this.messageQueueTrackingInformation);

        this.executorService.execute(task);
    }

    /**
     * Shutdowns the producer.
     */
    public void shutdown() {
        //
        // Signal the thread to shutdown gracefully...
        //
        super.shutdown();

        //
        // Shutdown the executor service...
        //
        this.executorService.shutdown();
    }
}
