#ifndef I_REVERSE_ITERATOR_H_d00c568a_72e5_4e9e_8b14_bc9dcd856096
#define I_REVERSE_ITERATOR_H_d00c568a_72e5_4e9e_8b14_bc9dcd856096

#include "IIterator.h"

namespace base
{
    /**
     * The IReverseIterator interface defines a reverse iterator.
     */
    template <typename T>
    class IReverseIterator : public IIterator<T>
    {
    public:
        /**
         * The constructor.
         */
        IReverseIterator() = default;

        /**
         * The destructor.
         */
        virtual ~IReverseIterator() = default;

        /**
         * The copy/move constructors.
         */
        IReverseIterator(const IReverseIterator&) = delete;
        IReverseIterator(IReverseIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IReverseIterator& operator=(const IReverseIterator&) = delete;
        IReverseIterator& operator=(IReverseIterator&&) = delete;
    };

    template <typename T>
    using IReverseIteratorPtr = std::shared_ptr<IReverseIterator<T>>;
}

#endif // I_REVERSE_ITERATOR_H_d00c568a_72e5_4e9e_8b14_bc9dcd856096
