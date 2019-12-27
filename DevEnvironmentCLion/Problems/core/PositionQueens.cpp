#include "PreCompiled.h"

#include "PositionQueens.h"

using namespace problems;

/**
 * Positions queens.
 */
std::vector<std::vector<std::string>> PositionQueens::positionQueens(int size)
{
    std::vector<std::vector<int>> positions;

    if (size < 4) {
        return createResults(positions);
    }

    int currColumnIndex = 0;
    std::vector<int> currPosition(size, -1);

    positionQueens(
        size,
        currPosition,
        currColumnIndex,
        positions);

    return createResults(positions);
}

/**
 * Positions queens.
 */
void PositionQueens::positionQueens(
    int size,
    std::vector<int>& currPosition,
    int currColIndex,
    std::vector<std::vector<int>>& positions)
{
    assert(currColIndex >= 0 && currColIndex <= size);

    if (currColIndex > size)
    {
        return;
    }

    if (currColIndex == size)
    {
        std::vector<int> newPosition(currPosition);
        positions.push_back(newPosition);
        return;
    }

    for (int currRowIndex = 0; currRowIndex < size; ++currRowIndex)
    {
        positionQueen(currPosition, currRowIndex, currColIndex);

        if (validatePosition(size, currPosition, currRowIndex, currColIndex))
        {
            positionQueens(
                size,
                currPosition,
                currColIndex + 1,
                positions);
        }

        unPositionQueen(currPosition, currColIndex);
    }
}

/**
 * Validates a specific position.
 */
bool PositionQueens::validatePosition(
    int size,
    std::vector<int>& currPosition,
    int rowIndex,
    int colIndex)
{
    //
    // Validate row...
    //
    int currRowIndex = rowIndex;
    int currColIndex = colIndex - 1;

    while (currColIndex >= 0)
    {
        if (hasQueen(currPosition, currRowIndex, currColIndex))
        {
            return false;
        }

        --currColIndex;
    }

    //
    // Validate diagonal: LeftUpper->RightBottom
    //
    currRowIndex = rowIndex + 1;
    currColIndex = colIndex - 1;

    while (currRowIndex < size && currColIndex >= 0)
    {
        if (hasQueen(currPosition, currRowIndex, currColIndex))
        {
            return false;
        }

        ++currRowIndex;
        --currColIndex;
    }

    //
    // Validate diagonal: LeftBottom->RightUpper
    //
    currRowIndex = rowIndex - 1;
    currColIndex = colIndex - 1;

    while (currRowIndex >= 0 && currColIndex >= 0)
    {
        if (hasQueen(currPosition, currRowIndex, currColIndex))
        {
            return false;
        }

        --currRowIndex;
        --currColIndex;
    }

    return true;
}

/**
 * Positions a queen.
 */
void PositionQueens::positionQueen(
    std::vector<int>& currPosition,
    int currRowIndex,
    int currColIndex)
{
    currPosition[currColIndex] = currRowIndex;
}

/**
 * UnPositions a queen.
 */
void PositionQueens::unPositionQueen(
    std::vector<int>& currPosition,
    int currColIndex)
{
    currPosition[currColIndex] = -1;
}

/**
 * Checks whether the specific position includes a queen.
 */
bool PositionQueens::hasQueen(std::vector<int>& position, int rowIndex, int columnIndex) {
    return position[columnIndex] == rowIndex;
}

/**
 * Create results.
 */
std::vector<std::vector<std::string>> PositionQueens::createResults(const std::vector<std::vector<int>>& positions)
{
    std::vector<std::vector<std::string>> results;

    for (const std::vector<int>& position : positions)
    {
        std::vector<std::string> result = createResult(position);
        results.push_back(result);
    }

    return results;
}

/**
 * Create a result.
 */
std::vector<std::string> PositionQueens::createResult(const std::vector<int>& position)
{
    int size = position.size();
    std::vector<std::string> result(size);

    for (int rowIndex = 0; rowIndex < size; ++rowIndex)
    {
        std::vector<char> currRow(size);

        for (int colIndex = 0; colIndex < size; ++colIndex)
        {
            char currCharacter = getPositionCharacter(position, rowIndex, colIndex);
            currRow[colIndex] = currCharacter;
        }

        std::string currRowString(currRow.begin(), currRow.end());
        result[rowIndex] = currRowString;
    }

    return result;
}

/**
 * Gets a specific character of a position.
 */
char PositionQueens::getPositionCharacter(const std::vector<int>& position, int rowIndex, int colIndex)
{
    int currRowIndex = position[colIndex];

    if (currRowIndex == rowIndex)
    {
        return 'Q';
    }
    else
    {
        return '.';
    }
}


