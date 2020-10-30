#ifndef DIMENSIONS_H_e5f0c1e0_aa6b_43ab_9fb3_72232a017de2
#define DIMENSIONS_H_e5f0c1e0_aa6b_43ab_9fb3_72232a017de2

namespace base
{
    /**
     * The Dimensions class implements complementary APIs for dimensions.
     */
    class Dimensions final
    {
    public:
        /**
         * Gets the number of indexes in a dimension.
         */
        template <typename T>
        static int indexes(T startIndex, T endIndex);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Dimensions() = delete;
        ~Dimensions() = delete;
    };

    /**
     * Gets the number of elements in a dimension.
     */
    template <typename T>
    int Dimensions::indexes(T startIndex, T endIndex)
    {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex)
        {
            return 0;
        }

        return endIndex - startIndex + 1;
    }
}

#endif // DIMENSIONS_H_e5f0c1e0_aa6b_43ab_9fb3_72232a017de2
