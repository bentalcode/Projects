package algorithms.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.ISizableCollection;

/**
 * The IGrayCode interface defines a gray code.
 * A gray code also known as Reflected Binary Code, we call it Gray code after Frank Gray.
 * Gray code is an ordering of the binary numeral system such that two successive values differ
 * in only one bit (binary digit).
 */
public interface IGrayCode extends
    ISizableCollection,
    IIterable<Integer>,
    IReverseIterable<Integer> {
}
