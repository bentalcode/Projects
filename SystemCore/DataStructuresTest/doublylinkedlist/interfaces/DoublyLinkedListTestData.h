#ifndef DOUBLY_LINKED_LIST_TEST_DATA_H_cb16d806_51a4_4424_bc36_e70b66e298a1
#define DOUBLY_LINKED_LIST_TEST_DATA_H_cb16d806_51a4_4424_bc36_e70b66e298a1

#include "DoublyLinkedListData.h"
#include <vector>
#include <string>

using namespace datastructures::doublylinkedlist;

namespace test {
    namespace datastructures {
        namespace doublylinkedlist {

            /**
             * The IDoublyLinkedListTestData interface defines the data of the tests of a doubly linked list.
             */
            class DoublyLinkedListTestData final
            {
            public:
                /**
                 * The DoublyLinkedListTestData constructor.
                 */
                DoublyLinkedListTestData();

                /**
                 * The DoublyLinkedListTestData destructor.
                 */
                ~DoublyLinkedListTestData();

                /**
                 * The copy/move constructors.
                 */
                DoublyLinkedListTestData(const DoublyLinkedListTestData&) = delete;
                DoublyLinkedListTestData(DoublyLinkedListTestData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                DoublyLinkedListTestData& operator=(const DoublyLinkedListTestData&) = delete;
                DoublyLinkedListTestData& operator=(DoublyLinkedListTestData&&) = delete;

                /**
                 * Gets the data of doubly linked lists.
                 */
                std::vector<DoublyLinkedListDataSharedPtr<int>> GetData() const;

                /**
                 * Gets the updation data of a doubly linked list.
                 */
                std::vector<std::tuple<std::wstring, int, std::vector<int>>> GetUpdationData() const;

            private:
                /**
                 * Gets the data of list.
                 */
                DoublyLinkedListDataSharedPtr<int> GetListData(size_t size) const;

                /**
                 * Gets the values of a doubly linked list.
                 */
                std::vector<int> CreateListValues(size_t size) const;

                /**
                 * Creates the nodes of a doubly linked list.
                 */
                template <typename T>
                std::vector<IDoublyLinkedListNodeSharedPtr<T>> CreateListNodes(const std::vector<T>& values) const;
            };

            //
            // Defines the SharedPtr of Doubly Linked List Test Data...
            //
            using DoublyLinkedListTestDataSharedPtr = std::shared_ptr<DoublyLinkedListTestData>;
        }
    }
}

#endif // DOUBLY_LINKED_LIST_TEST_DATA_H_cb16d806_51a4_4424_bc36_e70b66e298a1
