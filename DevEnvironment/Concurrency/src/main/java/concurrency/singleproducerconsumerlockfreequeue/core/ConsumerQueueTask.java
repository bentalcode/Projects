package concurrency.singleproducerconsumerlockfreequeue.core;

import base.core.Conditions;
import base.interfaces.IReceiver;
import base.interfaces.IRunnable;
import concurrency.interfaces.IConcurrentQueue;
import concurrency.interfaces.IMessageQueueTrackingInformation;
import java.time.Duration;
import java.util.Optional;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ConsumerQueueTask class implements a task of a consumer of a queue.
 */
public final class ConsumerQueueTask<T> implements java.lang.Runnable {
    private final IRunnable runnable;
    private final IConcurrentQueue<T> queue;
    private final IReceiver<T> receiver;
    private final Object eventMessagePublished;
    private final Object eventMessageReceived;
    private final Duration shutdownPollingDuration;
    private final IMessageQueueTrackingInformation messageQueueTrackingInformation;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The ConsumerQueueTask constructor.
     */
    public ConsumerQueueTask(
        IRunnable runnable,
        IConcurrentQueue<T> queue,
        IReceiver<T> receiver,
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
            receiver,
            "The receiver to send the messages.");

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
        this.receiver = receiver;
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
            "The consumer thread has started." +
            " [Thread Id: " + threadId + ", Thread Name: " + threadName + "]";

        this.log.info(informationalMessage);
        System.out.println(informationalMessage);

        while (this.runnable.isRunning()) {

            synchronized (this.eventMessagePublished) {
                while (this.runnable.isRunning() && this.queue.empty()) {
                    try {
                        this.eventMessagePublished.wait(this.shutdownPollingDuration.toMillis());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }

            if (!this.runnable.isRunning()) {
                break;
            }

            Optional<T> currElement = this.queue.dequeue();
            boolean status = currElement.isPresent();
            assert (status);

            if (status) {
                this.receiver.receive(currElement.get());

                if (this.messageQueueTrackingInformation != null) {
                    this.messageQueueTrackingInformation.messageReceived();
                }

                synchronized (this.eventMessageReceived) {
                    this.eventMessageReceived.notify();
                }
            }
            else {
                String warningMessage =
                    "The ConsumerQueueTask failed to dequeue an element from" +
                    " a single producer consumer lock free queue.";

                this.log.warn(warningMessage);
            }
        }

        informationalMessage =
            "The consumer thread has ended." +
            " [Thread Id: " + threadId + ", Thread Name: " + threadName + "]";

        this.log.info(informationalMessage);
        System.out.println(informationalMessage);
    }
}
