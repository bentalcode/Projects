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

        /**
         * Generates a new double.
         */
        virtual double nextDouble() override;

        /**
         * Generates a new double between the following specified values (inclusively).
         */
        virtual double nextDouble(double from, double to) override;

        /**
         * Generates a new character.
         */
        virtual char nextCharacter() override;

        /**
         * Generates a new character between the following specified values (inclusively).
         */
        virtual char nextCharacter(char from, char to) override;

        /**
         * Generates a new string.
         */
        virtual std::string nextString() override;

        /**
         * Generates a new string ignore case with a length between the specified lengths (inclusively).
         */
        virtual std::string nextString(size_t fromLength, size_t toLength) override;

        /**
         * Generates a new string with characters between the specified range (inclusively),
         * and length between the specified lengths (inclusively).
         */
        virtual std::string nextString(
            char fromCharacter,
            char toCharacter,
            size_t fromLength,
            size_t toLength) override;

    private:
        static const size_t defaultStringMaxLength;
    };
}

#endif // RANDOM_GENERATOR_H_f4975c61_a60f_4167_9cd2_e0a52c9b4b56
