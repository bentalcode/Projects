package canmessagegeneratorcommand.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IPair;
import canmessagegeneratorcommand.CANMessageGeneratorCommandException;
import canmessagegeneratorcommand.interfaces.ICANMessageGeneratorCommandParameters;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameter;
import java.time.Duration;
import java.util.ArrayList;
import java.util.List;

/**
 * The CANMessageGeneratorCommandParameters class implements parameters of
 * a Controller Area Network message generator command.
 */
public final class CANMessageGeneratorCommandParameters implements ICANMessageGeneratorCommandParameters {
    private static final int SESSION_DURATION_IN_SECONDS = 10 * 60;

    private final Duration driveSessionDuration;
    private final List<IPair<String, Integer>> messagesFrequencies;

    /**
     * The CANMessageGeneratorCommandParameters constructor.
     */
    public CANMessageGeneratorCommandParameters(ICommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of the command.");

        IParameter driveSessionDurationParameter = parameters.getParameterSet().getParameter("driveSessionTime");
        int driveSessionInSeconds = driveSessionDurationParameter != null && driveSessionDurationParameter.isSet() ?
            driveSessionDurationParameter.getIntegerValue() :
                SESSION_DURATION_IN_SECONDS;

        this.driveSessionDuration = Duration.ofSeconds(driveSessionInSeconds);

        IParameter messagesFrequenciesParameter = parameters.getParameterSet().getParameter("messagesFrequencies");
        String[] messagesFrequencies = messagesFrequenciesParameter != null && messagesFrequenciesParameter.isSet() ?
            messagesFrequenciesParameter.getStringArrayValue() : null;

        this.messagesFrequencies = parseMessageFrequencies(messagesFrequencies);
    }

    /**
     * Gets the duration of a drive session.
     */
    @Override
    public Duration getDriveSessionDuration() {
        return this.driveSessionDuration;
    }

    /**
     * Gets the messages frequencies.
     */
    @Override
    public List<IPair<String, Integer>> getMessagesFrequencies() {
        return this.messagesFrequencies;
    }

    /**
     * Parses the message frequencies.
     */
    private static List<IPair<String, Integer>> parseMessageFrequencies(String[] messagesFrequencies) {
        List<IPair<String, Integer>> result = new ArrayList<>();

        if (messagesFrequencies == null || messagesFrequencies.length == 0) {
            return result;
        }

        for (String messageFrequency : messagesFrequencies) {
            String value = messageFrequency.trim();
            String[] messageFrequencyTokens = value.split(":");

            if (messageFrequencyTokens.length != 2) {
                String errorMessage = "The message frequency token is invalid. Format: '<name>:<size>'";
                throw new CANMessageGeneratorCommandException(errorMessage);
            }

            String messageName = messageFrequencyTokens[0].trim();
            int frequencyInHertz = Integer.parseInt(messageFrequencyTokens[1].trim());

            result.add(Pair.make(messageName, frequencyInHertz));
        }

        return result;
    }
}
