#ifndef TRIPLE_H_46a00302_840a_4a69_89c0_7bb9880d1685
#define TRIPLE_H_46a00302_840a_4a69_89c0_7bb9880d1685

namespace base
{
    /**
     * The Triple class template implements a triple.
     */
    template<typename Type1, typename Type2, typename Type3>
    class Triple final
    {
    public:
        Triple(const Type1& first, const Type2& second, const Type3& third);
        Triple(const Triple& rhs);
        ~Triple();

        const Type1& getFirst() const;
        const Type2& getSecond() const;
        const Type3& getThird() const;

    private:
        Type1 m_first;
        Type2 m_second;
        Type2 m_third;
    };

    template<typename Type1, typename Type2, typename Type3>
    Triple<Type1, Type2, Type3>::Triple(const Type1& first, const Type2& second, const Type3& third) :
        m_first(first),
        m_second(second),
        m_third(third)
    {
    }

    template<typename Type1, typename Type2, typename Type3>
    Triple<Type1, Type2, Type3>::Triple(const Triple& rhs) :
        m_first(rhs.m_first),
        m_second(rhs.m_second),
        m_third(rhs.m_third)
    {
    }

    template<typename Type1, typename Type2, typename Type3>
    Triple<Type1, Type2, Type3>::~Triple()
    {
    }

    template<typename Type1, typename Type2, typename Type3>
    const Type1& Triple<Type1, Type2, Type3>::getFirst() const
    {
        return m_first;
    }

    template<typename Type1, typename Type2, typename Type3>
    const Type2& Triple<Type1, Type2, Type3>::getSecond() const
    {
        return m_second;
    }

    template<typename Type1, typename Type2, typename Type3>
    const Type3& Triple<Type1, Type2, Type3>::getThird() const
    {
        return m_third;
    }

    template<typename Type1, typename Type2, typename Type3>
    bool operator<(const Triple<Type1, Type2, Type3>& left, const Triple<Type1, Type2, Type3>& right) {
        if (left.getFirst() < right.getFirst()) {
            return true;
        }

        if (left.getFirst() > right.getFirst()) {
            return false;
        }

        if (left.getSecond() < right.getSecond()) {
            return true;
        }

        if (left.getSecond() > right.getSecond()) {
            return false;
        }

        return left.getThird() < right.getThird();
    }
}

#endif // TRIPLE_H_46a00302_840a_4a69_89c0_7bb9880d1685
