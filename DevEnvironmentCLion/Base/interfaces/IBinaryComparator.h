#ifndef I_BINARY_COMPARATOR_H_2ce77825_60fa_4a23_9859_22d635fa5f08
#define I_BINARY_COMPARATOR_H_2ce77825_60fa_4a23_9859_22d635fa5f08

#include "IHashCodeProvider.h"
#include "IEquatableComparator.h"
#include "IComparableComparator.h"

namespace base {

    /**
     * The IBinaryComparator interface defines a binary comparator.
     */
    template <typename T>
    class IBinaryComparator : public IHashCodeProvider<T>, IEquatableComparator<T>, IComparableComparator<T>
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
}

#endif // I_BINARY_COMPARATOR_H_2ce77825_60fa_4a23_9859_22d635fa5f08
