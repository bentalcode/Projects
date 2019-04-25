package datacommand.interfaces;

import datacommand.core.BPlusTreeAggregationResults;
import datacommand.core.MapAggregationResults;

/**
 * The AggregationDataStructureType defines an enum of a data-structure of an aggregation.
 */
public enum AggregationDataStructureType {

    Map () {
        /**
         * Creates the aggregation results.
         */
        @Override
        public IAggregationResults createAggregationResults(IAggregationResultsProperties properties) {
            return new MapAggregationResults(properties);
        }
    },

    BPlusTree () {
        /**
         * Creates the aggregation results.
         */
        @Override
        public IAggregationResults createAggregationResults(IAggregationResultsProperties properties) {
            return new BPlusTreeAggregationResults(properties);
        }

    };

    /**
     * Creates the aggregation results.
     */
    public abstract IAggregationResults createAggregationResults(IAggregationResultsProperties properties);
}
