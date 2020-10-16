package canmessagegenerator.interfaces;

import java.time.Duration;
import java.time.Instant;

/**
 * The IMessageGeneratorJitter interface defines a Jitter for messages.
 */
public interface IMessageJitter {
    /**
     * Registers a message.
     */
    void registerMessage(String messageName, Duration transmissionTime);

    /**
     * Unregisters a message.
     *
     * Returns true if the message got unregistered successfully from the Jitter.
     * Returns false if the message is not currently registered with the Jitter.
     */
    boolean unregisterMessage(String messageName);

    /**
     * Sets the sending time of a message.
     */
    void setMessageSendingTime(String messageName, Instant time);

    /**
     * Sets the receiving time of a message.
     */
    void setMessageReceivingTime(String messageName, Instant time);

    /**
     * Gets the jitter deviation.
     * J(i) = J(i-1) + (|D(i-1,i)| - J(i-1))/16
     */
    double getJitterDeviation(String messageName);

    /**
     * Gets the message data.
     */
    IJitterMessageData getMessageData(String messageName);
}
