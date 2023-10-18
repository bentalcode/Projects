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
                explicit DoublyLinkedListUnitTest(const std::wstring& name);

                /**
                 * The DoublyLinkedListUnitTest destructor.
                 */
                virtual ~DoublyLinkedListUnitTest();

                /**
                 * Registers tests of the unit test.
                 */
                virtual void RegisterTests(unit_testing::ITestRegistration& registration);

                /**
                 * Tests the creation logic of a doubly linked list.
                 */
                void DoublyLinkedListCreationTest();

                /**
                 * Tests the iteration logic of a doubly linked list.
                 */
                void DoublyLinkedListIterationTest();

                /**
                 * Tests the updation logic of a doubly linked list.
                 */
                void DoublyLinkedListUpdationTest();

            private:
                /**
                 * Tests the creation logic of a doubly linked list.
                 */
                template <typename T>
                void TestCreation(const DoublyLinkedListData<T>& data);

                /**
                 * Tests the iteration logic of a doubly linked list.
                 */
                template <typename T>
                void TestIteration(const DoublyLinkedListData<T>& data);

                /**
                 * Tests the updation logic of a doubly linked list.
                 */
                template <typename T>
                void TestUpdation(
                    DoublyLinkedList<T>& list,
                    const std::vector<std::tuple<std::wstring, int, std::vector<int>>>& data);

                /**
                 * Tests the updation logic of a doubly linked list.
                 */
                template <typename T>
                void TestUpdation(
                    DoublyLinkedList<T>& list,
                    const std::wstring& operation,
                    const T& item,
                    const std::vector<T>& expectedContent);

                /**
                 * Updates the list.
                 */
                template <typename T>
                void UpdateList(
                    DoublyLinkedList<T>& list,
                    const std::wstring& operation,
                    const T& item);

                /**
                 * Creates a doubly linked list.
                 */
                template <typename T>
                static IDoublyLinkedListSharedPtr<T> CreateDoublyLinkedList(const std::vector<T>& data);

                TestData m_testData;
            };

            /**
             * Tests the creation logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::TestCreation(const DoublyLinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                IDoublyLinkedListSharedPtr<T> container = CreateDoublyLinkedList(data.GetValues());

                //
                // Test the data of the container...
                //
                GetAssertion().AssertEqualsWithDereferenceIterators(
                    *container->GetIterator(),
                    *base::VectorIterator<IDoublyLinkedListNodeSharedPtr<T>>::Make(data.GetNodes()),
                    L"Invalid creation logic of a doubly linked list.");
            }

            /**
             * Tests the iteration logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::TestIteration(const DoublyLinkedListData<T>& data)
            {
                //
                // Create the container...
                //
                IDoublyLinkedListSharedPtr<T> container = CreateDoublyLinkedList(data.GetValues());

                //
                // Test the forward iterator of the container...
                //
                test_base::IterationTest iterationTest;

                base::IIterableSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> containerIterable = container;
                base::IIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> expectedIterator = base::VectorIterator<IDoublyLinkedListNodeSharedPtr<T>>::Make(
                        data.GetNodes());

                iterationTest.TestForwardIterationWithDereference(
                    containerIterable,
                    expectedIterator,
                    L"DoublyLinkedList");

                //
                // Test the reverse iterator of the container...
                //
                base::IReverseIterableSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> containerReverseIterable = container;
                base::IReverseIteratorSharedPtr<IDoublyLinkedListNodeSharedPtr<T>> expectedReverseIterator =
                        base::VectorReverseIterator<IDoublyLinkedListNodeSharedPtr<T>>::Make(data.GetNodes());

                iterationTest.TestReverseIterationWithDereference(
                    containerReverseIterable,
                    expectedReverseIterator,
                    L"DoublyLinkedList");

                //
                // Test the value iterator of the container...
                //
                base::IValueIterableSharedPtr<T> valueIterable = container;
                base::IIteratorSharedPtr<T> expectedValueIterator = base::VectorIterator<T>::Make(data.GetValues());

                iterationTest.TestValueIteration(
                    valueIterable,
                    expectedValueIterator,
                    L"DoublyLinkedList");

                //
                // Test the value reverse iterator of the container...
                //
                base::IValueReverseIterableSharedPtr<T> valueReverseIterable = container;
                base::IReverseIteratorSharedPtr<T> expectedValueReverseIterator =
                    base::VectorReverseIterator<T>::Make(data.GetValues());

                iterationTest.TestValueReverseIteration(
                    valueReverseIterable,
                    expectedValueReverseIterator,
                    L"DoublyLinkedList");
            }

            /**
             * Tests the updation logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::TestUpdation(
                DoublyLinkedList<T>& list,
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
             * Tests the updation logic of a doubly linked list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::TestUpdation(
                DoublyLinkedList<T>& list,
                const std::wstring& operation,
                const T& item,
                const std::vector<T>& expectedContent)
            {
                UpdateList(list, operation, item);

                GetAssertion().AssertEqualsWithIterators(
                    *list.GetValueIterator(),
                    *base::VectorIterator<T>::Make(expectedContent),
                    L"Invalid updating logic of a doubly linked list.");
            }

            /**
             * Updates the list.
             */
            template <typename T>
            void DoublyLinkedListUnitTest::UpdateList(
                DoublyLinkedList<T>& list,
                const std::wstring& operation,
                const T& item)
            {
                if (base::StringEquality::AreEqualIgnoreCase(operation, L"AddToFront"))
                {
                    list.AddToFront(DoublyLinkedListNode<T>::Make(item));
                }
                else if (base::StringEquality::AreEqualIgnoreCase(operation, L"AddToBack"))
                {
                    list.AddToBack(DoublyLinkedListNode<T>::Make(item));
                }
                else if (base::StringEquality::AreEqualIgnoreCase(operation, L"RemoveFromFront"))
                {
                    list.RemoveFromFront();
                }
                else if (base::StringEquality::AreEqualIgnoreCase(operation, L"RemoveFromBack"))
                {
                    list.RemoveFromBack();
                }
            }

            /**
             * Creates a doubly linked list.
             */
            template <typename T>
            IDoublyLinkedListSharedPtr<T> DoublyLinkedListUnitTest::CreateDoublyLinkedList(const std::vector<T>& data)
            {
                IDoublyLinkedListSharedPtr<T> result(new DoublyLinkedList<T>());

                for (T element : data)
                {
                    result->AddToBack(element);
                }

                return result;
            }
        }
    }
}

#endif // DOUBLY_LINKED_LIST_UNIT_TEST_H_bc2aca41_dce1_4d7f_8bce_a18f2649aeb3
