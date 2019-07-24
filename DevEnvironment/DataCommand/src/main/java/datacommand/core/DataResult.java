package datacommand.core;

import testbase.core.Conditions;
import datacommand.interfaces.IAggregationResult;
import datacommand.interfaces.IAggregationResults;
import datacommand.interfaces.IDataResult;
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
public final class DataResult implements IDataResult {
    private IAggregationResults aggregationResults;

    /**
     * The DataResult constructor.
     */
    public DataResult(IAggregationResults aggregationResults) {
        Conditions.validateNotNull(
            aggregationResults,
            "The aggregation results.");

        this.aggregationResults = aggregationResults;
    }

    /**
     * Gets an iterator for iterating over the results.
     */
    @Override
    public Iterator<IAggregationResult> getIterator() {
        return this.aggregationResults.getIterator();
    }
}
