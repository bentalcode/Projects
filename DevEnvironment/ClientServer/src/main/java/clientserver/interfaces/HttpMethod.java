package clientserver.interfaces;

import clientserver.ClientServerException;

/**
 * The HttpMethod defines a http method.
 */
public enum HttpMethod {
    POST("POST") {
    },
    PUT("PUT") {
    },
    GET("GET") {
    },
    DELETE("DELETE") {
    };

    private final String name;

    /**
     * The HttpMethod constructor.
     */
    HttpMethod(String name) {
        this.name = name;
    }

    /**
     * Gets the string representation of this enum.
     */
    @Override
    public String toString() {
        return this.name;
    }

    /**
     * Parses this enum.
     */
    public static HttpMethod parse(String name) {
        HttpMethod methodType = HttpMethod.tryParse(name);

        if (methodType == null) {
            String errorMessage = "The name: " + name + " for enum HttpMethod is not supported.";
            throw new ClientServerException(errorMessage);
        }

        return methodType;
    }

    /**
     * Tries to parse this enum
     */
    public static HttpMethod tryParse(String value) {
        for (HttpMethod methodType : HttpMethod.values()) {
            if (methodType.name().equalsIgnoreCase(value)) {
                return methodType;
            }
        }

        return null;
    }
}
