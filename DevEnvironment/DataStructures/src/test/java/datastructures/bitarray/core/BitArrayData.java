package datastructures.bitarray.core;

import datastructures.bitarray.interfaces.IBitArrayData;
import java.util.List;

/**
 * The BitArrayData class implements the data of a bit array.
 */
public final class BitArrayData implements IBitArrayData {
    private final List<Boolean> data;

    /**
     * The BitArrayData constructor.
     */
    public BitArrayData(List<Boolean> data) {
        this.data = data;
    }

    /**
     * Gets the data of a bit array.
     */
    @Override
    public List<Boolean> getData() {
        return this.data;
    }
}
