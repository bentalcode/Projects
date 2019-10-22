#ifndef UNIT_TEST_FUNCTION_H_3ff9bd71_b7ab_4ee2_92ae_9c427d421ee8
#define UNIT_TEST_FUNCTION_H_3ff9bd71_b7ab_4ee2_92ae_9c427d421ee8

#include "ITestFunction.h"

namespace unit_testing {

    /**
     * The UnitTestFunction abstract base class implements a unit test function.
     */
    template<typename UnitTestType>
    class UnitTestFunction : public ITestFunction {
    public:
        /**
         * The UnitTestFunction constructor.
         */
        UnitTestFunction(const std::string& testName, UnitTestType& unitTest);

        /**
         * The UnitTestFunction destructor.
         */
        virtual ~UnitTestFunction();

        /**
         * Gets the name of the test.
         */
        virtual const std::string& getName() const;

        /**
         * Gets the unit test.
         */
        UnitTestType& getUnitTest();

    private:
        std::string m_name;
        std::string m_testName;
        UnitTestType& m_unitTest;
    };

    /**
     * The UnitTestFunction constructor.
     */
    template<typename UnitTestType>
    inline UnitTestFunction<UnitTestType>::UnitTestFunction(const std::string& testName, UnitTestType& unitTest) :
        m_testName(testName),
        m_unitTest(unitTest)
    {
        m_name = m_unitTest.getName();
        m_name += "::";
        m_name += m_testName;
    }

    /**
     * The UnitTestFunction destructor.
     */
    template<typename UnitTestType>
    inline UnitTestFunction<UnitTestType>::~UnitTestFunction()
    {
    }

    /**
     * Gets the name of the test.
     */
    template<typename UnitTestType>
    inline const std::string& UnitTestFunction<UnitTestType>::getName() const
    {
        return m_name;
    }

    /**
     * Gets the unit test.
     */
    template<typename UnitTestType>
    inline UnitTestType& UnitTestFunction<UnitTestType>::getUnitTest()
    {
        return m_unitTest;
    }
}

#endif /* UNIT_TEST_FUNCTION_H_3ff9bd71_b7ab_4ee2_92ae_9c427d421ee8 */
