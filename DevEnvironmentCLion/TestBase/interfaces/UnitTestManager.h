#ifndef UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389
#define UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389

#include "IUnitTest.h"
#include "IUnitTestManager.h"

namespace test_base
{
    /**
     * The UnitTestManager class implements a unit test manager.
     */
    class UnitTestManager : public IUnitTestManager
    {
    public :
        UnitTestManager();
        virtual ~UnitTestManager();

        /**
         * Registers a test.
         */
        virtual void registerTest(IUnitTestPtr unitTest);

        /**
         * Unregisters a test.
         */
        virtual void unregisterTest(IUnitTestPtr unitTest);

        /**
         * Runs the registered tests.
         */
        virtual void run();

    private:
        /**
         * Disables the constructor and the assignment operator.
         */
        UnitTestManager(const UnitTestManager& rhs);
        UnitTestManager& operator=(const UnitTestManager& rhs);

        typedef std::list<IUnitTestPtr> UnitTestList;
        UnitTestList m_unitTests;
    };
}

#endif // UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389
