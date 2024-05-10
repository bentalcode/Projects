#ifndef I_HASH_CODE_PROVIDER_H_1404f95e_57cf_11ee_8c99_0242ac120002
#define I_HASH_CODE_PROVIDER_H_1404f95e_57cf_11ee_8c99_0242ac120002

#include <memory>

namespace base {

    /**
     * The IHashCodeProvider interface defines a provider for a hash code.
     */
    template <typename T>
    class IHashCodeProvider {
    public:
        IHashCodeProvider() = default;
        virtual ~IHashCodeProvider() = default;

        /**
         * Gets a hash code of an object.
         */
        virtual size_t GetHashCode(const T& obj) const = 0;
    };

    /**
     * Defines the Shared Ptr of Hash Code Provider.
     */
    template <typename T>
    using IHashCodeProviderSharedPtr = std::shared_ptr<IHashCodeProvider<T>>;

} // namespace base

#endif // I_HASH_CODE_PROVIDER_H_1404f95e_57cf_11ee_8c99_0242ac120002
