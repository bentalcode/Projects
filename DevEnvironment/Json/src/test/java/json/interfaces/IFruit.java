package json.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IFruit interface defines properties of a fruit.
 */
public interface IFruit extends IUnaryComparator<IFruit>, IJsonSerialization {
    /**
     * Gets the kind of a fruit.
     */
    String getKind();

    /**
     * Gets size of a fruit.
     */
    int getSize();

    /**
     * Gets color of a fruit.
     */
    String getColor();

    /**
     * Gets price of a fruit.
     */
    double getPrice();
}
