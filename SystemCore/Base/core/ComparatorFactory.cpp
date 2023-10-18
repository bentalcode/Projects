#include "ComparatorFactory.h"

#include "AlmostComparator.h"

using namespace base;

/**
 * Creates a comparator factory.
 */
IComparatorFactorySharedPtr ComparatorFactory::Make()
{
    return std::make_shared<ComparatorFactory>();
}

/**
 * The ComparatorFactory constructor.
 */
ComparatorFactory::ComparatorFactory() 
{
}

/**
 * The ComparatorFactory destructor.
 */
ComparatorFactory::~ComparatorFactory() 
{
}

/**
 * Gets an almost comparator of type integer.
 */
IBinaryComparatorSharedPtr<int> ComparatorFactory::GetAlmostIntegerComparator(double epsilon) const
{
    return AlmostComparator<int, double>::Make(epsilon);
}

/**
 * Gets an almost comparator of type double.
 */
IBinaryComparatorSharedPtr<double> ComparatorFactory::GetAlmostDoubleComparator(double epsilon) const
{
    return AlmostComparator<double, double>::Make(epsilon);
}
