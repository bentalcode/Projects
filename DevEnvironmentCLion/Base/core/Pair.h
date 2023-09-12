#ifndef PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9
#define PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9

namespace base
{
    /**
     * The Pair class template implements a pair.
     */
    template <typename Type1, typename Type2>
    class Pair final
    {
    public:
        /**
         * Creates a new pair.
         */
        static std::shared_ptr<Pair<Type1, Type2>> make(const Type1& first, const Type2& second);

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

        /**
         * Gets the string representation of this instance.
         */
        std::string toString() const;

    private:
        Type1 m_first;
        Type2 m_second;
    };

    //
    // Defines the SharedPtr of pairs...
    //
    template <typename Type1, typename Type2>
    using PairSharedPtr = std::shared_ptr<Pair<Type1, Type2>>;

    /**
     * Creates a new pair.
     */
    template <typename Type1, typename Type2>
    PairSharedPtr<Type1, Type2> Pair<Type1, Type2>::make(const Type1& first, const Type2& second)
    {
        return std::make_shared<Pair<Type1, Type2>>(first, second);
    }

    /**
     * The constructor.
     */
    template <typename Type1, typename Type2>
    Pair<Type1, Type2>::Pair(const Type1& first, const Type2& second) :
        m_first(first),
        m_second(second)
    {
    }

    /**
     * The destructor.
     */
    template <typename Type1, typename Type2>
    Pair<Type1, Type2>::~Pair()
    {
    }

    /**
     * Gets the first element.
     */
    template <typename Type1, typename Type2>
    const Type1& Pair<Type1, Type2>::getFirst() const
    {
        return m_first;
    }

    /**
     * Gets the second element.
     */
    template <typename Type1, typename Type2>
    const Type2& Pair<Type1, Type2>::getSecond() const
    {
        return m_second;
    }

    /**
     * Gets the string representation of this instance.
     */
    template <typename Type1, typename Type2>
    std::string Pair<Type1, Type2>::toString() const
    {
        std::stringstream stream;
        stream << "(" << m_first << "," << m_second << ")";
        return stream.str();
    }

    /**
     * The operator< for implementing equivalence relation.
     */
    template <typename Type1, typename Type2>
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
