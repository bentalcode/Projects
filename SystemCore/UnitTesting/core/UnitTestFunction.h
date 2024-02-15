#ifndef UNIT_TEST_FUNCTION_H_242274fc_e743_4f6d_8866_8915102f69ab
#define UNIT_TEST_FUNCTION_H_242274fc_e743_4f6d_8866_8915102f69ab

#include "ITestFunction.h"

namespace unit_testing {

    /**
     * The UnitTestFunction abstract base class implements a unit Test function.
     */
    template <typename UnitTestType>
    class UnitTestFunction : public ITestFunction {
    public:
        /**
         * The constructor.
         */
        UnitTestFunction(
            const std::wstring& testName,
            UnitTestType& unitTest);

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
         * Gets the name of the Test.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets the unit Test.
         */
        UnitTestType& GetUnitTest();

    private:
        std::wstring m_name;
        std::wstring m_testName;
        UnitTestType& m_unitTest;
    };

    /**
     * The UnitTestFunction constructor.
     */
    template <typename UnitTestType>
    inline UnitTestFunction<UnitTestType>::UnitTestFunction(
        const std::wstring& testName,
        UnitTestType& unitTest) :
        m_testName(testName),
        m_unitTest(unitTest)
    {
        m_name = m_unitTest.GetName();
        m_name += L"::";
        m_name += m_testName;
    }

    /**
     * The UnitTestFunction destructor.
     */
    template <typename UnitTestType>
    inline UnitTestFunction<UnitTestType>::~UnitTestFunction()
    {
    }

    /**
     * Gets the name of the Test.
     */
    template <typename UnitTestType>
    inline const std::wstring& UnitTestFunction<UnitTestType>::GetName() const
    {
        return m_name;
    }

    /**
     * Gets the unit Test.
     */
    template <typename UnitTestType>
    inline UnitTestType& UnitTestFunction<UnitTestType>::GetUnitTest()
    {
        return m_unitTest;
    }
}

#endif // UNIT_TEST_FUNCTION_H_242274fc_e743_4f6d_8866_8915102f69ab
