#ifndef I_HASH_CODE_PROVIDER_H_701134f5_4915_40aa_8a6d_24abea527432
#define I_HASH_CODE_PROVIDER_H_701134f5_4915_40aa_8a6d_24abea527432

namespace base {

    /**
     * The IHashCodeProvider interface defines a provider for a hash code.
     */
    template <typename T>
    class IHashCodeProvider
    {
    public:
        /**
         * The constructor.
         */
        IHashCodeProvider() = default;

        /**
         * The destructor.
         */
        virtual ~IHashCodeProvider() = default;

        /**
         * The copy/move constructors.
         */
        IHashCodeProvider(const IHashCodeProvider&) = delete;
        IHashCodeProvider(IHashCodeProvider&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IHashCodeProvider& operator=(const IHashCodeProvider&) = delete;
        IHashCodeProvider& operator=(IHashCodeProvider&&) = delete;

        /**
         * Gets the hash code of this instance.
         */
        virtual std::size_t getHashCode(const T& obj) const = 0;
    };

    //
    // Defines the SharedPtr of Hash Code Provider.
    //
    template <typename T>
    using IHashCodeSharedPtr = std::shared_ptr<IHashCodeProvider<T>>;
}

#endif // I_HASH_CODE_PROVIDER_H_701134f5_4915_40aa_8a6d_24abea527432
