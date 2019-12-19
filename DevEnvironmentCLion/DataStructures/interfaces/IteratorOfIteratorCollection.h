#ifndef ITERATOR_OF_ITERATOR_COLLECTION_H_4746ba48_2853_47de_9605_6880d7143e00
#define ITERATOR_OF_ITERATOR_COLLECTION_H_4746ba48_2853_47de_9605_6880d7143e00

#include "IIterator.h"
#include "IIterable.h"

namespace data_structures
{
    /**
     * The IteratorOfIteratorCollection class implements an iterator of a collection of iterators.
     */
    template <typename T>
    class IteratorOfIteratorCollection final : public base::IIterator<T>
    {
    public:
        /**
         * Creates a new iterator from a collection of iterators.
         */
        static base::IIteratorPtr<T> of(const std::vector<base::IIteratorPtr<T>>& iterators) {
            return new IteratorOfIteratorCollection<T>(iterators);
        }

        /**
         * Creates a new iterator from a collection of iterables.
         */
        static base::IIteratorPtr<T> ofIterables(const std::vector<base::IIterable<T>>& iterables) {
            std::vector<base::IIteratorPtr<T>> iterators;

            for (T iterable : iterables) {
                iterators.push_back(iterable.getIterator());
            }

            return new IteratorOfIteratorCollection<T>(iterators);
        }

        /**
         * The constructor.
         */
        explicit IteratorOfIteratorCollection(const std::vector<base::IIteratorPtr<T>>& iterators);

        /**
         * The destructor.
         */
        virtual ~IteratorOfIteratorCollection();

        /**
         * The copy/move constructors.
         */
        IteratorOfIteratorCollection(const IteratorOfIteratorCollection&) = delete;
        IteratorOfIteratorCollection(IteratorOfIteratorCollection&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IteratorOfIteratorCollection& operator=(const IteratorOfIteratorCollection&) = delete;
        IteratorOfIteratorCollection& operator=(IteratorOfIteratorCollection&&) = delete;

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
        std::vector<base::IIteratorPtr<T>> m_iterators;
        std::queue<base::IIteratorPtr<T>> m_iteratorsQueue;
    };

    template <typename T>
    IteratorOfIteratorCollection<T>::IteratorOfIteratorCollection(const std::vector<base::IIteratorPtr<T>>& iterators) :
        m_iterators(iterators)
    {
        reset();
    }

    template <typename T>
    IteratorOfIteratorCollection<T>::~IteratorOfIteratorCollection()
    {
    }

    template <typename T>
    bool IteratorOfIteratorCollection<T>::hasNext() const
    {
        return !m_iteratorsQueue.empty();
    }

    template <typename T>
    T IteratorOfIteratorCollection<T>::next()
    {
        assert(hasNext());

        base::IIteratorPtr<T> currIterator = m_iteratorsQueue.front();
        T currElement = currIterator->next();

        if (!currIterator->hasNext()) {
            m_iteratorsQueue.pop();
        }

        return currElement;
    }

    template <typename T>
    void IteratorOfIteratorCollection<T>::reset()
    {
        for (base::IIteratorPtr<T> iterator : m_iterators) {
            if (iterator->hasNext()) {
                m_iteratorsQueue.push(iterator);
            }
        }
    }
}

#endif // ITERATOR_OF_ITERATOR_COLLECTION_H_4746ba48_2853_47de_9605_6880d7143e00
