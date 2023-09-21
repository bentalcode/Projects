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
        static base::IReverseIteratorSharedPtr<T> Make(const std::list<T>& data);

        /**
         * The constructor.
         */
        explicit ListReverseIterator(const std::list<T>& data);

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
        virtual bool HasNext() const override;

        /**
         * Gets the next element.
         */
        virtual T Next() override;

        /**
         * Resets the iterator.
         */
        virtual void Reset() override;

    private:
        const std::list<T>& m_data;
        typename std::list<T>::const_reverse_iterator m_reverseIterator;
    };

    /**
     * Creates a reverse iterator of a list.
     */
    template <typename T>
    base::IReverseIteratorSharedPtr<T> ListReverseIterator<T>::Make(const std::list<T>& data)
    {
        return std::make_shared<ListReverseIterator>(data);
    }

    /**
     * The constructor.
     */
    template <typename T>
    ListReverseIterator<T>::ListReverseIterator(const std::list<T>& data) :
        m_data(data)
    {
        Reset();
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
    bool ListReverseIterator<T>::HasNext() const
    {
        return m_reverseIterator != m_data.rend();
    }

    /**
     * Gets the next element.
     */
    template <typename T>
    T ListReverseIterator<T>::Next()
    {
        assert(HasNext());

        T currElement = *m_reverseIterator;
        ++m_reverseIterator;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    template <typename T>
    void ListReverseIterator<T>::Reset()
    {
        m_reverseIterator = m_data.rbegin();
    }

} // namespace base

#endif // LIST_REVERSE_ITERATOR_H_137c889a_1b21_42bd_b571_6e0b58f2a74d
