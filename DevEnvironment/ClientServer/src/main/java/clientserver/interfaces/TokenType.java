package clientserver.interfaces;

import clientserver.ClientServerException;

/**
 * The TokenType defines a token type of a Http protocol.
 */
public enum TokenType {
    Bearer("Bearer") {
    };

    private final String name;

    /**
     * The TokenType constructor.
     */
    TokenType(String name) {
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
    public static TokenType parse(String name) {
        TokenType tokenType = TokenType.tryParse(name);

        if (tokenType == null) {
            String errorMessage = "The name: " + name + " for enum TokenType is not supported.";
            throw new ClientServerException(errorMessage);
        }

        return tokenType;
    }

    /**
     * Tries to parse this enum
     */
    public static TokenType tryParse(String value) {
        for (TokenType tokenType : TokenType.values()) {
            if (tokenType.name().equalsIgnoreCase(value)) {
                return tokenType;
            }
        }

        return null;
    }
}
