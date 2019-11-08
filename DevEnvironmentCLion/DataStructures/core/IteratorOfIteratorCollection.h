#ifndef ITERATOR_OF_ITERATOR_COLLECTION_H_4746ba48_2853_47de_9605_6880d7143e00
#define ITERATOR_OF_ITERATOR_COLLECTION_H_4746ba48_2853_47de_9605_6880d7143e00

#include "IIterator.h"

namespace base
{
    /**
     * The IteratorOfIteratorCollection class implements an iterator of a collection of iterators.
     */
    template <typename T>
    class IteratorOfIteratorCollection final : public IIterator<T>
    {
    public:
        /**
         * The IteratorOfIteratorCollection constructor.
         */
        IteratorOfIteratorCollection();

        /**
         * The IteratorOfIteratorCollection destructor.
         */
        virtual ~IteratorOfIteratorCollection();

        /**
         * Checks whether there is a next element.
         */
        virtual bool hasNext() const override;

        /**
         * Gets the next element.
         */
        virtual T next() override;

        /**
         * Resets the iterator.
         */
        virtual void reset() override;

    private:
    };

    template <typename T>
    IteratorOfIteratorCollection<T>::IteratorOfIteratorCollection() :
    {
    }

    template <typename T>
    IteratorOfIteratorCollection<T>::~IteratorOfIteratorCollection()
    {
    }

    template <typename T>
    bool IteratorOfIteratorCollection<T>::hasNext() const
    {
        return true;
    }

    template <typename T>
    T ListIterator<T>::next()
    {
        assert(hasNext());

        return nullptr;
    }

    template <typename T>
    void ListIterator<T>::reset()
    {
    }
}

#endif // ITERATOR_OF_ITERATOR_COLLECTION_H_4746ba48_2853_47de_9605_6880d7143e00
