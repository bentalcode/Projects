#ifndef LINKED_LIST_TEST_DATA_H_7f89b940_f201_429a_8882_af3ed3431452
#define LINKED_LIST_TEST_DATA_H_7f89b940_f201_429a_8882_af3ed3431452

#include "LinkedListData.h"

using namespace datastructures::linkedlist;

namespace test {
    namespace datastructures {
        namespace linkedlist {

            /**
             * The ILinkedListTestData interface defines the data of the tests of a linked list.
             */
            class LinkedListTestData final
            {
            public:
                /**
                 * The LinkedListTestData constructor.
                 */
                LinkedListTestData();

                /**
                 * The LinkedListTestData destructor.
                 */
                ~LinkedListTestData();

                /**
                 * The copy/move constructors.
                 */
                LinkedListTestData(const LinkedListTestData&) = delete;
                LinkedListTestData(LinkedListTestData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                LinkedListTestData& operator=(const LinkedListTestData&) = delete;
                LinkedListTestData& operator=(LinkedListTestData&&) = delete;

                /**
                 * Gets the data of linked lists.
                 */
                std::vector<LinkedListDataPtr<int>> getData() const;

                /**
                 * Gets the updation data of a linked list.
                 */
                std::vector<std::tuple<std::string, int, std::vector<int>>> getUpdationData();

            private:
                /**
                 * Gets the data of a list.
                 */
                LinkedListDataPtr<int> getListData(size_t size) const;

                /**
                 * Creates values of a list.
                 */
                std::vector<int> createListValues(size_t size) const;

                /**
                 * Creates nodes of a list.
                 */
                template <typename T>
                std::vector<ILinkedListNodeSharedPtr<T>> createListNodes(const std::vector<T>& values) const;
            };

            //
            // Defines the SharedPtr of Linked List Test Data...
            //
            using LinkedListTestDataSharedPtr = std::shared_ptr<LinkedListTestData>;
        }
    }
}

#endif // LINKED_LIST_TEST_DATA_H_7f89b940_f201_429a_8882_af3ed3431452
