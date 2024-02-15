#include "QueensPositioning.h"
#include <assert.h>

using namespace problems;

/**
 * Positions queens.
 */
std::vector<std::vector<std::wstring>> QueensPositioning::PositionQueens(size_t size)
{
    std::vector<std::vector<int>> positions;

    if (size == 1)
    {
        std::vector<int> position = {0};
        positions.push_back(position);
        return CreateBoardResults(positions);
    }

    if (size < 4) {
        return CreateBoardResults(positions);
    }

    size_t currColIndex = 0;
    std::vector<int> currPosition(size, -1);

    PositionQueens(
        currPosition,
        currColIndex,
        positions);

    return CreateBoardResults(positions);
}

/**
 * Positions queens.
 */
void QueensPositioning::PositionQueens(
    std::vector<int>& position,
    size_t colIndex,
    std::vector<std::vector<int>>& positions)
{
    size_t size = position.size();
    assert(colIndex <= size);

    if (colIndex > size)
    {
        return;
    }

    if (colIndex == size)
    {
        std::vector<int> newPosition(position);
        positions.push_back(newPosition);
        return;
    }

    for (size_t rowIndex = 0; rowIndex < size; ++rowIndex)
    {
        SetQueenPosition(position, rowIndex, colIndex);

        if (IsPositionValid(position, rowIndex, colIndex))
        {
            PositionQueens(
                position,
                colIndex + 1,
                positions);
        }

        UnsetQueenPosition(position, colIndex);
    }
}

/**
 * Validates a specific position.
 */
bool QueensPositioning::IsPositionValid(
    std::vector<int>& position,
    size_t rowIndex,
    size_t colIndex)
{
    size_t size = position.size();

    //
    // Validate row...
    //
    long long currRowIndex = rowIndex;
    long long currColIndex = colIndex - 1;

    while (currColIndex >= 0)
    {
        if (HasQueen(position, currRowIndex, currColIndex))
        {
            return false;
        }

        --currColIndex;
    }

    //
    // Validate upper column...
    //
    currRowIndex = rowIndex + 1;
    currColIndex = colIndex;

    while (currRowIndex < size)
    {
        if (HasQueen(position, currRowIndex, currColIndex))
        {
            return false;
        }

        ++currRowIndex;
    }

    //
    // Validate bottom column...
    //
    currRowIndex = rowIndex - 1;
    currColIndex = colIndex;

    while (currRowIndex >= 0)
    {
        if (HasQueen(position, currRowIndex, currColIndex))
        {
            return false;
        }

        --currRowIndex;
    }

    //
    // Validate diagonal: RightBottom -> LeftUpper
    //
    currRowIndex = rowIndex + 1;
    currColIndex = colIndex - 1;

    while (currRowIndex < size && currColIndex >= 0)
    {
        if (HasQueen(position, currRowIndex, currColIndex))
        {
            return false;
        }

        ++currRowIndex;
        --currColIndex;
    }

    //
    // Validate diagonal: RightUpper -> LeftBottom
    //
    currRowIndex = rowIndex - 1;
    currColIndex = colIndex - 1;

    while (currRowIndex >= 0 && currColIndex >= 0)
    {
        if (HasQueen(position, currRowIndex, currColIndex))
        {
            return false;
        }

        --currRowIndex;
        --currColIndex;
    }

    return true;
}

/**
 * Sets queen position.
 */
void QueensPositioning::SetQueenPosition(
    std::vector<int>& position,
    size_t rowIndex,
    size_t colIndex)
{
    position[colIndex] = rowIndex;
}

/**
 * Unsets queen position.
 */
void QueensPositioning::UnsetQueenPosition(
    std::vector<int>& position,
    size_t colIndex)
{
    position[colIndex] = -1;
}

/**
 * Checks whether the specific position includes a queen.
 */
bool QueensPositioning::HasQueen(
    std::vector<int>& position,
    size_t rowIndex,
    size_t columnIndex)
{
    return position[columnIndex] == rowIndex;
}

/**
 * Create board results.
 */
std::vector<std::vector<std::wstring>> QueensPositioning::CreateBoardResults(
    const std::vector<std::vector<int>>& positions)
{
    std::vector<std::vector<std::wstring>> results;

    for (const std::vector<int>& position : positions)
    {
        std::vector<std::wstring> result = CreateBoardResult(position);
        results.push_back(result);
    }

    return results;
}

/**
 * Create a result.
 */
std::vector<std::wstring> QueensPositioning::CreateBoardResult(const std::vector<int>& positions)
{
    size_t size = positions.size();
    std::vector<std::wstring> board;
    board.reserve(size);

    for (size_t rowIndex = 0; rowIndex < size; ++rowIndex)
    {
        std::vector<std::wstring::value_type> row;
        row.reserve(size);

        for (size_t colIndex = 0; colIndex < size; ++colIndex)
        {
            std::wstring::value_type character = GetPositionCharacter(
                positions,
                rowIndex,
                colIndex);

            row.push_back(character);
        }

        std::wstring rowString(row.begin(), row.end());
        board.push_back(rowString);
    }

    return board;
}

/**
 * Gets a specific character of a position.
 */
std::wstring::value_type QueensPositioning::GetPositionCharacter(
    const std::vector<int>& position,
    size_t rowIndex,
    size_t colIndex)
{
    return position[colIndex] == rowIndex ? L'Q' : L'.';
}
