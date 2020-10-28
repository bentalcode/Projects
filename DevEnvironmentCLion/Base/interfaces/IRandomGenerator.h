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
         * Generates a new size.
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
    };

    template <typename T>
    using IRandomGeneratorPtr = std::shared_ptr<IRandomGenerator>;
}

#endif // I_RANDOM_GENERATOR_H_9f2fd989_72d0_4c38_9660_ade9b37b2ef8
