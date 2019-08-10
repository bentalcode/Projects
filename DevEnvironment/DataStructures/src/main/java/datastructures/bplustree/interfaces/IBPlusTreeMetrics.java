package datastructures.bplustree.interfaces;

import base.interfaces.IUnaryComparator;
import datastructures.tree.interfaces.ITreeMetrics;
import java.math.BigInteger;

/**
 * The ITreeMetrics interface defines metrics of a tree.
 */
public interface IBPlusTreeMetrics extends ITreeMetrics, IUnaryComparator<IBPlusTreeMetrics> {
    /**
     * Gets the capacity in bytes of a tree.
     */
    BigInteger getCapacityInBytes();
}
