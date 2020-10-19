package canmessagegenerator.interfaces;

import java.time.Duration;
import java.time.Instant;

/**
 * The IJitterMessageData interface defines the message data for Jitter.
 */
public interface IJitterMessageData {
    /**
     * Gets the transmitting time.
     */
    Duration getTransmittingTime();

    /**
     * Gets the last sending time of a message.
     */
    Instant getMessageLastSendingTime();

    /**
     * Sets the last sending time of a message.
     */
    void setMessageLastSendingTime(Instant time);

    /**
     * Gets the number of messages sent.
     */
    long getNumberOfMessagesSent();

    /**
     * Gets the number of messages received.
     */
    long getNumberOfMessagesReceived();

    /**
     * Increments the number of messages sent.
     */
    void incrementNumberOfMessagesSent();

    /**
     * Increments the number of messages received.
     */
    void incrementNumberOfMessagesReceived();

    /**
     * Gets the Jitter deviation.
     */
    double getDeviation();

    /**
     * Sets the Jitter deviation.
     */
    void setDeviation(double deviation);
}
