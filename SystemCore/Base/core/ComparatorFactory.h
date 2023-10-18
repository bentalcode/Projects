#ifndef COLLECTION_FACTORY_H_2370f1ba_57d2_11ee_8c99_0242ac120002
#define COLLECTION_FACTORY_H_2370f1ba_57d2_11ee_8c99_0242ac120002

#include "IComparatorFactory.h"

namespace base {

    /**
     * The ComparatorFactory class implements a comparator factory.
     */
    class ComparatorFactory final : public IComparatorFactory {
    public:
        /**
         * Creates a comparator factory.
         */
        static IComparatorFactorySharedPtr Make();

        /**
         * The ComparatorFactory constructor.
         */
        ComparatorFactory();

        /**
         * The ComparatorFactory destructor.
         */
        virtual ~ComparatorFactory();

        /**
         * Gets an almost comparator of type integer.
         */
        virtual IBinaryComparatorSharedPtr<int> GetAlmostIntegerComparator(
            double epsilon = DEFAULT_EPSILON) const override;

        /**
         * Gets an almost comparator of type double.
         */
        virtual IBinaryComparatorSharedPtr<double> GetAlmostDoubleComparator(
            double epsilon = DEFAULT_EPSILON) const override;
    };

} // namespace base

#endif // COLLECTION_FACTORY_H_2370f1ba_57d2_11ee_8c99_0242ac120002
