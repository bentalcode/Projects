#include "UnitTestManager.h"
#include "ListUnitTest.h"
#include "TwoDimensionalListUnitTest.h"

#include "IBinaryComparator.h"
#include "IComparableComparator.h"
#include "IEquatableComparator.h"
#include "IHashCodeProvider.h"
#include "IterableComparator.h"
#include "IteratorComparator.h"
#include "ComparatorFactory.h"

using namespace base_test;
using namespace unit_testing;

int main()
{
    UnitTestManager testManager;
    IUnitTestPtr listUnitTest(new ListUnitTest("List"));
    IUnitTestPtr twoDimensionalListUnitTest(new TwoDimensionalListUnitTest("TwoDimensionalList"));

    testManager.registerTest(listUnitTest);
    testManager.registerTest(twoDimensionalListUnitTest);

    testManager.run();

    return 0;
}