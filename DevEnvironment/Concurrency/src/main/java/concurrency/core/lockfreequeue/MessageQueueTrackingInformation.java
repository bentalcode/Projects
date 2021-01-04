package concurrency.core.lockfreequeue;

import concurrency.interfaces.IMessageQueueTrackingInformation;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * The MessageQueueTrackingInformation class implements tracking information
 * of a message queue.
 */
public final class MessageQueueTrackingInformation implements IMessageQueueTrackingInformation {
    private final AtomicInteger numberOfMessagesPublished = new AtomicInteger();
    private final AtomicInteger numberOfMessagesReceived = new AtomicInteger();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The MessageQueueTrackingInformation constructor.
     */
    public MessageQueueTrackingInformation() {
    }

    /**
     * Marks that a new message published.
     */
    public void messagePublished() {
        int result = this.numberOfMessagesPublished.incrementAndGet();

        String informationalMessage = "Message Published: " + result;
        this.log.info(informationalMessage);
        System.out.println(informationalMessage);

        synchronized (this) {
            this.notify();
        }
    }

    /**
     * Marks that a new message received.
     */
    public void messageReceived() {
        int result = this.numberOfMessagesReceived.incrementAndGet();

        String informationalMessage = "Message Received: " + result;
        this.log.info(informationalMessage);
        System.out.println(informationalMessage);

        synchronized (this) {
            this.notify();
        }
    }

    /**
     * Gets the number Of messages published.
     */
    public int numberOfMessagesPublished() {
        return this.numberOfMessagesPublished.get();
    }

    /**
     * Gets the number Of messages received.
     */
    public int numberOfMessagesReceived() {
        return this.numberOfMessagesReceived.get();
    }
}
