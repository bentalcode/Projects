#ifndef ITERATOR_OF_ITERATOR_COLLECTION_H_33cd7522_968e_4b86_b51c_1a1dce0cbd7e
#define ITERATOR_OF_ITERATOR_COLLECTION_H_33cd7522_968e_4b86_b51c_1a1dce0cbd7e

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
        static base::IIteratorSharedPtr<T> of(const std::vector<base::IIteratorSharedPtr<T>>& iterators) {
            return new IteratorOfIteratorCollection<T>(iterators);
        }

        /**
         * Creates a new iterator from a collection of iterables.
         */
        static base::IIteratorSharedPtr<T> ofIterables(const std::vector<base::IIterable<T>>& iterables) {
            std::vector<base::IIteratorSharedPtr<T>> iterators;

            for (T iterable : iterables) {
                iterators.push_back(iterable.getIterator());
            }

            return new IteratorOfIteratorCollection<T>(iterators);
        }

        /**
         * The constructor.
         */
        explicit IteratorOfIteratorCollection(const std::vector<base::IIteratorSharedPtr<T>>& iterators);

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
        std::vector<base::IIteratorSharedPtr<T>> m_iterators;
        std::queue<base::IIteratorSharedPtr<T>> m_iteratorsQueue;
    };

    /**
     * The IteratorOfIteratorCollection constructor.
     */
    template <typename T>
    IteratorOfIteratorCollection<T>::IteratorOfIteratorCollection(const std::vector<base::IIteratorSharedPtr<T>>& iterators) :
        m_iterators(iterators)
    {
        reset();
    }

    /**
     * The IteratorOfIteratorCollection destructor.
     */
    template <typename T>
    IteratorOfIteratorCollection<T>::~IteratorOfIteratorCollection()
    {
    }

    /**
     * Checks whether there is a next element.
     */
    template <typename T>
    bool IteratorOfIteratorCollection<T>::hasNext() const
    {
        return !m_iteratorsQueue.empty();
    }

    /**
     * Gets the next element.
     */
    template <typename T>
    T IteratorOfIteratorCollection<T>::next()
    {
        assert(hasNext());

        base::IIteratorSharedPtr<T> currIterator = m_iteratorsQueue.front();
        T currElement = currIterator->next();

        if (!currIterator->hasNext()) {
            m_iteratorsQueue.pop();
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    template <typename T>
    void IteratorOfIteratorCollection<T>::reset()
    {
        for (base::IIteratorSharedPtr<T> iterator : m_iterators) {
            if (iterator->hasNext()) {
                m_iteratorsQueue.push(iterator);
            }
        }
    }
}

#endif // ITERATOR_OF_ITERATOR_COLLECTION_H_33cd7522_968e_4b86_b51c_1a1dce0cbd7e
