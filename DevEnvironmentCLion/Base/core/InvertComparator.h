#ifndef INVERT_COMPARATOR_H_cfb11670_10ea_4f49_9382_dc2e4bd0e6af
#define INVERT_COMPARATOR_H_cfb11670_10ea_4f49_9382_dc2e4bd0e6af

#include "IBinaryComparator.h"

namespace base
{
    /**
     * The InvertComparator class implements an invert comparator for a defined comparator.
     */
    template <typename T>
    class InvertComparator final : public IBinaryComparator<T>
    {
    public:
        /**
         * Creates an invert comparator.
         */
        static IBinaryComparatorPtr<T> make(IBinaryComparatorPtr<T> comparator);

        /**
         * The InvertComparator constructor.
         */
        explicit InvertComparator(IBinaryComparatorPtr<T> comparator);

        /**
         * The InvertComparator destructor.
         */
        virtual ~InvertComparator();

        /**
         * The copy/move constructors.
         */
        InvertComparator(const InvertComparator&) = delete;
        InvertComparator(InvertComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        InvertComparator& operator=(const InvertComparator&) = delete;
        InvertComparator& operator=(InvertComparator&&) = delete;

        /**
         * Gets the hash code of this instance.
         */
        virtual std::size_t getHashCode(const T& obj) const override;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool isEqual(const T& lhs, const T& rhs) const override;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int compareTo(const T& lhs, const T& rhs) const override;

    private:
        IBinaryComparatorPtr<T> m_comparator;
    };

    /**
     * Creates an invert comparator.
     */
    template <typename T>
    IBinaryComparatorPtr<T> InvertComparator<T>::make(IBinaryComparatorPtr<T> comparator)
    {
        return std::make_shared<InvertComparator>(comparator);
    }

    /**
     * The InvertComparator constructor.
     */
    template <typename T>
    InvertComparator<T>::InvertComparator(IBinaryComparatorPtr<T> comparator) :
        m_comparator(comparator)
    {
        if (!comparator)
        {
            std::string errorMessage = "The invert comparator is not defined.";
            throw BaseException(errorMessage);
        }
    }

    /**
     * The InvertComparator destructor.
     */
    template <typename T>
    InvertComparator<T>::~InvertComparator()
    {
    }

    /**
     * Gets the hash code of this instance.
     */
    template <typename T>
    std::size_t InvertComparator<T>::getHashCode(const T& obj) const
    {
        return m_comparator->getHashCode(obj);
    }

    /**
     * Checks whether two instances are equals.
     */
    template <typename T>
    bool InvertComparator<T>::isEqual(const T& lhs, const T& rhs) const
    {
        return m_comparator->isEqual(lhs, rhs);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename T>
    int InvertComparator<T>::compareTo(const T& lhs, const T& rhs) const
    {
        int compareStatus = m_comparator->compareTo(lhs, rhs);

        if (compareStatus == 0)
        {
            return 0;
        }
        else if (compareStatus < 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

#endif // INVERT_COMPARATOR_H_cfb11670_10ea_4f49_9382_dc2e4bd0e6af
