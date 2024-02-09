#ifndef I_FROM_STRING_H_706e7586_93df_4ab2_9919_868cab5c4867
#define I_FROM_STRING_H_706e7586_93df_4ab2_9919_868cab5c4867

#include <string>
#include <memory>

namespace base {

    /**
     * The IFromString interface defines an interface for transforming a string to an object.
     */
    template <typename T>
    class IFromString {
    public:
        /**
         * The IFromString constructor.
         */
        IFromString() = default;

        /**
         * The IFromString destructor.
         */
        virtual ~IFromString() = default;

        /**
         * Transforms a string to an object.
         */
        virtual T FromString(const std::wstring& str) const = 0;
    };

    /**
     * Defines the Shared Ptr of IFromString.
     */
    template <typename T>
    using IFromStringSharedPtr = std::shared_ptr<IFromString<T>>;

}  // namespace base

#endif // I_FROM_STRING_H_706e7586_93df_4ab2_9919_868cab5c4867
