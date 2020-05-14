#include "PreCompiled.h"

#include "WordFinder.h"

using namespace problems;

/**
 * The constructor.
 */
WordFinder::WordFinder(
    const base::Matrix<char>& matrix,
    const std::string& word) :
    m_matrix(matrix),
    m_word(word)
{
    m_directions.push_back(base::Position(0, -1));
    m_directions.push_back(base::Position(0, 1));
    m_directions.push_back(base::Position(-1, 0));
    m_directions.push_back(base::Position(1, 0));
}

/**
 * Finds all paths of a word in a matrix.
 */
std::vector<std::vector<base::Position>> WordFinder::find()
{
    std::vector<std::vector<base::Position>> result;

    if (m_word.empty())
    {
        return result;
    }

    char firstCharacter = m_word[0];

    for (std::size_t row = 0; row < m_matrix.rowsSize(); ++row)
    {
        for (std::size_t col = 0; col < m_matrix.colsSize(); ++col)
        {
            char currCharacter = m_matrix[row][col];

            if (currCharacter != firstCharacter)
            {
                continue;
            }

            base::Position currPosition(row, col);
            std::vector<base::Position> currPath;
            std::set<base::Position> visited;

            find(
                currPosition,
                currPath,
                visited,
                result);
        }
    }

    return result;
}

/**
 * Finds all paths of a word in a matrix.
 */
 void WordFinder::find(
    const base::Position& currPosition,
    std::vector<base::Position>& currPath,
    std::set<base::Position>& visited,
    std::vector<std::vector<base::Position>>& result) const
 {
     assert(currPath.size() >= 0 && currPath.size() < m_word.size());

     if (visited.find(currPosition) != visited.end() || currPath.size() >= m_word.size())
     {
         return;
     }

     std::string::value_type currCharacter = m_matrix[currPosition.getRow()][currPosition.getColumn()];
     std::size_t wordCharacterIndex = currPath.size();
     std::string::value_type wordCharacter = m_word[wordCharacterIndex];

     if (currCharacter != wordCharacter)
     {
         return;
     }

     if (currPath.size() == m_word.size() - 1)
     {
         std::vector<base::Position> newResult(currPath);
         newResult.push_back(currPosition);
         result.push_back(newResult);
         return;
     }

     currPath.push_back(currPosition);
     visited.insert(currPosition);

     for (const base::Position& nextPosition : getNextPositions(currPosition))
     {
        if (visited.find(nextPosition) != visited.end())
        {
            continue;
        }

        find(
            nextPosition,
            currPath,
            visited,
            result);
     }

     visited.erase(currPosition);
     currPath.erase(currPath.end() - 1);
 }

/**
 * Gets the next positions.
 */
std::vector<base::Position> WordFinder::getNextPositions(const base::Position& currPosition) const
{
    std::vector<base::Position> result;

    for (const base::Position& direction : m_directions)
    {
        base::Position nextPosition = currPosition + direction;

        if (m_matrix.inbound(nextPosition))
        {
            result.push_back(nextPosition);
        }
    }

    return result;
}
