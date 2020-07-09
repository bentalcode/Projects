#ifndef I_HASH_CODE_PROVIDER_H_6b685f61_da77_4c92_a6b2_c27ec8a7ddc4
#define I_HASH_CODE_PROVIDER_H_6b685f61_da77_4c92_a6b2_c27ec8a7ddc4

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
        virtual int getHashCode(const T& obj) = 0;
    };
}

#endif // I_HASH_CODE_PROVIDER_H_6b685f61_da77_4c92_a6b2_c27ec8a7ddc4
