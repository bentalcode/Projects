#ifndef PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9
#define PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9

namespace base
{
    /**
     * The Pair class template implements a pair.
     */
    template<typename Type1, typename Type2>
    class Pair final
    {
    public:
        /**
         * The constructor.
         */
        Pair(const Type1& first, const Type2& second);

        /**
         * The destructor.
         */
        ~Pair();

        /**
         * The copy/move constructors.
         */
        Pair(const Pair& rhs) = default;
        Pair(Pair&&) = default;

        /**
         * The copy/move assignment operators.
         */
        Pair& operator=(const Pair&) = default;
        Pair& operator=(Pair&&) = default;

        /**
         * Gets the first element.
         */
        const Type1& getFirst() const;

        /**
         * Gets the second element.
         */
        const Type2& getSecond() const;

    private:
        Type1 m_first;
        Type2 m_second;
    };

    template<typename Type1, typename Type2>
    Pair<Type1, Type2>::Pair(const Type1& first, const Type2& second) :
        m_first(first),
        m_second(second)
    {
    }

    template<typename Type1, typename Type2>
    Pair<Type1, Type2>::~Pair()
    {
    }

    template<typename Type1, typename Type2>
    const Type1& Pair<Type1, Type2>::getFirst() const
    {
        return m_first;
    }

    template<typename Type1, typename Type2>
    const Type2& Pair<Type1, Type2>::getSecond() const
    {
        return m_second;
    }

    template<typename Type1, typename Type2>
    bool operator<(const Pair<Type1, Type2>& left, const Pair<Type1, Type2>& right) {
        if (left.getFirst() < right.getFirst()) {
            return true;
        }

        if (left.getFirst() > right.getFirst()) {
            return false;
        }

        return left.getSecond() < right.getSecond();
    }
}

#endif // PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9
