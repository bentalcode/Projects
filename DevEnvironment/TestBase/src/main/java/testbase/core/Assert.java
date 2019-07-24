package testbase.core;

import testbase.interfaces.IAssert;
import java.util.Iterator;

/**
 * The Assert class implements an asset.
 */
public final class Assert implements IAssert {
    /**
     * The Assert constructor.
     */
    public Assert() {
    }

    /**
     * Asserts equality.
     */
    public <T> void assertEquals(
        Iterator<T> lhs,
        Iterator<T> rhs,
        String message) {


    }
}
