package canmessagegeneratorcommand.core;

import base.core.Threads;
import base.interfaces.IPair;
import canmessagegenerator.core.CANMessageRuleGenerator;
import canmessagegenerator.core.JitterMessageHandler;
import canmessagegenerator.interfaces.ICANMessageRule;
import canmessagegenerator.interfaces.ICANRuleGenerator;
import canmessagegenerator.interfaces.ICANSignalRule;
import canmessagegenerator.interfaces.IJitterMessageData;
import canmessagegenerator.interfaces.IJitterMessageHandler;
import canmessagegeneratorcommand.interfaces.ICANMessageGeneratorCommandParameters;
import command.core.AbstractCommand;
import java.time.Duration;
import java.time.Instant;
import java.util.List;
import base.interfaces.IMessageWriter;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CANMessageGeneratorCommand class implements a command for a controller area network.
 */
public final class CANMessageGeneratorCommand extends AbstractCommand {
    private static final String messagesDeviationText = "Controller Area Network Message Generator Summary:";
    private static final String messageNameText = "messageName:";

    private ICANMessageGeneratorCommandParameters parameters;
    private final IJitterMessageHandler messageHandler = new JitterMessageHandler();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CANMessageGeneratorCommand constructor.
     */
    public CANMessageGeneratorCommand() {
    }

    /**
     * Runs the command.
     */
    @Override
    public void run() {
        this.initialize();

        this.generateMessages(
            this.parameters.getDriveSessionDuration(),
            this.parameters.getMessagesFrequencies());

        this.getMessageWriter().writeInformationalMessage("\n");

        this.displayMessagesJitterInformation(
            this.parameters.getMessagesFrequencies(),
            this.getMessageWriter());
    }

    /**
     * Generates the specified messages.
     */
    private void generateMessages(
        Duration driveSessionDuration,
        List<IPair<String, Integer>> messages) {

        this.registerMessagesWithJitter(messages);

        Instant startTime = Instant.now();

        boolean processSession = true;

        while (processSession) {
            for (IPair<String, Integer> messageFrequency : messages) {
                processSession = sessionActive(startTime, driveSessionDuration);

                if (!processSession) {
                    break;
                }

                String messageName = messageFrequency.first();
                int frequency = messageFrequency.second();

                Duration timeout = Duration.ofSeconds(1);

                processMessages(messageName, frequency, timeout, this.getMessageWriter());
            }
        }
    }

    /**
     * Processes the messages.
     */
    private boolean processMessages(
        String messageName,
        int numberOfMessages,
        Duration timeout,
        IMessageWriter messageWriter) {

        int messageIndex = 0;

        Instant startTime = Instant.now();

        int delayInMilliseconds = 1000 / numberOfMessages;

        while (messageIndex < numberOfMessages && sessionActive(startTime, timeout)) {
            processMessage(messageName, messageWriter);
            ++messageIndex;

            Threads.sleep(delayInMilliseconds);
        }

        return true;
    }

    /**
     * Processes the message.
     */
    private void processMessage(
        String messageName,
        IMessageWriter messageWriter) {

        this.messageHandler.setMessageSendingTime(messageName, Instant.now());

        ICANRuleGenerator<ICANMessageRule> ruleGenerator = new CANMessageRuleGenerator();
        ICANMessageRule rule = ruleGenerator.generate(messageName);

        messageWriter.writeInformationalMessage(rule.toString());

        for (ICANSignalRule signalRule : rule.getSignalRules()) {
            messageWriter.writeInformationalMessage("    " + signalRule);
        }

        this.messageHandler.setMessageReceivingTime(messageName, Instant.now());
    }

    /**
     * Displays the Jitter information of the messages.
     */
    private void displayMessagesJitterInformation(
        List<IPair<String, Integer>> messages,
        IMessageWriter messageWriter) {

        messageWriter.writeInformationalMessage(messagesDeviationText);

        for (IPair<String, Integer> message : messages) {
            this.displayMessageJitterInformation(message.first(), messageWriter);
        }
    }

    /**
     * Displays the Jitter information of the message.
     */
    private void displayMessageJitterInformation(
        String messageName,
        IMessageWriter messageWriter) {

        IJitterMessageData messageData = this.messageHandler.getMessageData(messageName);

        StringBuilder information = new StringBuilder();
        information
            .append(messageNameText).append(" ").append(messageName)
            .append(", ")
            .append(messageData);

        messageWriter.writeInformationalMessage(information.toString());
    }

    /**
     * Registers the messages with the Jitter.
     */
    private void registerMessagesWithJitter(List<IPair<String, Integer>> messages) {
        for (IPair<String, Integer> message : messages) {
            String messageName = message.first();
            int frequencyInHz = message.second();

            long transmittingTimeInMilliseconds = 1000 / frequencyInHz;
            Duration transmittingTime = Duration.ofMillis(transmittingTimeInMilliseconds);

            this.messageHandler.registerMessage(messageName, transmittingTime);
        }
    }

    /**
     * Checks whether the session is active.
     */
    private static boolean sessionActive(Instant startTime, Duration timeout) {
        Instant currTime = Instant.now();
        Duration currDuration = Duration.between(startTime, currTime);

        return currDuration.compareTo(timeout) < 0;
    }

    /**
     * Initializes the command.
     */
    private void initialize() {
        this.parameters = new CANMessageGeneratorCommandParameters(this.getParameters());
    }
}
