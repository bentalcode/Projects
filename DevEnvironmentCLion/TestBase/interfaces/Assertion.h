#ifndef ASSERTION_H_d5cec444_dcab_450e_ba52_6e2ac44e787c
#define ASSERTION_H_d5cec444_dcab_450e_ba52_6e2ac44e787c

#include "IMessageWriter.h"
#include "EqualBuilder.h"
#include "EquatableComparator.h"
#include "DereferenceEquatableComparator.h"
#include "DereferenceEquatableComparator2.h"

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
        explicit Assertion(base::IMessageWriterPtr messageWriter);

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
         * Asserts equality with objects and a comparator.
         */
        template <typename T>
        void assertEquals(
            const T& lhs,
            const T& rhs,
            const base::IEquatableComparator<T>& comparator,
            const std::string& message);

        /**
         * Asserts equality with dereference.
         */
        template <typename T>
        void assertEqualsWithDereference(
            T lhs,
            T rhs,
            const std::string& message);

        /**
         * Asserts equality with dereference and a comparator.
         */
        template <typename T, typename TComparator>
        void assertEqualsWithDereference(
            T lhs,
            T rhs,
            const base::IEquatableComparator<TComparator>& comparator,
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
         * Asserts equality with iterators and a comparator.
         */
        template <typename T>
        void assertEqualsWithIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const base::IEquatableComparator<T>& comparator,
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
         * Asserts equality with dereference iterators and a comparator.
         */
        template <typename T, typename TComparator>
        void assertEqualsWithDereferenceIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const base::IEquatableComparator<TComparator>& comparator,
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
         * Asserts equality with iterables and a comparator.
         */
        template <typename T>
        void assertEqualsWithIterables(
            base::IIterable<T>& lhs,
            base::IIterable<T>& rhs,
            const base::IEquatableComparator<T>& comparator,
            const std::string& message);

        /**
         * Sets the message writer.
         */
        void setMessageWriter(base::IMessageWriterPtr messageWriter);

    private:
        base::IMessageWriterPtr m_messageWriter;
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
     * Asserts equality with objects and a comparator.
     */
    template <typename T>
    void Assertion::assertEquals(
        const T& lhs,
        const T& rhs,
        const base::IEquatableComparator<T>& comparator,
        const std::string& message)
    {
        bool status = comparator.isEqual(lhs, rhs);
        assertTrue(status, message);
    }

    /**
     * Asserts equality with dereference.
     */
    template <typename T>
    void Assertion::assertEqualsWithDereference(
        T lhs,
        T rhs,
        const std::string& message)
    {
        base::DereferenceEquatableComparator<T> comparator;
        assertEquals(lhs, rhs, comparator, message);
    }

    /**
     * Asserts equality with dereference and a comparator.
     */
    template <typename T, typename TComparator>
    void Assertion::assertEqualsWithDereference(
        T lhs,
        T rhs,
        const base::IEquatableComparator<TComparator>& comparator,
        const std::string& message)
    {
        base::DereferenceEquatableComparator2<T, TComparator> dereferenceComparator(comparator);
        assertEquals(lhs, rhs, dereferenceComparator, message);
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
        base::DereferenceEquatableComparator<T> dereferenceComparator;
        assertEqualsWithIterators(lhs, rhs, dereferenceComparator, message);
    }

    /**
     * Asserts equality with dereference iterators and a comparator.
     */
    template <typename T, typename TComparator>
    void Assertion::assertEqualsWithDereferenceIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const base::IEquatableComparator<TComparator>& comparator,
        const std::string& message)
    {
        base::DereferenceEquatableComparator2<T, TComparator> dereferenceComparator(comparator);
        assertEqualsWithIterators(lhs, rhs, dereferenceComparator, message);
    }

    /**
     * Asserts equality with iterators and a comparator.
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

    /**
     * Asserts equality with iterables and a comparator.
     */
    template <typename T>
    void Assertion::assertEqualsWithIterables(
        base::IIterable<T>& lhs,
        base::IIterable<T>& rhs,
        const base::IEquatableComparator<T>& comparator,
        const std::string& message)
    {
        assertEqualsWithIterators<T>(
            *lhs.getIterator(),
            *rhs.getIterator(),
            comparator,
            message);
    }
}

#endif // ASSERTION_H_d5cec444_dcab_450e_ba52_6e2ac44e787c
