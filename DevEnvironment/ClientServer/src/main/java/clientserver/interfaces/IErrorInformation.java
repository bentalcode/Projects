package clientserver.interfaces;

import json.interfaces.IJsonSerialization;
import java.util.Date;

/**
 * The IErrorInformation interface defines an error information.
 */
public interface IErrorInformation extends IJsonSerialization {
    /**
     * Gets an exception to the error.
     */
    Exception getException();

    /**
     * Gets the time in which the error occurs.
     */
    Date getTime();
}
