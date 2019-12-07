#ifndef MATCHING_TRIPLETS_H_bfa5e657_5c95_4b33_8a04_2a78037d346b
#define MATCHING_TRIPLETS_H_bfa5e657_5c95_4b33_8a04_2a78037d346b

#include "IMatchingTriplets.h"
#include "Triple.h"
#include "Pair.h"

namespace problems
{
    /**
     * The MatchingTriplets class implements the matching triplets problem.
     */
    class MatchingTriplets : public IMatchingTriplets
    {
    public:
        /**
         * The MatchingTriplets constructor.
         */
        MatchingTriplets();

        /**
         * The MatchingTriplets destructor.
         */
        virtual ~MatchingTriplets();

        /**
         * Gets the matching triplets values.
         */
        template<typename T>
        std::set<base::Triple<T, T, T>> getMatchingTriplets(const std::vector<T>& values, T sum);

    private:
        /**
         * Gets the matching pairs values.
         */
        template<typename T>
        std::set<base::Pair<T, T>> getMatchingPairs(
            const std::vector<T>& values,
            size_t startIndex,
            size_t endIndex,
            T sum);
    };

    /**
     * Gets the matching triplets values.
     */
    template<typename T>
    std::set<base::Triple<T, T, T>> MatchingTriplets::getMatchingTriplets(const std::vector<T>& values, T sum)
    {
        std::set<base::Triple<T, T, T>> result;

        if (values.size() < 3) {
            return result;
        }

        std::vector<int> sortedValues(values);
        std::sort(sortedValues.begin(), sortedValues.end());

        for (size_t i = 0; i < sortedValues.size() - 2; ++i) {
            int currValue = sortedValues[i];
            int matchingValue = sum - currValue;

            size_t startIndex = i + 1;
            size_t endIndex = sortedValues.size() - 1;

            std::set<base::Pair<T, T>> matchingPairs = getMatchingPairs(
                sortedValues,
                startIndex,
                endIndex,
                matchingValue);

            for (base::Pair<T, T> matchingPair : matchingPairs)
            {
                base::Triple<T, T, T> newResult(currValue, matchingPair.getFirst(), matchingPair.getSecond());
                result.insert(newResult);
            }
        }

        return result;
    }

    /**
     * Gets the matching pairs values.
     */
    template<typename T>
    std::set<base::Pair<T, T>> MatchingTriplets::getMatchingPairs(
        const std::vector<T>& sortedValues,
        size_t startIndex,
        size_t endIndex,
        T sum)
    {
        assert(startIndex <= endIndex);
        std::set<base::Pair<T, T>> result;


        size_t length = endIndex - startIndex + 1;

        if (length < 2) {
            return result;
        }

        size_t leftIndex = startIndex;
        size_t rightIndex = endIndex;

        while (leftIndex < rightIndex) {
            T leftValue = sortedValues[leftIndex];
            T rightValue = sortedValues[rightIndex];

            T currSum = leftValue + rightValue;

            if (currSum == sum) {
                base::Pair<T, T> newResult(leftValue, rightValue);
                result.insert(newResult);

                ++leftIndex;
                --rightIndex;
            }
            else if (currSum < sum) {
                ++leftIndex;
            }
            else {
                --rightIndex;
            }
        }

        return result;
    }

}

#endif // MATCHING_TRIPLETS_H_bfa5e657_5c95_4b33_8a04_2a78037d346b
