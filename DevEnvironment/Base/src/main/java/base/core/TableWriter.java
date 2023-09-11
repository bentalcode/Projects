package base.core;

import base.interfaces.IMatrix;
import base.interfaces.ITableWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

/**
 * The TableWriter class implements a writer of a table.
 */
public final class TableWriter implements ITableWriter {
    private static final String HORIZONTAL_LINE_UNIT = "-";
    private static final String VERTICAL_LINE_UNIT = "|";
    private static final String PAD_UNIT = " ";

    private final Writer writer;
    private final String horizontalLineUnit;
    private final String verticalLineUnit;
    private final String padUnit;

    /**
     * The TableWriter constructor.
     */
    public TableWriter(Writer writer) {
        this(
            writer,
                HORIZONTAL_LINE_UNIT,
                VERTICAL_LINE_UNIT,
                PAD_UNIT);
    }

    /**
     * The TableWriter constructor.
     */
    public TableWriter(
        Writer writer,
        String horizontalLineUnit,
        String verticalLineUnit,
        String padUnit) {

        Conditions.validateNotNull(
            writer,
            "The writer of a table.");

        Conditions.validateStringNotNullOrEmpty(
            horizontalLineUnit,
            "The horizontal line unit of a table.");

        Conditions.validateStringNotNullOrEmpty(
            verticalLineUnit,
            "The vertical line unit of a table.");

        Conditions.validateStringNotNullOrEmpty(
            padUnit,
            "The pad unit of a table.");

        this.writer = writer;
        this.horizontalLineUnit = horizontalLineUnit;
        this.verticalLineUnit = verticalLineUnit;
        this.padUnit = padUnit;
    }

    /**
     * Writes a table.
     */
    @Override
    public void write(
        List<String> header,
        IMatrix<String> data) {

        Conditions.validateNotNull(
            header,
            "The header of a table.");

        Conditions.validateNotNull(
            data,
            "The data of a table.");

        Conditions.validate(
            header.size() == data.colsSize(),
            "The header of a table does match the dimensions of it's data.");

        List<Integer> columnsLengths = calculateColumnsLengths(header, data);
        int width = calculateTableWidth(columnsLengths);

        this.writeHeader(header, width, columnsLengths);

        for (int rowIndex = 0; rowIndex < data.rowsSize(); ++rowIndex) {
            List<String> rowValues = data.getRow(rowIndex);
            this.writeRow(rowValues, width, columnsLengths);
        }
    }

    /**
     * Writes a header of a table.
     */
    private void writeHeader(List<String> headerValues, int width, List<Integer> columnsLengths) {
        this.drawLine(width);
        this.writeRow(headerValues, width, columnsLengths);
    }

    /**
     * Writes a row of a table.
     */
    private void writeRow(List<String> rowValues, int width, List<Integer> columnsLengths) {
        assert(rowValues.size() == columnsLengths.size());

        StringBuilder rowBuilder = new StringBuilder();
        this.append(this.verticalLineUnit, rowBuilder);

        int columnsSize = columnsLengths.size();
        for (int columnIndex = 0; columnIndex < columnsSize; ++columnIndex) {
            String cellValue = rowValues.get(columnIndex);
            int cellWidth = columnsLengths.get(columnIndex);

            this.appendCell(
                cellValue,
                cellWidth,
                rowBuilder);

            this.append(this.verticalLineUnit, rowBuilder);
        }

        this.writeLine(rowBuilder.toString());
        this.drawLine(width);
    }

    /**
     * Appends a cell.
     */
    private void appendCell(String content, int width, StringBuilder result) {
        int prePadSize = 1;
        int postPadSize = width - prePadSize - content.length();

        this.appendPad(prePadSize, result);
        this.append(content, result);
        this.appendPad(postPadSize, result);
    }

    /**
     * Calculates the lengths of columns.
     */
    private static List<Integer> calculateColumnsLengths(List<String> header, IMatrix<String> data) {
        assert(header.size() == data.colsSize());

        int columnSize = header.size();
        List<Integer> result = new ArrayList<>(columnSize);

        for (int columnIndex = 0; columnIndex < columnSize; ++columnIndex) {
            String headerValue = header.get(columnIndex);
            int maxValueLength = calculateMaxValueLength(data, columnIndex);

            int colLength = calculateColumnLength(headerValue, maxValueLength);

            result.add(colLength);
        }

        return result;
    }

    /**
     * Calculates the width of a table.
     */
    private static int calculateTableWidth(List<Integer> columnsLengths) {
        int width = 2;

        for (int columnLength : columnsLengths) {
            width += columnLength;
        }

        return width;
    }

    /**
     * Calculates the maximum length of a value.
     */
    private static int calculateMaxValueLength(IMatrix<String> data, int columnIndex) {
        int maxLength = 0;

        for (int rowIndex = 0; rowIndex < data.rowsSize(); ++rowIndex) {
            String value = data.get(rowIndex, columnIndex);

            if (value.length() > maxLength) {
                maxLength = value.length();
            }
        }

        return maxLength;
    }

    /**
     * Calculates the length of a column.
     */
    private static int calculateColumnLength(String columnName, int maxValueLength) {
        int length = Math.max(columnName.length(), maxValueLength);

        if (length == 0) {
            return 1;
        }

        return length + 2;
    }

    /**
     * Draws a line.
     */
    private void drawLine(int size) {
        StringBuilder lineBuilder = new StringBuilder();

        for (int i = 0; i < size; ++i) {
            lineBuilder.append(this.horizontalLineUnit);
        }

        this.writeLine(lineBuilder.toString());
    }

    /**
     * Writes a line.
     */
    private void writeLine(String content) {
        Writers.write(this.writer, content);
        Writers.write(this.writer, "\n");
    }

    /**
     * Appends a content.
     */
    private void append(String content, StringBuilder result) {
        result.append(content);
    }

    /**
     * Appends a pad.
     */
    private void appendPad(int size, StringBuilder result) {
        for (int i = 0; i < size; ++i) {
            result.append(this.padUnit);
        }
    }
}
