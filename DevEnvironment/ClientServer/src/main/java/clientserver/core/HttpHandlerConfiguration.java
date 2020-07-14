package clientserver.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import clientserver.interfaces.IHttpHandlerConfiguration;
import clientserver.interfaces.IRetryPolicy;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.time.Duration;

/**
 * The HttpHandlerConfiguration class implements a configuration for a Http Handler.
 */
public final class HttpHandlerConfiguration implements IHttpHandlerConfiguration {
    private static final String propertyRetryPolicy = "retryPolicy";
    private static final String propertyConnectTimeout = "connectTimeout";
    private static final String propertyWriteTimeout = "writeTimeout";
    private static final String propertyReadTimeout = "readTimeout";
    private static final String propertySocketTimeout = "socketTimeout";

    private final IRetryPolicy retryPolicy;

    private final Duration connectTimeout;
    private final Duration writeTimeout;
    private final Duration readTimeout;
    private final Duration socketTimeout;

    private final IBinaryComparator<IHttpHandlerConfiguration> comparator = HttpHandlerConfiguration.defaultComparator();

    /**
     * Gets the default configuration.
     */
    public static IHttpHandlerConfiguration defaultConfiguration() {
        return new HttpHandlerConfiguration(
            RetryPolicy.defaultRetryPolicy(),
            HttpConstants.defaultConnectTimeout,
            HttpConstants.defaultWriteTimeout,
            HttpConstants.defaultReadTimeout,
            HttpConstants.defaultSocketTimeout);
    }

    /**
     * The HttpHandlerConfiguration constructor.
     */
    public HttpHandlerConfiguration(
        IRetryPolicy retryPolicy,
        Duration connectTimeout,
        Duration writeTimeout,
        Duration readTimeout,
        Duration socketTimeout) {

        Conditions.validateNotNull(
            retryPolicy,
            "The retry policy.");

        Conditions.validateNotNull(
            connectTimeout,
            "The connect timeout.");

        Conditions.validateNotNull(
            writeTimeout,
            "The write timeout.");

        Conditions.validateNotNull(
            readTimeout,
            "The read timeout.");

        Conditions.validateNotNull(
            socketTimeout,
            "The socket timeout.");

        this.retryPolicy = retryPolicy;
        this.connectTimeout = connectTimeout;
        this.writeTimeout = writeTimeout;
        this.readTimeout = readTimeout;
        this.socketTimeout = socketTimeout;
    }

    /**
     * Gets a retry policy.
     */
    @Override
    public IRetryPolicy getRetryPolicy() {
        return this.retryPolicy;
    }

    /**
     * Gets a connect timeout.
     *
     * A connect timeout defines a time period in which our client should establish a connection
     * with a target host.
     * By default, for the OkHttpClient, this timeout is set to 10 seconds.
     */
    @Override
    public Duration getConnectTimeout() {
        return this.connectTimeout;
    }

    /**
     * Gets a write timeout.
     * The write timeout is the maximum time for writing (sending) the request data to the service.
     */
    @Override
    public Duration getWriteTimeout() {
        return this.writeTimeout;
    }

    /**
     * Gets a read timeout.
     * The read timeout is the time for waiting for a response.
     */
    @Override
    public Duration getReadTimeout() {
        return this.readTimeout;
    }

    /**
     * Gets a socket timeout.
     *
     * The time waiting for data – after establishing the connection.
     * The maximum time of inactivity between two data packets.
     */
    @Override
    public Duration getSocketTimeout() {
        return this.socketTimeout;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IHttpHandlerConfiguration other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IHttpHandlerConfiguration other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IHttpHandlerConfiguration> defaultComparator() {
        return new HttpHandlerConfiguration.Comparator();
    }

    /**
     * The Comparator class implements a comparator of a Http Handler configuration.
     */
    public static final class Comparator extends AbstractBinaryComparator<IHttpHandlerConfiguration> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IHttpHandlerConfiguration obj) {
            return new HashCodeBuilder(71, 73)
                .withObject(obj.getRetryPolicy(), RetryPolicy.defaultComparator())
                .withDuration(obj.getConnectTimeout())
                .withDuration(obj.getWriteTimeout())
                .withDuration(obj.getReadTimeout())
                .withDuration(obj.getSocketTimeout())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IHttpHandlerConfiguration lhs, IHttpHandlerConfiguration rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getRetryPolicy(), rhs.getRetryPolicy(), RetryPolicy.defaultComparator())
                .withDuration(lhs.getConnectTimeout(), rhs.getConnectTimeout())
                .withDuration(lhs.getWriteTimeout(), rhs.getWriteTimeout())
                .withDuration(lhs.getReadTimeout(), rhs.getReadTimeout())
                .withDuration(lhs.getSocketTimeout(), rhs.getSocketTimeout())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IHttpHandlerConfiguration lhs, IHttpHandlerConfiguration rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withObject(lhs.getRetryPolicy(), rhs.getRetryPolicy(), RetryPolicy.defaultComparator())
                .withDuration(lhs.getConnectTimeout(), rhs.getConnectTimeout())
                .withDuration(lhs.getWriteTimeout(), rhs.getWriteTimeout())
                .withDuration(lhs.getReadTimeout(), rhs.getReadTimeout())
                .withDuration(lhs.getSocketTimeout(), rhs.getSocketTimeout())
                .build();
        }
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeObjectProperty(HttpHandlerConfiguration.propertyRetryPolicy, this.getRetryPolicy());
        writer.writeDurationProperty(HttpHandlerConfiguration.propertyConnectTimeout, this.getConnectTimeout());
        writer.writeDurationProperty(HttpHandlerConfiguration.propertyWriteTimeout, this.getWriteTimeout());
        writer.writeDurationProperty(HttpHandlerConfiguration.propertyReadTimeout, this.getReadTimeout());
        writer.writeDurationProperty(HttpHandlerConfiguration.propertySocketTimeout, this.getSocketTimeout());
    }

    /**
     * Reads an object from a json reader.
     */
    public static IHttpHandlerConfiguration readJson(IJsonObjectReader reader) {
        IRetryPolicy retryPolicy = reader.readObjectProperty(HttpHandlerConfiguration.propertyRetryPolicy, RetryPolicy.class);
        Duration connectTimeout = reader.readDurationProperty(HttpHandlerConfiguration.propertyConnectTimeout);
        Duration writeTimeout = reader.readDurationProperty(HttpHandlerConfiguration.propertyWriteTimeout);
        Duration readTimeout = reader.readDurationProperty(HttpHandlerConfiguration.propertyReadTimeout);
        Duration socketTimeout = reader.readDurationProperty(HttpHandlerConfiguration.propertySocketTimeout);

        return new HttpHandlerConfiguration(
            retryPolicy,
            connectTimeout,
            writeTimeout,
            readTimeout,
            socketTimeout);
    }
}
