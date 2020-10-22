#ifndef LIST_H_0d5b5bf5_8693_4928_a489_9dddfaaa7b15
#define LIST_H_0d5b5bf5_8693_4928_a489_9dddfaaa7b15

#include "IList.h"
#include "ListIterator.h"

namespace base
{
    /**
     * The List interface defines a generic list.
     */
    template <typename T>
    class List final : public IList<T>
    {
    public:
        /**
         * The default constructor.
         */
        List();

        /**
         * The destructor.
         */
        virtual ~List();

        /**
         * The copy/move constructors.
         */
        List(const List&) = default;
        List(List&&) = default;

        /**
         * The copy/move assignment operators.
         */
        List& operator=(const List&) = default;
        List& operator=(List&&) = default;

        /**
         * Gets an element from the front.
         */
        virtual const T& front() const override;

        /**
         * Gets an element from the back.
         */
        virtual const T& back() const override;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(std::size_t index) const override;

        /**
         * Adds an element to the back of the list.
         */
        virtual void addBack(const T& element) override;

        /**
         * Adds an element to the front of the list.
         */
        virtual void addFront(const T& element) override;

        /**
         * Removes an element from the back of the list.
         */
        virtual void removeBack() override;

        /**
         * Removes an element from the front of the list.
         */
        virtual void removeFront() override;

        /**
         * Returns whether the collection is empty.
         */
        virtual bool empty() const override;

        /**
         * Gets the size of the collection.
         */
        virtual std::size_t size() const override;

        /**
         * Gets the iterator.
         */
        virtual IIteratorPtr<T> getIterator() const override;

    private:
        std::list<T> m_data;
    };

    /**
     * The List constructor.
     */
    template <typename T>
    List<T>::List()
    {
    }

    /**
     * The List destructor.
     */
    template <typename T>
    List<T>::~List()
    {
    }

    /**
     * Gets an element from the front.
     */
    template <typename T>
    const T& List<T>::front() const
    {
        return m_data.front();
    }

    /**
     * Gets an element from the back.
     */
    template <typename T>
    const T& List<T>::back() const
    {
        return m_data.back();
    }

    /**
     * Gets an element at a specified position.
     */
    template <typename T>
    const T& List<T>::get(std::size_t index) const
    {
        auto iterator = m_data.begin();
        std::advance(iterator, index);
        return *iterator;
    }

    /**
     * Adds an element to the back of the list.
     */
    template <typename T>
    void List<T>::addBack(const T& element)
    {
        m_data.push_back(element);
    }

    /**
     * Adds an element to the front of the list.
     */
    template <typename T>
    void List<T>::addFront(const T& element)
    {
        m_data.push_front(element);
    }

    /**
     * Removes an element from the back of the list.
     */
    template <typename T>
    void List<T>::removeBack()
    {
        return m_data.pop_back();
    }

    /**
     * Removes an element from the front of the list.
     */
    template <typename T>
    void List<T>::removeFront()
    {
        return m_data.pop_front();
    }

    template <typename T>
    bool List<T>::empty() const
    {
        return m_data.empty();
    }

    template <typename T>
    std::size_t List<T>::size() const
    {
        return m_data.size();
    }

    template <typename T>
    IIteratorPtr<T> List<T>::getIterator() const
    {
        IIteratorPtr<T> iterator(new ListIterator<T>(m_data));
        return iterator;
    }
}

#endif // LIST_H_0d5b5bf5_8693_4928_a489_9dddfaaa7b15
