#ifndef ALMOST_COMPARATOR_H_7093f5e0_57ce_11ee_8c99_0242ac120002
#define ALMOST_COMPARATOR_H_7093f5e0_57ce_11ee_8c99_0242ac120002

#include "IBinaryComparator.h"
#include "UnexpectedException.h"
#include <assert.h>

namespace base {

    /**
     * The AlmostComparator class implements a generic almost comparator.
     */
    template <typename Type, typename EpsilonType>
    class AlmostComparator final : public IBinaryComparator<Type>
    {
    public:
        /**
         * Creates an almost comparator.
         */
        static IBinaryComparatorSharedPtr<Type> Make(EpsilonType epsilon);

        /**
         * The AlmostComparator constructor.
         */
        AlmostComparator(EpsilonType epsilon);

        /**
         * The AlmostComparator destructor.
         */
        virtual ~AlmostComparator();

        /**
         * Gets a hash code of an object.
         */
        virtual size_t GetHashCode(const Type& obj) const override;

        /**
         * Checks whether two instances are equals.
         */
        virtual bool AreEqual(const Type& lhs, const Type& rhs) const override;

        /**
         * Determines the comparision relative order between two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int CompareTo(const Type& lhs, const Type& rhs) const override;

    private:
        EpsilonType m_epsilon;
    };

    /**
     * Creates an almost comparator.
     */
    template <typename Type, typename EpsilonType>
    IBinaryComparatorSharedPtr<Type> AlmostComparator<Type, EpsilonType>::Make(EpsilonType epsilon)
    {
        return std::make_shared<AlmostComparator<Type, EpsilonType>>(epsilon);
    }

    /**
     * The AlmostComparator constructor.
     */
    template <typename Type, typename EpsilonType>
    AlmostComparator<Type, EpsilonType>::AlmostComparator(EpsilonType epsilon) :
        m_epsilon(epsilon)
    {
    }

    /**
     * The AlmostComparator destructor.
     */
    template <typename Type, typename EpsilonType>
    AlmostComparator<Type, EpsilonType>::~AlmostComparator()
    {
    }

    /**
     * Gets a hash code of an object.
     */
    template <typename Type, typename EpsilonType>
    size_t AlmostComparator<Type, EpsilonType>::GetHashCode(const Type& obj) const
    {
        return std::hash<Type>{}(obj);
    }

    /**
     * Checks whether two instances are equals.
     */
    template <typename Type, typename EpsilonType>
    bool AlmostComparator<Type, EpsilonType>::AreEqual(const Type& lhs, const Type& rhs) const
    {
        if (lhs == rhs) {
            return true;
        }

        EpsilonType difference = std::abs(lhs - rhs);

        return difference <= m_epsilon;
    }

    /**
     * Determines the comparision relative order between two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    template <typename Type, typename EpsilonType>
    int AlmostComparator<Type, EpsilonType>::CompareTo(const Type& lhs, const Type& rhs) const
    {
        if (AreEqual(lhs, rhs)) {
            return 0;
        }

        if (lhs < rhs) {
            return -1;
        }

        if (lhs > rhs) {
            return 1;
        }

        assert(false);

        long errorCode = ErrorCodes::UNEXPECTED;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"AlmostComparator Has failed comparing relative order between two instances with en epsilon"
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw UnexpectedException(errorMessage);
    }

} // namespace base

#endif // ALMOST_COMPARATOR_H_7093f5e0_57ce_11ee_8c99_0242ac120002
