#include "PreCompiled.h"
#include "RandomGenerator.h"
#include "Dimensions.h"
#include "Range.h"
#include "Conversion.h"

using namespace base;

const size_t RandomGenerator::defaultStringMaxLength = 1000;

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
    Range<size_t>::validate(from, to);

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
 * Generates a new float between the following specified values (inclusively).
 */
float RandomGenerator::nextFloat(float from, float to)
{
    Range<float>::validate(from, to);

    if (from == to)
    {
        return from;
    }

    float randomZeroToOne = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

    float range = to - from;
    float randomRange = range * randomZeroToOne;
    float result = from + randomRange;

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new double.
 */
double RandomGenerator::nextDouble()
{
    return nextDouble(0.0, RAND_MAX);
}

/**
 * Generates a new double between the following specified values (inclusively).
 */
double RandomGenerator::nextDouble(double from, double to)
{
    Range<double>::validate(from, to);

    if (from == to)
    {
        return from;
    }

    double randomZeroToOne = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);

    double range = to - from;
    double randomRange = range * randomZeroToOne;
    double result = from + randomRange;

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new character.
 */
char RandomGenerator::nextCharacter()
{
    char fromCharacter = std::numeric_limits<char>::min();
    char toCharacter = std::numeric_limits<char>::max();

    return nextCharacter(
        fromCharacter,
        toCharacter);
}

/**
 * Generates a new character between the following specified values (inclusively).
 */
char RandomGenerator::nextCharacter(char from, char to) {
    Range<char>::validate(from, to);

    int range = to - from;
    int randomRange = this->nextInteger(0, range);

    int randomResult = from + randomRange;
    char result = Conversion::integerConversion().toCharacter(randomResult);

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new string.
 */
std::string RandomGenerator::nextString()
{
    size_t fromLength = 0;
    size_t toLength = RandomGenerator::defaultStringMaxLength;

    return nextString(
        fromLength,
        toLength);
}

/**
 * Generates a new string ignore case with a length between the specified lengths (inclusively).
 */
std::string RandomGenerator::nextString(size_t fromLength, size_t toLength)
{
    char fromCharacter = std::numeric_limits<char>::min();
    char toCharacter = std::numeric_limits<char>::max();

    return nextString(
        fromCharacter,
        toCharacter,
        fromLength,
        toLength);
}

/**
 * Generates a new string with characters between the specified range (inclusively),
 * and length between the specified lengths (inclusively).
 */
std::string RandomGenerator::nextString(
    char fromCharacter,
    char toCharacter,
    size_t fromLength,
    size_t toLength)
{
    Range<char>::validate(fromCharacter, toCharacter);
    Range<size_t>::validate(fromLength, toLength);

    size_t length = nextSizeT(fromLength, toLength);

    if (length == 0) {
        return "";
    }

    std::string::value_type data[length];

    for (size_t i = 0; i < length; ++i) {
        data[i] = nextCharacter(fromCharacter, toCharacter);
    }

    std::string result(data);
    assert(result.size() >= fromLength && result.size() <= toLength);

    return result;
}
