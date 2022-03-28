package canmessagegenerator.core;

import canmessagegenerator.interfaces.IJitterMessageData;
import java.time.Duration;
import java.time.Instant;

/**
 * The JitterMessageData class implements the jitter message data.
 */
public final class JitterMessageData implements IJitterMessageData {
    private static final String TRANSMITTING_TIME_TEXT = "TransmittingTime:";
    private static final String DEVIATION_TEXT = "Deviation:";
    private static final String NUMBER_OF_MESSAGES_SENT_TEXT = "numberOfMessagesSent:";
    private static final String NUMBER_OF_MESSAGES_RECEIVED_TEXT = "numberOfMessagesReceived:";

    private final Duration transmittingTime;
    private Instant lastSendingTime;
    private long numberOfMessagesSent;
    private long numberOfMessagesReceived;
    private double deviation;

    /**
     * Creates a new message data.
     */
    public static IJitterMessageData make(Duration transmittingTime) {
        return new JitterMessageData(transmittingTime);
    }

    /**
     * The JitterMessageData constructor.
     */
    private JitterMessageData(Duration transmittingTime) {
        this.transmittingTime = transmittingTime;
    }

    /**
     * Gets the transmitting time.
     */
    @Override
    public Duration getTransmittingTime() {
        return this.transmittingTime;
    }

    /**
     * Gets the last sending time of a message.
     */
    @Override
    public Instant getMessageLastSendingTime() {
        return this.lastSendingTime;
    }

    /**
     * Sets the last sending time of a message.
     */
    @Override
    public void setMessageLastSendingTime(Instant time) {
        this.lastSendingTime = time;
    }

    /**
     * Gets the number of messages sent.
     */
    @Override
    public long getNumberOfMessagesSent() {
        return this.numberOfMessagesSent;
    }

    /**
     * Gets the number of messages received.
     */
    @Override
    public long getNumberOfMessagesReceived() {
        return this.numberOfMessagesReceived;
    }

    /**
     * Increments the number of messages sent.
     */
    @Override
    public void incrementNumberOfMessagesSent() {
        ++this.numberOfMessagesSent;
    }

    /**
     * Increments the number of messages received.
     */
    @Override
    public void incrementNumberOfMessagesReceived() {
        ++this.numberOfMessagesReceived;
    }

    /**
     * Gets the Jitter deviation.
     */
    @Override
    public double getDeviation() {
        return this.deviation;
    }

    /**
     * Sets the Jitter deviation.
     */
    @Override
    public void setDeviation(double deviation) {
        this.deviation = deviation;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return
            TRANSMITTING_TIME_TEXT + " " + this.transmittingTime +
            ", " +
            DEVIATION_TEXT + " " + this.deviation +
            ", " +
            NUMBER_OF_MESSAGES_SENT_TEXT + " " + this.numberOfMessagesSent +
            ", " +
            NUMBER_OF_MESSAGES_RECEIVED_TEXT + " " + this.numberOfMessagesReceived;
    }
}
