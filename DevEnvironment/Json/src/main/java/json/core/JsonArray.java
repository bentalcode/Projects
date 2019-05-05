package json.core;

import base.core.Casting;
import base.core.Conditions;
import org.json.simple.JSONArray;

/**
 * The JsonArray class implements a json array.
 */
public final class JsonArray<T> extends JsonElement implements IJsonArray<T> {
    private final JSONArray array;

    /**
     * The JsonArray constructor.
     */
    public JsonArray(JSONArray array) {
        Conditions.validateNotNull(
            array,
            "The json array.");

        this.array = array;
    }

    /**
     * Gets an element of an array at a specified index.
     */
    @Override
    public T get(int index) {
        Object value = this.array.get(index);

        T result = Casting.cast(value);

        return result;
    }

    /**
     * Gets the size of an array.
     */
    @Override
    public int size() {
        return this.array.size();
    }

    /**
     * Checks whether an array is empty.
     */
    @Override
    public boolean empty() {
        return this.array.isEmpty();
    }
}
