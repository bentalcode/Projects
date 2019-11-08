#ifndef ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_d6ac9f8b_aea2_4065_8eba_3924818d5673
#define ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_d6ac9f8b_aea2_4065_8eba_3924818d5673

#include "PreCompiled.h"
#include "UnitTestBase.h"

namespace data_structures_test {

    /**
     * The IteratorOfIteratorCollectionUnitTest class implements a unit test
     * for an iterator of a collection of iterators.
     */
    class IteratorOfIteratorCollectionUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The IteratorOfIteratorCollectionUnitTest constructor.
         */
        explicit IteratorOfIteratorCollectionUnitTest(const std::string& name);

        /**
         * The IteratorOfIteratorCollectionUnitTest destructor.
         */
        virtual ~IteratorOfIteratorCollectionUnitTest();

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the iterator of a collection of iterators.
         */
        void iteratorOfIteratorCollectionTest();

    private:
        /**
         * Tests the iterator of a collection of iterators.
         */
        void testIteratorOfIteratorCollection();
    };
}

#endif /* ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_d6ac9f8b_aea2_4065_8eba_3924818d5673 */
