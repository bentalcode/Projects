#ifndef I_FROM_STRING_H_69006faf_17df_4745_8cc6_9e5ba7dcd7ac
#define I_FROM_STRING_H_69006faf_17df_4745_8cc6_9e5ba7dcd7ac

namespace base
{
    /**
     * The IFromString interface of a from string transformer.
     */
    template <typename T>
    class IFromString
    {
    public:
        /**
         * The constructor.
         */
        IFromString() = default;

        /**
         * The destructor.
         */
        virtual ~IFromString() = default;

        /**
         * The copy/move constructors.
         */
        IFromString(const IFromString&) = delete;
        IFromString(IFromString&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IFromString& operator=(const IFromString&) = delete;
        IFromString& operator=(IFromString&&) = delete;

        /**
         * Transforms a string to an object.
         */
        virtual T fromString(const std::string& value) const = 0;
    };

    //
    // Defines the SharedPtr of From String...
    //
    template <typename T>
    using IFromStringSharedPtr = std::shared_ptr<IFromString<T>>;
}

#endif // I_FROM_STRING_H_69006faf_17df_4745_8cc6_9e5ba7dcd7ac
