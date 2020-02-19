package testbase.interfaces;

import json.interfaces.IJsonSerialization;

/**
 * The IJsonStreamingTest interface defines a generic json streaming test.
 */
public interface IJsonObjectStreamingTest {
    /**
     * Tests the json streaming of an object.
     */
    <T extends IJsonSerialization> void testStreaming(String json, Class<T> classType);
}
