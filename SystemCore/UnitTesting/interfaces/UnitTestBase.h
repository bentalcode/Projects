#ifndef UNIT_TEST_BASE_H_bd6c22df_f5b1_4659_8457_b44aec9d69b1
#define UNIT_TEST_BASE_H_bd6c22df_f5b1_4659_8457_b44aec9d69b1

#include "IUnitTest.h"
#include "Assertion.h"

namespace unit_testing {
    /**
     * The UnitTestBase class implements a unit test.
     */
    class UnitTestBase : public IUnitTest
    {
    public:
        /**
         * The constructor.
         */
        explicit UnitTestBase(const std::wstring& name);

        /**
         * The destructor.
         */
        virtual ~UnitTestBase();

        /**
         * The copy/move constructors.
         */
        UnitTestBase(const UnitTestBase&) = delete;
        UnitTestBase(UnitTestBase&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        UnitTestBase& operator=(const UnitTestBase&) = delete;
        UnitTestBase& operator=(UnitTestBase&&) = delete;

        /**
         * Gets the name of the unit test.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Runs the logic pre-running the tests.
         */
        virtual void PreRun() override;

        /**
         * Runs the logic post running the tests.
         */
        virtual void PostRun() override;

        /**
         * Sets the message writer.
         */
        virtual void SetMessageWriter(base::IMessageWriterSharedPtr messageWriter) override;

    protected:
        /**
         * Gets the message writer.
         */
        base::IMessageWriter& GetMessageWriter();

        /**
         * Gets the assertion.
         */
        test_base::Assertion& GetAssertion();

    private:
        std::wstring m_name;
        base::IMessageWriterSharedPtr m_messageWriter;
        test_base::Assertion m_assertion;
    };
}

#endif // UNIT_TEST_BASE_H_bd6c22df_f5b1_4659_8457_b44aec9d69b1
