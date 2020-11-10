#ifndef SMART_POINTERS_H_3ef47755_7215_4d79_b0de_01e0a7943a8f
#define SMART_POINTERS_H_3ef47755_7215_4d79_b0de_01e0a7943a8f

namespace base
{
    /**
     * The SmartPointers class implements complementary APIs for smart pointers.
     */
    class SmartPointers final
    {
    public:
        /**
         * Validates that the smart pointer refers to a real object.
         */
        template <typename T>
        static void validate(std::shared_ptr<T> ptr);

        /**
         * Validates that the smart pointer refers to a real object.
         */
        template <typename T>
        static void validate(std::unique_ptr<T> ptr);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        SmartPointers() = delete;
        ~SmartPointers() = delete;
    };

    /**
     * Validates that the smart pointer refers to a real object.
     */
    template <typename T>
    void SmartPointers::validate(std::shared_ptr<T> ptr)
    {
        if (!ptr)
        {
            std::string errorMessage = "The shared pointer refer to a null.";
            throw BaseException(errorMessage);
        }
    }

    template <typename T>
    void SmartPointers::validate(std::unique_ptr<T> ptr)
    {
        if (!ptr)
        {
            std::string errorMessage = "The unique pointer refer to a null.";
            throw BaseException(errorMessage);
        }
    }
}

#endif // SMART_POINTERS_H_3ef47755_7215_4d79_b0de_01e0a7943a8f
