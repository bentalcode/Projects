#ifndef I_CLASS_TYPE_H_336fb880_9817_40c3_8a48_2f083391252c
#define I_CLASS_TYPE_H_336fb880_9817_40c3_8a48_2f083391252c

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
        virtual const std::string& getClassName() const = 0;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int compare(const IClassType& classType) const = 0;
    };

    inline bool operator<(const IClassType& left, const IClassType& right)
    {
        return left.compare(right) < 0;
    }

    using IClassTypePtr = std::shared_ptr<IClassType>;
}

#endif // I_CLASS_TYPE_H_336fb880_9817_40c3_8a48_2f083391252c
