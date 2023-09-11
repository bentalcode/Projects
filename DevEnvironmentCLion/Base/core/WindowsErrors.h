#ifndef WINDOWS_ERRORS_H_4b6123a4_f0ab_401d_94fc_62c4ae77022c
#define WINDOWS_ERRORS_H_4b6123a4_f0ab_401d_94fc_62c4ae77022c

namespace base
{
    /**
     * The Windows Errors class implements complementary APIs for windows errors.
     */
    class WindowsErrors final
    {
    public:
        /**
         * Gets the last windows errors as a string.
         */
        static std::string getLastErrorAsString();

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        WindowsErrors() = delete;
        ~WindowsErrors() = delete;
    };
}

#endif // WINDOWS_ERRORS_H_4b6123a4_f0ab_401d_94fc_62c4ae77022c
