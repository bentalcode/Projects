#include "StringComparable.h"
#include "Indexes.h"
#include <assert.h>

using namespace base;

/**
 * Compares strings with start and End indexes.
 */
int StringComparable::Compare(
    const std::wstring& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return Compare(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        false);
}

/**
 * Compares strings with start and End indexes. (Ignore case)
 */
int StringComparable::CompareIgnoreCase(
    const std::wstring& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return Compare(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        true);
}

/**
 * Compares strings with start index and length.
 */
int StringComparable::Compare(
    const std::wstring& left,
    size_t leftStartIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t length)
{
    return Compare(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        false);
}

/**
 * Compares strings with start index and length. (Ignore case)
 */
int StringComparable::CompareIgnoreCase(
    const std::wstring& left,
    size_t leftStartIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t length)
{
    return Compare(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        true);
}

/**
 * Compares buffer strings with start and End indexes.
 */
int StringComparable::Compare(
    wchar_t left[],
    size_t leftStartIndex,
    size_t leftEndIndex,
    wchar_t right[],
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return Compare(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        false);
}

/**
 * Compares buffer strings with start and End indexes. (Ignore case)
 */
int StringComparable::CompareIgnoreCase(
    wchar_t left[],
    size_t leftStartIndex,
    size_t leftEndIndex,
    wchar_t right[],
    size_t rightStartIndex,
    size_t rightEndIndex)
{
    return Compare(
        left, leftStartIndex, leftEndIndex,
        right, rightStartIndex, rightEndIndex,
        true);
}

/**
 * Compares buffer strings with start index and length.
 */
int StringComparable::Compare(
    wchar_t left[],
    size_t leftStartIndex,
    wchar_t right[],
    size_t rightStartIndex,
    size_t length)
{
    return Compare(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        false);
}

/**
 * Compares buffer strings with start index and length. (Ignore case)
 */
int StringComparable::CompareIgnoreCase(
    wchar_t left[],
    size_t leftStartIndex,
    wchar_t right[],
    size_t rightStartIndex,
    size_t length)
{
    return Compare(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        true);
}

/**
 * Compares strings with start and End indexes.
 */
int StringComparable::Compare(
    const std::wstring& left,
    size_t leftStartIndex,
    size_t leftEndIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t rightEndIndex,
    bool ignoreCase)
{
    return Compare(
        left.c_str(), leftStartIndex, leftEndIndex,
        right.c_str(), rightStartIndex, rightEndIndex,
        ignoreCase);
}

/**
 * Compares strings with start index and length.
 */
int StringComparable::Compare(
    const std::wstring& left,
    size_t leftStartIndex,
    const std::wstring& right,
    size_t rightStartIndex,
    size_t length,
    bool ignoreCase)
{
    return Compare(
        left.c_str(), leftStartIndex,
        right.c_str(), rightStartIndex,
        length,
        ignoreCase);
}

/**
 * Compares buffer strings with start and End indexes.
 */
int StringComparable::Compare(
    wchar_t left[],
    size_t leftStartIndex,
    size_t leftEndIndex,
    wchar_t right[],
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

    if (leftLength < rightLength) {
        return -1;
    }

    if (leftLength > rightLength) {
        return 1;
    }

    size_t length = leftLength;

    return Compare(
        left, leftStartIndex,
        right, rightStartIndex,
        length,
        ignoreCase);
}

/**
 * Compares buffer strings with start index and length.
 */
int StringComparable::Compare(
    wchar_t left[],
    size_t leftStartIndex,
    wchar_t right[],
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

        if (leftValue < rightValue) {
            return -1;
        }

        if (leftValue > rightValue) {
            return 1;
        }

        ++leftIndex;
        ++rightIndex;
        ++counter;
    }

    assert(counter == length);
    return 0;
}
