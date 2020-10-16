package canmessagegenerator.core;

import base.core.CaseInsensitiveStringComparator;
import canmessagegenerator.CANMessageGeneratorException;
import canmessagegenerator.MessageJitterException;
import canmessagegenerator.interfaces.IJitterMessageData;
import canmessagegenerator.interfaces.IMessageJitter;
import java.time.Duration;
import java.time.Instant;
import java.util.Map;
import java.util.TreeMap;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The MessageGeneratorJitter class implements a Jitter for messages.
 */
public final class MessageJitter implements IMessageJitter {
    private final Map<String, IJitterMessageData> messageDataMap =
        new TreeMap<>(new CaseInsensitiveStringComparator());

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The MessageJitter constructor.
     */
    public MessageJitter() {
    }

    /**
     * Registers a message.
     */
    @Override
    public void registerMessage(String messageName, Duration transmissionTime) {
        if (this.messageDataMap.containsKey(messageName)) {
            String errorMessage =
                "The message type: " + messageName + " has already been registered with the Jitter.";

            this.log.error(errorMessage);
            throw new MessageJitterException(errorMessage);
        }

        IJitterMessageData messageData = new JitterMessageData(transmissionTime);
        this.messageDataMap.put(messageName, messageData);
    }

    /**
     * Unregisters a message.
     *
     * Returns true if the message got unregistered successfully from the Jitter.
     * Returns false if the message is not currently registered with the Jitter.
     */
    @Override
    public boolean unregisterMessage(String messageName) {
        if (!this.messageDataMap.containsKey(messageName)) {
            return false;
        }

        this.messageDataMap.remove(messageName);

        return true;
    }

    /**
     * Sets the sending time of a message.
     */
    @Override
    public void setMessageSendingTime(String messageName, Instant time) {
        IJitterMessageData data = this.getMessageData(messageName);

        data.setMessageLastSendingTime(time);
        data.incrementNumberOfMessagesSent();
    }

    /**
     * Sets the receiving time of a message.
     */
    @Override
    public void setMessageReceivingTime(String messageName, Instant time) {
        IJitterMessageData data = this.getMessageData(messageName);

        Instant sendingTime = data.getMessageLastSendingTime();

        if (sendingTime == null) {
            String errorMessage =
                "The sending time of message: " + messageName +
                " was not recorded with the Jitter.";

            this.log.error(errorMessage);
            throw new CANMessageGeneratorException(errorMessage);
        }

        data.incrementNumberOfMessagesReceived();

        //
        // Update the deviation...
        // J(i) = J(i-1) + (|D(i-1,i)| - J(i-1))/16
        //
        double prevDeviation = data.getDeviation();

        Duration currDuration = Duration.between(sendingTime, time);
        double currDeviation = currDuration.toMillis() - data.getTransmissionTime().toMillis();

        double deviation = prevDeviation + (Math.abs(currDeviation) - prevDeviation) / 16;

        data.setDeviation(deviation);
    }

    /**
     * Gets the jitter deviation.
     */
    @Override
    public double getJitterDeviation(String messageName) {
        IJitterMessageData data = this.getMessageData(messageName);

        return data.getDeviation();
    }

    /**
     * Gets the message data.
     */
    @Override
    public IJitterMessageData getMessageData(String messageName) {
        if (!this.messageDataMap.containsKey(messageName)) {
            String errorMessage = "The message: " + messageName + " is not registered with the Jitter.";

            this.log.error(errorMessage);
            throw new MessageJitterException(errorMessage);
        }

        return this.messageDataMap.get(messageName);
    }
}
