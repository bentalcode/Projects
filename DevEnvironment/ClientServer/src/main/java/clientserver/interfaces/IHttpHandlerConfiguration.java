package clientserver.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.time.Duration;

/**
 * The IHttpHandlerConfiguration interface defines configuration of a Http Handler.
 */
public interface IHttpHandlerConfiguration extends
    IUnaryComparator<IHttpHandlerConfiguration>,
    IJsonSerialization {

    /**
     * Gets a retry policy.
     */
    IRetryPolicy getRetryPolicy();

    /**
     * Gets a connect timeout.
     *
     * A connect timeout defines a time period in which our client should establish a connection
     * with a target host.
     * By default, for the OkHttpClient, this timeout is set to 10 seconds.
     */
    Duration getConnectTimeout();

    /**
     * Gets a write timeout.
     * The write timeout is the maximum time for writing (sending) the request data to the service.
     */
    Duration getWriteTimeout();

    /**
     * Gets a read timeout.
     * The read timeout is the time for waiting for a response.
     */
    Duration getReadTimeout();

    /**
     * Gets a socket timeout.
     *
     * The time waiting for data – after establishing the connection.
     * The maximum time of inactivity between two data packets.
     */
    Duration getSocketTimeout();
}
