package basicio.core;

import base.core.ArrayLists;
import base.core.Conditions;
import basicio.BasicIOException;
import basicio.interfaces.IFilePathScanner;
import java.io.File;
import java.io.IOException;
import java.nio.file.DirectoryIteratorException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The FilePathScanner class implements a file path scanner.
 */
public final class FilePathScanner implements IFilePathScanner {
    /**
     * The FilePathScanner constructor.
     */
    public FilePathScanner() {
    }

    /**
     * Scans file paths in a specific directory.
     * The function returns a list of paths for the matching extensions.
     */
    @Override
    public List<Path> scan(Path directory, List<String> extensions) {
        List<List<String>> extensionsCategories = ArrayLists.make(extensions);

        List<List<Path>> result = this.scanByCategory(directory, extensionsCategories);
        assert(result.size() == 1);

        return result.get(0);
    }

    /**
     * Scans file paths in a specific directory per category.
     * The function returns a list of category-paths for each matching extensions.
     */
    @Override
    public List<List<Path>> scanByCategory(
        Path directory,
        List<List<String>> extensions) {

        Conditions.validatePathNotNullOrEmpty(
            directory,
            "The directory to scan.");

        Conditions.validate(
            extensions != null && !extensions.isEmpty(),
            "The extensions of the files are not defined.");

        int size = extensions.size();

        List<List<Path>> result = createScanResult(size);

        try (DirectoryStream<Path> stream = Files.newDirectoryStream(directory)) {
            for (Path currPath : stream) {
                File currFile = currPath.toFile();

                if (currFile.isDirectory()) {
                    this.processDirectory(
                        currPath,
                        extensions,
                        result);
                }
                else if (currFile.isFile()) {
                    processFile(
                        currPath,
                        currFile,
                        extensions,
                        result);
                }
            }
        }
        catch (IOException | DirectoryIteratorException e) {
            String errorMessage =
                "The FilePathScanner failed processing the directory: " + directory +
                ", due to the following error: " + e.getMessage();

            throw new BasicIOException(errorMessage);
        }

        return result;
    }

    /**
     * Processes a directory.
     */
    private void processDirectory(
        Path path,
        List<List<String>> extensions,
        List<List<Path>> result) {

        assert(extensions.size() == result.size());

        try (DirectoryStream<Path> stream = Files.newDirectoryStream(path)) {
            for (Path currPath : stream) {
                File currFile = currPath.toFile();

                if (currFile.isDirectory()) {
                    this.processDirectory(
                        currPath,
                        extensions,
                        result);
                }
                else if (currFile.isFile()) {
                    processFile(
                        currPath,
                        currFile,
                        extensions,
                        result);
                }
            }
        }
        catch (IOException | DirectoryIteratorException e) {
            String errorMessage =
                "The FilePathScanner failed processing the directory: " + path +
                ", due to the following error: " + e.getMessage();

            throw new BasicIOException(errorMessage);
        }
    }

    /**
     * Processes a file.
     */
    private static void processFile(
        Path filePath,
        File file,
        List<List<String>> extensions,
        List<List<Path>> result) {

        assert(extensions.size() == result.size());

        int size = extensions.size();

        for (int index = 0; index < size; ++index) {
            List<String> extensionList = extensions.get(index);
            List<Path> resultPaths = result.get(index);

            String fileName = file.getName();

            if (hasExtension(fileName, extensionList)) {
                resultPaths.add(filePath);
            }
        }
    }

    /**
     * Creates the scan results.
     */
    private static List<List<Path>> createScanResult(int size) {
        List<List<Path>> result = new ArrayList<>(size);

        for (int i = 0; i < size; ++i) {
            result.add(new ArrayList<>());
        }

        return result;
    }

    /**
     * Checks whether this file has the specified extensions.
     */
    private static boolean hasExtension(String fileName, List<String> extensions) {
        for (String extension : extensions) {
            if (fileName.endsWith(extension)) {
                return true;
            }
        }

        return false;
    }
}
