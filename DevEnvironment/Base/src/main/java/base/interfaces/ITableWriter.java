package base.interfaces;

import java.util.List;

/**
 * The ITableWriter interface defines a writer of a table.
 */
public interface ITableWriter {
    /**
     * Writes a table.
     */
    void write(
        List<String> header,
        IMatrix<String> data);
}
