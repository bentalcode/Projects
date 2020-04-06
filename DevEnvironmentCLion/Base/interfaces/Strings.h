#ifndef STRINGS_H_c3ecae46_5171_4061_9f30_8efa76f1c45a
#define STRINGS_H_c3ecae46_5171_4061_9f30_8efa76f1c45a

namespace base
{
    /**
     * The Strings class implements complementary APIs for strings.
     */
    class Strings final
    {
    public:
        /**
         * The constructor.
         */
        Strings() = delete;

        /**
         * The destructor.
         */
        ~Strings() = delete;

        /**
         * The copy/move constructors.
         */
        Strings(const Strings&) = delete;
        Strings(Strings&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Strings& operator=(const Strings&) = delete;
        Strings& operator=(Strings&&) = delete;

        /**
         * Trims from start (in place).
         */
        static inline void ltrim(std::string& str)
        {
            str.erase(
                str.begin(),
                std::find_if(str.begin(), str.end(), [](std::string::value_type ch)
                {
                    return !std::isspace(ch);
                })
            );
        }

        /**
         * Trims from end (in place).
         */
        static inline void rtrim(std::string& str)
        {
            str.erase(
                std::find_if(str.rbegin(), str.rend(), [](std::string::value_type ch)
                {
                    return !std::isspace(ch);
                }).base(),
                str.end());
        }

        /**
         * Trims from both ends (in place).
         */
        static inline void trim(std::string& str)
        {
            ltrim(str);
            rtrim(str);
        }

        /**
         * Trims from start (copying).
         */
        static inline std::string ltrim_copy(const std::string& str)
        {
            std::string copiedStr(str);
            ltrim(copiedStr);
            return copiedStr;
        }

        /**
         * Trims from end (copying).
         */
        static inline std::string rtrim_copy(const std::string& str)
        {
            std::string copiedStr(str);
            rtrim(copiedStr);
            return copiedStr;
        }

        /**
         * Trims from both ends (copying).
         */
        static inline std::string trim_copy(const std::string& str)
        {
            std::string copiedStr(str);
            trim(copiedStr);
            return copiedStr;
        }
    };
}

#endif // STRINGS_H_c3ecae46_5171_4061_9f30_8efa76f1c45a
