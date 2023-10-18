#include "StringEquality.h"
#include "Indexes.h"
#include <assert.h>

using namespace base;

/**
 * Checks whether strings are equals. (Ignore case)
 */
bool StringEquality::AreEqualIgnoreCase(
    const std::wstring& left,
    const std::wstring& right)
{
    if (left.size() != right.size())
    {
        return false;
    }

    if (left.empty() && right.empty())
    {
        return true;
    }

    return AreEqual(
        left, 0, left.size() - 1,
        right, 0, right.size() - 1,
        true);
}

/**
 * Checks whether strings are equals with start and End indexes.
 */
bool StringEquality::AreEqual(
    const std::wstring& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return AreEqual(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        false);
}

/**
 * Checks whether strings are equals with start and End indexes. (Ignore case)
 */
bool StringEquality::AreEqualIgnoreCase(
    const std::wstring& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return AreEqual(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        true);
}

/**
 * Checks whether strings are equals with start index and length.
 */
bool StringEquality::AreEqual(
    const std::wstring& left,
    size_t leftStartIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t length)
{
    return AreEqual(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        false);
}

/**
 * Checks whether strings are equals with start index and length. (Ignore case)
 */
bool StringEquality::AreEqualIgnoreCase(
    const std::wstring& left,
    size_t leftStartIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t length)
{
    return AreEqual(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        true);
}

/**
 * Checks whether buffer strings are equals with start and End indexes.
 */
bool StringEquality::AreEqual(
    const std::wstring::value_type* left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring::value_type* right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return AreEqual(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        false);
}

/**
 * Checks whether buffer strings are equals with start and End indexes. (Ignore case)
 */
bool StringEquality::AreEqualIgnoreCase(
    const std::wstring::value_type* left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring::value_type* right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return AreEqual(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        true);
}

/**
 * Checks whether buffer strings are equals with start index and length.
 */
bool StringEquality::AreEqual(
    const std::wstring::value_type* left,
    size_t leftStartIndex,
    const std::wstring::value_type* right,
    size_t rightStartIndex,
    size_t length)
{
    return AreEqual(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        false);
}

/**
 * Checks whether buffer strings are equals with start index and length. (Ignore case)
 */
bool StringEquality::AreEqualIgnoreCase(
    const std::wstring::value_type* left,
    size_t leftStartIndex,
    const std::wstring::value_type* right,
    size_t rightStartIndex,
    size_t length)
{
    return AreEqual(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        true);
}

/**
 * Checks whether strings are equals with start and End indexes.
 */
bool StringEquality::AreEqual(
    const std::wstring& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t rightEndIndex,
    bool ignoreCase)
{
    const std::wstring::value_type* leftStr = left.c_str();
    const std::wstring::value_type* rightStr = right.c_str();

    return AreEqual(
        leftStr, leftStartIndex, leftEndIndex,
        rightStr, rightStartIndex, rightEndIndex,
        ignoreCase);
}

/**
 * Checks whether strings are equals with start index and length.
 */
bool StringEquality::AreEqual(
    const std::wstring& left,
    size_t leftStartIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t length,
    bool ignoreCase)
{
    const std::wstring::value_type* leftStr = left.c_str();
    const std::wstring::value_type* rightStr = right.c_str();

    return AreEqual(
        leftStr, leftStartIndex,
        rightStr, rightStartIndex,
        length,
        ignoreCase);
}

/**
 * Checks whether buffer strings are equals with start and End indexes.
 */
bool StringEquality::AreEqual(
    const wchar_t* left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const wchar_t* right,
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

    size_t leftLength = Indexes::Size(leftStartIndex, leftEndIndex);
    size_t rightLength = Indexes::Size(rightStartIndex, rightEndIndex);

    if (leftLength != rightLength) {
        return false;
    }

    size_t length = leftLength;

    return AreEqual(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        ignoreCase);
}

/**
 * Checks whether buffer strings are equals with start index and length.
 */
bool StringEquality::AreEqual(
    const std::wstring::value_type* left,
    size_t leftStartIndex,
    const std::wstring::value_type* right,
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
        wchar_t leftValue = left[leftIndex];
        wchar_t rightValue = right[rightIndex];

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
