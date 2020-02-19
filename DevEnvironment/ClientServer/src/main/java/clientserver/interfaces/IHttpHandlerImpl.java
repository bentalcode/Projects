package clientserver.interfaces;

import base.interfaces.ITriple;

import java.util.Map;

/**
 * The IHttpHandlerImpl interface defines an implementation of a Http Handler.
 */
public interface IHttpHandlerImpl {
    /**
     * Makes a http request.
     */
    ITriple<Integer, Map<String, String>, String> make(
        Map<String, String> header,
        String body);
}
