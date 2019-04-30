package json.core;

import base.core.Casting;
import java.io.IOException;
import java.io.Reader;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonParser class implements a json parser.
 */
public final class JsonParser implements IJsonParser {
    private final JSONParser parser = new JSONParser();
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonParser constructor.
     */
    public JsonParser() {

    }

    /**
     * Parses a json into a tree.
     */
    @Override
    public IJsonTree parse(Reader reader) {
        Object result;

        try {
            result = this.parser.parse(reader);
        }
        catch (IOException | ParseException e) {
            String errorMessage =
                "The JsonParser failed parsing json due to the following error: " +
                e.getMessage();

            this.log.error(errorMessage, e);
            throw new JsonException(errorMessage, e);
        }

        JSONObject object = Casting.cast(result);
        return new JsonTree(object);
    }
}
