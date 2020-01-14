package testbase.interfaces;

import json.interfaces.IJsonSerialization;

/**
 * The IJsonStreamingTest interface defines a generic json streaming test.
 */
public interface IJsonStreamingTest {
    /**
     * Tests the json streaming.
     */
    <T extends IJsonSerialization> void testStreaming(String json, Class<T> classType);
}
