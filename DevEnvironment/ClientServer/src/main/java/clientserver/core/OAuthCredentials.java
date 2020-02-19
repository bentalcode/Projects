package clientserver.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import clientserver.interfaces.IOAuthCredentials;
import json.core.JsonStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

import java.util.Base64;

/**
 * The OAuthCredentials class implements credentials of OAuth.
 */
public final class OAuthCredentials implements IOAuthCredentials {
    private static final String propertyUserName = "userName";
    private static final String propertyUserPassword = "userPassword";

    private final String userName;
    private final String userPassword;
    private final IBinaryComparator<IOAuthCredentials> comparator = OAuthCredentials.defaultComparator();

    /**
     * The OAuthCredentials constructor.
     */
    public OAuthCredentials(
        String userName,
        String userPassword) {

        Conditions.validateStringNotNullOrEmpty(
            userName,
            "The user name.");

        Conditions.validateStringNotNullOrEmpty(
            userPassword,
            "The user password.");

        this.userName = userName;
        this.userPassword = userPassword;
    }

    /**
     * Gets the user name.
     */
    @Override
    public String getUserName() {
        return this.userName;
    }

    /**
     * Gets the user password.
     */
    @Override
    public String getUserPassword() {
        return this.userPassword;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonStream.serialize(this);
    }

    /**
     * Encodes the credentials.
     */
    @Override
    public String encode() {
        String authorizationToken = this.userName + ":" + this.userPassword;
        return Base64.getEncoder().encodeToString(authorizationToken.getBytes());
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
    public boolean isEqual(IOAuthCredentials other) {
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
    public int compareTo(IOAuthCredentials other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IOAuthCredentials> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of an OAuth credentials.
     */
    public static final class Comparator extends AbstractBinaryComparator<IOAuthCredentials> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IOAuthCredentials obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getUserName())
                .withString(obj.getUserPassword())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IOAuthCredentials lhs, IOAuthCredentials rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getUserName(), rhs.getUserName())
                .withString(lhs.getUserPassword(), rhs.getUserPassword())
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
        public int compareTo(IOAuthCredentials lhs, IOAuthCredentials rhs) {
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
                .withString(lhs.getUserName(), rhs.getUserName())
                .withString(lhs.getUserPassword(), rhs.getUserPassword())
                .build();
        }
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(OAuthCredentials.propertyUserName, this.getUserName());
        writer.writeStringProperty(OAuthCredentials.propertyUserPassword, this.getUserPassword());
    }

    /**
     * Reads an object from a json reader.
     */
    public static IOAuthCredentials readJson(IJsonObjectReader reader) {
        String userName = reader.readStringProperty(OAuthCredentials.propertyUserName);
        String userPassword = reader.readStringProperty(OAuthCredentials.propertyUserPassword);

        return new OAuthCredentials(
            userName,
            userPassword);
    }
}
