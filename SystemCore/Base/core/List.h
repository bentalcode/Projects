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
         * The Copy/move constructors.
         */
        List(const List&) = default;
        List(List&&) = default;

        /**
         * The Copy/move assignment operators.
         */
        List& operator=(const List&) = default;
        List& operator=(List&&) = default;

        /**
         * Gets an element from the Front.
         */
        virtual const T& Front() const override;

        /**
         * Gets an element from the Back.
         */
        virtual const T& Back() const override;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& Get(std::size_t index) const override;

        /**
         * Adds an element to the Back of the list.
         */
        virtual void AddBack(const T& element) override;

        /**
         * Adds an element to the Front of the list.
         */
        virtual void AddFront(const T& element) override;

        /**
         * Removes an element from the Back of the list.
         */
        virtual void RemoveBack() override;

        /**
         * Removes an element from the Front of the list.
         */
        virtual void RemoveFront() override;

        /**
         * Returns whether the collection is Empty.
         */
        virtual bool Empty() const override;

        /**
         * Gets the size of the collection.
         */
        virtual std::size_t Size() const override;

        /**
         * Gets the iterator.
         */
        virtual IIteratorSharedPtr<T> GetIterator() const override;

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
     * Gets an element from the Front.
     */
    template <typename T>
    const T& List<T>::Front() const
    {
        return m_data.front();
    }

    /**
     * Gets an element from the Back.
     */
    template <typename T>
    const T& List<T>::Back() const
    {
        return m_data.back();
    }

    /**
     * Gets an element at a specified position.
     */
    template <typename T>
    const T& List<T>::Get(std::size_t index) const
    {
        auto iterator = m_data.begin();
        std::advance(iterator, index);
        return *iterator;
    }

    /**
     * Adds an element to the Back of the list.
     */
    template <typename T>
    void List<T>::AddBack(const T& element)
    {
        m_data.push_back(element);
    }

    /**
     * Adds an element to the Front of the list.
     */
    template <typename T>
    void List<T>::AddFront(const T& element)
    {
        m_data.push_front(element);
    }

    /**
     * Removes an element from the Back of the list.
     */
    template <typename T>
    void List<T>::RemoveBack()
    {
        return m_data.pop_back();
    }

    /**
     * Removes an element from the Front of the list.
     */
    template <typename T>
    void List<T>::RemoveFront()
    {
        return m_data.pop_front();
    }

    /**
     * Returns whether the collection is Empty.
     */
    template <typename T>
    bool List<T>::Empty() const
    {
        return m_data.empty();
    }

    /**
     * Gets the size of the collection.
     */
    template <typename T>
    std::size_t List<T>::Size() const
    {
        return m_data.size();
    }

    /**
     * Gets the iterator.
     */
    template <typename T>
    IIteratorSharedPtr<T> List<T>::GetIterator() const
    {
        IIteratorSharedPtr<T> iterator(new ListIterator<T>(m_data));
        return iterator;
    }

} // namespace base

#endif // LIST_H_0d5b5bf5_8693_4928_a489_9dddfaaa7b15
