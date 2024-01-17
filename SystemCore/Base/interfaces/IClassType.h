#ifndef I_CLASS_TYPE_H_336fb880_9817_40c3_8a48_2f083391252c
#define I_CLASS_TYPE_H_336fb880_9817_40c3_8a48_2f083391252c

#include <string>
#include <memory>

namespace base
{
    /**
     * The IClassType interface defines a class type.
     */
    class IClassType
    {
    public:
        /**
         * The constructor.
         */
        IClassType() = default;

        /**
         * The destructor.
         */
        virtual ~IClassType() = default;

        /**
         * The copy/move constructors.
         */
        IClassType(const IClassType&) = default;
        IClassType(IClassType&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IClassType& operator=(const IClassType&) = default;
        IClassType& operator=(IClassType&&) = delete;

        /**
         * Gets the name of a class.
         */
        virtual const std::wstring& ClassName() const = 0;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int Compare(const IClassType& classType) const = 0;
    };

    /**
     * Implements operator equal for class types.
     */
    inline bool operator==(const IClassType& left, const IClassType& right)
    {
        return left.Compare(right) == 0;
    }

    /**
     * Implements operator not equal for class types.
     */
    inline bool operator!=(const IClassType& left, const IClassType& right)
    {
        return left.Compare(right) != 0;
    }

    /**
     * Implements operator less than for class types.
     */
    inline bool operator<(const IClassType& left, const IClassType& right)
    {
        return left.Compare(right) < 0;
    }

    /**
     * Implements operator less or equal than for class types.
     */
    inline bool operator<=(const IClassType& left, const IClassType& right)
    {
        return left.Compare(right) <= 0;
    }

    /**
     * Implements operator greater for class types.
     */
    inline bool operator>(const IClassType& left, const IClassType& right)
    {
        return left.Compare(right) > 0;
    }

    /**
     * Implements operator greater or equal for class types.
     */
    inline bool operator>=(const IClassType& left, const IClassType& right)
    {
        return left.Compare(right) >= 0;
    }

    //
    // Defines the SharedPtr of Class Type...
    //
    using IClassTypeSharedPtr = std::shared_ptr<IClassType>;

} // namespace base

#endif // I_CLASS_TYPE_H_336fb880_9817_40c3_8a48_2f083391252c
