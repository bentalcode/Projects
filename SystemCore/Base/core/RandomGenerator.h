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
        virtual bool NextBoolean() override;

        /**
         * Generates a new integer.
         */
        virtual int NextInteger() override;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual int NextInteger(int from, int to) override;

        /**
         * Generates a new Size.
         */
        virtual size_t NextSizeT() override;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual size_t NextSizeT(size_t from, size_t to) override;

        /**
         * Generates a new float.
         */
        virtual float NextFloat() override;

        /**
         * Generates a new float between the following specified values (inclusively).
         */
        virtual float NextFloat(float from, float to) override;

        /**
         * Generates a new double.
         */
        virtual double NextDouble() override;

        /**
         * Generates a new double between the following specified values (inclusively).
         */
        virtual double NextDouble(double from, double to) override;

        /**
         * Generates a new character.
         */
        virtual wchar_t NextCharacter() override;

        /**
         * Generates a new character between the following specified values (inclusively).
         */
        virtual wchar_t NextCharacter(wchar_t from, wchar_t to) override;

        /**
         * Generates a new string.
         */
        virtual std::wstring NextString() override;

        /**
         * Generates a new string ignore case with a length between the specified lengths (inclusively).
         */
        virtual std::wstring NextString(size_t fromLength, size_t toLength) override;

        /**
         * Generates a new string with characters between the specified range (inclusively),
         * and length between the specified lengths (inclusively).
         */
        virtual std::wstring NextString(
            wchar_t fromCharacter,
            wchar_t toCharacter,
            size_t fromLength,
            size_t toLength) override;

    private:
        static const size_t DEFAULT_STRING_MAX_LENGTH;
    };
}

#endif // RANDOM_GENERATOR_H_f4975c61_a60f_4167_9cd2_e0a52c9b4b56
