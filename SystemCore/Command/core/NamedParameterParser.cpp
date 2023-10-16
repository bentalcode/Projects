#include "NamedParameterParser.h"
#include "ParsingResult.h"
#include "StringSearch.h"
#include "StringEquality.h"
#include "Indexes.h"
#include "CommandConstants.h"

using namespace command;

/**
 * The NamedParameterParser constructor.
 */
NamedParameterParser::NamedParameterParser()
{
}

/**
 * The NamedParameterParser destructor.
 */
NamedParameterParser::~NamedParameterParser()
{
}

/**
 * Parses a named parameter.
 */
IParsingResultSharedPtr<base::PairSharedPtr<std::wstring, std::wstring>> NamedParameterParser::Parse(const std::wstring& arg)
{
    if (isShortNamedParameter(arg))
    {
        if (base::StringEquality::AreEqualIgnoreCase(
                arg, CommandConstants::SHORT_NAMED_PARAMETER_PREFIX.size(), arg.size() - 1,
                CommandConstants::HELP_SHORT_NAME, 0, CommandConstants::HELP_SHORT_NAME.size() - 1))
        {
            base::PairSharedPtr<std::wstring, std::wstring> nameAndValue = base::Pair<std::wstring, std::wstring>::Make(
                CommandConstants::HELP_SHORT_NAME,
                CommandConstants::TRUE_VALUE);

            return ParsingResult<base::PairSharedPtr<std::wstring, std::wstring>>::SuccessfulResult(nameAndValue);
        }
        else
        {
            return parseNamedParameter(arg, CommandConstants::SHORT_NAMED_PARAMETER_PREFIX);
        }
    }
    else if (isLongNamedParameter(arg))
    {
        if (base::StringEquality::AreEqualIgnoreCase(
                arg, CommandConstants::LONG_NAMED_PARAMETER_PREFIX.length(), arg.length() - 1,
                CommandConstants::HELP_LONG_NAME, 0, CommandConstants::HELP_LONG_NAME.length() - 1))
        {
            base::PairSharedPtr<std::wstring, std::wstring> nameAndValue = base::Pair<std::wstring, std::wstring>::Make(
                CommandConstants::HELP_LONG_NAME,
                CommandConstants::TRUE_VALUE);

            return ParsingResult<base::PairSharedPtr<std::wstring, std::wstring>>::SuccessfulResult(nameAndValue);
        }
        else
        {
            return parseNamedParameter(arg, CommandConstants::LONG_NAMED_PARAMETER_PREFIX);
        }
    }
    else
    {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"The argument: " << arg << L" is not a named parameter"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        return ParsingResult<base::PairSharedPtr<std::wstring, std::wstring>>::FailureResult(errorMessage);
    }
}

/**
 * Parses a named parameter.
 */
IParsingResultSharedPtr<base::PairSharedPtr<std::wstring, std::wstring>> NamedParameterParser::parseNamedParameter(
    const std::wstring& arg,
    const std::wstring& prefix)
{
    std::wstring::size_type separatorIndex = arg.find(CommandConstants::NAMED_PARAMETER_SEPARATOR);

    std::wstring name;
    std::wstring value;

    if (separatorIndex == std::wstring::npos)
    {
        //
        // This is a flag parameter...
        //
        size_t nameStartIndex = prefix.size();
        size_t nameEndIndex = arg.length() - 1;
        size_t nameLength = base::Indexes::Size(nameStartIndex, nameEndIndex);

        name = arg.substr(nameStartIndex, nameLength);
    }
    else
    {
        //
        // This is a named parameter...
        //
        size_t nameStartIndex = prefix.size();
        size_t nameEndIndex = separatorIndex - 1;
        size_t nameLength = base::Indexes::Size(nameStartIndex, nameEndIndex);

        size_t valueStartIndex = separatorIndex + CommandConstants::NAMED_PARAMETER_SEPARATOR.size();
        size_t valueEndIndex = arg.length() - 1;
        size_t valueLength = base::Indexes::Size(valueStartIndex, valueEndIndex);

        name = arg.substr(nameStartIndex, nameLength);
        value = arg.substr(valueStartIndex, valueLength);
    }

    base::PairSharedPtr<std::wstring, std::wstring> namedParameter = base::Pair<std::wstring, std::wstring>::Make(name, value);
    return ParsingResult<base::PairSharedPtr<std::wstring, std::wstring>>::SuccessfulResult(namedParameter);
}

/**
 * Checks if a parameter is named parameter.
 */
bool NamedParameterParser::IsNamedParameter(const std::wstring& arg)
{
    return isShortNamedParameter(arg) || isLongNamedParameter(arg);
}

/**
 * Checks if a parameter is short named parameter.
 */
bool NamedParameterParser::isShortNamedParameter(const std::wstring& arg)
{
    return
            base::StringSearch::StartsWith(arg, CommandConstants::SHORT_NAMED_PARAMETER_PREFIX) &&
            !base::StringSearch::StartsWith(arg, CommandConstants::LONG_NAMED_PARAMETER_PREFIX);
}

/**
 * Checks if a parameter is long named parameter.
 */
bool NamedParameterParser::isLongNamedParameter(const std::wstring& arg)
{
    return base::StringSearch::StartsWith(arg, CommandConstants::LONG_NAMED_PARAMETER_PREFIX);
}
