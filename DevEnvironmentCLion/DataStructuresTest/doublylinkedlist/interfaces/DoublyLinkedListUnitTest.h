#ifndef DOUBLY_LINKED_LIST_UNIT_TEST_H_bc2aca41_dce1_4d7f_8bce_a18f2649aeb3
#define DOUBLY_LINKED_LIST_UNIT_TEST_H_bc2aca41_dce1_4d7f_8bce_a18f2649aeb3

#include "UnitTestBase.h"
#include "DoublyLinkedList.h"
#include "TestData.h"
#include "ListIterator.h"

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
                base::IIteratorPtr<IDoublyLinkedListNodePtr<T>> a = container->getIterator();
                base::IIteratorPtr<IDoublyLinkedListNodePtr<T>> b = base::ListIterator<IDoublyLinkedListNodePtr<T>>::make(data.getNodes());

                getAssertion().assertEqualsWithDereferenceIterators(
                    *a,
                    *b,
                    "Invalid creation logic of a doubly linked list.");
            }

            /**
             * Creates a doubly linked list.
             */
            template <typename T>
            IDoublyLinkedListPtr<T> DoublyLinkedListUnitTest::createDoublyLinkedList(const std::vector<T>& data) {
                IDoublyLinkedListPtr<T> result(new DoublyLinkedList<T>());

                for (T element : data) {
                    result->addToBack(element);
                }

                return result;
            }
        }
    }
}

#endif // DOUBLY_LINKED_LIST_UNIT_TEST_H_bc2aca41_dce1_4d7f_8bce_a18f2649aeb3
