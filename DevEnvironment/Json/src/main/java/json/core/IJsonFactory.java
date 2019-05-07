package json.core;

import java.io.Reader;
import java.io.Writer;

/**
 * The IJsonFactory interface defines a factory for json.
 */
public interface IJsonFactory {
    /**
     * Creates a tokenizer.
     */
    JsonTokenizer createTokenizer(Reader reader);

    /**
     * Creates a generator.
     */
    JsonGenerator createGenerator(Writer writer);
}
