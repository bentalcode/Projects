#include "RandomGenerator.h"
#include "Indexes.h"
#include "Range.h"

using namespace base;

const size_t RandomGenerator::DEFAULT_STRING_MAX_LENGTH = 1000;

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
bool RandomGenerator::NextBoolean()
{
    int randomIndex = rand() % 2;
    return randomIndex == 0 ? false : true;
}

/**
 * Generates a new integer.
 */
int RandomGenerator::NextInteger()
{
    return rand();
}

/**
 * Generates a new integer between the following specified values (inclusively).
 */
int RandomGenerator::NextInteger(int from, int to)
{
    Range<int>::Validate(from, to);

    if (from == to)
    {
        return from;
    }

    int length = base::Indexes::Size(from, to);

    length = base::Indexes::Size(from, to);
    int result = from + rand() % length;

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new Size.
 */
size_t RandomGenerator::NextSizeT()
{
    return rand();
}

/**
 * Generates a new Size between the following specified values (inclusively).
 */
size_t RandomGenerator::NextSizeT(size_t from, size_t to)
{
    Range<size_t>::Validate(from, to);

    if (from == to)
    {
        return from;
    }

    size_t length = base::Indexes::Size(from, to);
    size_t result = from + rand() % length;

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new float.
 */
float RandomGenerator::NextFloat()
{
    return NextFloat(0.0, RAND_MAX);
}

/**
 * Generates a new float between the following specified values (inclusively).
 */
float RandomGenerator::NextFloat(float from, float to)
{
    Range<float>::Validate(from, to);

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
double RandomGenerator::NextDouble()
{
    return NextDouble(0.0, RAND_MAX);
}

/**
 * Generates a new double between the following specified values (inclusively).
 */
double RandomGenerator::NextDouble(double from, double to)
{
    Range<double>::Validate(from, to);

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
wchar_t RandomGenerator::NextCharacter()
{
    wchar_t fromCharacter = std::numeric_limits<wchar_t>::min();
    wchar_t toCharacter = std::numeric_limits<wchar_t>::max();

    return NextCharacter(
        fromCharacter,
        toCharacter);
}

/**
 * Generates a new character between the following specified values (inclusively).
 */
wchar_t RandomGenerator::NextCharacter(wchar_t from, wchar_t to) {
    Range<wchar_t>::Validate(from, to);

    int range = to - from;
    int randomRange = this->NextInteger(0, range);

    int randomResult = from + randomRange;
    wchar_t result = static_cast<wchar_t>(randomResult);

    assert(result >= from && result <= to);

    return result;
}

/**
 * Generates a new string.
 */
std::wstring RandomGenerator::NextString()
{
    size_t fromLength = 0;
    size_t toLength = RandomGenerator::DEFAULT_STRING_MAX_LENGTH;

    return NextString(
        fromLength,
        toLength);
}

/**
 * Generates a new string ignore case with a length between the specified lengths (inclusively).
 */
std::wstring RandomGenerator::NextString(size_t fromLength, size_t toLength)
{
    wchar_t fromCharacter = std::numeric_limits<wchar_t>::min();
    wchar_t toCharacter = std::numeric_limits<wchar_t>::max();

    return NextString(
        fromCharacter,
        toCharacter,
        fromLength,
        toLength);
}

/**
 * Generates a new string with characters between the specified range (inclusively),
 * and length between the specified lengths (inclusively).
 */
std::wstring RandomGenerator::NextString(
    wchar_t fromCharacter,
    wchar_t toCharacter,
    size_t fromLength,
    size_t toLength)
{
    Range<wchar_t>::Validate(fromCharacter, toCharacter);
    Range<size_t>::Validate(fromLength, toLength);

    size_t length = NextSizeT(fromLength, toLength);

    if (length == 0) {
        return L"";
    }

    std::wstring::value_type data[length];

    for (size_t i = 0; i < length; ++i) {
        data[i] = NextCharacter(fromCharacter, toCharacter);
    }

    std::wstring result(data);
    assert(result.size() >= fromLength && result.size() <= toLength);

    return result;
}
