#ifndef LINKED_LIST_UNIT_TEST_H_7754fd62_c28d_424a_a2d1_c9ad3846c4fa
#define LINKED_LIST_UNIT_TEST_H_7754fd62_c28d_424a_a2d1_c9ad3846c4fa

#include "UnitTestBase.h"
#include "LinkedList.h"
#include "TestData.h"
#include "LinkedListData.h"
#include "VectorIterator.h"
#include "IterationTest.h"
#include "StringEquality.h"
#include "UnitTestingException.h"

using namespace datastructures::linkedlist;

namespace test {
    namespace datastructures {
        namespace linkedlist {

            /**
             * The LinkedListUnitTest class implements tests for a linked list.
             */
            class LinkedListUnitTest final : public unit_testing::UnitTestBase
            {
            public:
                /**
                 * The LinkedListUnitTest constructor.
                 */
                explicit LinkedListUnitTest(const std::string& name);

                /**
                 * The LinkedListUnitTest destructor.
                 */
                virtual ~LinkedListUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a linked list.
                 */
                void linkedListCreationTest();

                /**
                 * Tests the iteration logic of a linked list.
                 */
                void linkedListIterationTest();

                /**
                 * Tests the updation logic of a linked list.
                 */
                void linkedListUpdationTest();

            private:
                /**
                 * Tests the creation logic of a linked list.
                 */
                template <typename T>
                void testCreation(const LinkedListData<T>& data);

                /**
                 * Tests the iteration logic of a linked list.
                 */
                template <typename T>
                void testIteration(const LinkedListData<T>& data);

                /**
                 * Tests the updation logic of a linked list.
                 */
                template <typename T>
                void testUpdation(
                    LinkedList<T>& list,
                    const std::vector<std::tuple<std::string, int, std::vector<int>>>& data);

                /**
                 * Tests the updation logic of a linked list.
                 */
                template <typename T>
                void testUpdation(
                    LinkedList<T>& list,
                    const std::string& operation,
                    const T& item,
                    const std::vector<T>& expectedContent);

                /**
                 * Updates the list.
                 */
                template <typename T>
                void updateList(
                    LinkedList<T>& list,
                    const std::string& operation,
                    const T& item);

                /**
                 * Creates a linked list.
                 */
                template <typename T>
                static ILinkedListPtr<T> createLinkedList(const std::vector<T>& data);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a linked list.
             */
            template <typename T>
            void LinkedListUnitTest::testCreation(const LinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                ILinkedListPtr<T> container = createLinkedList(data.getValues());

                //
                // Test the data of the container...
                //
                getAssertion().assertEqualsWithDereferenceIterators(
                    *container->getIterator(),
                    *base::VectorIterator<ILinkedListNodePtr<T>>::make(data.getNodes()),
                    "Invalid creation logic of a linked list.");
            }

            /**
             * Tests the iteration logic of a linked list.
             */
            template <typename T>
            void LinkedListUnitTest::testIteration(const LinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                ILinkedListPtr<T> container = createLinkedList(data.getValues());

                //
                // Test the forward iterator of the container...
                //
                test_base::IterationTest iterationTest;

                base::IIterablePtr<ILinkedListNodePtr<T>> containerIterable = container;
                base::IIteratorPtr<ILinkedListNodePtr<T>> expectedIterator =
                    base::VectorIterator<ILinkedListNodePtr<T>>::make(data.getNodes());

                iterationTest.testForwardIterationWithDereference(
                    containerIterable,
                    expectedIterator,
                    "LinkedList");

                //
                // Test the value iterator of the container...
                //
                base::IValueIterablePtr<T> valueIterable = container;
                base::IIteratorPtr<T> expectedValueIterator = base::VectorIterator<T>::make(data.getValues());

                iterationTest.testValueIteration(
                    valueIterable,
                    expectedValueIterator,
                    "LinkedList");
            }

            /**
             * Tests the updation logic of a linked list.
             */
            template <typename T>
            void LinkedListUnitTest::testUpdation(
                LinkedList<T>& list,
                const std::vector<std::tuple<std::string, int, std::vector<int>>>& data)
            {
                for (const std::tuple<std::string, int, std::vector<int>>& entry : data)
                {
                    testUpdation(
                        list,
                        std::get<0>(entry),
                        std::get<1>(entry),
                        std::get<2>(entry));
                }
            }

            /**
             * Tests the updation logic of a linked list.
             */
            template <typename T>
            void LinkedListUnitTest::testUpdation(
                LinkedList<T>& list,
                const std::string& operation,
                const T& item,
                const std::vector<T>& expectedContent)
            {
                updateList(list, operation, item);

                getAssertion().assertEqualsWithIterators(
                    *list.getValueIterator(),
                    *base::VectorIterator<T>::make(expectedContent),
                    "Invalid updating logic of a linked list.");
            }

            /**
             * Updates the list.
             */
            template <typename T>
            void LinkedListUnitTest::updateList(
                LinkedList<T>& list,
                const std::string& operation,
                const T& item)
            {
                if (base::StringEquality::equalsIgnoreCase(operation, "addToFront"))
                {
                    list.addToFront(LinkedListNode<T>::make(item));
                }
                else if (base::StringEquality::equalsIgnoreCase(operation, "addToBack"))
                {
                    list.addToBack(LinkedListNode<T>::make(item));
                }
                else if (base::StringEquality::equalsIgnoreCase(operation, "removeFromFront"))
                {
                    list.removeFromFront();
                }
                else if (base::StringEquality::equalsIgnoreCase(operation, "removeAfter"))
                {
                    ILinkedListNodePtr<T> currNode = list.getNode(0);
                    list.removeAfter(currNode);
                }
                else
                {
                    std::string errorMessage = "The operation: " + operation + " is not supported.";
                    throw unit_testing::UnitTestingException(errorMessage);
                }
            }

            /**
             * Creates a linked list.
             */
            template <typename T>
            ILinkedListPtr<T> LinkedListUnitTest::createLinkedList(const std::vector<T>& data) {
                ILinkedListPtr<T> result(new LinkedList<T>());

                for (T element : data) {
                    result->addToBack(element);
                }

                return result;
            }
        }
    }
}

#endif // LINKED_LIST_UNIT_TEST_H_7754fd62_c28d_424a_a2d1_c9ad3846c4fa
