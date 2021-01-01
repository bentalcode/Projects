package testbase.core;

import java.util.ArrayList;
import java.util.List;

/**
 * The CollectionValues class implements complementary APIs for collections.
 */
public final class CollectionValues {
    /**
     * Creates values of a list.
     */
    public static List<Integer> createListValues(int size) {
        List<Integer> result = new ArrayList<>(size);

        for (int i = 0; i < size; ++i) {
            int value = i + 1;
            result.add(value);
        }

        return result;
    }

    /**
     * The CollectionValues constructor - Disables the default constructor.
     */
    private CollectionValues() {
    }
}
