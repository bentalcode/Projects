#ifndef DOUBLY_LINKED_LIST_DATA_H_548908b4_b007_4688_a11e_bbe1c45dfe9b
#define DOUBLY_LINKED_LIST_DATA_H_548908b4_b007_4688_a11e_bbe1c45dfe9b

#include "DoublyLinkedListNode.h"
#include <vector>

using namespace datastructures::doublylinkedlist;

namespace test {
    namespace datastructures {
        namespace doublylinkedlist {

            /**
             * The DoublyLinkedListData class implements the data of a doubly linked list.
             */
            template <typename T>
            class DoublyLinkedListData final {
            public:
                /**
                 * The DoublyLinkedListData constructor.
                 */
                DoublyLinkedListData(
                    const std::vector<T>& values,
                    const std::vector<IDoublyLinkedListNodeSharedPtr<T>>& nodes);

                /**
                 * The DoublyLinkedListData destructor.
                 */
                ~DoublyLinkedListData();

                /**
                 * The copy/move constructors.
                 */
                DoublyLinkedListData(const DoublyLinkedListData&) = delete;
                DoublyLinkedListData(DoublyLinkedListData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                DoublyLinkedListData& operator=(const DoublyLinkedListData&) = delete;
                DoublyLinkedListData& operator=(DoublyLinkedListData&&) = delete;

                /**
                 * Gets the values of the list.
                 */
                const std::vector<T>& GetValues() const;

                /**
                 * Gets the nodes of the list.
                 */
                const std::vector<IDoublyLinkedListNodeSharedPtr<T>>& GetNodes() const;

            private:
                std::vector<T> m_values;
                std::vector<IDoublyLinkedListNodeSharedPtr<T>> m_nodes;
            };

            //
            // Defines the SharedPtr of Doubly Linked List Data...
            //
            template <typename T>
            using DoublyLinkedListDataSharedPtr = std::shared_ptr<DoublyLinkedListData<T>>;

            /**
             * The DoublyLinkedListData constructor.
             */
            template <typename T>
            DoublyLinkedListData<T>::DoublyLinkedListData(
                const std::vector<T>& values,
                const std::vector<IDoublyLinkedListNodeSharedPtr<T>>& nodes) :
                m_values(values),
                m_nodes(nodes)
            {
            }

            /**
             * The DoublyLinkedListData destructor.
             */
            template <typename T>
            DoublyLinkedListData<T>::~DoublyLinkedListData()
            {
            }

            /**
             * Gets the values of the list.
             */
            template <typename T>
            const std::vector<T>& DoublyLinkedListData<T>::GetValues() const
            {
                return m_values;
            }

            /**
             * Gets the nodes of the list.
             */
            template <typename T>
            const std::vector<IDoublyLinkedListNodeSharedPtr<T>>& DoublyLinkedListData<T>::GetNodes() const
            {
                return m_nodes;
            }
        }
    }
}

#endif // DOUBLY_LINKED_LIST_DATA_H_548908b4_b007_4688_a11e_bbe1c45dfe9b
