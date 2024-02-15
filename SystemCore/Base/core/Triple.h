#ifndef TRIPLE_H_d3659ec3_69ec_4938_8fd0_a99b97a30dad
#define TRIPLE_H_d3659ec3_69ec_4938_8fd0_a99b97a30dad

#include <sstream>
#include <memory>

namespace base
{
    /**
     * The Triple class template implements a triple.
     */
    template <typename Type1, typename Type2, typename Type3>
    class Triple final
    {
    public:
        /**
         * Creates a new triple.
         */
        std::shared_ptr<Triple<Type1, Type2, Type3>> Make(
            const Type1& first,
            const Type2& second,
            const Type3& third);

        /**
         * The constructor.
         */
        Triple(
            const Type1& first,
            const Type2& second,
            const Type3& third);

        /**
         * The destructor.
         */
        ~Triple();

        /**
         * The Copy/move constructors.
         */
        Triple(const Triple& rhs) = default;
        Triple(Triple&&) = default;

        /**
         * The Copy/move assignment operators.
         */
        Triple& operator=(const Triple&) = default;
        Triple& operator=(Triple&&) = default;

        /**
         * Gets the first Element.
         */
        const Type1& GetFirst() const;

        /**
         * Gets the second Element.
         */
        const Type2& GetSecond() const;

        /**
         * Gets the third Element.
         */
        const Type3& GetThird() const;

        /**
         * Gets the string representation ofthis instance.
         */
        std::wstring toString() const;

    private:
        Type1 m_first;
        Type2 m_second;
        Type3 m_third;
    };

    //
    // Defines the SharedPtr of triples...
    //
    template <typename Type1, typename Type2, typename Type3>
    using TripleSharedPtr = std::shared_ptr<Triple<Type1, Type2, Type3>>;

    /**
     * Creates a new triple.
     */
    template <typename Type1, typename Type2, typename Type3>
    TripleSharedPtr<Type1, Type2, Type3> Triple<Type1, Type2, Type3>::Make(
        const Type1& first,
        const Type2& second,
        const Type3& third)
    {
        return std::make_shared<Triple<Type1, Type2, Type3>>(first, second, third);
    }

    /**
     * The constructor.
     */
    template <typename Type1, typename Type2, typename Type3>
    Triple<Type1, Type2, Type3>::Triple(
        const Type1& first,
        const Type2& second,
        const Type3& third) :
        m_first(first),
        m_second(second),
        m_third(third)
    {
    }

    /**
     * The destructor.
     */
    template <typename Type1, typename Type2, typename Type3>
    Triple<Type1, Type2, Type3>::~Triple()
    {
    }

    /**
     * Gets the first Element.
     */
    template <typename Type1, typename Type2, typename Type3>
    const Type1& Triple<Type1, Type2, Type3>::GetFirst() const
    {
        return m_first;
    }

    /**
     * Gets the second Element.
     */
    template <typename Type1, typename Type2, typename Type3>
    const Type2& Triple<Type1, Type2, Type3>::GetSecond() const
    {
        return m_second;
    }

    /**
     * Gets the third Element.
     */
    template <typename Type1, typename Type2, typename Type3>
    const Type3& Triple<Type1, Type2, Type3>::GetThird() const
    {
        return m_third;
    }

    /**
     * Gets the string representation ofthis instance.
     */
    template <typename Type1, typename Type2, typename Type3>
    std::wstring Triple<Type1, Type2, Type3>::toString() const
    {
        std::wstringstream stream;
        stream << L"(" << m_first << L"," << m_second << L"," << m_third << L")";
        return stream.str();
    }

    /**
     * Implements an operator not equals for triples.
     */
    template <typename Type1, typename Type2, typename Type3>
    inline bool operator==(
        const Triple<Type1, Type2, Type3>& lhs,
        const Triple<Type1, Type2, Type3>& rhs)
    {
        return
            lhs.GetFirst() == rhs.GetFirst() &&
            lhs.GetSecond() == rhs.GetSecond() &&
            lhs.GetThird() == rhs.GetThird();
    }

    /**
     * Implements an operator not equals for triples.
     */
    template <typename Type1, typename Type2, typename Type3>
    inline bool operator!=(
        const Triple<Type1, Type2, Type3>& lhs,
        const Triple<Type1, Type2, Type3>& rhs)
    {
        return !(lhs == rhs);
    }

    /**
     * Implements an operator less than for triples.
     */
    template <typename Type1, typename Type2, typename Type3>
    bool operator<(
        const Triple<Type1, Type2, Type3>& lhs,
        const Triple<Type1, Type2, Type3>& rhs)
    {
        if (lhs.GetFirst() < rhs.GetFirst()) {
            return true;
        }

        if (lhs.GetFirst() > rhs.GetFirst()) {
            return false;
        }

        if (lhs.GetSecond() < rhs.GetSecond()) {
            return true;
        }

        if (lhs.GetSecond() > rhs.GetSecond()) {
            return false;
        }

        return lhs.GetThird() < rhs.GetThird();
    }

    /**
     * Implements an operator less than or equal for triples.
     */
    template <typename Type1, typename Type2, typename Type3>
    inline bool operator<=(
        const Triple<Type1, Type2, Type3>& lhs,
        const Triple<Type1, Type2, Type3>& rhs)
    {
        return !(rhs < lhs);
    }

    /**
     * Implements an operator greater than for triples.
     */
    template <typename Type1, typename Type2, typename Type3>
    inline bool operator>(
        const Triple<Type1, Type2, Type3>& lhs,
        const Triple<Type1, Type2, Type3>& rhs)
    {
        return rhs < lhs;
    }

    /**
     * Implements an operator greater than or equal for triples.
     */
    template <typename Type1, typename Type2, typename Type3>
    inline bool operator>=(
        const Triple<Type1, Type2, Type3>& lhs,
        const Triple<Type1, Type2, Type3>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif // TRIPLE_H_d3659ec3_69ec_4938_8fd0_a99b97a30dad
