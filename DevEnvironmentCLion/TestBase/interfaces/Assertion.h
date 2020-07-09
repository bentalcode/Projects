#ifndef ASSERTION_H_a0c6a15b_097f_43c7_a873_5024c3b40f3f
#define ASSERTION_H_a0c6a15b_097f_43c7_a873_5024c3b40f3f

#include <core/DereferenceEquatableComparator.h>
#include "EqualBuilder.h"
#include "EquatableComparator.h"
#include "LogStreamWriter.h"

namespace test_base {

    /**
     * The Assertion class implements an assertion.
     */
    class Assertion final
    {
    public:
        /**
         * The default constructor.
         */
        Assertion();

        /**
         * The constructor.
         */
        explicit Assertion(base::LogStreamWriterPtr logStreamWriter);

        /**
         * The destructor.
         */
        ~Assertion();

        /**
         * The copy/move constructors.
         */
        Assertion(const Assertion&) = delete;
        Assertion(Assertion&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Assertion& operator=(const Assertion&) = delete;
        Assertion& operator=(Assertion&&) = delete;

        /**
         * Asserts true.
         */
        void assertTrue(
            bool expression,
            const std::string& message);

        /**
         * Asserts equality with objects.
         */
        template <typename T>
        void assertEquals(
            const T& lhs,
            const T& rhs,
            const std::string& message);

        /**
         * Asserts equality with iterators.
         */
        template <typename T>
        void assertEqualsWithIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const std::string& message);

        /**
         * Asserts equality with dereference iterators.
         */
        template <typename T>
        void assertEqualsWithDereferenceIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const std::string& message);

        /**
         * Asserts equality with iterators.
         */
        template <typename T>
        void assertEqualsWithIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const base::IEquatableComparator<T>& comparator,
            const std::string& message);

        /**
         * Asserts equality with iterables.
         */
        template <typename T>
        void assertEqualsWithIterables(
            base::IIterable<T>& lhs,
            base::IIterable<T>& rhs,
            const std::string& message);

        /**
         * Asserts equality with iterables.
         */
        template <typename T>
        void assertEqualsWithIterables(
            base::IIterable<T>& lhs,
            base::IIterable<T>& rhs,
            const base::IEquatableComparator<T>& comparator,
            const std::string& message);

        /**
         * Sets the log stream writer.
         */
        void setLogStreamWriter(base::LogStreamWriterPtr logStreamWriter);

    private:
        base::LogStreamWriterPtr m_logStreamWriter;
    };

    /**
     * Asserts equality with objects.
     */
    template <typename T>
    void Assertion::assertEquals(
        const T& lhs,
        const T& rhs,
        const std::string& message)
    {
        bool status = lhs == rhs;
        assertTrue(status, message);
    }

    /**
     * Asserts equality with iterators.
     */
    template <typename T>
    void Assertion::assertEqualsWithIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const std::string& message)
    {
        base::EquatableComparator<T> comparator;
        assertEqualsWithIterators(lhs, rhs, comparator, message);
    }

    /**
     * Asserts equality with dereference iterators.
     */
    template <typename T>
    void Assertion::assertEqualsWithDereferenceIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const std::string& message)
    {
        base::DereferenceEquatableComparator<T> comparator;
        assertEqualsWithIterators(lhs, rhs, comparator, message);
    }

    /**
     * Asserts equality with iterators.
     */
    template <typename T>
    void Assertion::assertEqualsWithIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const base::IEquatableComparator<T>& comparator,
        const std::string& message)
    {
        base::EqualBuilder equalBuilder;
        bool status = equalBuilder.withIterator(lhs, rhs, comparator).build();

        assertTrue(status, message);
    }

    /**
     * Asserts equality with iterables.
     */
    template <typename T>
    void Assertion::assertEqualsWithIterables(
        base::IIterable<T>& lhs,
        base::IIterable<T>& rhs,
        const std::string& message)
    {
        assertEqualsWithIterators<T>(
            *lhs.getIterator(),
            *rhs.getIterator(),
            message);
    }
}

#endif // ASSERTION_H_a0c6a15b_097f_43c7_a873_5024c3b40f3f
