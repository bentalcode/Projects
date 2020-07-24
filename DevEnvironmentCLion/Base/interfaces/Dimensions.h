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
         * Gets the length of a dimension.
         */
        template <typename T>
        static T length(T start, T end);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Dimensions() = delete;
        ~Dimensions() = delete;
    };

    /**
     * Gets the length of a dimension.
     */
    template <typename T>
    T Dimensions::length(T start, T end)
    {
        if (start < 0 || end < 0 || start > end)
        {
            return 0;
        }

        return end - start + 1;
    }
}

#endif // DIMENSIONS_H_e5f0c1e0_aa6b_43ab_9fb3_72232a017de2
