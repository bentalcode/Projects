#ifndef RANDOM_GENERATOR_H_f4975c61_a60f_4167_9cd2_e0a52c9b4b56
#define RANDOM_GENERATOR_H_f4975c61_a60f_4167_9cd2_e0a52c9b4b56

#include "IRandomGenerator.h"
#include <bits/stdc++.h>

namespace base
{
    /**
     * The RandomGenerator class implements a random generator.
     */
    class RandomGenerator : public IRandomGenerator
    {
    public:
        /**
         * The RandomGenerator constructor.
         */
        RandomGenerator();

        /**
         * The RandomGenerator destructor.
         */
        virtual ~RandomGenerator();

        /**
         * The copy/move constructors.
         */
        RandomGenerator(const RandomGenerator&) = delete;
        RandomGenerator(RandomGenerator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        RandomGenerator& operator=(const RandomGenerator&) = delete;
        RandomGenerator& operator=(RandomGenerator&&) = delete;

        /**
         * Generates a new boolean.
         */
        virtual bool nextBoolean() override;

        /**
         * Generates a new integer.
         */
        virtual int nextInteger() override;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual int nextInteger(int from, int to) override;

        /**
         * Generates a new size.
         */
        virtual size_t nextSizeT() override;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual size_t nextSizeT(size_t from, size_t to) override;

        /**
         * Generates a new float.
         */
        virtual float nextFloat() override;

        /**
         * Generates a new float between the following specified values (inclusively).
         */
        virtual float nextFloat(float from, float to) override;

    private:
        /**
         * Validates the specified range.
         */
        template <typename T>
        static void validateRange(T start, T end);
    };
}

#endif // RANDOM_GENERATOR_H_f4975c61_a60f_4167_9cd2_e0a52c9b4b56
