#ifndef VECTOR_ITERATOR_H_90fd931a_c1c2_47bb_8348_1e2c5a6509df
#define VECTOR_ITERATOR_H_90fd931a_c1c2_47bb_8348_1e2c5a6509df

#include "IIterator.h"
#include <vector>
#include <assert.h>

namespace base
{
    /**
     * The VectorIterator class implements an iterator of a vector.
     */
    template <typename T>
    class VectorIterator final : public IIterator<T>
    {
    public:
        /**
         * Creates an iterator of a vector.
         */
        static base::IIteratorSharedPtr<T> Make(const std::vector<T>& data);

        /**
         * The constructor.
         */
        explicit VectorIterator(const std::vector<T>& data);

        /**
         * The destructor.
         */
        virtual ~VectorIterator();

        /**
         * The Copy/move constructors.
         */
        VectorIterator(const VectorIterator&) = delete;
        VectorIterator(VectorIterator&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        VectorIterator& operator=(const VectorIterator&) = delete;
        VectorIterator& operator=(VectorIterator&&) = delete;

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
        typename std::vector<T>::const_iterator m_iterator;
    };

    /**
     * Creates an iterator of a list.
     */
    template <typename T>
    base::IIteratorSharedPtr<T> VectorIterator<T>::Make(const std::vector<T>& data)
    {
        return std::make_shared<VectorIterator>(data);
    }

    /**
     * The constructor.
     */
    template <typename T>
    VectorIterator<T>::VectorIterator(const std::vector<T>& data) :
        m_data(data)
    {
        Reset();
    }

    /**
     * The destructor.
     */
    template <typename T>
    VectorIterator<T>::~VectorIterator()
    {
    }

    /**
     * Checks whether there is a next element.
     */
    template <typename T>
    bool VectorIterator<T>::HasNext() const
    {
        return m_iterator != m_data.end();
    }

    /**
     * Gets the next element.
     */
    template <typename T>
    T VectorIterator<T>::Next()
    {
        assert(HasNext());

        const T& currElement = *m_iterator;
        ++m_iterator;

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    template <typename T>
    void VectorIterator<T>::Reset()
    {
        m_iterator = m_data.begin();
    }

} // namespace base

#endif // VECTOR_ITERATOR_H_90fd931a_c1c2_47bb_8348_1e2c5a6509df
