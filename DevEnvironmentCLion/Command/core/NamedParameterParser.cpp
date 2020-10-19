#include "PreCompiled.h"
#include "NamedParameterParser.h"
#include "ParsingResult.h"
#include "StringSearch.h"
#include "StringEquality.h"
#include "Dimensions.h"
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
base::IParsingResultPtr<base::PairPtr<std::string, std::string>> NamedParameterParser::parse(const std::string& arg)
{
    if (isShortNamedParameter(arg))
    {
        if (base::StringEquality::equalsIgnoreCase(
                arg, CommandConstants::shortNamedParameterPrefix.size(), arg.size() - 1,
                CommandConstants::helpShortName, 0, CommandConstants::helpShortName.size() - 1))
        {
            base::PairPtr<std::string, std::string> nameAndValue = base::Pair<std::string, std::string>::make(
                CommandConstants::helpShortName,
                CommandConstants::trueValue);

            return base::ParsingResult<base::PairPtr<std::string, std::string>>::successfulResult(nameAndValue);
        }
        else
        {
            return parseNamedParameter(arg, CommandConstants::shortNamedParameterPrefix);
        }
    }
    else if (isLongNamedParameter(arg))
    {
        if (base::StringEquality::equalsIgnoreCase(
                arg, CommandConstants::longNamedParameterPrefix.length(), arg.length() - 1,
                CommandConstants::helpLongName, 0, CommandConstants::helpLongName.length() - 1))
        {
            base::PairPtr<std::string, std::string> nameAndValue = base::Pair<std::string, std::string>::make(
                CommandConstants::helpLongName,
                CommandConstants::trueValue);

            return base::ParsingResult<base::PairPtr<std::string, std::string>>::successfulResult(nameAndValue);
        }
        else
        {
            return parseNamedParameter(arg, CommandConstants::longNamedParameterPrefix);
        }
    }
    else
    {
        std::string errorMessage = "The argument: " + arg + " is not a named parameter.";
        return base::ParsingResult<base::PairPtr<std::string, std::string>>::failureResult(errorMessage);
    }
}

/**
 * Parses a named parameter.
 */
base::IParsingResultPtr<base::PairPtr<std::string, std::string>> NamedParameterParser::parseNamedParameter(
    const std::string& arg,
    const std::string& prefix)
{
    std::string::size_type separatorIndex = arg.find(CommandConstants::namedParameterSeparator);

    std::string name;
    std::string value;

    if (separatorIndex == std::string::npos)
    {
        //
        // This is a flag parameter...
        //
        size_t nameStartIndex = prefix.size();
        size_t nameEndIndex = arg.length() - 1;
        size_t nameLength = base::Dimensions::length(nameStartIndex, nameEndIndex);

        name = arg.substr(nameStartIndex, nameLength);
    }
    else
    {
        //
        // This is a named parameter...
        //
        size_t nameStartIndex = prefix.size();
        size_t nameEndIndex = separatorIndex - 1;
        size_t nameLength = base::Dimensions::length(nameStartIndex, nameEndIndex);

        size_t valueStartIndex = separatorIndex + CommandConstants::namedParameterSeparator.size();
        size_t valueEndIndex = arg.length() - 1;
        size_t valueLength = base::Dimensions::length(valueStartIndex, valueEndIndex);

        name = arg.substr(nameStartIndex, nameLength);
        value = arg.substr(valueStartIndex, valueLength);
    }

    base::PairPtr<std::string, std::string> namedParameter = base::Pair<std::string, std::string>::make(name, value);
    return base::ParsingResult<base::PairPtr<std::string, std::string>>::successfulResult(namedParameter);
}

/**
 * Checks if a parameter is named parameter.
 */
bool NamedParameterParser::isNamedParameter(const std::string& arg)
{
    return isShortNamedParameter(arg) || isLongNamedParameter(arg);
}

/**
 * Checks if a parameter is short named parameter.
 */
bool NamedParameterParser::isShortNamedParameter(const std::string& arg)
{
    return
        base::StringSearch::startsWith(arg, CommandConstants::shortNamedParameterPrefix) &&
        !base::StringSearch::startsWith(arg, CommandConstants::longNamedParameterPrefix);
}

/**
 * Checks if a parameter is long named parameter.
 */
bool NamedParameterParser::isLongNamedParameter(const std::string& arg)
{
    return base::StringSearch::startsWith(arg, CommandConstants::longNamedParameterPrefix);
}
