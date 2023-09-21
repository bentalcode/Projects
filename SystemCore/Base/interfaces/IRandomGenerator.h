#ifndef I_RANDOM_GENERATOR_H_9f2fd989_72d0_4c38_9660_ade9b37b2ef8
#define I_RANDOM_GENERATOR_H_9f2fd989_72d0_4c38_9660_ade9b37b2ef8

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
        virtual bool nextBoolean() = 0;

        /**
         * Generates a new integer.
         */
        virtual int nextInteger() = 0;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual int nextInteger(int from, int to) = 0;

        /**
         * Generates a new Size.
         */
        virtual size_t nextSizeT() = 0;

        /**
         * Generates a new integer between the following specified values (inclusively).
         */
        virtual size_t nextSizeT(size_t from, size_t to) = 0;

        /**
         * Generates a new float.
         */
        virtual float nextFloat() = 0;

        /**
         * Generates a new float between the following specified values (inclusively).
         */
        virtual float nextFloat(float from, float to) = 0;

        /**
         * Generates a new double.
         */
        virtual double nextDouble() = 0;

        /**
         * Generates a new double between the following specified values (inclusively).
         */
        virtual double nextDouble(double from, double to) = 0;

        /**
         * Generates a new character.
         */
        virtual char nextCharacter() = 0;

        /**
         * Generates a new character between the following specified values (inclusively).
         */
        virtual char nextCharacter(char from, char to) = 0;

        /**
         * Generates a new string.
         */
        virtual std::string nextString() = 0;

        /**
         * Generates a new string ignore case with a length between the specified lengths (inclusively).
         */
        virtual std::string nextString(size_t fromLength, size_t toLength) = 0;

        /**
         * Generates a new string with characters between the specified range (inclusively),
         * and length between the specified lengths (inclusively).
         */
        virtual std::string nextString(
            char fromCharacter,
            char toCharacter,
            size_t fromLength,
            size_t toLength) = 0;
    };

    //
    // Defines the Shared Ptr of Random Generator...
    //
    template <typename T>
    using IRandomGeneratorSharedPtr = std::shared_ptr<IRandomGenerator>;

} // namespace base

#endif // I_RANDOM_GENERATOR_H_9f2fd989_72d0_4c38_9660_ade9b37b2ef8
