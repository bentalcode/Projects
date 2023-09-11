package problems.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The ISparseSimilarityResult interface defines a result of a sparse similarity.
 */
public interface ISparseSimilarityResult extends IUnaryComparator<ISparseSimilarityResult> {
    /**
     * Gets an id of collection1.
     */
    int getCollectionId1();

    /**
     * Gets an id of collection2.
     */
    int getCollectionId2();

    /**
     * Gets an intersection size.
     */
    int getIntersectionSize();

    /**
     * Sets an intersection size.
     */
    void setIntersectionSize(int size);

    /**
     * Gets a union size.
     */
    int getUnionSize();

    /**
     * Sets a union size.
     */
    void setUnionSize(int size);

    /**
     * Gets a sparse similarity.
     */
    double getSparseSimilarity();

    /**
     * Sets a sparse similarity.
     */
    void setSparseSimilarity(double sparseSimilarity);
}
