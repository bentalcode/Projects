package clientserver.interfaces;

import base.core.Enums;

/**
 * The TokenType defines a token type of Http protocol.
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
    public static TokenType parse(String str) {
        return Enums.parse(TokenType.class, str);
    }

    /**
     * Tries to parse this enum
     */
    public static TokenType tryParse(String str) {
        return Enums.tryParse(TokenType.class, str);
    }
}
