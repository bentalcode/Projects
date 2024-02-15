#ifndef POSITION_H_07c3409f_947b_41d2_ac03_5362fe879678
#define POSITION_H_07c3409f_947b_41d2_ac03_5362fe879678

namespace base
{
    /**
     * The Position class implements a position.
     */
    template <typename T>
    class Position final
    {
    public:
        /**
         * The constructor.
         */
        Position(const T& row, const T& col);

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
        T GetRow() const;

        /**
         * Gets the column of a specific position.
         */
        T GetColumn() const;

        /**
         * Defines operator add of position.
         */
        Position<T>& operator+=(const Position<T>& right);

        /**
         * Defines operator minus of position.
         */
        Position<T>& operator-=(const Position<T>& right);

    private:
        T m_row;
        long m_col;
    };

    /**
     * The constructor.
     */
    template <typename T>
    Position<T>::Position(const T& row, const T& col) :
        m_row(row),
        m_col(col)
    {
    }

    /**
     * The destructor.
     */
    template <typename T>
    Position<T>::~Position()
    {
    }

    /**
     * Gets the row of a specific position.
     */
    template <typename T>
    T Position<T>::GetRow() const
    {
        return m_row;
    }

    /**
     * Gets the column of a specific position.
     */
    template <typename T>
    T Position<T>::GetColumn() const
    {
        return m_col;
    }

    /**
     * Defines operator add of position.
     */
    template <typename T>
    Position<T>& Position<T>::operator+=(const Position<T>& right)
    {
        m_row += right.GetRow();
        m_col += right.GetColumn();
        return *this;
    }

    /**
     * Defines operator minus of position.
     */
    template <typename T>
    Position<T>& Position<T>::operator-=(const Position<T>& right)
    {
        m_row -= right.GetRow();
        m_col -= right.GetColumn();
        return *this;
    }

    /**
     * Defines operator less than of positions.
     */
    template <typename T>
    inline bool operator<(const Position<T>& left, const Position<T>& right)
    {
        if (left.GetRow() < right.GetRow())
        {
            return true;
        }

        if (left.GetRow() > right.GetRow())
        {
            return false;
        }

        return left.GetColumn() < right.GetColumn();
    }

    /**
     * Defines operator add of positions.
     */
    template <typename T>
    inline Position<T> operator+(
        const Position<T>& left,
        const Position<T>& right)
    {
        Position<T> result(
            left.GetRow() + right.GetRow(),
            left.GetColumn() + right.GetColumn());

        return result;
    }

    /**
     * Defines operator minus of positions.
     */
    template <typename T>
    inline Position<T> operator-(
        const Position<T>& left,
        const Position<T>& right)
    {
        Position<T> result(
            left.GetRow() - right.GetRow(),
            left.GetColumn() - right.GetColumn());

        return result;
    }
}

#endif // POSITION_H_07c3409f_947b_41d2_ac03_5362fe879678
