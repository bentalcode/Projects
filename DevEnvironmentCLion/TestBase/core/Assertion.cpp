#include "PreCompiled.h"

#include "Assertion.h"

using namespace test_base;

/**
 * The Assertion constructor.
 */
Assertion::Assertion()
{
}

/**
 * The Assertion destructor.
 */
Assertion::~Assertion()
{
}

/**
 * Asserts true.
 */
void Assertion::assertTrue(
    bool expression,
    const std::string& message)
{
    assert(expression);
}
