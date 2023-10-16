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
        explicit Assertion(base::IMessageWriterSharedPtr messageWriter);

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
        void AssertTrue(
            bool expression,
            const std::wstring& message);

        /**
         * Asserts equality with objects.
         */
        template <typename T>
        void AssertEquals(
            const T& lhs,
            const T& rhs,
            const std::wstring& message);

        /**
         * Asserts equality with objects and a comparator.
         */
        template <typename T>
        void AssertEquals(
            const T& lhs,
            const T& rhs,
            const base::IEquatableComparator<T>& comparator,
            const std::wstring& message);

        /**
         * Asserts equality with dereference.
         */
        template <typename T>
        void AssertEqualsWithDereference(
            T lhs,
            T rhs,
            const std::wstring& message);

        /**
         * Asserts equality with dereference and a comparator.
         */
        template <typename T, typename TComparator>
        void AssertEqualsWithDereference(
            T lhs,
            T rhs,
            const base::IEquatableComparator<TComparator>& comparator,
            const std::wstring& message);

        /**
         * Asserts equality with iterators.
         */
        template <typename T>
        void AssertEqualsWithIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const std::wstring& message);

        /**
         * Asserts equality with iterators and a comparator.
         */
        template <typename T>
        void AssertEqualsWithIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const base::IEquatableComparator<T>& comparator,
            const std::wstring& message);

        /**
         * Asserts equality with dereference iterators.
         */
        template <typename T>
        void AssertEqualsWithDereferenceIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const std::wstring& message);

        /**
         * Asserts equality with dereference iterators and a comparator.
         */
        template <typename T, typename TComparator>
        void AssertEqualsWithDereferenceIterators(
            base::IIterator<T>& lhs,
            base::IIterator<T>& rhs,
            const base::IEquatableComparator<TComparator>& comparator,
            const std::wstring& message);

        /**
         * Asserts equality with iterables.
         */
        template <typename T>
        void AssertEqualsWithIterables(
            base::IIterable<T>& lhs,
            base::IIterable<T>& rhs,
            const std::wstring& message);

        /**
         * Asserts equality with iterables and a comparator.
         */
        template <typename T>
        void AssertEqualsWithIterables(
            base::IIterable<T>& lhs,
            base::IIterable<T>& rhs,
            const base::IEquatableComparator<T>& comparator,
            const std::wstring& message);

        /**
         * Sets the message writer.
         */
        void setMessageWriter(base::IMessageWriterSharedPtr messageWriter);

    private:
        base::IMessageWriterSharedPtr m_messageWriter;
    };

    /**
     * Asserts equality with objects.
     */
    template <typename T>
    void Assertion::AssertEquals(
        const T& lhs,
        const T& rhs,
        const std::wstring& message)
    {
        bool status = lhs == rhs;
        AssertTrue(status, message);
    }

    /**
     * Asserts equality with objects and a comparator.
     */
    template <typename T>
    void Assertion::AssertEquals(
        const T& lhs,
        const T& rhs,
        const base::IEquatableComparator<T>& comparator,
        const std::wstring& message)
    {
        bool status = comparator.AreEqual(lhs, rhs);
        AssertTrue(status, message);
    }

    /**
     * Asserts equality with dereference.
     */
    template <typename T>
    void Assertion::AssertEqualsWithDereference(
        T lhs,
        T rhs,
        const std::wstring& message)
    {
        base::DereferenceEquatableComparator<T> comparator;
        AssertEquals(lhs, rhs, comparator, message);
    }

    /**
     * Asserts equality with dereference and a comparator.
     */
    template <typename T, typename TComparator>
    void Assertion::AssertEqualsWithDereference(
        T lhs,
        T rhs,
        const base::IEquatableComparator<TComparator>& comparator,
        const std::wstring& message)
    {
        base::DereferenceEquatableComparator2<T, TComparator> dereferenceComparator(comparator);
        AssertEquals(lhs, rhs, dereferenceComparator, message);
    }

    /**
     * Asserts equality with iterators.
     */
    template <typename T>
    void Assertion::AssertEqualsWithIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const std::wstring& message)
    {
        base::EquatableComparator<T> comparator;
        AssertEqualsWithIterators(lhs, rhs, comparator, message);
    }

    /**
     * Asserts equality with dereference iterators.
     */
    template <typename T>
    void Assertion::AssertEqualsWithDereferenceIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const std::wstring& message)
    {
        base::DereferenceEquatableComparator<T> dereferenceComparator;
        AssertEqualsWithIterators(lhs, rhs, dereferenceComparator, message);
    }

    /**
     * Asserts equality with dereference iterators and a comparator.
     */
    template <typename T, typename TComparator>
    void Assertion::AssertEqualsWithDereferenceIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const base::IEquatableComparator<TComparator>& comparator,
        const std::wstring& message)
    {
        base::DereferenceEquatableComparator2<T, TComparator> dereferenceComparator(comparator);
        AssertEqualsWithIterators(lhs, rhs, dereferenceComparator, message);
    }

    /**
     * Asserts equality with iterators and a comparator.
     */
    template <typename T>
    void Assertion::AssertEqualsWithIterators(
        base::IIterator<T>& lhs,
        base::IIterator<T>& rhs,
        const base::IEquatableComparator<T>& comparator,
        const std::wstring& message)
    {
        base::EqualBuilder equalBuilder;
        bool status = true; // ToDo: equalBuilder.WithIterator(lhs, rhs, comparator).Build();

        AssertTrue(status, message);
    }

    /**
     * Asserts equality with iterables.
     */
    template <typename T>
    void Assertion::AssertEqualsWithIterables(
        base::IIterable<T>& lhs,
        base::IIterable<T>& rhs,
        const std::wstring& message)
    {
        AssertEqualsWithIterators<T>(
            *lhs.getIterator(),
            *rhs.getIterator(),
            message);
    }

    /**
     * Asserts equality with iterables and a comparator.
     */
    template <typename T>
    void Assertion::AssertEqualsWithIterables(
        base::IIterable<T>& lhs,
        base::IIterable<T>& rhs,
        const base::IEquatableComparator<T>& comparator,
        const std::wstring& message)
    {
        AssertEqualsWithIterators<T>(
            *lhs.getIterator(),
            *rhs.getIterator(),
            comparator,
            message);
    }
}

#endif // ASSERTION_H_d5cec444_dcab_450e_ba52_6e2ac44e787c
