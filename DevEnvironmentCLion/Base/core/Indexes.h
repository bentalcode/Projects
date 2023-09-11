#ifndef INDEXES_H_e5f0c1e0_aa6b_43ab_9fb3_72232a017de2
#define INDEXES_H_e5f0c1e0_aa6b_43ab_9fb3_72232a017de2

namespace base
{
    /**
     * The Indexes class implements complementary APIs for dimensions.
     */
    class Indexes final
    {
    public:
        /**
         * Validates an index.
         */
        template <typename T>
        static void validateIndex(T index, T startIndex, T endIndex);

        /**
         * Gets the number of indexes in a dimension.
         */
        template <typename T>
        static int size(T startIndex, T endIndex);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Indexes() = delete;
        ~Indexes() = delete;
    };

    /**
     * Validates an index.
     */
    template <typename T>
    void Indexes::validateIndex(T index, T startIndex, T endIndex)
    {
        if (index < startIndex || index > endIndex)
        {
            std::string errorMessage =
                "The index " + std::to_string(index) + "is out of range." +
                " The specified range is: [" + std::to_string(startIndex) + "-" + std::to_string(endIndex) + "]";

            throw BaseException(errorMessage);
        }
    }

    /**
     * Gets the number of elements in a dimension.
     */
    template <typename T>
    int Indexes::size(T startIndex, T endIndex)
    {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex)
        {
            return 0;
        }

        return endIndex - startIndex + 1;
    }
}

#endif // INDEXES_H_e5f0c1e0_aa6b_43ab_9fb3_72232a017de2
