package clientserver.interfaces;

import json.interfaces.IJsonSerialization;
import java.util.Date;

/**
 * The ILogicRuntimeInformation interface defines the runtime information of the logic execution.
 */
public interface ILogicRuntimeInformation extends IJsonSerialization {
    /**
     * Gets the name of the logic.
     */
    String getName();

    /**
     * Gets the status of the logic execution.
     */
    boolean getStatus();

    /**
     * Gets the time in which the logic has started.
     */
    Date getStartTime();

    /**
     * Gets the time in which the logic has ended.
     */
    Date getEndTime();

    /**
     * Gets the information of the error.
     */
    IErrorInformation getErrorInformation();
}
