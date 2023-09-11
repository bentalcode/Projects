package concurrency.singleproducerconsumerlockfreequeue.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import base.interfaces.IRunnable;
import concurrency.interfaces.IConcurrentQueue;
import concurrency.interfaces.IMessageQueueTrackingInformation;
import java.time.Duration;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ProducerQueueTask class implements a task of a producer of a queue.
 */
public final class ProducerQueueTask<T> implements Runnable {
    private final IRunnable runnable;
    private final IConcurrentQueue<T> queue;
    private final IIterator<T> dataIterator;
    private final Object eventMessagePublished;
    private final Object eventMessageReceived;
    private final Duration shutdownPollingDuration;
    private final IMessageQueueTrackingInformation messageQueueTrackingInformation;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The ProducerQueueTask constructor.
     */
    public ProducerQueueTask(
        IRunnable runnable,
        IConcurrentQueue<T> queue,
        IIterator<T> dataIterator,
        Object eventMessagePublished,
        Object eventMessageReceived,
        Duration shutdownPollingDuration,
        IMessageQueueTrackingInformation messageQueueTrackingInformation) {

        Conditions.validateNotNull(
            runnable,
            "The runnable object.");

        Conditions.validateNotNull(
            queue,
            "The concurrent queue.");

        Conditions.validateNotNull(
            dataIterator,
            "The iterator of data.");

        Conditions.validateNotNull(
            eventMessagePublished,
            "The message published event.");

        Conditions.validateNotNull(
            eventMessageReceived,
            "The message received event.");

        Conditions.validateNotNull(
            shutdownPollingDuration,
            "The polling duration during shutdown.");

        this.runnable = runnable;
        this.queue = queue;
        this.dataIterator = dataIterator;
        this.eventMessagePublished = eventMessagePublished;
        this.eventMessageReceived = eventMessageReceived;
        this.shutdownPollingDuration = shutdownPollingDuration;
        this.messageQueueTrackingInformation = messageQueueTrackingInformation;
    }

    /**
     * The thread main entry point.
     */
    @Override
    public void run() {
        long threadId = Thread.currentThread().getId();
        String threadName = Thread.currentThread().getName();

        String informationalMessage =
            "The producer thread has started." +
            " [Thread Id: " + threadId + ", Thread Name: " + threadName + "]";

        this.log.info(informationalMessage);
        System.out.println(informationalMessage);

        while (this.runnable.isRunning() &&
               this.dataIterator.hasNext()) {

            T currElement = this.dataIterator.next();

            synchronized (this.eventMessageReceived) {

                while (this.runnable.isRunning() && this.queue.size() == this.queue.getCapacity()) {
                    try {
                        this.eventMessageReceived.wait(this.shutdownPollingDuration.toMillis());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }

            if (!this.runnable.isRunning()) {
                break;
            }

            this.queue.enqueue(currElement);

            if (this.messageQueueTrackingInformation != null) {
                this.messageQueueTrackingInformation.messagePublished();
            }

            synchronized (this.eventMessagePublished) {
                this.eventMessagePublished.notify();
            }
        }

        informationalMessage =
            "The producer thread has ended." +
            " [Thread Id: " + threadId + ", Thread Name: " + threadName + "]";

        this.log.info(informationalMessage);
        System.out.println(informationalMessage);
    }
}
