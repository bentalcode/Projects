#ifndef DOUBLY_LINKED_LIST_UNIT_TEST_H_bc2aca41_dce1_4d7f_8bce_a18f2649aeb3
#define DOUBLY_LINKED_LIST_UNIT_TEST_H_bc2aca41_dce1_4d7f_8bce_a18f2649aeb3

#include "UnitTestBase.h"
#include "DoublyLinkedList.h"
#include "TestData.h"
#include "VectorIterator.h"
#include "VectorReverseIterator.h"
#include "IterationTest.h"
#include "StringEquality.h"

using namespace datastructures::doublylinkedlist;

namespace test {
    namespace datastructures {
        namespace doublylinkedlist {

            /**
             * The DoublyLinkedListUnitTest class implements tests for a doubly linked list.
             */
            class DoublyLinkedListUnitTest final : public unit_testing::UnitTestBase
            {
            public:
                /**
                 * The DoublyLinkedListUnitTest constructor.
                 */
                explicit DoublyLinkedListUnitTest(const std::string& name);

                /**
                 * The DoublyLinkedListUnitTest destructor.
                 */
                virtual ~DoublyLinkedListUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void registerTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a doubly linked list.
                 */
                void doublyLinkedListCreationTest();

                /**
                 * Tests the iteration logic of a doubly linked list.
                 */
                void doublyLinkedListIterationTest();

                /**
                 * Tests the updation logic of a doubly linked list.
                 */
                void doublyLinkedListUpdationTest();

            private:
                /**
                 * Tests the creation logic of a doubly linked list.
                 */
                template <typename T>
                void testCreation(const DoublyLinkedListData<T>& data);

                /**
                 * Tests the iteration logic of a doubly linked list.
                 */
                template <typename T>
                void testIteration(const DoublyLinkedListData<T>& data);

                /**
                 * Tests the updation logic of a doubly linked list.
                 */
                template <typename T>
                void testUpdation(
                    DoublyLinkedList<T>& list,
                    const std::vector<std::tuple<std::string, int, std::vector<int>>>& data);

                /**
                 * Tests the updation logic of a doubly linked list.
                 */
                template <typename T>
                void testUpdation(
                    DoublyLinkedList<T>& list,
                    const std::string& operation,
                    const T& item,
                    const std::vector<T>& expectedContent);

                /**
                 * Updates the list.
                 */
                template <typename T>
                void updateList(
                    DoublyLinkedList<T>& list,
                    const std::string& operation,
                    const T& item);

                /**
                 * Creates a doubly linked list.
                 */
                template <typename T>
                static IDoublyLinkedListPtr<T> createDoublyLinkedList(const std::vector<T>& data);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::testCreation(const DoublyLinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                IDoublyLinkedListPtr<T> container = createDoublyLinkedList(data.getValues());

                //
                // Test the data of the container...
                //
                getAssertion().assertEqualsWithDereferenceIterators(
                    *container->getIterator(),
                    *base::VectorIterator<IDoublyLinkedListNodePtr<T>>::make(data.getNodes()),
                    "Invalid creation logic of a doubly linked list.");
            }

            /**
             * Tests the iteration logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::testIteration(const DoublyLinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                IDoublyLinkedListPtr<T> container = createDoublyLinkedList(data.getValues());

                //
                // Test the forward iterator of the container...
                //
                test_base::IterationTest iterationTest;

                base::IIterablePtr<IDoublyLinkedListNodePtr<T>> containerIterable = container;
                base::IIteratorPtr<IDoublyLinkedListNodePtr<T>> expectedIterator = base::VectorIterator<IDoublyLinkedListNodePtr<T>>::make(data.getNodes());

                iterationTest.testForwardIterationWithDereference(
                    containerIterable,
                    expectedIterator,
                    "DoublyLinkedList");

                //
                // Test the reverse iterator of the container...
                //
                base::IReverseIterablePtr<IDoublyLinkedListNodePtr<T>> containerReverseIterable = container;
                base::IReverseIteratorPtr<IDoublyLinkedListNodePtr<T>> expectedReverseIterator =
                    base::VectorReverseIterator<IDoublyLinkedListNodePtr<T>>::make(data.getNodes());

                iterationTest.testReverseIterationWithDereference(
                    containerReverseIterable,
                    expectedReverseIterator,
                    "DoublyLinkedList");

                //
                // Test the value iterator of the container...
                //
                base::IValueIterablePtr<T> valueIterable = container;
                base::IIteratorPtr<T> expectedValueIterator = base::VectorIterator<T>::make(data.getValues());

                iterationTest.testValueIteration(
                    valueIterable,
                    expectedValueIterator,
                    "DoublyLinkedList");

                //
                // Test the value reverse iterator of the container...
                //
                base::IValueReverseIterablePtr<T> valueReverseIterable = container;
                base::IReverseIteratorPtr<T> expectedValueReverseIterator = base::VectorReverseIterator<T>::make(data.getValues());

                iterationTest.testValueReverseIteration(
                    valueReverseIterable,
                    expectedValueReverseIterator,
                    "DoublyLinkedList");
            }

            /**
             * Tests the updation logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::testUpdation(
                DoublyLinkedList<T>& list,
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
             * Tests the updation logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::testUpdation(
                DoublyLinkedList<T>& list,
                const std::string& operation,
                const T& item,
                const std::vector<T>& expectedContent)
            {
                updateList(list, operation, item);

                getAssertion().assertEqualsWithIterators(
                    *list.getValueIterator(),
                    *base::VectorIterator<T>::make(expectedContent),
                    "Invalid updating logic of a doubly linked list.");
            }

            /**
             * Updates the list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::updateList(
                DoublyLinkedList<T>& list,
                const std::string& operation,
                const T& item)
            {
                if (base::StringEquality::equalsIgnoreCase(operation, "addToFront"))
                {
                    list.addToFront(DoublyLinkedListNode<T>::make(item));
                }
                else if (base::StringEquality::equalsIgnoreCase(operation, "addToBack"))
                {
                    list.addToBack(DoublyLinkedListNode<T>::make(item));
                }
                else if (base::StringEquality::equalsIgnoreCase(operation, "removeFromFront"))
                {
                    list.removeFromFront();
                }
                else if (base::StringEquality::equalsIgnoreCase(operation, "removeFromBack"))
                {
                    list.removeFromBack();
                }
            }

            /**
             * Creates a doubly linked list.
             */
            template <typename T>
            IDoublyLinkedListPtr<T> DoublyLinkedListUnitTest::createDoublyLinkedList(const std::vector<T>& data)
            {
                IDoublyLinkedListPtr<T> result(new DoublyLinkedList<T>());

                for (T element : data)
                {
                    result->addToBack(element);
                }

                return result;
            }
        }
    }
}

#endif // DOUBLY_LINKED_LIST_UNIT_TEST_H_bc2aca41_dce1_4d7f_8bce_a18f2649aeb3
