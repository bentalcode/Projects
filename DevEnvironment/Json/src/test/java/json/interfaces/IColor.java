package json.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IColor interface defines properties of a color.
 */
public interface IColor extends IUnaryComparator<IColor>, IJsonSerialization {
    /**
     * Gets the name of a color.
     */
    String getName();

    /**
     * Gets the hex of a color.
     */
    String getHex();

    /**
     * Gets the rgb of a color.
     */
    String getRgb();
}
