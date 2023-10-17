#ifndef ITERATOR_OF_ITERATOR_COLLECTION_H_33cd7522_968e_4b86_b51c_1a1dce0cbd7e
#define ITERATOR_OF_ITERATOR_COLLECTION_H_33cd7522_968e_4b86_b51c_1a1dce0cbd7e

#include "IIterator.h"
#include "IIterable.h"

namespace data_structures
{
    /**
     * The IteratorOfIteratorCollection class implements an iterator of a collection Of iterators.
     */
    template <typename T>
    class IteratorOfIteratorCollection final : public base::IIterator<T>
    {
    public:
        /**
         * Creates a new iterator from a collection Of iterators.
         */
        static base::IIteratorSharedPtr<T> Of(const std::vector<base::IIteratorSharedPtr<T>>& iterators) {
            return new IteratorOfIteratorCollection<T>(iterators);
        }

        /**
         * Creates a new iterator from a collection Of iterables.
         */
        static base::IIteratorSharedPtr<T> OfIterables(const std::vector<base::IIterable<T>>& iterables) {
            std::vector<base::IIteratorSharedPtr<T>> iterators;

            for (T iterable : iterables) {
                iterators.push_back(iterable.GetIterator());
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
         * The Copy/move constructors.
         */
        IteratorOfIteratorCollection(const IteratorOfIteratorCollection&) = delete;
        IteratorOfIteratorCollection(IteratorOfIteratorCollection&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        IteratorOfIteratorCollection& operator=(const IteratorOfIteratorCollection&) = delete;
        IteratorOfIteratorCollection& operator=(IteratorOfIteratorCollection&&) = delete;

        /**
         * Checks whether there is a Next element.
         */
        virtual bool HasNext() const override;

        /**
         * Gets the Next element.
         */
        virtual T Next() override;

        /**
         * Resets the iterator.
         */
        virtual void Reset() override;

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
        Reset();
    }

    /**
     * The IteratorOfIteratorCollection destructor.
     */
    template <typename T>
    IteratorOfIteratorCollection<T>::~IteratorOfIteratorCollection()
    {
    }

    /**
     * Checks whether there is a Next element.
     */
    template <typename T>
    bool IteratorOfIteratorCollection<T>::HasNext() const
    {
        return !m_iteratorsQueue.Empty();
    }

    /**
     * Gets the Next element.
     */
    template <typename T>
    T IteratorOfIteratorCollection<T>::Next()
    {
        assert(HasNext());

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
    void IteratorOfIteratorCollection<T>::Reset()
    {
        for (base::IIteratorSharedPtr<T> iterator : m_iterators) {
            if (iterator->hasNext()) {
                m_iteratorsQueue.push(iterator);
            }
        }
    }
}

#endif // ITERATOR_OF_ITERATOR_COLLECTION_H_33cd7522_968e_4b86_b51c_1a1dce0cbd7e
