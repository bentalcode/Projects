#ifndef UNIT_TEST_FUNCTION_H_242274fc_e743_4f6d_8866_8915102f69ab
#define UNIT_TEST_FUNCTION_H_242274fc_e743_4f6d_8866_8915102f69ab

#include "ITestFunction.h"

namespace unit_testing {

    /**
     * The UnitTestFunction abstract base class implements a unit test function.
     */
    template<typename UnitTestType>
    class UnitTestFunction : public ITestFunction {
    public:
        /**
         * The constructor.
         */
        UnitTestFunction(const std::string& testName, UnitTestType& unitTest);

        /**
         * The destructor.
         */
        virtual ~UnitTestFunction();

        /**
         * The copy/move constructors.
         */
        UnitTestFunction(const UnitTestFunction&) = delete;
        UnitTestFunction(UnitTestFunction&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        UnitTestFunction& operator=(const UnitTestFunction&) = delete;
        UnitTestFunction& operator=(UnitTestFunction&&) = delete;

        /**
         * Gets the name of the test.
         */
        virtual const std::string& getName() const override;

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

#endif // UNIT_TEST_FUNCTION_H_242274fc_e743_4f6d_8866_8915102f69ab
