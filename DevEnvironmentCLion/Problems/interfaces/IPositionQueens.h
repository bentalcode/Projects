#ifndef I_POSITION_QUEENS_H_ef889057_2648_4076_8c54_795efa76f5df
#define I_POSITION_QUEENS_H_ef889057_2648_4076_8c54_795efa76f5df

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

#endif // I_POSITION_QUEENS_H_ef889057_2648_4076_8c54_795efa76f5df
