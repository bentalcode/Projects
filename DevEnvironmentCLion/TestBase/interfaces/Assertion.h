#ifndef ASSERTION_H_3dbe3f51_2dc7_4d6e_81d3_349dca1dca60
#define ASSERTION_H_3dbe3f51_2dc7_4d6e_81d3_349dca1dca60

#include "EqualBuilder.h"
#include "EquatableComparator.h"

namespace test_base {

    /**
     * The Assertion class implements an assertion.
     */
    class Assertion final
    {
    public:
        /**
         * The Assertion constructor.
         */
        Assertion();

        /**
         * The Assertion destructor.
         */
        ~Assertion();

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
        bool status = false;
        assertTrue(status, message);
    }
}

#endif /* ASSERTION_H_3dbe3f51_2dc7_4d6e_81d3_349dca1dca60 */
