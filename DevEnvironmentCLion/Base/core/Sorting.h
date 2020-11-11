#ifndef SORTING_H_6d32e854_ee98_4512_98e0_b388bf208164
#define SORTING_H_6d32e854_ee98_4512_98e0_b388bf208164

namespace base
{
    /**
     * The Sorting class implements complementary APIs for sorting.
     */
    class Sorting final
    {
    public:
        /**
         * Sorts the collection.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static void sort(CollectionType& intervals);

        /**
         * Sorts the collection with a functor.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static void sort(
            CollectionType& intervals,
            const std::binary_function<ValueType, ValueType, bool>& functor);

        /**
         * Sorts the collection by dereference it's pointers.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static void dereferenceSort(CollectionType& intervals);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Sorting() = delete;
        ~Sorting() = delete;
    };

    /**
     * Defines the dereference sort functor for pointers.
     */
    template <typename T>
    struct DereferenceSortedFunctor final : public std::binary_function<T, T, bool>
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
    void Sorting::sort(CollectionType& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
    }

    /**
     * Sorts the collection with a functor.
     */
    template<typename CollectionType, typename ValueType>
    void Sorting::sort(
        CollectionType& intervals,
        const std::binary_function<ValueType, ValueType, bool>& functor)
    {
        std::sort(intervals.begin(), intervals.end(), functor);
    }

    /**
     * Sorts the collection by dereference it's pointers.
     */
    template<typename CollectionType, typename ValueType>
    void Sorting::dereferenceSort(CollectionType& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), DereferenceSortedFunctor<ValueType>());
    }

}

#endif // SORTING_H_6d32e854_ee98_4512_98e0_b388bf208164
