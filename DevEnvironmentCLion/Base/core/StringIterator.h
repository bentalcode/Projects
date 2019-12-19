#ifndef STRING_ITERATOR_H_656f997f_c2d5_4b1a_81de_2281c2625e03
#define STRING_ITERATOR_H_656f997f_c2d5_4b1a_81de_2281c2625e03

#include "IIterator.h"

namespace base
{
    /**
     * The StringIterator class implements an iterator of a string.
     */
    template <typename T>
    class StringIterator final : public IIterator<T>
    {
    public:
        /**
         * The constructor.
         */
        explicit StringIterator(const std::string<T>& data);

        /**
         * The destructor.
         */
        virtual ~StringIterator();

        /**
         * The copy/move constructors.
         */
        StringIterator(const StringIterator&) = delete;
        StringIterator(StringIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        StringIterator& operator=(const StringIterator&) = delete;
        StringIterator& operator=(StringIterator&&) = delete;

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
        /**
         * Resets the iterator.
         */
        void reset(size_t index);

        const std::string<T>& m_data;
        size_t m_index;
    };

    template <typename T>
    StringIterator<T>::StringIterator(const std::string<T>& data) :
        m_data(data),
        m_index(0)
    {
    }

    template <typename T>
    StringIterator<T>::~StringIterator()
    {
    }

    template <typename T>
    bool StringIterator<T>::hasNext() const
    {
        return m_index < m_data.size();
    }

    template <typename T>
    T StringIterator<T>::next()
    {
        assert(hasNext());

        T currElement = m_data[m_index];
        ++m_index;

        return currElement;
    }

    template <typename T>
    void StringIterator<T>::reset()
    {
        reset(0);
    }

    template <typename T>
    void StringIterator<T>::reset(size_t index)
    {
        m_index = index;
    }
}

#endif // STRING_ITERATOR_H_656f997f_c2d5_4b1a_81de_2281c2625e03
