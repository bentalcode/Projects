#ifndef TRIPLE_H_4c6d7a66_4121_46d3_b014_31489f56a076
#define TRIPLE_H_4c6d7a66_4121_46d3_b014_31489f56a076

namespace base
{
    /**
     * The Triple class template implements a triple.
     */
    template<typename Type1, typename Type2, typename Type3>
    class Triple final
    {
    public:
        /**
         * The constructor.
         */
        Triple(const Type1& first, const Type2& second, const Type3& third);

        /**
         * The destructor.
         */
        ~Triple();

        /**
         * The copy/move constructors.
         */
        Triple(const Triple&) = default;
        Triple(Triple&&) = default;

        /**
         * The copy/move assignment operators.
         */
        Triple& operator=(const Triple&) = default;
        Triple& operator=(Triple&&) = default;

        /**
         * Gets the first element.
         */
        const Type1& getFirst() const;

        /**
         * Gets the second element.
         */
        const Type2& getSecond() const;

        /**
         * Gets the third element.
         */
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

#endif // TRIPLE_H_4c6d7a66_4121_46d3_b014_31489f56a076
