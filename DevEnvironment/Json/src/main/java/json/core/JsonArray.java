package json.core;

import base.core.Conditions;
import base.interfaces.IIterator;

import java.util.ArrayList;
import java.util.List;

/**
 * The JsonArray class implements a json array.
 */
public final class JsonArray extends JsonElement implements IJsonArray {
    private final List<IJsonValue> array = new ArrayList<>();
    private int position;

    /**
     * The JsonArray constructor.
     */
    public JsonArray(int id) {
        super(id);

        this.reset();
    }

    /**
     * Gets a json value of an array at a specified index.
     */
    @Override
    public IJsonValue get(int index) {
        return this.array.get(index);
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

    /**
     * Adds a json value to an array.
     */
    @Override
    public void add(IJsonValue obj) {
        this.array.add(obj);
    }

    /**
     * Gets an iterator for iterating over the collection.
     */
    @Override
    public IIterator<IJsonValue> getIterator() {
        this.reset();
        return this;
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.position < this.array.size();
    }

    /**
     * Gets the next element.
     */
    @Override
    public IJsonValue next() {
        assert (this.hasNext());

        IJsonValue currElement = this.get(this.position);
        ++this.position;

        return currElement;
    }

    /**
     * Sets a value.
     */
    @Override
    public void setValue(String name, IJsonValue value) {
        Conditions.validate(
            name == null,
            "A Json Array does not support properties.");

        this.array.add(value);
    }

    /**
     * Reset the iterator.
     */
    @Override
    public void reset() {
        this.position = 0;
    }
}
