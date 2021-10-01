package algorithms.core;

import algorithms.interfaces.IGrayCode;
import base.core.Collections;
import base.core.Conditions;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.IIterator;
import base.interfaces.IPrimitiveSize;
import base.interfaces.IReverseIterator;
import base.core.Bits;
import java.util.ArrayList;
import java.util.List;

/**
 * The GrayCode class implements a gray code.
 * A gray code also known as Reflected Binary Code, we call it Gray code after Frank Gray.
 * Gray code is an ordering of the binary numeral system such that two successive values differ
 * in only one bit (binary digit).
 */
public final class GrayCode implements IGrayCode {
    private final List<Integer> grayCodes;

    /**
     * The GrayCode constructor.
     */
    public GrayCode(int bitsSize) {
        Conditions.validate(
            bitsSize >= 0 && bitsSize < IPrimitiveSize.InBits.IntegerSize,
            "The number of bits has to be between: [0-32).");

        this.grayCodes = createGrayCodes(bitsSize);
    }

    /**
     * Gets the size of gray codes.
     */
    @Override
    public int size() {
        return this.grayCodes.size();
    }

    /**
     * Checks whether gray codes are empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<Integer> getIterator() {
        return ListIterator.make(this.grayCodes);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<Integer> getReverseIterator() {
        return ListReverseIterator.make(this.grayCodes);
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
    }

    /**
     * Creates the gray codes.
     */
    private static List<Integer> createGrayCodes(int numberOfBits) {
        assert(numberOfBits >= 0);

        int capacity = (int)Math.pow(2, numberOfBits);
        List<Integer> codes = new ArrayList<>(capacity);

        if (numberOfBits == 0) {
            return codes;
        }

        codes.add(0);
        codes.add(1);

        if (numberOfBits == 1) {
            return codes;
        }

        int currNumberOfBits = 2;

        while (currNumberOfBits <= numberOfBits) {
            List<Integer> nextCodes = createNextGrayCodes(codes, currNumberOfBits);
            codes.addAll(nextCodes);

            ++currNumberOfBits;
        }

        return codes;
    }

    /**
     * Creates the next gray codes.
     * Reverse the original set, and for each number, add a one bit in front of the number.
     */
    private static List<Integer> createNextGrayCodes(List<Integer> codes, int numberOfBits) {
        List<Integer> nextCodes = new ArrayList<>(codes.size());

        int bitIndex = numberOfBits - 1;

        for (int i = codes.size() - 1; i >= 0; --i) {
            int code = codes.get(i);
            code = Bits.turnOn(code, bitIndex);

            nextCodes.add(code);
        }

        return nextCodes;
    }
}
