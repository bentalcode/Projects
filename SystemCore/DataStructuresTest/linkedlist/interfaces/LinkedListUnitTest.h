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
                explicit LinkedListUnitTest(const std::wstring& name);

                /**
                 * The LinkedListUnitTest destructor.
                 */
                virtual ~LinkedListUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a linked list.
                 */
                void LinkedListCreationTest();

                /**
                 * Tests the iteration logic of a linked list.
                 */
                void LinkedListIterationTest();

                /**
                 * Tests the updation logic of a linked list.
                 */
                void LinkedListUpdationTest();

            private:
                /**
                 * Tests the creation logic of a linked list.
                 */
                template <typename T>
                void TestCreation(const LinkedListData<T>& data);

                /**
                 * Tests the iteration logic of a linked list.
                 */
                template <typename T>
                void TestIteration(const LinkedListData<T>& data);

                /**
                 * Tests the updation logic of a linked list.
                 */
                template <typename T>
                void TestUpdation(
                    LinkedList<T>& list,
                    const std::vector<std::tuple<std::wstring, int, std::vector<int>>>& data);

                /**
                 * Tests the updation logic of a linked list.
                 */
                template <typename T>
                void TestUpdation(
                    LinkedList<T>& list,
                    const std::wstring& operation,
                    const T& item,
                    const std::vector<T>& expectedContent);

                /**
                 * Updates the list.
                 */
                template <typename T>
                void UpdateList(
                    LinkedList<T>& list,
                    const std::wstring& operation,
                    const T& item);

                /**
                 * Creates a linked list.
                 */
                template <typename T>
                static ILinkedListSharedPtr<T> CreateLinkedList(const std::vector<T>& data);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a linked list.
             */
            template <typename T>
            void LinkedListUnitTest::TestCreation(const LinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                ILinkedListSharedPtr<T> container = CreateLinkedList(data.GetValues());

                //
                // Test the data of the container...
                //
                GetAssertion().AssertEqualsWithDereferenceIterators(
                    *container->GetIterator(),
                    *base::VectorIterator<ILinkedListNodeSharedPtr<T>>::Make(data.GetNodes()),
                    L"Invalid creation logic of a linked list.");
            }

            /**
             * Tests the iteration logic of a linked list.
             */
            template <typename T>
            void LinkedListUnitTest::TestIteration(const LinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                ILinkedListSharedPtr<T> container = CreateLinkedList(data.GetValues());

                //
                // Test the forward iterator of the container...
                //
                test_base::IterationTest iterationTest;

                base::IIterableSharedPtr<ILinkedListNodeSharedPtr<T>> containerIterable = container;
                base::IIteratorSharedPtr<ILinkedListNodeSharedPtr<T>> expectedIterator =
                    base::VectorIterator<ILinkedListNodeSharedPtr<T>>::Make(data.GetNodes());

                iterationTest.TestForwardIterationWithDereference(
                    containerIterable,
                    expectedIterator,
                    L"LinkedList");

                //
                // Test the value iterator of the container...
                //
                base::IValueIterableSharedPtr<T> valueIterable = container;
                base::IIteratorSharedPtr<T> expectedValueIterator = base::VectorIterator<T>::Make(data.GetValues());

                iterationTest.TestValueIteration(
                    valueIterable,
                    expectedValueIterator,
                    L"LinkedList");
            }

            /**
             * Tests the updation logic of a linked list.
             */
            template <typename T>
            void LinkedListUnitTest::TestUpdation(
                LinkedList<T>& list,
                const std::vector<std::tuple<std::wstring, int, std::vector<int>>>& data)
            {
                for (const std::tuple<std::wstring, int, std::vector<int>>& entry : data)
                {
                    TestUpdation(
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
            void LinkedListUnitTest::TestUpdation(
                LinkedList<T>& list,
                const std::wstring& operation,
                const T& item,
                const std::vector<T>& expectedContent)
            {
                UpdateList(list, operation, item);

                GetAssertion().AssertEqualsWithIterators(
                    *list.GetValueIterator(),
                    *base::VectorIterator<T>::Make(expectedContent),
                    L"Invalid updating logic of a linked list.");
            }

            /**
             * Updates the list.
             */
            template <typename T>
            void LinkedListUnitTest::UpdateList(
                LinkedList<T>& list,
                const std::wstring& operation,
                const T& item)
            {
                if (base::StringEquality::AreEqualIgnoreCase(operation, L"AddToFront"))
                {
                    list.AddToFront(LinkedListNode<T>::Make(item));
                }
                else if (base::StringEquality::AreEqualIgnoreCase(operation, L"AddToBack"))
                {
                    list.AddToBack(LinkedListNode<T>::Make(item));
                }
                else if (base::StringEquality::AreEqualIgnoreCase(operation, L"RemoveFromFront"))
                {
                    list.RemoveFromFront();
                }
                else if (base::StringEquality::AreEqualIgnoreCase(operation, L"RemoveAfter"))
                {
                    ILinkedListNodeSharedPtr<T> currNode = list.GetNode(0);
                    list.RemoveAfter(currNode);
                }
                else
                {
                    long statusCode = base::ErrorCodes::ACCESS_DENIED;
                    std::wstring errorMessage = L"The operation: " + operation + L" is not supported.";

                    throw unit_testing::UnitTestingException(statusCode, errorMessage);
                }
            }

            /**
             * Creates a linked list.
             */
            template <typename T>
            ILinkedListSharedPtr<T> LinkedListUnitTest::CreateLinkedList(const std::vector<T>& data) {
                ILinkedListSharedPtr<T> result(new LinkedList<T>());

                for (T element : data) {
                    result->AddToBack(element);
                }

                return result;
            }
        }
    }
}

#endif // LINKED_LIST_UNIT_TEST_H_7754fd62_c28d_424a_a2d1_c9ad3846c4fa
