package json.core;

import testbase.core.Conditions;
import testbase.core.Converter;
import testbase.core.DestructorHandler;
import base.interfaces.ICloseable;
import base.interfaces.IConverter;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.io.IOException;

/**
 * The JsonTokenizer class implements a tokenizer for json.
 */
public final class JsonTokenizer implements IJsonTokenizer, ICloseable {
    private final com.fasterxml.jackson.core.JsonParser parser;
    private final IConverter<com.fasterxml.jackson.core.JsonToken, JsonToken> tokenConverter = new Converter<>();
    private final DestructorHandler destructorHandler = new DestructorHandler();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonTokenizer constructor.
     */
    public JsonTokenizer(com.fasterxml.jackson.core.JsonParser parser) {
        Conditions.validateNotNull(
            parser,
            "The jackson json parser.");

        this.parser = parser;
        this.destructorHandler.register(this.parser);

        this.tokenConverter
            .register(com.fasterxml.jackson.core.JsonToken.NOT_AVAILABLE, JsonToken.NOT_AVAILABLE)
            .register(com.fasterxml.jackson.core.JsonToken.START_OBJECT, JsonToken.START_OBJECT)
            .register(com.fasterxml.jackson.core.JsonToken.END_OBJECT, JsonToken.END_OBJECT)
            .register(com.fasterxml.jackson.core.JsonToken.START_ARRAY, JsonToken.START_ARRAY)
            .register(com.fasterxml.jackson.core.JsonToken.END_ARRAY, JsonToken.END_ARRAY)
            .register(com.fasterxml.jackson.core.JsonToken.FIELD_NAME, JsonToken.FIELD_NAME)
            .register(com.fasterxml.jackson.core.JsonToken.VALUE_EMBEDDED_OBJECT, JsonToken.VALUE_EMBEDDED_OBJECT)
            .register(com.fasterxml.jackson.core.JsonToken.VALUE_STRING, JsonToken.VALUE_STRING)
            .register(com.fasterxml.jackson.core.JsonToken.VALUE_NUMBER_INT, JsonToken.VALUE_NUMBER_INTEGER)
            .register(com.fasterxml.jackson.core.JsonToken.VALUE_NUMBER_FLOAT, JsonToken.VALUE_NUMBER_DOUBLE)
            .register(com.fasterxml.jackson.core.JsonToken.VALUE_TRUE, JsonToken.VALUE_TRUE)
            .register(com.fasterxml.jackson.core.JsonToken.VALUE_FALSE, JsonToken.VALUE_FALSE)
            .register(com.fasterxml.jackson.core.JsonToken.VALUE_NULL, JsonToken.VALUE_NULL);
    }

    /**
     * Closes the tokenizer.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Gets the next token.
     * Returns null if no token is available
     */
    @Override
    public JsonToken next() {
        com.fasterxml.jackson.core.JsonToken token;

        try {
            token = this.parser.nextToken();
        }
        catch (IOException e) {
            String errorMessage = "The Json Tokenizer failed to retrieve the next token.";

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage);
        }

        return this.tokenConverter.convert(token);
    }

    /**
     * Gets the identifier of the current token.
     */
    @Override
    public int currentTokenId() {
        return this.parser.currentTokenId();
    }

    /**
     * Gets the current name.
     */
    @Override
    public String currentName() {
        String result;

        try {
            result = this.parser.getCurrentName();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Tokenizer failed retrieving the current name for token id: " +
                this.currentTokenId();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage);
        }

        return result;
    }

    /**
     * Gets the current string value.
     */
    @Override
    public String currentStringValue() {
        String result;

        try {
            result = this.parser.getValueAsString();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Tokenizer failed retrieving the current string value for token id: " +
                this.parser.currentTokenId();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage);
        }

        return result;
    }

    /**
     * Gets the current long value.
     */
    @Override
    public long currentLongValue() {
        long result;

        try {
            result = this.parser.getValueAsLong();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Tokenizer failed retrieving the current long value for token id: " +
                this.parser.currentTokenId();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage);
        }

        return result;
    }

    /**
     * Gets the current double value.
     */
    @Override
    public double currentDoubleValue() {
        double result;

        try {
            result = this.parser.getValueAsDouble();
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Tokenizer failed retrieving the current double value for token id: " +
                this.parser.currentTokenId();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage);
        }

        return result;
    }
}
