#ifndef ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_6ddff803_dcce_4af9_893a_0d4d3293e6f9
#define ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_6ddff803_dcce_4af9_893a_0d4d3293e6f9

#include "UnitTestBase.h"
#include "TestData.h"
#include "VectorIterator.h"
#include "TwoDimensionalVectorIterator.h"
#include "IteratorOfIteratorCollection.h"

namespace test {
    namespace datastructures {

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
            explicit IteratorOfIteratorCollectionUnitTest(const std::wstring& name);

            /**
             * The IteratorOfIteratorCollectionUnitTest destructor.
             */
            virtual ~IteratorOfIteratorCollectionUnitTest();

            /**
             * Registers tests of the unit test.
             */
            virtual void RegisterTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the iterator of a collection of iterators.
             */
            void IteratorOfIteratorCollectionTest();

        private:
            /**
             * Tests the iterator of a collection of iterators.
             */
            template <typename T>
            void TestIteratorOfIteratorCollection(
                const std::vector<T>& oneDimensionalArray,
                const std::vector<std::vector<T>>& twoDimensionalArray);

            TestData m_testData;
        };

        template <typename T>
        void IteratorOfIteratorCollectionUnitTest::TestIteratorOfIteratorCollection(
            const std::vector<T>& oneDimensionalArray,
            const std::vector<std::vector<T>>& twoDimensionalArray)
        {
            base::IIteratorSharedPtr<T> oneDimensionalArrayIterator(new base::VectorIterator<T>(oneDimensionalArray));
            base::IIteratorSharedPtr<T> twoDimensionalArrayIterator(new base::TwoDimensionalVectorIterator<T>(twoDimensionalArray));

            std::vector<base::IIteratorSharedPtr<T>> iterators;
            iterators.push_back(oneDimensionalArrayIterator);
            iterators.push_back(twoDimensionalArrayIterator);

            base::IIteratorSharedPtr<int> iteratorOfIterators(new data_structures::IteratorOfIteratorCollection<int>(iterators));

            std::vector<T> data;
            data.insert(data.end(), oneDimensionalArray.begin(), oneDimensionalArray.end());

            for (const std::vector<T>& row : twoDimensionalArray) {
                data.insert(data.end(), row.begin(), row.end());
            }

            base::IIteratorSharedPtr<T> dataIterator(new base::VectorIterator<T>(data));

            GetAssertion().AssertEqualsWithIterators(
                *iteratorOfIterators,
                *dataIterator,
                L"Invalid logic of an iterator collection.");
        }
    }
}

#endif // ITERATOR_OF_ITERATOR_COLLECTION_UNIT_TEST_H_6ddff803_dcce_4af9_893a_0d4d3293e6f9
