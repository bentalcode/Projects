package datastructures.bitarray.interfaces;

import java.util.List;

/**
 * The IBitArrayData interface defines the data of a bit array.
 */
public interface IBitArrayData {
    /**
     * Gets the creation data of the bit array.
     */
    List<Boolean> getCreationData();

    /**
     * Gets the actual data of the bit array.
     */
    List<Boolean> getData();
}
