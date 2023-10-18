#ifndef LIST_ITERATOR_H_9d18cf60_d223_4bab_b5fd_8841deb8eb1f
#define LIST_ITERATOR_H_9d18cf60_d223_4bab_b5fd_8841deb8eb1f

#include "IIterator.h"
#include <list>
#include <assert.h>

namespace base
{
    /**
     * The ListIterator class implements an iterator of a list.
     */
    template <typename T>
    class ListIterator final : public IIterator<T>
    {
    public:
        /**
         * Creates an iterator of a list.
         */
        static base::IIteratorSharedPtr<T> Make(const std::list<T>& data);

        /**
         * The ListIterator constructor.
         */
        explicit ListIterator(const std::list<T>& data);

        /**
         * The ListIterator destructor.
         */
        virtual ~ListIterator();

        /**
         * The Copy/move constructors.
         */
        ListIterator(const ListIterator&) = delete;
        ListIterator(ListIterator&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        ListIterator& operator=(const ListIterator&) = delete;
        ListIterator& operator=(ListIterator&&) = delete;

        /**
         * Checks whether there is a next Element.
         */
        virtual bool HasNext() const override;

        /**
         * Gets the next Element.
         */
        virtual T Next() override;

        /**
         * Resets the iterator.
         */
        virtual void Reset() override;

    private:
        const std::list<T>& m_data;
        typename std::list<T>::const_iterator m_iterator;
    };

    /**
     * Creates an iterator of a list.
     */
    template <typename T>
    base::IIteratorSharedPtr<T> ListIterator<T>::Make(const std::list<T>& data)
    {
        return std::make_shared<ListIterator>(data);
    }

    /**
     * The ListIterator constructor.
     */
    template <typename T>
    ListIterator<T>::ListIterator(const std::list<T>& data) :
        m_data(data)
    {
        Reset();
    }

    /**
     * The ListIterator destructor.
     */
    template <typename T>
    ListIterator<T>::~ListIterator()
    {
    }

    /**
     * Checks whether there is a next Element.
     */
    template <typename T>
    bool ListIterator<T>::HasNext() const
    {
        return m_iterator != m_data.end();
    }

    /**
     * Gets the next Element.
     */
    template <typename T>
    T ListIterator<T>::Next()
    {
        assert(HasNext());

        T currElement = *m_iterator;
        ++m_iterator;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    template <typename T>
    void ListIterator<T>::Reset()
    {
        m_iterator = m_data.begin();
    }

} // namespace base

#endif // LIST_ITERATOR_H_9d18cf60_d223_4bab_b5fd_8841deb8eb1f
