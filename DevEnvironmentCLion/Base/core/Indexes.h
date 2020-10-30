#ifndef INDEXES_H_62e92087_fd0f_4d6a_8bc1_ea6b1bc449ed
#define INDEXES_H_62e92087_fd0f_4d6a_8bc1_ea6b1bc449ed

namespace base
{
    /**
     * The Indexes class implements complementary APIs for indexes.
     */
    class Indexes final
    {
    public:

        /**
         * Validates an index.
         */
        template <typename T>
        static void validateIndex(T index, T startIndex, T endIndex);

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
}

#endif // INDEXES_H_62e92087_fd0f_4d6a_8bc1_ea6b1bc449ed
