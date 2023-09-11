#ifndef I_TO_STRING_H_14d08249_40ab_449a_ac4f_aab15cea5793
#define I_TO_STRING_H_14d08249_40ab_449a_ac4f_aab15cea5793

namespace base
{
    /**
     * The IToString interface defines a to string transformer.
     */
    template <typename T>
    class IToString
    {
    public:
        /**
         * The constructor.
         */
        IToString() = default;

        /**
         * The destructor.
         */
        virtual ~IToString() = default;

        /**
         * The copy/move constructors.
         */
        IToString(const IToString&) = delete;
        IToString(IToString&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IToString& operator=(const IToString&) = delete;
        IToString& operator=(IToString&&) = delete;

        /**
         * Transforms an object to a string.
         */
        virtual std::string toString(const T& obj) const = 0;
    };

    template <typename T>
    using IToStringPtr = std::shared_ptr<IToString<T>>;
}

#endif // I_TO_STRING_H_14d08249_40ab_449a_ac4f_aab15cea5793
