#ifndef MATCHING_TRIPLETS_H_8cfc291f_317b_4e1d_8123_835935e5e447
#define MATCHING_TRIPLETS_H_8cfc291f_317b_4e1d_8123_835935e5e447

#include "IMatchingTriplets.h"
#include "Triple.h"
#include "Pair.h"

namespace problems
{
    using IndexList = std::list<size_t>;
    using IndexListPtr = std::shared_ptr<IndexList>;

    /**
     * The MatchingTriplets class implements the matching triplets problem.
     */
    template <typename T>
    class MatchingTriplets final : public IMatchingTriplets<T>
    {
    public:
        /**
         * The constructor.
         */
        MatchingTriplets() = default;

        /**
         * The destructor.
         */
        virtual ~MatchingTriplets() = default;

        /**
         * The copy/move constructors.
         */
        MatchingTriplets(const MatchingTriplets&) = delete;
        MatchingTriplets(MatchingTriplets&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MatchingTriplets& operator=(const MatchingTriplets&) = delete;
        MatchingTriplets& operator=(MatchingTriplets&&) = delete;

        /**
         * Gets the matching triplets values.
         */
        virtual std::set<base::Triple<T, T, T>> getMatchingTriplets(const std::vector<T>& values, T sum) override;

        /**
         * Gets the matching closest triplet.
         */
        virtual std::unique_ptr<base::Triple<T, T, T>> getMatchingClosestTriplet(const std::vector<T>& values, T sum) override;

        /**
         * Gets the matching triplets indexes.
         */
        virtual std::list<base::Triple<size_t, size_t, size_t>> getMatchingTripletsIndexes(const std::vector<T>& values, T sum) override;

    private:
        using ElementIndexesMap = std::map<T, IndexListPtr>;

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
            const ElementIndexesMap& indexesMap);

        /**
         * Gets the matching closest pair.
         */
        std::unique_ptr<base::Pair<T, T>> getMatchingClosestPair(
            const std::vector<T>& sortedValues,
            size_t startIndex,
            size_t endIndex,
            T sum);

        /**
         * Creates the mapping of the elements to their's indexes.
         */
        void createElementIndexesMap(const std::vector<T>& values, ElementIndexesMap& indexesMap);
    };

    /**
     * Gets the matching triplets values.
     */
    template <typename T>
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
    template <typename T>
    std::list<base::Triple<size_t, size_t, size_t>> MatchingTriplets<T>::getMatchingTripletsIndexes(const std::vector<T>& values, T sum)
    {
        std::list<base::Triple<size_t, size_t, size_t>> result;

        if (values.size() < 3) {
            return result;
        }


        ElementIndexesMap indexesMap;
        createElementIndexesMap(values, indexesMap);

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
                indexesMap);

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
    template <typename T>
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
    template <typename T>
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
    template <typename T>
    std::list<base::Pair<size_t, size_t>> MatchingTriplets<T>::getMatchingPairsIndexes(
        const std::vector<T>& values,
        size_t startIndex,
        size_t endIndex,
        T sum,
        const ElementIndexesMap& indexesMap)
    {
        std::list<base::Pair<size_t, size_t>> result;

        for (size_t i = startIndex; i <= endIndex - 1; ++i)
        {
            T currValue = values[i];
            T matchingValue = sum - currValue;

            typename ElementIndexesMap::const_iterator matchingValueIterator = indexesMap.find(matchingValue);

            if (matchingValueIterator != indexesMap.end())
            {
                IndexListPtr matchingIndexes = matchingValueIterator->second;
                size_t firstIndex = i;

                for (size_t secondIndex : *matchingIndexes) {
                    if (secondIndex > firstIndex && secondIndex <= endIndex)
                    {
                        base::Pair<size_t, size_t> newResult(firstIndex, secondIndex);
                        result.push_back(newResult);
                    }
                }
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

    /**
     * Creates the mapping of the elements to their's indexes.
     */
    template <typename T>
    void MatchingTriplets<T>::createElementIndexesMap(const std::vector<T>& values, ElementIndexesMap& indexesMap)
    {
        for (size_t i = 0; i < values.size(); ++i)
        {
            T currValue = values[i];

            IndexListPtr indexList;

            typename ElementIndexesMap::iterator valueIterator = indexesMap.find(currValue);

            if (valueIterator != indexesMap.end())
            {
                indexList = valueIterator->second;
            }
            else
            {
                indexList.reset(new IndexList);
                indexesMap.insert({currValue, indexList});
            }

            indexList->push_back(i);
        }
    }

}

#endif // MATCHING_TRIPLETS_H_8cfc291f_317b_4e1d_8123_835935e5e447
