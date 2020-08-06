#include "PreCompiled.h"
#include "StringEquality.h"
#include "Dimensions.h"

using namespace base;

/**
 * Checks whether strings are equals with start and end indexes.
 */
bool StringEquality::equals(
    const std::string& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::string& right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return equals(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        false);
}

/**
 * Checks whether strings are equals with start and end indexes. (Ignore case)
 */
bool StringEquality::equalsIgnoreCase(
    const std::string& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::string& right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return equals(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        true);
}

/**
 * Checks whether strings are equals with start index and length.
 */
bool StringEquality::equals(
    const std::string& left,
    size_t leftStartIndex,
    const std::string& right,
    size_t rightStartIndex,
    size_t length)
{
    return equals(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        false);
}

/**
 * Checks whether strings are equals with start index and length. (Ignore case)
 */
bool StringEquality::equalsIgnoreCase(
    const std::string& left,
    size_t leftStartIndex,
    const std::string& right,
    size_t rightStartIndex,
    size_t length)
{
    return equals(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        true);
}

/**
 * Checks whether buffer strings are equals with start and end indexes.
 */
bool StringEquality::equals(
    char left[],
    size_t leftStartIndex,
    size_t leftEndIndex,
    char right[],
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return equals(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        false);
}

/**
 * Checks whether buffer strings are equals with start and end indexes. (Ignore case)
 */
bool StringEquality::equalsIgnoreCase(
    char left[],
    size_t leftStartIndex,
    size_t leftEndIndex,
    char right[],
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return equals(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        true);
}

/**
 * Checks whether buffer strings are equals with start index and length.
 */
bool StringEquality::equals(
    char left[],
    size_t leftStartIndex,
    char right[],
    size_t rightStartIndex,
    size_t length)
{
    return equals(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        false);
}

/**
 * Checks whether buffer strings are equals with start index and length. (Ignore case)
 */
bool StringEquality::equalsIgnoreCase(
    char left[],
    size_t leftStartIndex,
    char right[],
    size_t rightStartIndex,
    size_t length)
{
    return equals(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        true);
}

/**
 * Checks whether strings are equals with start and end indexes.
 */
bool StringEquality::equals(
    const std::string& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::string& right,
    size_t rightStartIndex,
    size_t rightEndIndex,
    bool ignoreCase)
{
    return equals(
        left.c_str(), leftStartIndex, leftEndIndex,
        right.c_str(), rightStartIndex, rightEndIndex,
        ignoreCase);
}

/**
 * Checks whether strings are equals with start index and length.
 */
bool StringEquality::equals(
    const std::string& left,
    size_t leftStartIndex,
    const std::string& right,
    size_t rightStartIndex,
    size_t length,
    bool ignoreCase)
{
    return equals(
        left.c_str(), leftStartIndex,
        right.c_str(), rightStartIndex,
        length,
        ignoreCase);
}

/**
 * Checks whether buffer strings are equals with start and end indexes.
 */
bool StringEquality::equals(
    char left[],
    size_t leftStartIndex,
    size_t leftEndIndex,
    char right[],
    size_t rightStartIndex,
    size_t rightEndIndex,
    bool ignoreCase)
{
    assert(left != nullptr);
    assert(right != nullptr);
    assert(leftStartIndex >= 0);
    assert(leftEndIndex >= leftStartIndex);
    assert(rightStartIndex >= 0);
    assert(rightEndIndex >= rightStartIndex);

    size_t leftLength = Dimensions::length(leftStartIndex, leftEndIndex);
    size_t rightLength = Dimensions::length(rightStartIndex, rightEndIndex);

    if (leftLength != rightLength) {
        return false;
    }

    size_t length = leftLength;

    return equals(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        ignoreCase);
}

/**
 * Checks whether buffer strings are equals with start index and length.
 */
bool StringEquality::equals(
    char left[],
    size_t leftStartIndex,
    char right[],
    size_t rightStartIndex,
    size_t length,
    bool ignoreCase)
{
    assert(left != nullptr);
    assert(leftStartIndex >= 0);

    assert(right != nullptr);
    assert(rightStartIndex >= 0);

    size_t leftIndex = leftStartIndex;
    size_t rightIndex = rightStartIndex;

    size_t counter = 0;
    while (counter < length)
    {
        char leftValue = left[leftIndex];
        char rightValue = right[rightIndex];

        if (ignoreCase) {
            leftValue = std::tolower(leftValue);
            rightValue = std::tolower(rightValue);
        }

        if (leftValue != rightValue)
        {
            return false;
        }

        ++leftIndex;
        ++rightIndex;
        ++counter;
    }

    return counter == length;
}
