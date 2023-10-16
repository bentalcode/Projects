#ifndef I_RANDOM_GENERATOR_H_9f2fd989_72d0_4c38_9660_ade9b37b2ef8
#define I_RANDOM_GENERATOR_H_9f2fd989_72d0_4c38_9660_ade9b37b2ef8

#include "StringComparisonType.h"
#include <string>
#include <memory>

namespace base
{
    /**
     * The IRandomGenerator interface defines a random generator.
     */
    class IRandomGenerator
    {
    public:
        /**
         * The constructor.
         */
        IRandomGenerator() = default;

        /**
         * The destructor.
         */
        virtual ~IRandomGenerator() = default;

        /**
         * The copy/move constructors.
         */
        IRandomGenerator(const IRandomGenerator&) = delete;
        IRandomGenerator(IRandomGenerator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IRandomGenerator& operator=(const IRandomGenerator&) = delete;
        IRandomGenerator& operator=(IRandomGenerator&&) = delete;

        /**
         * Generates a new boolean.
         */
        virtual bool NextBoolean() = 0;

        /**
         * Generates a new integer.
         */
        virtual int NextInteger() = 0;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual int NextInteger(int from, int to) = 0;

        /**
         * Generates a new Size.
         */
        virtual size_t NextSizeT() = 0;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual size_t NextSizeT(size_t from, size_t to) = 0;

        /**
         * Generates a new float.
         */
        virtual float NextFloat() = 0;

        /**
         * Generates a new float between the following specified values (inclusively).
         */
        virtual float NextFloat(float from, float to) = 0;

        /**
         * Generates a new double.
         */
        virtual double NextDouble() = 0;

        /**
         * Generates a new double between the following specified values (inclusively).
         */
        virtual double NextDouble(double from, double to) = 0;

        /**
         * Generates a new character.
         */
        virtual wchar_t NextCharacter() = 0;

        /**
         * Generates a new character between the following specified values (inclusively).
         */
        virtual wchar_t NextCharacter(wchar_t from, wchar_t to) = 0;

        /**
         * Generates a new string.
         */
        virtual std::wstring NextString() = 0;

        /**
         * Generates a new string ignore case with a length between the specified lengths (inclusively).
         */
        virtual std::wstring NextString(size_t fromLength, size_t toLength) = 0;

        /**
         * Generates a new string with characters between the specified range (inclusively),
         * and length between the specified lengths (inclusively).
         */
        virtual std::wstring NextString(
            wchar_t fromCharacter,
            wchar_t toCharacter,
            size_t fromLength,
            size_t toLength) = 0;
    };

    //
    // Defines the Shared Ptr of Random Generator...
    //
    template <typename T>
    using IRandomGeneratorSharedPtr = std::shared_ptr<IRandomGenerator>;
}

#endif // I_RANDOM_GENERATOR_H_9f2fd989_72d0_4c38_9660_ade9b37b2ef8
