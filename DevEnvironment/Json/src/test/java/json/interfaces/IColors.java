package json.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The IColors interface defines properties of colors.
 */
public interface IColors extends IUnaryComparator<IColors>, IJsonSerialization {
    /**
     * Gets the category of a color.
     */
    String getCategory();

    /**
     * Gets the colors.
     */
    List<IColor> getColors();
}
