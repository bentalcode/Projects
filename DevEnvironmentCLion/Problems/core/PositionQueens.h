#ifndef POSITION_QUEENS_H_1ff82a68_29ad_4200_8014_8493b5554094
#define POSITION_QUEENS_H_1ff82a68_29ad_4200_8014_8493b5554094

#include "IPositionQueens.h"

namespace problems
{
    /**
     * The PositionQueens class implements the position queens problem.
     */
    class PositionQueens final : public IPositionQueens
    {
    public:
        /**
         * The constructor.
         */
        PositionQueens() = default;

        /**
         * The destructor.
         */
        virtual ~PositionQueens() = default;

        /**
         * The copy/move constructors.
         */
        PositionQueens(const PositionQueens&) = delete;
        PositionQueens(PositionQueens&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        PositionQueens& operator=(const PositionQueens&) = delete;
        PositionQueens& operator=(PositionQueens&&) = delete;

        /**
         * Positions queens.
         */
        virtual std::vector<std::vector<std::string>> positionQueens(int size);

    private:
        /**
         * Positions queens.
         */
        void positionQueens(
            int size,
            std::vector<int>& currPosition,
            int currColIndex,
            std::vector<std::vector<int>>& positions);

        /**
         * Validates a specific position.
         */
        bool validatePosition(
            int size,
            std::vector<int>& currPosition,
            int rowIndex,
            int colIndex);

        /**
         * Positions a queen.
         */
        void positionQueen(
            std::vector<int>& currPosition,
            int currRowIndex,
            int currColIndex);

        /**
         * UnPositions a queen.
         */
        void unPositionQueen(
            std::vector<int>& currPosition,
            int currColIndex);

        /**
         * Checks whether the specific position includes a queen.
         */
        bool hasQueen(std::vector<int>& position, int rowIndex, int columnIndex);

        /**
         * Create results.
         */
        std::vector<std::vector<std::string>> createResults(const std::vector<std::vector<int>>& positions);

        /**
         * Create a result.
         */
         std::vector<std::string> createResult(const std::vector<int>& position);

        /**
         * Gets a specific character of a position.
         */
        char getPositionCharacter(const std::vector<int>& position, int rowIndex, int colIndex);
    };
}

#endif // POSITION_QUEENS_H_1ff82a68_29ad_4200_8014_8493b5554094
