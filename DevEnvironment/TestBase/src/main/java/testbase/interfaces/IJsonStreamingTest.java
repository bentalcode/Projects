package testbase.interfaces;

/**
 * The IJsonStreamingTest interface defines a generic json streaming test.
 */
public interface IJsonStreamingTest {
    /**
     * Tests the json streaming.
     */
    <T> void testStreaming(String json, Class<T> classType);
}
