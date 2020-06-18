package cmakebuildsystem.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;

/**
 * The IEditorSettings interface defines settings of an editor.
 */
public interface IEditorSettings extends IUnaryComparator<IEditorSettings>, IJsonSerialization {
    /**
     * Gets the tab size.
     */
    int getTabSize();
}
