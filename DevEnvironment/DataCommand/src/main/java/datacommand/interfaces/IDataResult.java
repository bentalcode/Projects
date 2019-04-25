package datacommand.interfaces;

import java.util.Iterator;

/**
 * The IDataResult interface defines a result of the data.
 *
 * The command should compute, for each key the number of values
 * with that key and the value with the highest sort order.
 *
 * For example, if the input data is:
 *
 * key1 abcd
 * key2 zzz
 * key1 hello
 * key3 world
 * ```
 *
 * The result should be:
 *
 * key1: 2, hello
 * key2: 1, zzz
 * key3: 1, world
 *
 */
public interface IDataResult {
    /**
     * Gets the iterator for iterating over the results.
     */
    Iterator<IAggregationResult> getIterator();
}
