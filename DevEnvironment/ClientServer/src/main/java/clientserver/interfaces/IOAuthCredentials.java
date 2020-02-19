package clientserver.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;

/**
 * The IOAuthCredentials interface defines credentials for OAuth.
 */
public interface IOAuthCredentials extends
    IUnaryComparator<IOAuthCredentials>,
    IJsonSerialization {

    /**
     * Gets the user name.
     */
    String getUserName();

    /**
     * Gets the user password.
     */
    String getUserPassword();

    /**
     * Encodes the credentials.
     */
    String encode();
}
