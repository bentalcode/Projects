#ifndef ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96
#define ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96

#include "IIterable.h"
#include "IReverseIterable.h"
#include "IKeyIterable.h"
#include "IKeyReverseIterable.h"
#include "IValueIterable.h"
#include "IValueReverseIterable.h"
#include "Assertion.h"

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
        void testForwardIteration(
            base::IIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::string& containerName);

        /**
         * Tests the forward iteration logic of a container with a dereference.
         */
        template <typename T>
        void testForwardIterationWithDereference(
            base::IIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::string& containerName);

        /**
         * Tests the reverse iteration logic of a container.
         */
        template <typename T>
        void testReverseIteration(
            base::IReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::string& containerName);

        /**
         * Tests the reverse iteration logic of a container with dereference.
         */
        template <typename T>
        void testReverseIterationWithDereference(
            base::IReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::string& containerName);

        /**
         * Tests the key iteration logic of a container.
         */
        template <typename T>
        void testKeyIteration(
            base::IKeyIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::string& containerName);

        /**
         * Tests the key iteration logic of a container with a dereference.
         */
        template <typename T>
        void testKeyIterationWithDereference(
            base::IKeyIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::string& containerName);

        /**
         * Tests the key reverse iteration logic of a container.
         */
        template <typename T>
        void testKeyReverseIteration(
            base::IKeyReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::string& containerName);

        /**
         * Tests the value iteration logic of a container.
         */
        template <typename T>
        void testValueIteration(
            base::IValueIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::string& containerName);

        /**
         * Tests the value iteration logic of a container with a dereference.
         */
        template <typename T>
        void testValueIterationWithDereference(
            base::IValueIterableSharedPtr<T> container,
            base::IIteratorSharedPtr<T> expectedIterator,
            const std::string& containerName);

        /**
         * Tests the value reverse iteration logic of a container.
         */
        template <typename T>
        void testValueReverseIteration(
            base::IValueReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::string& containerName);

        /**
         * Tests the value reverse iteration logic of a container with dereference.
         */
        template <typename T>
        void testValueReverseIterationWithDereference(
            base::IValueReverseIterableSharedPtr<T> container,
            base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
            const std::string& containerName);

    private:
        test_base::Assertion m_assertion;
    };

    /**
     * Tests the forward iteration logic of a container.
     */
    template <typename T>
    void IterationTest::testForwardIteration(
        base::IIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The forward iteration logic of " << containerName << " is invalid."
                << " Invalid element found in index: " << std::to_string(index);

            m_assertion.assertEquals(
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
    void IterationTest::testForwardIterationWithDereference(
        base::IIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The forward iteration logic with a dereference of " << containerName << " is invalid."
                << " Invalid element found in index: " << std::to_string(index);

            m_assertion.assertEqualsWithDereference(
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
    void IterationTest::testReverseIteration(
        base::IReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::string& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The reverse iteration logic of " << containerName << " is invalid."
                << " Invalid element found in reverse index: " << std::to_string(index);

            m_assertion.assertEquals(
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
    void IterationTest::testReverseIterationWithDereference(
        base::IReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::string& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext()) {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The reverse iteration logic of with a dereference " << containerName << " is invalid."
                << " Invalid element found in reverse index: " << std::to_string(index);

            m_assertion.assertEqualsWithDereference(
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
    void IterationTest::testKeyIteration(
        base::IKeyIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getKeyIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The key iteration logic of " << containerName << " is invalid."
                << " Invalid element found in index: " << std::to_string(index);

            m_assertion.assertEquals(
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
    void IterationTest::testKeyIterationWithDereference(
        base::IKeyIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getKeyIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The key iteration logic with a dereference of " << containerName << " is invalid."
                << " Invalid element found in index: " << std::to_string(index);

            m_assertion.assertEqualsWithDereference(
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
    void IterationTest::testKeyReverseIteration(
        base::IKeyReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::string& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getKeyReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The key reverse iteration logic of " << containerName << " is invalid."
                << " Invalid element found in reverse index: " << std::to_string(index);

            m_assertion.assertEquals(
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
    void IterationTest::testValueIteration(
        base::IValueIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getValueIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The value iteration logic of " << containerName << " is invalid."
                << " Invalid element found in index: " << std::to_string(index);

            m_assertion.assertEquals(
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
    void IterationTest::testValueIterationWithDereference(
        base::IValueIterableSharedPtr<T> container,
        base::IIteratorSharedPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorSharedPtr<T> iterator = container->getValueIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The value iteration logic with a dereference of " << containerName << " is invalid."
                << " Invalid element found in index: " << std::to_string(index);

            m_assertion.assertEqualsWithDereference(
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
    void IterationTest::testValueReverseIteration(
        base::IValueReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::string& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getValueReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The value reverse iteration logic of " << containerName << " is invalid."
                << " Invalid element found in reverse index: " << std::to_string(index);

            m_assertion.assertEquals(
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
    void IterationTest::testValueReverseIterationWithDereference(
        base::IValueReverseIterableSharedPtr<T> container,
        base::IReverseIteratorSharedPtr<T> expectedReverseIterator,
        const std::string& containerName)
    {
        base::IReverseIteratorSharedPtr<T> reverseIterator = container->getValueReverseIterator();

        size_t index = 0;

        while (reverseIterator->hasNext() && expectedReverseIterator->hasNext())
        {
            T element = reverseIterator->next();
            T expectedElement = expectedReverseIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The value reverse iteration logic with a dereference of " << containerName << " is invalid."
                << " Invalid element found in reverse index: " << std::to_string(index);

            m_assertion.assertEqualsWithDereference(
                element,
                expectedElement,
                errorMessageStream.str());

            ++index;
        }
    }
}

#endif // ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96
