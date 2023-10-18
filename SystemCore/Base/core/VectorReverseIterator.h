#ifndef VECTOR_REVERSE_ITERATOR_H_6e1bff60_0654_4324_8b91_1dc5b821536f
#define VECTOR_REVERSE_ITERATOR_H_6e1bff60_0654_4324_8b91_1dc5b821536f

#include "IReverseIterator.h"

namespace base
{
    /**
     * The VectorReverseIterator class implements a reverse iterator of a vector.
     */
    template <typename T>
    class VectorReverseIterator final : public IReverseIterator<T>
    {
    public:
        /**
         * Creates a new reverse iterator of a vector.
         */
        static base::IReverseIteratorSharedPtr<T> Make(const std::vector<T>& data);

        /**
         * The constructor.
         */
        explicit VectorReverseIterator(const std::vector<T>& data);

        /**
         * The destructor.
         */
        virtual ~VectorReverseIterator();

        /**
         * The Copy/move constructors.
         */
        VectorReverseIterator(const VectorReverseIterator&) = delete;
        VectorReverseIterator(VectorReverseIterator&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        VectorReverseIterator& operator=(const VectorReverseIterator&) = delete;
        VectorReverseIterator& operator=(VectorReverseIterator&&) = delete;

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
        const std::vector<T>& m_data;
        typename std::vector<T>::const_reverse_iterator m_reverseIterator;
    };

    /**
     * Creates a reverse iterator of a list.
     */
    template <typename T>
    base::IReverseIteratorSharedPtr<T> VectorReverseIterator<T>::Make(const std::vector<T>& data)
    {
        return std::make_shared<VectorReverseIterator>(data);
    }

    /**
     * The constructor.
     */
    template <typename T>
    VectorReverseIterator<T>::VectorReverseIterator(const std::vector<T>& data) :
        m_data(data)
    {
        Reset();
    }

    /**
     * The destructor.
     */
    template <typename T>
    VectorReverseIterator<T>::~VectorReverseIterator()
    {
    }

    /**
     * Checks whether there is a next element.
     */
    template <typename T>
    bool VectorReverseIterator<T>::HasNext() const
    {
        return m_reverseIterator != m_data.rend();
    }

    /**
     * Gets the next element.
     */
    template <typename T>
    T VectorReverseIterator<T>::Next()
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
    void VectorReverseIterator<T>::Reset()
    {
        m_reverseIterator = m_data.rbegin();
    }

} // namespace base

#endif // VECTOR_REVERSE_ITERATOR_H_6e1bff60_0654_4324_8b91_1dc5b821536f
