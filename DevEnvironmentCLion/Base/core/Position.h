#ifndef POSITION_H_26b7ee00_0ae0_478e_89f7_1106f21335f2
#define POSITION_H_26b7ee00_0ae0_478e_89f7_1106f21335f2

namespace base
{
    /**
     * The Position class implements a position.
     */
    class Position final
    {
    public:
        /**
         * The constructor.
         */
        Position(long row, long column);

        /**
         * The destructor.
         */
        virtual ~Position();

        /**
         * The copy/move constructors.
         */
        Position(const Position&);
        Position(Position&&) = default;

        /**
         * The copy/move assignment operators.
         */
        Position& operator=(const Position&);
        Position& operator=(Position&&) = default;

        /**
         * Gets the row of a specific position.
         */
        inline long getRow() const;

        /**
         * Gets the column of a specific position.
         */
        inline long getColumn() const;

    private:
        long m_row;
        long m_column;
    };

    inline long Position::getRow() const
    {
        return m_row;
    }

    inline long Position::getColumn() const
    {
        return m_column;
    }

    inline bool operator<(const Position& left, const Position& right)
    {
        if (left.getRow() < right.getRow())
        {
            return true;
        }

        if (left.getRow() > right.getRow())
        {
            return false;
        }

        return left.getColumn() < right.getColumn();
    }

    inline Position operator+(const Position& left, const Position& right)
    {
        Position result(
            left.getRow() + right.getRow(),
            left.getColumn() + right.getColumn());

        return result;
    }

    inline Position operator-(const Position& left, const Position& right)
    {
        Position result(
            left.getRow() - right.getRow(),
            left.getColumn() - right.getColumn());

        return result;
    }
}

#endif // POSITION_H_26b7ee00_0ae0_478e_89f7_1106f21335f2
