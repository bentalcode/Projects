#ifndef ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_fb9576a2_66dc_4dc5_96ad_2f1d78e4fe55
#define ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_fb9576a2_66dc_4dc5_96ad_2f1d78e4fe55

#include "PreCompiled.h"
#include "UnitTestBase.h"
#include "TestData.h"
#include "ListIterator.h"
#include "TwoDimensionalListIterator.h"
#include "IteratorOfIteratorCollection.h"

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
        template <typename T>
        void testIteratorOfIteratorCollection(
            const std::vector<T>& oneDimensionalArray,
            const std::vector<std::vector<T>>& twoDimensionalArray);

        TestData m_testData;
    };

    template <typename T>
    void IteratorOfIteratorCollectionUnitTest::testIteratorOfIteratorCollection(
        const std::vector<T>& oneDimensionalArray,
        const std::vector<std::vector<T>>& twoDimensionalArray)
    {
        base::IIteratorPtr<T> oneDimensionalArrayIterator(new base::ListIterator<T>(oneDimensionalArray));
        base::IIteratorPtr<T> twoDimensionalArrayIterator(new base::TwoDimensionalListIterator<T>(twoDimensionalArray));

        std::vector<base::IIteratorPtr<T>> iterators;
        iterators.push_back(oneDimensionalArrayIterator);
        iterators.push_back(twoDimensionalArrayIterator);

        base::IIteratorPtr<int> iteratorOfIterators(new data_structures::IteratorOfIteratorCollection<int>(iterators));

        std::vector<T> data;
        data.insert(data.end(), oneDimensionalArray.begin(), oneDimensionalArray.end());

        for (const std::vector<T>& row : twoDimensionalArray) {
            data.insert(data.end(), row.begin(), row.end());
        }

        base::IIteratorPtr<T> dataIterator(new base::ListIterator<T>(data));

        getAssertion().assertEqualsWithIterators(
            *iteratorOfIterators,
            *dataIterator,
            "Invalid logic of an iterator collection.");
    }
}

#endif // ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_fb9576a2_66dc_4dc5_96ad_2f1d78e4fe55
