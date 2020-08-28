#ifndef LIST_ITERATOR_H_9d18cf60_d223_4bab_b5fd_8841deb8eb1f
#define LIST_ITERATOR_H_9d18cf60_d223_4bab_b5fd_8841deb8eb1f

#include "IIterator.h"
#include "IList.h"

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
        static base::IIteratorPtr<T> make(const std::vector<T>& data);

        /**
         * The constructor.
         */
        explicit ListIterator(const std::vector<T>& data);

        /**
         * The destructor.
         */
        virtual ~ListIterator();

        /**
         * The copy/move constructors.
         */
        ListIterator(const ListIterator&) = delete;
        ListIterator(ListIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ListIterator& operator=(const ListIterator&) = delete;
        ListIterator& operator=(ListIterator&&) = delete;

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
     * Creates an iterator of a list.
     */
    template <typename T>
    base::IIteratorPtr<T> ListIterator<T>::make(const std::vector<T>& data)
    {
        return std::make_shared<ListIterator>(data);
    }

    template <typename T>
    ListIterator<T>::ListIterator(const std::vector<T>& data) :
        m_data(data),
        m_index(0)
    {
    }

    template <typename T>
    ListIterator<T>::~ListIterator()
    {
    }

    template <typename T>
    bool ListIterator<T>::hasNext() const
    {
        return m_index < m_data.size();
    }

    template <typename T>
    T ListIterator<T>::next()
    {
        assert(hasNext());

        T currElement = m_data[m_index];
        ++m_index;

        return currElement;
    }

    template <typename T>
    void ListIterator<T>::reset()
    {
        m_index = 0;
    }
}

#endif // LIST_ITERATOR_H_9d18cf60_d223_4bab_b5fd_8841deb8eb1f
