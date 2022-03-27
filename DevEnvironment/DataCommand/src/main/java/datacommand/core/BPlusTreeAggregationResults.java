package datacommand.core;

import base.core.Conversion;
import base.interfaces.IIterator;
import base.core.Comparator;
import base.interfaces.IBinaryComparator;
import datacommand.interfaces.IAggregationResult;
import datacommand.interfaces.IAggregationResultsProperties;
import datastructures.bplustree.core.BPlusTree;
import datastructures.bplustree.core.BPlusTreeNode;
import datastructures.bplustree.core.BPlusTreeProperties;
import datastructures.bplustree.interfaces.IBPlusTree;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;

/**
 * The BPlusTreeAggregationResults class implements aggregation results of the data
 * by using a B+ tree data structure.
 */
public final class BPlusTreeAggregationResults extends AbstractAggregationResults {
    private final IBPlusTree<String, IAggregationResult> results;

    /**
     * The BPlusTreeAggregationResults constructor.
     */
    public BPlusTreeAggregationResults(IAggregationResultsProperties properties) {
        super(properties);

        IBinaryComparator<String> keyComparator = Comparator.make();
        IBinaryComparator<IBPlusTreeNode<String>> nodeComparator = BPlusTreeNode.defaultComparator(keyComparator);

        IBPlusTreeProperties<String, IAggregationResult> treeProperties =
            new BPlusTreeProperties.Builder<String, IAggregationResult>()
                .withDegree(4)
                .withKeyClassType(String.class)
                .withValueClassType(IAggregationResult.class)
                .withKeyComparator(keyComparator)
                .withNodeComparator(nodeComparator)
                .withKeySizeInBytes(properties.getKeyMaxSizeInBytes())
                .withValueSizeInBytes(properties.getAggregationResultMaxSize())
                .build();

        this.results = new BPlusTree<>(treeProperties);
    }

    /**
     * Adds an aggregation result.
     */
    @Override
    protected void addResult(String key, IAggregationResult result) {
        this.results.insert(key, result);
    }

    /**
     * Finds an aggregation result.
     */
    @Override
    protected IAggregationResult findResult(String key) {
        return this.results.search(key);
    }

    /**
     * Checks whether an aggregation result exists.
     */
    @Override
    protected boolean hasResult(String key) {
        IAggregationResult result = this.results.search(key);
        return result != null;
    }

    /**
     * Gets an iterator for iterating over the results.
     */
    @Override
    public IIterator<IAggregationResult> getIterator() {
        return this.results.getValueIterator();
    }

    /**
     * Calculates the size of the aggregation results.
     */
    @Override
    public long calculateSize() {
        IBPlusTreeMetrics metrics = this.results.calculateMetrics();
        return Conversion.bigIntegerConversion().toLong(metrics.getCapacityInBytes());
    }

    /**
     * Reduces the aggregation results to the reduction size.
     */
    @Override
    protected void reduce(long reductionSize) {
        assert(reductionSize >= 0);

        //
        // In this section serialize portion of the data into storage,
        // and keep into memory up to the specified size...
        //
        throw new UnsupportedOperationException();
    }
}
