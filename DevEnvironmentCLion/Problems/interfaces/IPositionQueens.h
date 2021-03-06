#ifndef I_POSITION_QUEENS_H_b91590fa_e0b3_4e6f_965c_95e281a3fdc1
#define I_POSITION_QUEENS_H_b91590fa_e0b3_4e6f_965c_95e281a3fdc1

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

#endif // I_POSITION_QUEENS_H_b91590fa_e0b3_4e6f_965c_95e281a3fdc1
