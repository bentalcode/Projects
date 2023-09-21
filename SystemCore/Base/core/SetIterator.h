#ifndef SET_ITERATOR_H_aa850962_e8fc_482e_9583_ee6ffa625c18
#define SET_ITERATOR_H_aa850962_e8fc_482e_9583_ee6ffa625c18

#include "IIterator.h"
#include <set>

namespace base
{
    /**
     * The SetIterator class implements an iterator of a Set.
     */
    template <typename T>
    class SetIterator final : public IIterator<T>
    {
    public:
        /**
         * Creates an iterator of a Set.
         */
        static base::IIteratorSharedPtr<T> Make(const std::set<T>& data);

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
        const std::set<T>& m_data;
        typename std::set<T>::const_iterator m_iterator;
    };

    /**
     * Creates an iterator of a list.
     */
    template <typename T>
    base::IIteratorSharedPtr<T> SetIterator<T>::Make(const std::set<T>& data)
    {
        return std::make_shared<SetIterator>(data);
    }

    template <typename T>
    SetIterator<T>::SetIterator(const std::set<T>& data) :
        m_data(data)
    {
        Reset();
    }

    template <typename T>
    SetIterator<T>::~SetIterator()
    {
    }

    template <typename T>
    bool SetIterator<T>::HasNext() const
    {
        return m_iterator != m_data.end();
    }

    template <typename T>
    T SetIterator<T>::Next()
    {
        assert(HasNext());

        const T& currElement = *m_iterator;
        ++m_iterator;

        return currElement;
    }

    template <typename T>
    void SetIterator<T>::Reset()
    {
        m_iterator = m_data.begin();
    }
}

#endif // SET_ITERATOR_H_aa850962_e8fc_482e_9583_ee6ffa625c18
