#ifndef I_COMBINATION_SUM_H_33a7d338_4f7b_4322_939c_3faf69bd2448
#define I_COMBINATION_SUM_H_33a7d338_4f7b_4322_939c_3faf69bd2448

#include "BaseDependencies.h"

namespace problems
{
    /**
     * The ICombinationSum interface defines a combination sum problem.
     */
    template <typename T>
    class ICombinationSum
    {
    public:
        /**
         * The constructor.
         */
        ICombinationSum() = default;

        /**
         * The destructor.
         */
        virtual ~ICombinationSum() = default;

        /**
         * The copy/move constructors.
         */
        ICombinationSum(const ICombinationSum&) = delete;
        ICombinationSum(ICombinationSum&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICombinationSum& operator=(const ICombinationSum&) = delete;
        ICombinationSum& operator=(ICombinationSum&&) = delete;

        /**
         * Gets the combination sum.
         * The result set must not contain duplicate combinations.
         */
        virtual std::set<std::vector<T>> combinationSum(const std::vector<T>& values, T sum) = 0;

        /**
         * Gets the combination sum.
         * Each value should be used once.
         * The result set must not contain duplicate combinations.
         */
        virtual std::set<std::vector<T>> singleCombinationSum(const std::vector<T>& values, int sum) = 0;
    };

}

#endif // I_MATCHING_TRIPLETS_H_ecadeedd_0413_4823_a1e6_2bfec8721330
