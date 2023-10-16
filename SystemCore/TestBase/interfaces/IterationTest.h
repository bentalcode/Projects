#ifndef ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96
#define ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96

#include "IIterable.h"
#include "IReverseIterable.h"
#include "IKeyIterable.h"
#include "IKeyReverseIterable.h"
#include "IValueIterable.h"
#include "IValueReverseIterable.h"
#include "Assertion.h"
#include <sstream>

namespace test_base {

    /**
     * The IterationTest class implements generic iteration tests.
     */
    class IterationTest final
    {
    public:
        /**
         * The constructor.
         */
        IterationTest();

        /**
         * The destructor.
         */
        virtual ~IterationTest();

        /**
         * The copy/move constructors.
         */
        IterationTest(const IterationTest&) = delete;
        IterationTest(IterationTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IterationTest& operator=(const IterationTest&) = delete;
        IterationTest& operator=(IterationTest&&) = delete;

        /**
         * Tests the forward iteration logic of a container.
         */
        template <typename T>
        void TestForwardIteration(
            base::IIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::wstring& containerName);

        /**
         * Tests the forward iteration logic of a container with a dereference.
         */
        template <typename T>
        void TestForwardIterationWithDereference(
            base::IIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::wstring& containerName);

        /**
         * Tests the reverse iteration logic of a container.
         */
        template <typename T>
        void TestReverseIteration(
            base::IReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::wstring& containerName);

        /**
         * Tests the reverse iteration logic of a container with dereference.
         */
        template <typename T>
        void TestReverseIterationWithDereference(
            base::IReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::wstring& containerName);

        /**
         * Tests the key iteration logic of a container.
         */
        template <typename T>
        void TestKeyIteration(
            base::IKeyIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::wstring& containerName);

        /**
         * Tests the key iteration logic of a container with a dereference.
         */
        template <typename T>
        void TestKeyIterationWithDereference(
            base::IKeyIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::wstring& containerName);

        /**
         * Tests the key reverse iteration logic of a container.
         */
        template <typename T>
        void TestKeyReverseIteration(
            base::IKeyReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::wstring& containerName);

        /**
         * Tests the value iteration logic of a container.
         */
        template <typename T>
        void TestValueIteration(
            base::IValueIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::wstring& containerName);

        /**
         * Tests the value iteration logic of a container with a dereference.
         */
        template <typename T>
        void TestValueIterationWithDereference(
            base::IValueIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::wstring& containerName);

        /**
         * Tests the value reverse iteration logic of a container.
         */
        template <typename T>
        void TestValueReverseIteration(
            base::IValueReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::wstring& containerName);

        /**
         * Tests the value reverse iteration logic of a container with dereference.
         */
        template <typename T>
        void TestValueReverseIterationWithDereference(
            base::IValueReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::wstring& containerName);

    private:
        test_base::Assertion m_assertion;
    };

    /**
     * Tests the forward iteration logic of a container.
     */
    template <typename T>
    void IterationTest::TestForwardIteration(
        base::IIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::wstring& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The forward iteration logic of " << containerName << " is invalid."
                << L" Invalid element found in index: " << std::to_wstring(index);

            m_assertion.AssertEquals(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the forward iteration logic of a container with a dereference.
     */
    template <typename T>
    void IterationTest::TestForwardIterationWithDereference(
        base::IIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::wstring& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The forward iteration logic with a dereference of " << containerName << L" is invalid."
                << L" Invalid element found in index: " << std::to_wstring(index);

            m_assertion.AssertEqualsWithDereference(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the reverse iteration logic of a container.
     */
    template <typename T>
    void IterationTest::TestReverseIteration(
        base::IReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::wstring& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The reverse iteration logic of " << containerName << L" is invalid."
                << L" Invalid element found in reverse index: " << std::to_wstring(index);

            m_assertion.AssertEquals(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the reverse iteration logic of a container with a dereference.
     */
    template <typename T>
    void IterationTest::TestReverseIterationWithDereference(
        base::IReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::wstring& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext()) {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The reverse iteration logic of with a dereference " << containerName << L" is invalid."
                << L" Invalid element found in reverse index: " << std::to_wstring(index);

            m_assertion.AssertEqualsWithDereference(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the key iteration logic of a container.
     */
    template <typename T>
    void IterationTest::TestKeyIteration(
        base::IKeyIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::wstring& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getKeyIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The key iteration logic of " << containerName << L" is invalid."
                << L" Invalid element found in index: " << std::to_wstring(index);

            m_assertion.AssertEquals(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the key iteration logic of a container with a dereference.
     */
    template <typename T>
    void IterationTest::TestKeyIterationWithDereference(
        base::IKeyIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::wstring& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getKeyIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The key iteration logic with a dereference of " << containerName << L" is invalid."
                << L" Invalid element found in index: " << std::to_wstring(index);

            m_assertion.AssertEqualsWithDereference(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the key reverse iteration logic of a container.
     */
    template <typename T>
    void IterationTest::TestKeyReverseIteration(
        base::IKeyReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::wstring& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getKeyReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The key reverse iteration logic of " << containerName << L" is invalid."
                << L" Invalid element found in reverse index: " << std::to_wstring(index);

            m_assertion.AssertEquals(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the value iteration logic of a container.
     */
    template <typename T>
    void IterationTest::TestValueIteration(
        base::IValueIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::wstring& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getValueIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The value iteration logic of " << containerName << L" is invalid."
                << L" Invalid element found in index: " << std::to_wstring(index);

            m_assertion.AssertEquals(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the value iteration logic of a container with a dereference.
     */
    template <typename T>
    void IterationTest::TestValueIterationWithDereference(
        base::IValueIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::wstring& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getValueIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The value iteration logic with a dereference of " << containerName << L" is invalid."
                << L" Invalid element found in index: " << std::to_wstring(index);

            m_assertion.AssertEqualsWithDereference(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the value reverse iteration logic of a container.
     */
    template <typename T>
    void IterationTest::TestValueReverseIteration(
        base::IValueReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::wstring& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getValueReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The value reverse iteration logic of " << containerName << L" is invalid."
                << L" Invalid element found in reverse index: " << std::to_wstring(index);

            m_assertion.AssertEquals(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }

    /**
     * Tests the value reverse iteration logic of a container with a dereference.
     */
    template <typename T>
    void IterationTest::TestValueReverseIterationWithDereference(
        base::IValueReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::wstring& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getValueReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The value reverse iteration logic with a dereference of " << containerName << L" is invalid."
                << L" Invalid element found in reverse index: " << std::to_wstring(index);

            m_assertion.AssertEqualsWithDereference(
                    element,
                    expectedElement,
                    errorMessageStream.str());

            ++index;
        }
    }
}

#endif // ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96
