#include "PreCompiled.h"

#include "NumberValidator.h"
#include "Strings.h"

using namespace problems;

/**
 * The constructor.
 */
NumberValidator::NumberValidator(const std::string& str) :
    m_str(str)
{
}

/**
 * Validates a number.
 *
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 */
bool NumberValidator::validate() const
{
    if (m_str.empty())
    {
        return false;
    }

    std::string data = base::Strings::trimCopy(m_str);

    std::string::size_type exponentPosition = std::string::npos;

    std::string::size_type currIndex = 0;
    for (std::string::value_type currValue : data)
    {
        if (!isCharacterValid(currValue))
        {
            return false;
        }

        if (isExponent(currValue))
        {
            if (exponentPosition != std::string::npos)
            {
                return false;
            }

            exponentPosition = currIndex;
        }

        ++currIndex;
    }

    if (exponentPosition != std::string::npos)
    {
        return
            validateNumberComponent(data, 0, exponentPosition - 1, false) &&
            validateNumberComponent(data, exponentPosition + 1, data.size() - 1, true);
    }
    else
    {
        return validateNumberComponent(data, 0, data.size() - 1, false);
    }
}

/**
 * Validates that a number component is valid.
 */
 bool NumberValidator::validateNumberComponent(
    const std::string& data,
    std::string::size_type startIndex,
    std::string::size_type endIndex,
    bool componentAfterExponent) const
{
    if (startIndex > endIndex)
    {
        return false;
    }

    if (startIndex == endIndex)
    {
        return isDigit(data[startIndex]);
    }

    bool foundDecimalPoint = false;

    for (std::string::size_type i = startIndex; i <= endIndex; ++i)
    {
        std::string::value_type currValue = data[i];

        if (isPlus(currValue) || isMinus(currValue))
        {
            if (i > startIndex)
            {
                return false;
            }
        }
        else if (isDecimalPoint(currValue))
        {
            if (foundDecimalPoint || i == endIndex || componentAfterExponent)
            {
                return false;
            }

            foundDecimalPoint = true;
        }
        else
        {
            if (!isDigit(currValue))
            {
                return false;
            }
        }
    }

    return true;
}

/**
 * Checks whether a character is valid.
 */
bool NumberValidator::isCharacterValid(char value) const
{
    return
        isDigit(value) ||
        isPlus(value) ||
        isMinus(value) ||
        isExponent(value) ||
        isDecimalPoint(value);
}

/**
 * Checks whether a character is a digit.
 */
bool NumberValidator::isDigit(char value) const
{
    return value >= '0' && value <= '9';
}

/**
 * Checks whether a character is a plus.
 */
bool NumberValidator::isPlus(char value) const
{
    return value == '+';
}

/**
 * Checks whether a character is a minus.
 */
bool NumberValidator::isMinus(char value) const
{
    return value == '-';
}

/**
 * Checks whether a character is an exponent.
 */
bool NumberValidator::isExponent(char value) const
{
    return value == 'e';
}

/**
 * Checks whether a character is a decimal point.
 */
bool NumberValidator::isDecimalPoint(char value) const
{
    return value == '.';
}
