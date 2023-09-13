#ifndef TEST_DATA_H_0617b4eb_3504_48e8_aa96_9747cc17335d
#define TEST_DATA_H_0617b4eb_3504_48e8_aa96_9747cc17335d

#include "BitArrayTestData.h"
#include "LinkedListTestData.h"
#include "DoublyLinkedListTestData.h"
#include "BinaryTreeTestData.h"
#include "PriorityQueueTestData.h"
#include "GraphTestData.h"
#include "CacheTestData.h"

using namespace test::datastructures::bitarray;
using namespace test::datastructures::linkedlist;
using namespace test::datastructures::doublylinkedlist;
using namespace test::datastructures::binarytree;
using namespace test::datastructures::priority_queue;
using namespace test::datastructures::graph;
using namespace test::datastructures::cache;

namespace test {
    namespace datastructures {

        /**
         * The TestData class implements data of tests.
         */
        class TestData final
        {
        public:
            /**
             * The TestData constructor.
             */
            TestData();

            /**
             * The TestData destructor.
             */
            ~TestData();

            /**
             * Gets the data of tests of a bit array.
             */
            BitArrayTestDataPtr getBitArrayData() const;

            /**
             * Gets the data of tests of a linked list.
             */
            LinkedListTestDataSharedPtr getLinkedListData() const;

            /**
             * Gets the data of tests of a doubly linked list.
             */
            DoublyLinkedListTestDataSharedPtr getDoublyLinkedListData() const;

            /**
             * Gets the data of tests of a binary tree.
             */
            BinaryTreeTestDataPtr getBinaryTreeData() const;

            /**
             * Gets the data of tests of a priority queue.
             */
            PriorityQueueTestDataSharedPtr getPriorityQueueData() const;

            /**
             * Gets the data of tests of a graph.
             */
            GraphTestDataSharedPtr getGraphData() const;

            /**
             * Gets the data of tests of a cache.
             */
            CacheTestDataSharedPtr getCacheData() const;

            /**
             * Creates a vector.
             */
            template <typename T>
            std::shared_ptr<std::vector<T>> createVector(
                size_t size,
                const T& initialValue) const;

            /**
             * Creates a two dimensional vector.
             */
            template <typename T>
            std::shared_ptr<std::vector<std::vector<T>>> createTwoDimensionalVector(
                size_t rows,
                size_t columns,
                const T& initialValue) const;
        };

        template <typename T>
        std::shared_ptr<std::vector<T>> TestData::createVector(
            size_t size,
            const T& initialValue) const
        {
            std::shared_ptr<std::vector<T>> vector = std::make_shared<std::vector<T>>(size);

            T currValue = initialValue;

            for (size_t i = 0; i < size; ++i) {
                (*vector)[i] = currValue;
                ++currValue;
            }

            return vector;
        }

        template <typename T>
        std::shared_ptr<std::vector<std::vector<T>>> TestData::createTwoDimensionalVector(
            size_t rows,
            size_t columns,
            const T& initialValue) const
        {
            std::shared_ptr<std::vector<std::vector<T>>> vector = std::make_shared<std::vector<std::vector<T>>>(rows);

            for (size_t row = 0; row < rows; ++row)
            {
                std::vector<T> rowData(columns);
                (*vector)[row] = rowData;
            }

            T value = initialValue;
            for (size_t row = 0; row < rows; ++row)
            {
                for (size_t column = 0; column < columns; ++column)
                {
                    (*vector)[row][column] = value;
                    ++value;
                }
            }

            return vector;
        }
    }
}

#endif // TEST_DATA_H_0617b4eb_3504_48e8_aa96_9747cc17335d
