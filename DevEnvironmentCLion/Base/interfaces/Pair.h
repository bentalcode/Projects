#ifndef PAIR_H_b150619a_9f60_4a1a_8df9_d7ef0debe4ca
#define PAIR_H_b150619a_9f60_4a1a_8df9_d7ef0debe4ca

#include <iostream>
#include "ReferenceCountHolder.h"
#include "BaseException.h"

namespace base
{
    /**
     * The Pair class template implements a pair.
     */
    template<typename Type1, typename Type2>
    class Pair
    {
    public:
        explicit Pair(const Type1& first, const Type2& second);
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
}

#endif // PAIR_H_b150619a_9f60_4a1a_8df9_d7ef0debe4ca
