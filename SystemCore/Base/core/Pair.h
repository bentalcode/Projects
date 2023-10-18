#ifndef PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9
#define PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9

#include <sstream>

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
        static std::shared_ptr<Pair<Type1, Type2>> Make(
            const Type1& first,
            const Type2& second);

        /**
         * The constructor.
         */
        Pair(
            const Type1& first,
            const Type2& second);

        /**
         * The destructor.
         */
        ~Pair();

        /**
         * The Copy/move constructors.
         */
        Pair(const Pair& rhs) = default;
        Pair(Pair&&) = default;

        /**
         * The Copy/move assignment operators.
         */
        Pair& operator=(const Pair&) = default;
        Pair& operator=(Pair&&) = default;

        /**
         * Gets the first Element.
         */
        const Type1& GetFirst() const;

        /**
         * Gets the second Element.
         */
        const Type2& GetSecond() const;

        /**
         * Gets the string representation ofthis instance.
         */
        std::wstring toString() const;

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
    PairSharedPtr<Type1, Type2> Pair<Type1, Type2>::Make(
        const Type1& first,
        const Type2& second)
    {
        return std::make_shared<Pair<Type1, Type2>>(first, second);
    }

    /**
     * The constructor.
     */
    template <typename Type1, typename Type2>
    Pair<Type1, Type2>::Pair(
        const Type1& first,
        const Type2& second) :
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
     * Gets the first Element.
     */
    template <typename Type1, typename Type2>
    const Type1& Pair<Type1, Type2>::GetFirst() const
    {
        return m_first;
    }

    /**
     * Gets the second Element.
     */
    template <typename Type1, typename Type2>
    const Type2& Pair<Type1, Type2>::GetSecond() const
    {
        return m_second;
    }

    /**
     * Gets the string representation ofthis instance.
     */
    template <typename Type1, typename Type2>
    std::wstring Pair<Type1, Type2>::toString() const
    {
        std::wstringstream stream;
        stream << L"(" << m_first << L"," << m_second << L")";
        return stream.str();
    }

    /**
     * Implements an operator not equals for pairs.
     */
    template <typename Type1, typename Type2>
    inline bool operator==(
        const Pair<Type1, Type2>& lhs,
        const Pair<Type1, Type2>& rhs)
    {
        return
            lhs.GetFirst() == rhs.GetFirst() &&
            lhs.GetSecond() == rhs.GetSecond();
    }

    /**
     * Implements an operator not equals for pairs.
     */
    template <typename Type1, typename Type2>
    inline bool operator!=(
        const Pair<Type1, Type2>& lhs,
        const Pair<Type1, Type2>& rhs)
    {
        return !(lhs == rhs);
    }

    /**
     * Implements an operator less than for pairs.
     */
    template <typename Type1, typename Type2>
    bool operator<(
        const Pair<Type1, Type2>& lhs,
        const Pair<Type1, Type2>& rhs)
    {
        if (lhs.getFirst() < rhs.getFirst()) {
            return true;
        }

        if (lhs.getFirst() > rhs.getFirst()) {
            return false;
        }

        return lhs.getSecond() < rhs.getSecond();
    }

    /**
     * Implements an operator less than or equal for pairs.
     */
    template <typename Type1, typename Type2>
    inline bool operator<=(
        const Pair<Type1, Type2>& lhs,
        const Pair<Type1, Type2>& rhs)
    {
        return !(rhs < lhs);
    }

    /**
     * Implements an operator greater than for pairs.
     */
    template <typename Type1, typename Type2>
    inline bool operator>(
        const Pair<Type1, Type2>& lhs,
        const Pair<Type1, Type2>& rhs)
    {
        return rhs < lhs;
    }

    /**
     * Implements an operator greater than or equal for pairs.
     */
    template <typename Type1, typename Type2>
    inline bool operator>=(
        const Pair<Type1, Type2>& lhs,
        const Pair<Type1, Type2>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif // PAIR_H_6ddd1cc4_d037_4ebb_b30e_8ac857f3c8d9
