#include "PreCompiled.h"

#include "UnitTestManager.h"

using namespace test_base;

class UnitTestPredicate //: public unary_function<IUnitTestPtr, bool>
{
public:
    UnitTestPredicate(const std::string& name) :
        m_name(name)
    {
    }

    bool operator()(IUnitTestPtr unitTest) {
        return m_name == unitTest->getName();
    }

private:
    std::string m_name;
};

/**
 * The UnitTestManager constructor.
 */
UnitTestManager::UnitTestManager()
{
}

/**
 * The UnitTestManager destructor.
 */
UnitTestManager::~UnitTestManager()
{
}

/**
 * Registers a test.
 */
void UnitTestManager::registerTest(IUnitTestPtr unitTest)
{
    m_unitTests.push_back(unitTest);
}

/**
 * Unregisters a test.
 */
void UnitTestManager::unregisterTest(IUnitTestPtr unitTest)
{
    UnitTestPredicate unitTestPredicate(unitTest->getName());
    m_unitTests.erase(
        remove_if(m_unitTests.begin(), m_unitTests.end(), unitTestPredicate),
        m_unitTests.end());
}

/**
 * Runs the registered tests.
 */
void UnitTestManager::run()
{
    for (UnitTestList::const_iterator i = m_unitTests.begin(); i != m_unitTests.end(); ++i) {
        IUnitTestPtr unitTest = *i;

        unitTest->preRun();
        unitTest->run();
        unitTest->postRun();
    }
}


