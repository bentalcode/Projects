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
    template<typename T>
    class MatchingTriplets : public IMatchingTriplets<T>
    {
    public:
        /**
         * The MatchingTriplets constructor.
         */
        MatchingTriplets() = default;

        /**
         * The MatchingTriplets destructor.
         */
        virtual ~MatchingTriplets() = default;

        /**
         * Gets the matching triplets values.
         */
        virtual std::set<base::Triple<T, T, T>> getMatchingTriplets(const std::vector<T>& values, T sum);

        /**
         * Gets the matching closest triplet.
         */
        virtual std::unique_ptr<base::Triple<T, T, T>> getMatchingClosestTriplet(const std::vector<T>& values, T sum);

        /**
         * Gets the matching triplets indexes.
         */
        virtual std::list<base::Triple<size_t, size_t, size_t>> getMatchingTripletsIndexes(const std::vector<T>& values, T sum);

    private:
        /**
         * Gets the matching pairs values.
         */
        std::set<base::Pair<T, T>> getMatchingPairs(
            const std::vector<T>& sortedValues,
            size_t startIndex,
            size_t endIndex,
            T sum);

        /**
         * Gets the matching pairs indexes.
         */
        std::list<base::Pair<size_t, size_t>> getMatchingPairsIndexes(
            const std::vector<T>& values,
            size_t startIndex,
            size_t endIndex,
            T sum,
            std::map<T, std::set<size_t>> indexes);

        /**
         * Gets the matching closest pair.
         */
        std::unique_ptr<base::Pair<T, T>> getMatchingClosestPair(
            const std::vector<T>& sortedValues,
            size_t startIndex,
            size_t endIndex,
            T sum);
    };

    /**
     * Gets the matching triplets values.
     */
    template<typename T>
    std::set<base::Triple<T, T, T>> MatchingTriplets<T>::getMatchingTriplets(const std::vector<T>& values, T sum)
    {
        std::set<base::Triple<T, T, T>> result;

        if (values.size() < 3)
        {
            return result;
        }

        std::vector<int> sortedValues(values);
        std::sort(sortedValues.begin(), sortedValues.end());

        for (size_t i = 0; i < sortedValues.size() - 2; ++i)
        {
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
     * Gets the matching triplets indexes.
     */
    template<typename T>
    std::list<base::Triple<size_t, size_t, size_t>> MatchingTriplets<T>::getMatchingTripletsIndexes(const std::vector<T>& values, T sum)
    {
        std::list<base::Triple<size_t, size_t, size_t>> result;

        if (values.size() < 3) {
            return result;
        }

        std::map<T, std::set<size_t>> indexes;

        for (size_t i = 0; i < values.size() - 2; ++i)
        {
            T currValue = values[i];
            T matchingValue = sum - currValue;

            size_t startIndex = i + 1;
            size_t endIndex = values.size() - 1;

            std::list<base::Pair<size_t, size_t>> matchingPairs = getMatchingPairsIndexes(
                values,
                startIndex,
                endIndex,
                matchingValue,
                indexes);

            for (base::Pair<size_t, size_t> matchingPair : matchingPairs)
            {
                base::Triple<size_t, size_t, size_t> newResult(i, matchingPair.getFirst(), matchingPair.getSecond());
                result.push_back(newResult);
            }
        }

        return result;
    }

    /**
     * Gets the matching closest triplet.
     */
    template<typename T>
    std::unique_ptr<base::Triple<T, T, T>> MatchingTriplets<T>::getMatchingClosestTriplet(const std::vector<T>& values, T sum)
    {
        std::unique_ptr<base::Triple<T, T, T>> result;
        T minDiff = std::numeric_limits<T>::max();

        std::vector<T> sortedValues(values);
        std::sort(sortedValues.begin(), sortedValues.end());

        for (size_t i = 0; i < sortedValues.size() - 2; ++i)
        {
            T currValue = sortedValues[i];
            T matchingValue = sum - currValue;

            size_t startIndex = i + 1;
            size_t endIndex = sortedValues.size() - 1;

            std::unique_ptr<base::Pair<T, T>> pairResult = getMatchingClosestPair(
                sortedValues,
                startIndex,
                endIndex,
                matchingValue);

            assert(pairResult.get() != nullptr);

            T firstValue = currValue;
            T secondValue = pairResult->getFirst();
            T thirdValue = pairResult->getSecond();

            int currSum = firstValue + secondValue + thirdValue;

            if (currSum == sum)
            {
                result.reset(new base::Triple<T, T, T>(firstValue, secondValue, thirdValue));
                return result;
            }

            T currDiff = std::abs(sum - currSum);

            if (currDiff < minDiff)
            {
                minDiff = currDiff;
                result.reset(new base::Triple<T, T, T>(firstValue, secondValue, thirdValue));
            }
        }

        return result;
    }

    /**
     * Gets the matching pairs values.
     */
    template<typename T>
    std::set<base::Pair<T, T>> MatchingTriplets<T>::getMatchingPairs(
        const std::vector<T>& sortedValues,
        size_t startIndex,
        size_t endIndex,
        T sum)
    {
        assert(startIndex <= endIndex);
        std::set<base::Pair<T, T>> result;


        size_t length = endIndex - startIndex + 1;

        if (length < 2)
        {
            return result;
        }

        size_t leftIndex = startIndex;
        size_t rightIndex = endIndex;

        while (leftIndex < rightIndex)
        {
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

    /**
     * Gets the matching pairs indexes.
     */
    template<typename T>
    std::list<base::Pair<size_t, size_t>> MatchingTriplets<T>::getMatchingPairsIndexes(
        const std::vector<T>& values,
        size_t startIndex,
        size_t endIndex,
        T sum,
        std::map<T, std::set<size_t>> indexes)
    {
        std::list<base::Pair<size_t, size_t>> result;

        for (size_t i = startIndex; i <= endIndex; ++i)
        {
            T currValue = values[i];
            T matchingValue = sum - currValue;

            typename std::map<T, std::set<size_t>>::iterator matchingValueIterator = indexes.find(matchingValue);

            if (matchingValueIterator != indexes.end())
            {
                std::set<size_t> matchingIndexes = matchingValueIterator->second;

                for (size_t matchingIndex : matchingIndexes) {
                    size_t firstIndex = matchingIndex;
                    size_t secondIndex = i;

                    base::Pair<size_t, size_t> newResult(firstIndex, secondIndex);
                    result.push_back(newResult);
                }
            }

            typename std::map<T, std::set<size_t>>::iterator currValueIterator = indexes.find(currValue);

            if (currValueIterator != indexes.end())
            {
                std::set<size_t>& currValueIndexes = currValueIterator->second;
                currValueIndexes.insert(i);
            }
            else
            {
                std::set<size_t> currValueIndexes;
                currValueIndexes.insert(i);
                indexes.insert({currValue, currValueIndexes});
            }
        }

        return result;
    }

    template <typename T>
    std::unique_ptr<base::Pair<T, T>> MatchingTriplets<T>::getMatchingClosestPair(
        const std::vector<T>& sortedValues,
        size_t startIndex,
        size_t endIndex,
        T sum)
    {
        std::unique_ptr<base::Pair<T, T>> result;
        T minDiff = std::numeric_limits<T>::max();

        size_t length = endIndex - startIndex + 1;

        if (length < 2) {
            return result;
        }

        size_t leftIndex = startIndex;
        size_t rightIndex = endIndex;

        while (leftIndex < rightIndex)
        {
            T leftValue = sortedValues[leftIndex];
            T rightValue = sortedValues[rightIndex];

            T currSum = leftValue + rightValue;

            if (currSum == sum)
            {
                result.reset(new base::Pair<T, T>(leftValue, rightValue));
                return result;
            }

            T currDiff = std::abs(sum - currSum);

            if (currDiff < minDiff)
            {
                minDiff = currDiff;
                result.reset(new base::Pair<T, T>(leftValue, rightValue));
            }

            if (currSum < sum)
            {
                ++leftIndex;
            }
            else
            {
                --rightIndex;
            }
        }

        return result;
    }

}

#endif // MATCHING_TRIPLETS_H_bfa5e657_5c95_4b33_8a04_2a78037d346b
