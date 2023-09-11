#ifndef I_MATCHING_TRIPLETS_H_8886e60b_bad4_49f9_8f89_5d0da2eef261
#define I_MATCHING_TRIPLETS_H_8886e60b_bad4_49f9_8f89_5d0da2eef261

#include "Triple.h"

namespace problems
{
    /**
     * The IMatchingTriplets interface defines a matching triplets problem.
     */
    template <typename T>
    class IMatchingTriplets
    {
    public:
        /**
         * The constructor.
         */
        IMatchingTriplets() = default;

        /**
         * The destructor.
         */
        virtual ~IMatchingTriplets() = default;

        /**
         * The copy/move constructors.
         */
        IMatchingTriplets(const IMatchingTriplets&) = delete;
        IMatchingTriplets(IMatchingTriplets&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMatchingTriplets& operator=(const IMatchingTriplets&) = delete;
        IMatchingTriplets& operator=(IMatchingTriplets&&) = delete;

        /**
         * Gets the matching triplets values.
         */
        virtual std::set<base::Triple<T, T, T>> getMatchingTriplets(const std::vector<T>& values, T sum) = 0;

        /**
         * Gets the matching closest triplet.
         */
        virtual std::unique_ptr<base::Triple<T, T, T>> getMatchingClosestTriplet(const std::vector<T>& values, T sum) = 0;

        /**
         * Gets the matching triplets indexes.
         */
        virtual std::list<base::Triple<size_t, size_t, size_t>> getMatchingTripletsIndexes(const std::vector<T>& values, T sum) = 0;
    };

}

#endif // I_MATCHING_TRIPLETS_H_8886e60b_bad4_49f9_8f89_5d0da2eef261
