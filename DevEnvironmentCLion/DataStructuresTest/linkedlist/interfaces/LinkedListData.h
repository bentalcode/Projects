#ifndef LINKED_LIST_DATA_H_537b9338_2fc1_464f_8501_6f50d9c58616
#define LINKED_LIST_DATA_H_537b9338_2fc1_464f_8501_6f50d9c58616

#include "LinkedListNode.h"

using namespace datastructures::linkedlist;

namespace test {
    namespace datastructures {
        namespace linkedlist {

            /**
             * The ILinkedListData interface defines the data of a linked list.
             */
            template <typename T>
            class LinkedListData final {
            public:
                /**
                 * The LinkedListData constructor.
                 */
                LinkedListData(
                    const std::vector<T>& values,
                    const std::vector<ILinkedListNodePtr<T>>& nodes);

                /**
                 * The LinkedListData destructor.
                 */
                ~LinkedListData();

                /**
                 * The copy/move constructors.
                 */
                LinkedListData(const LinkedListData&) = delete;
                LinkedListData(LinkedListData&&) = delete;

                /**
                 * The copy/move assignment operators.
                 */
                LinkedListData& operator=(const LinkedListData&) = delete;
                LinkedListData& operator=(LinkedListData&&) = delete;

                /**
                 * Gets the values of the list.
                 */
                const std::vector<T>& getValues() const;

                /**
                 * Gets the nodes of the list.
                 */
                const std::vector<ILinkedListNodePtr<T>>& getNodes() const;

            private:
                std::vector<T> m_values;
                std::vector<ILinkedListNodePtr<T>> m_nodes;
            };

            template <typename T>
            using LinkedListDataPtr = std::shared_ptr<LinkedListData<T>>;

            /**
             * The LinkedListData constructor.
             */
            template <typename T>
            LinkedListData<T>::LinkedListData(
                const std::vector<T>& values,
                const std::vector<ILinkedListNodePtr<T>>& nodes) :
                m_values(values),
                m_nodes(nodes)
            {
            }

            /**
             * The LinkedListData destructor.
             */
            template <typename T>
            LinkedListData<T>::~LinkedListData()
            {
            }

            /**
             * Gets the values of the list.
             */
            template <typename T>
            const std::vector<T>& LinkedListData<T>::getValues() const
            {
                return m_values;
            }

            /**
             * Gets the nodes of the list.
             */
            template <typename T>
            const std::vector<ILinkedListNodePtr<T>>& LinkedListData<T>::getNodes() const
            {
                return m_nodes;
            }
        }
    }
}

#endif // LINKED_LIST_DATA_H_537b9338_2fc1_464f_8501_6f50d9c58616
