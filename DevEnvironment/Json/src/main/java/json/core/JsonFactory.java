package json.core;

import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonFactory class implements a factory for json.
 */
public final class JsonFactory implements IJsonFactory {
    private final com.fasterxml.jackson.core.JsonFactory factory = new com.fasterxml.jackson.core.JsonFactory();
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonFactory constructor.
     */
    public JsonFactory() {
    }

    /**
     * Creates a tokenizer.
     */
    @Override
    public JsonTokenizer createTokenizer(Reader reader) {
        com.fasterxml.jackson.core.JsonParser parser;

        try {
            parser = this.factory.createParser(reader);
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Factory failed creating a parser" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }

        return new JsonTokenizer(parser);
    }

    /**
     * Creates a generator.
     */
    @Override
    public JsonGenerator createGenerator(Writer writer) {
        com.fasterxml.jackson.core.JsonGenerator generator;

        try {
            generator = this.factory.createGenerator(writer);
        }
        catch (IOException e) {
            String errorMessage =
                "The Json Factory failed creating a generator" +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }

        return new JsonGenerator(generator);
    }
}
