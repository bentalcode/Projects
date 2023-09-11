package concurrency.interfaces;

/**
 * The IMessageQueueTrackingInformation interface defines tracking information of a message queue.
 */
public interface IMessageQueueTrackingInformation {
    /**
     * Marks that a new message published.
     */
    void messagePublished();

    /**
     * Marks that a new message received.
     */
    void messageReceived();

    /**
     * Gets the number Of messages published.
     */
    int numberOfMessagesPublished();

    /**
     * Gets the number Of messages received.
     */
    int numberOfMessagesReceived();
}
