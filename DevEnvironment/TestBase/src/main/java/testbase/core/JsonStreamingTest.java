package testbase.core;

import json.core.JsonStream;
import json.interfaces.IJsonSerialization;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IJsonStreamingTest;

/**
 * The JsonStreamingTest class implements a generic streaming test.
 */
public final class JsonStreamingTest implements IJsonStreamingTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The JsonStreamingTest constructor.
     */
    public JsonStreamingTest() {
    }

    /**
     * Tests the json streaming.
     */
    public <T extends IJsonSerialization> void testStreaming(String json, Class<T> classType) {
        T obj1 = JsonStream.deserialize(json, classType);

        String json2 = JsonStream.serialize(obj1);

        T obj2 = JsonStream.deserialize(json2, classType);

        this.assertion.assertTrue(
            obj1.equals(obj2),
            "The json streaming logic is invalid.");
    }
}
