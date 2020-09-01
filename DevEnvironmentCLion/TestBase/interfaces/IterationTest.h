#ifndef ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96
#define ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96

#include "IIterable.h"
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
            base::IIterablePtr<T> container,
            base::IIteratorPtr<T> containerIterator,
            const std::string& containerName);

        /**
         * Tests the forward iteration logic of a container with dereference.
         */
        template <typename T>
        void testForwardIterationWithDereference(
            base::IIterablePtr<T> container,
            base::IIteratorPtr<T> containerIterator,
            const std::string& containerName);

    private:
        test_base::Assertion m_assertion;
    };

    /**
     * Tests the forward iteration logic of a container.
     */
    template <typename T>
    void IterationTest::testForwardIteration(
        base::IIterablePtr<T> container,
        base::IIteratorPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorPtr<T> iterator = container->getIterator();

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
        base::IIterablePtr<T> container,
        base::IIteratorPtr<T> expectedIterator,
        const std::string& containerName)
    {
        base::IIteratorPtr<T> iterator = container->getIterator();

        size_t index = 0;

        while (iterator->hasNext() && expectedIterator->hasNext())
        {
            T element = iterator->next();
            T expectedElement = expectedIterator->next();

            std::stringstream errorMessageStream;
            errorMessageStream
                << "The forward iteration logic of " << containerName << " is invalid."
                << " Invalid element found in index: " << std::to_string(index);

            m_assertion.assertEqualsWithDereference(
                element,
                expectedElement,
                errorMessageStream.str());

            ++index;
        }
    }
}

#endif // ITERATION_TEST_H_73905a7a_4eb0_4d33_862b_af3e0a07fe96
