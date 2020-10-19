#include "PreCompiled.h"
#include "RandomGenerator.h"

using namespace base;

/**
 * The RandomGenerator constructor.
 */
RandomGenerator::RandomGenerator()
{
}

/**
 * The RandomGenerator destructor.
 */
RandomGenerator::~RandomGenerator()
{
}

/**
 * Generates a new boolean.
 */
bool RandomGenerator::nextBoolean()
{
    return true;
}

/**
 * Generates a new integer.
 */
int RandomGenerator::nextInteger()
{
    return 0;
}

/**
 * Generates a new integer between the following specified values (inclusively).
 */
int RandomGenerator::nextInteger(int from, int to)
{
    return 0;
}

/**
 * Generates a new size.
 */
size_t RandomGenerator::nextSizeT()
{
    return 0;
}

/**
 * Generates a new size between the following specified values (inclusively).
 */
size_t RandomGenerator::nextSizeT(size_t from, size_t to)
{
    return 0;
}

/**
 * Generates a new float.
 */
float RandomGenerator::nextFloat()
{
    return 0.0;
}

/**
 * Generates a new double between the following specified values (inclusively).
 */
float RandomGenerator::nextFloat(float from, float to)
{
    return 0.0;
}
