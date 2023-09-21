#ifndef I_BINARY_COMPARATOR_H_ddd2ac78_57ce_11ee_8c99_0242ac120002
#define I_BINARY_COMPARATOR_H_ddd2ac78_57ce_11ee_8c99_0242ac120002

#include "IHashCodeProvider.h"
#include "IEquatableComparator.h"
#include "IComparableComparator.h"

namespace base {

    /**
     * The IBinaryComparator interface defines a binary comparator.
     */
    template <typename T>
    class IBinaryComparator :
        public IHashCodeProvider<T>,
        public IEquatableComparator<T>,
        public IComparableComparator<T>
    {
    public:
        IBinaryComparator() = default;
        virtual ~IBinaryComparator() = default;
    };

    /**
     * Defines the Shared Ptr of Binary Comparator.
     */
    template <typename T>
    using IBinaryComparatorSharedPtr = std::shared_ptr<IBinaryComparator<T>>;

}  // namespace base

#endif // I_BINARY_COMPARATOR_H_ddd2ac78_57ce_11ee_8c99_0242ac120002
