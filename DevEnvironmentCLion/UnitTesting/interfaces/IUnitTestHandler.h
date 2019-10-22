#ifndef I_UNIT_TEST_HANDLER_H_468be4fa_4f37_478b_8e29_79004d0ad18a
#define I_UNIT_TEST_HANDLER_H_468be4fa_4f37_478b_8e29_79004d0ad18a

namespace unit_testing
{
    /**
     * The IUnitTestHandler interface defines a handler for running a single unit test.
     */
    class IUnitTestHandler
    {
    public :
        IUnitTestHandler();
        virtual ~IUnitTestHandler();

        /**
         * Runs the unit test.
         */
        virtual void run() = 0;

    private:
        /**
         * Disables the constructor and the assignment operator.
         */
        IUnitTestHandler(const IUnitTestHandler& rhs);
        IUnitTestHandler& operator=(const IUnitTestHandler& rhs);
    };

    /**
     * The IUnitTestHandler constructor.
     */
    inline IUnitTestHandler::IUnitTestHandler()
    {
    }

    /**
     * The IUnitTestHandler destructor.
     */
    inline IUnitTestHandler::~IUnitTestHandler()
    {
    }
}

#endif // I_UNIT_TEST_HANDLER_H_468be4fa_4f37_478b_8e29_79004d0ad18a
