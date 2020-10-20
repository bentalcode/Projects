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
         * The constructor.
         */
        explicit List(size_t initialSize);

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
         * Gets an element at a specified position.
         */
        virtual const T& get(std::size_t index) const override;

        /**
         * Adds an element.
         */
        virtual void add(const T& element) override;

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

    template <typename T>
    List<T>::List()
    {
    }

    template <typename T>
    List<T>::List(size_t initialSize) :
        m_data(initialSize)
    {
    }

    template <typename T>
    List<T>::~List()
    {
    }

    template <typename T>
    const T& List<T>::get(std::size_t index) const
    {
        auto iterator = m_data.begin();
        std::advance(iterator, index);
        return *iterator;
    }

    template <typename T>
    void List<T>::add(const T& element)
    {
        m_data.push_back(element);
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
