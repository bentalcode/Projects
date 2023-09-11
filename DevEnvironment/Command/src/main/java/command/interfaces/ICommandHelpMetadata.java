package command.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;

/**
 * The ICommandHelpMetadata interface defines meta-data of help of a command.
 */
public interface ICommandHelpMetadata extends IUnaryComparator<ICommandHelpMetadata>, IJsonSerialization {
    /**
     * Gets a short name of a help parameter.
     */
    String getShortName();

    /**
     * Gets a long name of a help parameter.
     */
    String getLongName();

    /**
     * Gets a usage message of a command.
     */
    String getUsageMessage();
}
