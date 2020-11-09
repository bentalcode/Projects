#ifndef SET_ITERATOR_H_aa850962_e8fc_482e_9583_ee6ffa625c18
#define SET_ITERATOR_H_aa850962_e8fc_482e_9583_ee6ffa625c18

#include "IIterator.h"

namespace base
{
    /**
     * The SetIterator class implements an iterator of a set.
     */
    template <typename T>
    class SetIterator final : public IIterator<T>
    {
    public:
        /**
         * Creates an iterator of a set.
         */
        static base::IIteratorPtr<T> make(const std::set<T>& data);

        /**
         * The constructor.
         */
        explicit SetIterator(const std::set<T>& data);

        /**
         * The destructor.
         */
        virtual ~SetIterator();

        /**
         * The copy/move constructors.
         */
        SetIterator(const SetIterator&) = delete;
        SetIterator(SetIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        SetIterator& operator=(const SetIterator&) = delete;
        SetIterator& operator=(SetIterator&&) = delete;

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
        const std::set<T>& m_data;
        typename std::set<T>::const_iterator m_iterator;
    };

    /**
     * Creates an iterator of a list.
     */
    template <typename T>
    base::IIteratorPtr<T> SetIterator<T>::make(const std::set<T>& data)
    {
        return std::make_shared<SetIterator>(data);
    }

    template <typename T>
    SetIterator<T>::SetIterator(const std::set<T>& data) :
        m_data(data)
    {
        reset();
    }

    template <typename T>
    SetIterator<T>::~SetIterator()
    {
    }

    template <typename T>
    bool SetIterator<T>::hasNext() const
    {
        return m_iterator != m_data.end();
    }

    template <typename T>
    T SetIterator<T>::next()
    {
        assert(hasNext());

        const T& currElement = *m_iterator;
        ++m_iterator;

        return currElement;
    }

    template <typename T>
    void SetIterator<T>::reset()
    {
        m_iterator = m_data.begin();
    }
}

#endif // SET_ITERATOR_H_aa850962_e8fc_482e_9583_ee6ffa625c18
