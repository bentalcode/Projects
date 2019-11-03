#ifndef I_BINARY_COMPARATOR_H_f3d2a17d_a480_4e14_81d3_e8df7793b7f4
#define I_BINARY_COMPARATOR_H_f3d2a17d_a480_4e14_81d3_e8df7793b7f4

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
         * The IBinaryComparator constructor.
         */
        IBinaryComparator() = default;

        /**
         * The IBinaryComparator destructor.
         */
        virtual ~IBinaryComparator() = default;
    };
}

#endif // I_BINARY_COMPARATOR_H_f3d2a17d_a480_4e14_81d3_e8df7793b7f4
