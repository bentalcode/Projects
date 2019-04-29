package json.core;

import java.util.HashMap;
import java.util.Map;

/**
 * The JsonObject class implements a json object.
 */
public final class JsonObject extends JsonElement implements IJsonObject {
    private final Map<String, IJsonValue> values = new HashMap<>();

    /**
     * The JsonObject constructor.
     */
    public JsonObject(int id) {
        super(id);
    }
}
