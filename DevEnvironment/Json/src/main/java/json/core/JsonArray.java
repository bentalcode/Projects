package json.core;

import base.core.Conditions;
import org.json.simple.JSONArray;

/**
 * The JsonArray class implements a json array.
 */
public final class JsonArray extends JsonElement implements IJsonArray {
    private final JSONArray array;

    /**
     * The JsonArray constructor.
     */
    public JsonArray(int id, JSONArray array) {
        super(id);

        Conditions.validateNotNull(
            array,
            "The json array.");

        this.array = array;
    }
}
