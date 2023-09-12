#ifndef I_BINARY_COMPARATOR_H_daa463f1_8170_47c6_88a5_5e7f79de9df5
#define I_BINARY_COMPARATOR_H_daa463f1_8170_47c6_88a5_5e7f79de9df5

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
        /**
         * The constructor.
         */
        IBinaryComparator() = default;

        /**
         * The destructor.
         */
        virtual ~IBinaryComparator() = default;

        /**
         * The copy/move constructors.
         */
        IBinaryComparator(const IBinaryComparator&) = delete;
        IBinaryComparator(IBinaryComparator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IBinaryComparator& operator=(const IBinaryComparator&) = delete;
        IBinaryComparator& operator=(IBinaryComparator&&) = delete;
    };

    //
    // Defines the SharedPtr of Binary Comparator...
    //
    template <typename T>
    using IBinaryComparatorSharedPtr = std::shared_ptr<IBinaryComparator<T>>;
}

#endif // I_BINARY_COMPARATOR_H_daa463f1_8170_47c6_88a5_5e7f79de9df5
