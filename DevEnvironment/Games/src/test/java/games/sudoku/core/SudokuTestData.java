package games.sudoku.core;

import java.util.ArrayList;
import java.util.List;
import games.sudoku.interfaces.ISudokuData;
import games.sudoku.interfaces.ISudokuTestData;

/**
 * The SudokuTestData class implements data of tests of a Sudoku.
 */
public final class SudokuTestData implements ISudokuTestData {
    /**
     * The SudokuTestData constructor.
     */
    public SudokuTestData() {
    }

    /**
     * Gets the data of a Sudoku.
     */
    @Override
    public List<ISudokuData> getData() {
        List<ISudokuData> data = new ArrayList<>();

        data.add(this.getSudokuData1());

        return data;
    }

    /**
     * Gets the data of Sudoku1.
     */
    private ISudokuData getSudokuData1() {
        char[][] board =
        {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        char[][] resultBoard =
        {
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
        };

        return new SudokuData(
            board,
            resultBoard);
    }
}
