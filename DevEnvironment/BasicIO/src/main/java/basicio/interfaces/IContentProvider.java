package basicio.interfaces;

import java.util.regex.Matcher;

/**
 * The IContentProvider interface defines a content provider.
 */
public interface IContentProvider {
    /**
     * Gets the new content.
     */
    String get(String currContent, Matcher matcher);
}
