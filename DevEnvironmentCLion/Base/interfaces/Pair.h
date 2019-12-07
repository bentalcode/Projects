#ifndef PAIR_H_b150619a_9f60_4a1a_8df9_d7ef0debe4ca
#define PAIR_H_b150619a_9f60_4a1a_8df9_d7ef0debe4ca

namespace base
{
    /**
     * The Pair class template implements a pair.
     */
    template<typename Type1, typename Type2>
    class Pair final
    {
    public:
        Pair(const Type1& first, const Type2& second);
        Pair(const Pair& rhs);
        ~Pair();

        const Type1& getFirst() const;
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
    Pair<Type1, Type2>::Pair(const Pair& rhs) :
        m_first(rhs.m_first),
        m_second(rhs.m_second)
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

#endif // PAIR_H_b150619a_9f60_4a1a_8df9_d7ef0debe4ca
