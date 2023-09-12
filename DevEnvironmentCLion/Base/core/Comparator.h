#ifndef COMPARATOR_H_9211ae8b_638b_424a_8ad2_d75f20f5e24a
#define COMPARATOR_H_9211ae8b_638b_424a_8ad2_d75f20f5e24a

#include "InvertComparator.h"

namespace base
{
    /**
     * The Comparator class implements a binary comparator for a generic object.
     */
    template <typename T>
    class Comparator final : public IBinaryComparator<T>
    {
    public:
        /**
         * Creates a comparator.
         */
        static IBinaryComparatorSharedPtr<T> make();

        /**
         * Creates an invert comparator.
         */
        static IBinaryComparatorSharedPtr<T> makeInvert();

        /**
         * Creates an invert comparator.
         */
        static IBinaryComparatorSharedPtr<T> makeInvert(IBinaryComparatorSharedPtr<T> comparator);

        /**
         * The Comparator constructor.
         */
        Comparator();

        /**
         * The Comparator destructor.
         */
        virtual ~Comparator();

        /**
         * The copy/move constructors.
         */
        Comparator(const Comparator&) = delete;
        Comparator(Comparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Comparator& operator=(const Comparator&) = delete;
        Comparator& operator=(Comparator&&) = delete;

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
    };

    /**
     * Creates a comparator.
     */
    template <typename T>
    IBinaryComparatorSharedPtr<T> Comparator<T>::make()
    {
        return std::make_shared<Comparator>();
    }

    /**
     * Creates an invert comparator.
     */
    template <typename T>
    IBinaryComparatorSharedPtr<T> Comparator<T>::makeInvert()
    {
        IBinaryComparatorSharedPtr<T> comparator = Comparator<T>::make();
        return makeInvert(comparator);
    }

    /**
     * Creates an invert comparator.
     */
    template <typename T>
    IBinaryComparatorSharedPtr<T> Comparator<T>::makeInvert(IBinaryComparatorSharedPtr<T> comparator)
    {
        return InvertComparator<T>::make(comparator);
    }

    /**
     * The Comparator constructor.
     */
    template <typename T>
    Comparator<T>::Comparator()
    {
    }

    /**
     * The Comparator destructor.
     */
    template <typename T>
    Comparator<T>::~Comparator()
    {
    }

    /**
     * Gets the hash code of this instance.
     */
    template <typename T>
    std::size_t Comparator<T>::getHashCode(const T& obj) const
    {
        return 0;
    }

    /**
     * Checks whether two instances are equals.
     */
    template <typename T>
    bool Comparator<T>::isEqual(const T& lhs, const T& rhs) const
    {
        return lhs == rhs;
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename T>
    int Comparator<T>::compareTo(const T& lhs, const T& rhs) const
    {
        if (lhs < rhs)
        {
            return -1;
        }

        if (lhs > rhs)
        {
            return 1;
        }

        return 0;
    }
}

#endif // COMPARATOR_H_9211ae8b_638b_424a_8ad2_d75f20f5e24a
