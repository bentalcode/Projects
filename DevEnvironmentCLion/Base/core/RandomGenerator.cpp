#include "PreCompiled.h"
#include "RandomGenerator.h"
#include "Dimensions.h"
#include "Range.h"

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
    int randomIndex = rand() % 2;
    return randomIndex == 0 ? false : true;
}

/**
 * Generates a new integer.
 */
int RandomGenerator::nextInteger()
{
    return rand();
}

/**
 * Generates a new integer between the following specified values (inclusively).
 */
int RandomGenerator::nextInteger(int from, int to)
{
    Range<int>::validate(from, to);

    if (from == to)
    {
        return from;
    }

    int length = base::Dimensions::indexes(from, to);

    length = base::Dimensions::indexes(from, to);
    int result = from + rand() % length;

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new size.
 */
size_t RandomGenerator::nextSizeT()
{
    return rand();
}

/**
 * Generates a new size between the following specified values (inclusively).
 */
size_t RandomGenerator::nextSizeT(size_t from, size_t to)
{
    Range<int>::validate(from, to);

    if (from == to)
    {
        return from;
    }

    size_t length = base::Dimensions::indexes(from, to);
    size_t result = from + rand() % length;

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new float.
 */
float RandomGenerator::nextFloat()
{
    return nextFloat(0.0, RAND_MAX);
}

/**
 * Generates a new double between the following specified values (inclusively).
 */
float RandomGenerator::nextFloat(float from, float to)
{
    Range<int>::validate(from, to);

    if (from == to)
    {
        return from;
    }

    float range = to - from;
    float result = from + (range * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)));

    assert(result >= from && result <= to);

    return result;
}
