#ifndef I_POSITION_QUEENS_H_46ea5dba_32bb_4077_be5f_caa9fd9dbe42
#define I_POSITION_QUEENS_H_46ea5dba_32bb_4077_be5f_caa9fd9dbe42

#include "BaseDependencies.h"

namespace problems
{
    /**
     * The IPositionQueens interface defines a position queens problem.
     */
    class IPositionQueens
    {
    public:
        /**
         * The constructor.
         */
        IPositionQueens() = default;

        /**
         * The destructor.
         */
        virtual ~IPositionQueens() = default;

        /**
         * The copy/move constructors.
         */
        IPositionQueens(const IPositionQueens&) = delete;
        IPositionQueens(IPositionQueens&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IPositionQueens& operator=(const IPositionQueens&) = delete;
        IPositionQueens& operator=(IPositionQueens&&) = delete;

        /**
         * Positions queens.
         */
        virtual std::vector<std::vector<std::string>> positionQueens(int size) = 0;
    };

}

#endif // I_POSITION_QUEENS_H_46ea5dba_32bb_4077_be5f_caa9fd9dbe42
