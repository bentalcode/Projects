#ifndef I_MINIMUM_WINDOW_SUBSTRING_H_942b9b72_d2dd_43b9_8c8a_a3eace6076a0
#define I_MINIMUM_WINDOW_SUBSTRING_H_942b9b72_d2dd_43b9_8c8a_a3eace6076a0

namespace problems
{
    /**
     * The IMinimumWindowSubstring interface defines a minimum window substring problem.
     */
    class IMinimumWindowSubstring
    {
    public:
        /**
         * The constructor.
         */
        IMinimumWindowSubstring() = default;

        /**
         * The destructor.
         */
        virtual ~IMinimumWindowSubstring() = default;

        /**
         * The copy/move constructors.
         */
        IMinimumWindowSubstring(const IMinimumWindowSubstring&) = delete;
        IMinimumWindowSubstring(IMinimumWindowSubstring&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMinimumWindowSubstring& operator=(const IMinimumWindowSubstring&) = delete;
        IMinimumWindowSubstring& operator=(IMinimumWindowSubstring&&) = delete;

        /**
         * Given a string S and a string T, find the minimum window in S,
         * which will contain all the characters in T in complexity O(n).
         */
        virtual bool findMinimumWindow(std::string& result) = 0;
    };

}

#endif // I_MINIMUM_WINDOW_SUBSTRING_H_942b9b72_d2dd_43b9_8c8a_a3eace6076a0
