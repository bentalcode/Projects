package canmessagegenerator.interfaces;

import java.sql.Time;
import java.time.Duration;
import java.time.Instant;

/**
 * The IMessageData interface defines the jitter message data.
 */
public interface IJitterMessageData {
    /**
     * Gets the transmission time.
     */
    Duration getTransmissionTime();

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
