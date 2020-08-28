package datacommand.core;

import base.core.Iterator;
import base.interfaces.IIterator;
import base.interfaces.IPrimitiveSize;
import datacommand.interfaces.IAggregationResult;
import datacommand.interfaces.IAggregationResultsProperties;
import java.util.HashMap;
import java.util.Map;

/**
 * The MapAggregationResults class implements aggregation results of the data
 * by using a map data structure.
 */
public final class MapAggregationResults extends AbstractAggregationResults {
    private final Map<String, IAggregationResult> results = new HashMap<>();

    /**
     * The MapAggregationResults constructor.
     */
    public MapAggregationResults(IAggregationResultsProperties properties) {
        super(properties);
    }

    /**
     * Adds an aggregation result.
     */
    @Override
    protected void addResult(String key, IAggregationResult result) {
        this.results.put(key, result);
    }

    /**
     * Finds an aggregation result.
     */
    @Override
    protected IAggregationResult findResult(String key) {
        IAggregationResult result = this.results.get(key);
        return result;
    }

    /**
     * Checks whether an aggregation result exists.
     */
    @Override
    protected boolean hasResult(String key) {
        return this.results.containsKey(key);
    }

    /**
     * Gets an iterator for iterating over the results.
     */
    @Override
    public IIterator<IAggregationResult> getIterator() {
        return Iterator.make(this.results.values());
    }

    /**
     * Calculates the size of the aggregation results.
     */
    @Override
    protected long calculateSize() {
        long size = 0;

        for (Map.Entry<String, IAggregationResult> entry : this.results.entrySet()) {

            String key = entry.getKey();
            IAggregationResult value = entry.getValue();

            //
            // Update the total size of the current entry...
            //
            int keySize = key.length() * IPrimitiveSize.InBytes.CharacterSize;
            int valueSize = value.getSizeInBytes();
            int entrySize = keySize + valueSize;

            size += entrySize;
        }

        return size;
    }

    /**
     * Reduces the aggregation results to the reduction size.
     */
    @Override
    protected void reduce(long reductionSize) {
        //
        // In this section serialize portion of the data into storage,
        // and keep into memory up to the specified size...
        //
    }
}
