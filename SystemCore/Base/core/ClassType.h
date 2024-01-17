#ifndef CLASS_TYPE_H_c3f3b6bb_dea8_4c6c_a08d_0da472765510
#define CLASS_TYPE_H_c3f3b6bb_dea8_4c6c_a08d_0da472765510

#include "IClassType.h"
#include "NotImplementedException.h"

namespace base
{
    /**
     * The ClassType class implements a class type.
     */
    class ClassType final : public IClassType
    {
    public:
        /**
         * The ClassType constructor.
         */
        explicit ClassType(const std::wstring& className);

        /**
         * The ClassType destructor.
         */
        virtual ~ClassType();

        /**
         * The Copy/move constructors.
         */
        ClassType(const ClassType&) = default;
        ClassType(ClassType&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        ClassType& operator=(const ClassType&) = default;
        ClassType& operator=(ClassType&&) = delete;

        /**
         * Gets the name of a class.
         */
        virtual const std::wstring& ClassName() const;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int Compare(const IClassType& classType) const;

        /**
         * Determines if the class or interface represented by this Class object is either the same as,
         * or is a superclass or superinterface of, the class or interface represented by the specified Class parameter.
         */
        template <typename T>
        static bool IsAssignableFrom(T& obj);

    private:
        std::wstring m_className;
    };

    /**
     * Determines if the class or interface represented by this Class object is either the same as,
     * or is a superclass or superinterface of, the class or interface represented by the specified Class parameter.
     */
    template <typename T>
    bool ClassType::IsAssignableFrom(T& obj)
    {
        throw NotImplementedException(L"ClassType::IsAssignableFrom() is not implemented.");
    }

} // namespace base

#endif // CLASS_TYPE_H_c3f3b6bb_dea8_4c6c_a08d_0da472765510
