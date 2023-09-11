package basicio.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The IFilePathScanner interface defines a file path scanner.
 */
public interface IFilePathScanner {
    /**
     * Scans file paths in a specific directory.
     * The function returns a list of paths for the matching extensions.
     */
    List<Path> scan(Path directory, List<String> extensions);

    /**
     * Scans file paths in a specific directory per category.
     * The function returns a list of category-paths for each matching extensions.
     */
    List<List<Path>> scanByCategory(Path directory, List<List<String>> extensions);
}
