#ifndef POSITION_QUEENS_H_1ad3c029_67b7_4a3d_8b2e_e8b076ab0751
#define POSITION_QUEENS_H_1ad3c029_67b7_4a3d_8b2e_e8b076ab0751

#include "IQueensPositioning.h"

namespace problems
{
    /**
     * The QueensPositioning class implements a queens positioning problem.
     */
    class QueensPositioning final : public IQueensPositioning {
    public:
        /**
         * The constructor.
         */
        QueensPositioning() = default;

        /**
         * The destructor.
         */
        virtual ~QueensPositioning() = default;

        /**
         * The copy/move constructors.
         */
        QueensPositioning(const QueensPositioning&) = delete;
        QueensPositioning(QueensPositioning&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        QueensPositioning& operator=(const QueensPositioning&) = delete;
        QueensPositioning& operator=(QueensPositioning&&) = delete;

        /**
         * Positions queens.
         */
        virtual std::vector<std::vector<std::wstring>> PositionQueens(size_t size) override;

    private:
        /**
         * Positions queens.
         */
        void PositionQueens(
            std::vector<int>& position,
            size_t colIndex,
            std::vector<std::vector<int>>& positions);

        /**
         * Checks whether a specific position is valid.
         */
        bool IsPositionValid(
            std::vector<int>& currPosition,
            size_t rowIndex,
            size_t colIndex);

        /**
         * Sets queen position.
         */
        void SetQueenPosition(
            std::vector<int>& position,
            size_t rowIndex,
            size_t colIndex);

        /**
         * Unsets queen position.
         */
        void UnsetQueenPosition(
            std::vector<int>& position,
            size_t colIndex);

        /**
         * Checks whether the specific position includes a queen.
         */
        bool HasQueen(
            std::vector<int>& position,
            size_t rowIndex,
            size_t columnIndex);

        /**
         * Create board results.
         */
        static std::vector<std::vector<std::wstring>> CreateBoardResults(
            const std::vector<std::vector<int>>& positions);

        /**
         * Create a board result.
         */
        static std::vector<std::wstring> CreateBoardResult(
            const std::vector<int>& position);

        /**
         * Gets a specific character of a position.
         */
        static std::wstring::value_type GetPositionCharacter(
            const std::vector<int>& position,
            size_t rowIndex,
            size_t colIndex);
    };
}

#endif // POSITION_QUEENS_H_1ad3c029_67b7_4a3d_8b2e_e8b076ab0751
