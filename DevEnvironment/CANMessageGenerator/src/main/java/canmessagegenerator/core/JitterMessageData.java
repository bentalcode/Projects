package canmessagegenerator.core;

import canmessagegenerator.interfaces.IJitterMessageData;
import java.time.Duration;
import java.time.Instant;

/**
 * The JitterMessageData class implements the jitter message data.
 */
public final class JitterMessageData implements IJitterMessageData {
    private static final String transmittingTimeText = "TransmittingTime:";
    private static final String deviationText = "Deviation:";
    private static final String numberOfMessagesSentText = "numberOfMessagesSent:";
    private static final String numberOfMessagesReceivedText = "numberOfMessagesReceived:";

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
        StringBuilder result = new StringBuilder();

        result
            .append(transmittingTimeText).append(" ").append(this.transmittingTime)
            .append(", " )
            .append(deviationText).append(" ").append(this.deviation)
            .append(", " )
            .append(numberOfMessagesSentText).append(" ").append(this.numberOfMessagesSent)
            .append(", " )
            .append(numberOfMessagesReceivedText).append(" ").append(this.numberOfMessagesReceived);

        return result.toString();
    }
}
