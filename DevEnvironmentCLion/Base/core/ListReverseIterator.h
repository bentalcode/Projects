#ifndef LIST_REVERSE_ITERATOR_H_137c889a_1b21_42bd_b571_6e0b58f2a74d
#define LIST_REVERSE_ITERATOR_H_137c889a_1b21_42bd_b571_6e0b58f2a74d

#include "IReverseIterator.h"

namespace base
{
    /**
     * The ListReverseIterator class implements a reverse iterator of a list.
     */
    template <typename T>
    class ListReverseIterator final : public IReverseIterator<T>
    {
    public:
        /**
         * Creates a new reverse iterator of a list.
         */
        static base::IReverseIteratorPtr<T> make(const std::vector<T>& data);

        /**
         * The constructor.
         */
        explicit ListReverseIterator(const std::vector<T>& data);

        /**
         * The destructor.
         */
        virtual ~ListReverseIterator();

        /**
         * The copy/move constructors.
         */
        ListReverseIterator(const ListReverseIterator&) = delete;
        ListReverseIterator(ListReverseIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ListReverseIterator& operator=(const ListReverseIterator&) = delete;
        ListReverseIterator& operator=(ListReverseIterator&&) = delete;

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
        const std::vector<T>& m_data;
        size_t m_index;
    };

    /**
     * Creates a reverse iterator of a list.
     */
    template <typename T>
    base::IReverseIteratorPtr<T> ListReverseIterator<T>::make(const std::vector<T>& data)
    {
        return std::make_shared<ListReverseIterator>(data);
    }

    /**
     * The constructor.
     */
    template <typename T>
    ListReverseIterator<T>::ListReverseIterator(const std::vector<T>& data) :
        m_data(data)
    {
        reset();
    }

    /**
     * The destructor.
     */
    template <typename T>
    ListReverseIterator<T>::~ListReverseIterator()
    {
    }

    /**
     * Checks whether there is a next element.
     */
    template <typename T>
    bool ListReverseIterator<T>::hasNext() const
    {
        return m_index >= 0;
    }

    /**
     * Gets the next element.
     */
    template <typename T>
    T ListReverseIterator<T>::next()
    {
        assert(hasNext());

        T currElement = m_data[m_index];
        --m_index;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    template <typename T>
    void ListReverseIterator<T>::reset()
    {
        m_index = m_data.size() - 1;
    }
}

#endif // LIST_REVERSE_ITERATOR_H_137c889a_1b21_42bd_b571_6e0b58f2a74d
