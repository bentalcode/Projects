package testbase.core;

import base.core.ClassTypes;
import base.core.Conditions;
import json.core.JsonStream;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IJsonStreamingTest;
import java.util.Objects;

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
    @Override
    public <T> void testStreaming(String json, Class<T> classType) {
        Conditions.validateNotNull(
            json,
            "The json to stream.");

        Conditions.validateNotNull(
            classType,
            "The class type of the json.");

        T obj1 = JsonStream.deserialize(json, classType);

        this.assertion.assertTrue(
            obj1 != null,
            "Incorrect de-serialization logic.");

        String json2 = JsonStream.serialize(obj1);

        this.assertion.assertTrue(
            json2 != null,
            "Incorrect serialization logic" +
            " of object type: " + ClassTypes.getName(classType));

        T obj2 = JsonStream.deserialize(json2, classType);
        boolean status = Objects.equals(obj1, obj2);

        this.assertion.assertTrue(
            status,
            "Incorrect comparison logic" +
            " of object type: " + ClassTypes.getName(classType));
    }
}
