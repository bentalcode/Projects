#ifndef LINKED_LIST_UNIT_TEST_H_7754fd62_c28d_424a_a2d1_c9ad3846c4fa
#define LINKED_LIST_UNIT_TEST_H_7754fd62_c28d_424a_a2d1_c9ad3846c4fa

#include "UnitTestBase.h"
#include "LinkedList.h"
#include "TestData.h"
#include "LinkedListData.h"
#include "ListIterator.h"

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
                    *base::ListIterator<ILinkedListNodePtr<T>>::make(data.getNodes()),
                    "Invalid creation logic of a linked list.");
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
