package canmessagegenerator.core;

import canmessagegenerator.interfaces.IJitterMessageData;
import java.time.Duration;
import java.time.Instant;

/**
 * The JitterMessageData class implements the jitter message data.
 */
public final class JitterMessageData implements IJitterMessageData {
    private static final String transmissionTimeText = "TransmissionTime:";
    private static final String deviationText = "Deviation:";
    private static final String numberOfMessagesSentText = "numberOfMessagesSent:";
    private static final String numberOfMessagesReceivedText = "numberOfMessagesReceived:";

    private final Duration transmissionTime;
    private Instant lastSendingTime;
    private long numberOfMessagesSent;
    private long numberOfMessagesReceived;
    private double deviation;

    /**
     * The JitterMessageData constructor.
     */
    public JitterMessageData(Duration transmissionTime) {
        this.transmissionTime = transmissionTime;
    }

    /**
     * Gets the transmission time.
     */
    @Override
    public Duration getTransmissionTime() {
        return this.transmissionTime;
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
            .append(transmissionTimeText).append(" ").append(this.transmissionTime)
            .append(", " )
            .append(deviationText).append(" ").append(this.deviation)
            .append(", " )
            .append(numberOfMessagesSentText).append(" ").append(this.numberOfMessagesSent)
            .append(", " )
            .append(numberOfMessagesReceivedText).append(" ").append(this.numberOfMessagesReceived);

        return result.toString();
    }
}
