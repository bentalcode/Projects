#ifndef I_EQUATABLE_COMPARATOR_H_43caf2e2_57cf_11ee_8c99_0242ac120002
#define I_EQUATABLE_COMPARATOR_H_43caf2e2_57cf_11ee_8c99_0242ac120002

#include <memory>

namespace base {

    /**
     * The IEquatableComparator interface defines an equatable comparator,
     * for determining equality between two instances.
     */
    template <typename T>
    class IEquatableComparator
    {
    public:
        IEquatableComparator() = default;
        virtual ~IEquatableComparator() = default;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool AreEquals(const T& lhs, const T& rhs) const = 0;
    };

    /**
     * Defines the Shared Ptr of Equatable Comparator.
     */
    template <typename T>
    using IEquatableComparatorSharedPtr = std::shared_ptr<IEquatableComparator<T>>;

}  // namespace Utilities

#endif // I_EQUATABLE_COMPARATOR_H_43caf2e2_57cf_11ee_8c99_0242ac120002
