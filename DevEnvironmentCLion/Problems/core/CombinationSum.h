#ifndef COMBINATION_SUM_H_3fe5c424_b764_4b7e_ad2d_9ea20db0416a
#define COMBINATION_SUM_H_3fe5c424_b764_4b7e_ad2d_9ea20db0416a

#include "ICombinationSum.h"

namespace problems
{
    /**
     * The CombinationSum class implements the combination sum problem.
     */
    template <typename T>
    class CombinationSum final : public ICombinationSum<T>
    {
    public:
        /**
         * The constructor.
         */
        CombinationSum() = default;

        /**
         * The destructor.
         */
        virtual ~CombinationSum() = default;

        /**
         * The copy/move constructors.
         */
        CombinationSum(const CombinationSum&) = delete;
        CombinationSum(CombinationSum&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CombinationSum& operator=(const CombinationSum&) = delete;
        CombinationSum& operator=(CombinationSum&&) = delete;

        /**
         * Gets the combination sum.
         * The result set must not contain duplicate combinations.
         */
        virtual std::set<std::vector<T>> combinationSum(const std::vector<T>& values, T sum);

        /**
         * Gets the combination sum.
         * Each value should be used once.
         * The result set must not contain duplicate combinations.
         */
        virtual std::set<std::vector<T>> singleCombinationSum(const std::vector<T>& values, int sum);

    private:
        void combinationSum(
            const std::vector<T>& values,
            T sum,
            int currIndex,
            T currSum,
            std::vector<T>& currResult,
            std::set<std::vector<T>>& results);

        void singleCombinationSum(
            const std::vector<T>& values,
            T sum,
            int currIndex,
            T currSum,
            std::vector<T>& currResult,
            std::set<std::vector<T>>& results);
    };

    /**
     * Gets the combination sum.
     * The result set must not contain duplicate combinations.
     */
    template <typename T>
    std::set<std::vector<T>> CombinationSum<T>::combinationSum(const std::vector<T>& values, T sum) {
        std::set<std::vector<T>> results;

        if (values.empty()) {
            return results;
        }

        std::vector<T> sortedValues(values);
        std::sort(sortedValues.begin(), sortedValues.end());

        int currIndex = 0;
        int currSum = 0;
        std::vector<T> currResult;

        combinationSum(
            sortedValues,
            sum,
            currIndex,
            currSum,
            currResult,
            results);

        return results;
    }

    /**
     * Gets the combination sum.
     * Each value should be used once.
     * The result set must not contain duplicate combinations.
     */
    template <typename T>
    std::set<std::vector<T>> CombinationSum<T>::singleCombinationSum(const std::vector<T>& values, int sum) {
        std::set<std::vector<T>> results;

        if (values.empty()) {
            return results;
        }

        std::vector<T> sortedValues(values.begin(), values.end());
        std::sort(sortedValues.begin(), sortedValues.end());

        int currIndex = 0;
        T currSum = 0;
        std::vector<T> currResult;

        singleCombinationSum(sortedValues, sum, currIndex, currSum, currResult, results);

        return results;
    }

    template <typename T>
    void CombinationSum<T>::combinationSum(
        const std::vector<T>& values,
        T sum,
        int currIndex,
        T currSum,
        std::vector<T>& currResult,
        std::set<std::vector<T>>& results) {

        assert(currIndex >= 0 && currIndex <= values.size());

        if (currIndex > values.size()) {
            return;
        }

        if (currSum > sum) {
            return;
        }

        if (currSum == sum) {
            std::vector<T> newResult(currResult);
            results.insert(newResult);
            return;
        }

        if (currIndex == values.size()) {
            return;
        }

        T currValue = values[currIndex];
        T maxNumberOfInstances = (sum - currSum) / currValue;

        for (int instanceCount = 0; instanceCount <= maxNumberOfInstances; ++instanceCount) {
            T sumSoFar = currSum + (instanceCount * currValue);
            assert(sumSoFar <= sum);

            for (int i = 0; i < instanceCount; ++i) {
                currResult.push_back(currValue);
            }

            combinationSum(values, sum, currIndex + 1, sumSoFar, currResult, results);

            for (int i = 0; i < instanceCount; ++i) {
                currResult.pop_back();
            }
        }
    }

    template <typename T>
    void CombinationSum<T>::singleCombinationSum(
        const std::vector<T>& values,
        T sum,
        int currIndex,
        T currSum,
        std::vector<T>& currResult,
        std::set<std::vector<T>>& results) {

        assert(currIndex >= 0 && currIndex <= values.size());

        if (currIndex > values.size()) {
            return;
        }

        if (currSum > sum) {
            return;
        }

        if (currSum == sum) {
            std::vector<T> newResult(currResult);
            results.insert(newResult);
            return;
        }

        if (currIndex == values.size()) {
            return;
        }

        singleCombinationSum(values, sum, currIndex + 1, currSum, currResult, results);

        T currValue = values[currIndex];
        T sumSoFar = currSum + currValue;

        if (sumSoFar > sum) {
            return;
        }

        currResult.push_back(currValue);
        singleCombinationSum(values, sum, currIndex + 1, sumSoFar, currResult, results);
        currResult.pop_back();
    }
}

#endif // COMBINATION_SUM_H_3fe5c424_b764_4b7e_ad2d_9ea20db0416a
