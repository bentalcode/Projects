#ifndef CLASS_TYPE_H_c3f3b6bb_dea8_4c6c_a08d_0da472765510
#define CLASS_TYPE_H_c3f3b6bb_dea8_4c6c_a08d_0da472765510

#include "IClassType.h"

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
        ClassType(const std::string& className);

        /**
         * The ClassType destructor.
         */
        virtual ~ClassType();

        /**
         * The copy/move constructors.
         */
        ClassType(const ClassType&) = default;
        ClassType(ClassType&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ClassType& operator=(const ClassType&) = default;
        ClassType& operator=(ClassType&&) = delete;

        /**
         * Gets the name of a class.
         */
        virtual const std::string& getClassName() const;

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        virtual int compare(const IClassType& classType) const;

    private:
        std::string m_className;
    };
}

#endif // CLASS_TYPE_H_c3f3b6bb_dea8_4c6c_a08d_0da472765510
