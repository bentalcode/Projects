#ifndef SORTING_H_6d32e854_ee98_4512_98e0_b388bf208164
#define SORTING_H_6d32e854_ee98_4512_98e0_b388bf208164

#include <functional>
#include <memory>
#include <algorithm>

namespace base
{
    /**
     * The Sorting class implements complementary APIs for sorting.
     */
    class Sorting final
    {
    public:
        //
        // Defines the SharedPtr of Sorting Functor...
        //
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        using ISortingFunctor = std::function<bool(const ValueType&, const ValueType&)>;

        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        using ISortingFunctorSharedPtr = std::shared_ptr<ISortingFunctor<CollectionType, ValueType>>;

        /**
         * Sorts the collection.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static void Sort(CollectionType& intervals);

        /**
         * Sorts the collection with a functor.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static void Sort(
            CollectionType& intervals,
            const ISortingFunctor<CollectionType, ValueType>& functor);

        /**
         * Sorts the collection by dereference it's pointers.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static void DereferenceSort(CollectionType& intervals);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Sorting() = delete;
        ~Sorting() = delete;
    };

    /**
     * Defines the dereference Sort functor for pointers.
     */
    template <typename T>
    struct DereferenceSortedFunctor final
    {
        bool operator()(T left, T right) const
        {
            if (!left && !right)
            {
                return false;
            }

            if (!left)
            {
                return true;
            }

            if (!right)
            {
                return false;
            }

            return *left < *right;
        }
    };

    /**
     * Sorts the elements.
     */
    template <typename CollectionType, typename ValueType>
    void Sorting::Sort(CollectionType& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
    }

    /**
     * Sorts the collection with a functor.
     */
    template<typename CollectionType, typename ValueType>
    void Sorting::Sort(
        CollectionType& intervals,
        const ISortingFunctor<CollectionType, ValueType>& functor)
    {
        std::sort(intervals.begin(), intervals.end(), functor);
    }

    /**
     * Sorts the collection by dereference it's pointers.
     */
    template<typename CollectionType, typename ValueType>
    void Sorting::DereferenceSort(CollectionType& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), DereferenceSortedFunctor<ValueType>());
    }

}

#endif // SORTING_H_6d32e854_ee98_4512_98e0_b388bf208164
