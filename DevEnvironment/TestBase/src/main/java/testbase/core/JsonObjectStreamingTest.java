package testbase.core;

import json.core.JsonObjectStream;
import json.interfaces.IJsonSerialization;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IJsonObjectStreamingTest;

/**
 * The JsonObjectStreamingTest class implements a generic streaming test.
 */
public final class JsonObjectStreamingTest implements IJsonObjectStreamingTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The JsonObjectStreamingTest constructor.
     */
    public JsonObjectStreamingTest() {
    }

    /**
     * Tests the json streaming.
     */
    public <T extends IJsonSerialization> void testStreaming(String json, Class<T> classType) {
        T obj1 = JsonObjectStream.deserialize(json, classType);

        String json2 = JsonObjectStream.serialize(obj1);

        T obj2 = JsonObjectStream.deserialize(json2, classType);

        this.assertion.assertTrue(
            obj1.equals(obj2),
            "The json streaming logic is invalid.");
    }
}
