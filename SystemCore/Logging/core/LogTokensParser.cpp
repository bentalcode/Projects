#include "LogTokensParser.h"
#include "ErrorCodes.h"
#include "Indexes.h"
#include "StringUtils.h"
#include <assert.h>

using namespace logging;

const std::wstring LogTokensParser::SPACE_REGEX = 
    L"[ \\t]+";

const std::wstring LogTokensParser::LINE_INDEX_REGEX = 
    L"([0-9]+)";

const std::wstring LogTokensParser::TIME_REGEX1 = 
    L"([0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}.[0-9]{3})";

const std::wstring LogTokensParser::TIME_REGEX2 = 
    L"([0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2})";

const std::wstring LogTokensParser::THREAD_ID_REGEX = 
    L"([0-9]{1,10})";

const std::wstring LogTokensParser::COMPONENT_REGEX = 
    L"([a-zA-Z0-9.-_]+)";

const std::wstring LogTokensParser::LOG_LEVEL_REGEX =
    L"(TL_NONE|TL_FATAL|TL_ERROR|TL_WARN|TL_INFO|TL_VERBOSE|TL_NOISE|TL_COMPID)";

const std::wstring LogTokensParser::FUNCTION_REGEX = 
    L"(<none>\\(\\)|[a-zA-Z_\\-0-9]+\\(\\))";

const std::wstring LogTokensParser::SHARED_MEMORY_REGEX = 
    L"\\[([0-9a-fA-F]{8,16})\\]:";

const std::wstring LogTokensParser::MESSAGE_REGEX = 
    L"(.*)";

const std::wstring LogTokensParser::FILE_LINE_REGEX = 
    L"\\((<none>|[\\:a-zA-Z0-9._-]+):([0-9]+)\\)";

const std::wstring LogTokensParser::REGEX_SEPERATOR1 = 
    LINE_INDEX_REGEX +      // Line Number
    SPACE_REGEX +           // Space
    TIME_REGEX1 +           // Time
    SPACE_REGEX +           // Space
    THREAD_ID_REGEX +       // Thread
    SPACE_REGEX +           // Space
    COMPONENT_REGEX +       // Component
    SPACE_REGEX +           // Space
    LOG_LEVEL_REGEX +       // Level
    SPACE_REGEX +           // Space
    FUNCTION_REGEX +        // Function
    SPACE_REGEX +           // Space
    SHARED_MEMORY_REGEX +   // Shared Memory
    SPACE_REGEX +           // Space
    MESSAGE_REGEX;          // Message

const std::wstring LogTokensParser::REGEX_SEPERATOR2 = 
    LINE_INDEX_REGEX +      // Line Number
    SPACE_REGEX +           // Space
    TIME_REGEX2 +           // Time
    SPACE_REGEX +           // Space
    THREAD_ID_REGEX +       // Thread
    SPACE_REGEX +           // Space
    COMPONENT_REGEX +       // Component
    SPACE_REGEX +           // Space
    LOG_LEVEL_REGEX +       // Level
    SPACE_REGEX +           // Space
    FUNCTION_REGEX +        // Function
    SPACE_REGEX +           // Space
    SHARED_MEMORY_REGEX +   // Shared Memory
    SPACE_REGEX +           // Space
    MESSAGE_REGEX;          // Message

/**
 * Creates default regex seperators.
 */
std::vector<std::wstring> LogTokensParser::CreateDefaultRegexSeperators()
{
    return { REGEX_SEPERATOR1, REGEX_SEPERATOR2 };
}

/**
 * Creates a Log Tokens Parser.
 */
tabular_data::ITokensParserSharedPtr LogTokensParser::Make(const std::vector<std::wstring> regexSeparators)
{
    return std::make_shared<LogTokensParser>(regexSeparators);
}

/**
 * The LogTokensParser constructor.
 */
LogTokensParser::LogTokensParser(const std::vector<std::wstring>& regexSeparators) : 
    m_regexSeparators(regexSeparators)
{
}

/**
 * The LogTokensParser destructor.
 */
LogTokensParser::~LogTokensParser() 
{
}

/**
 * Parses tokens.
 */
bool LogTokensParser::Parse(
    const std::wstring& content, 
    std::vector<std::wstring>& tokens) const
{
    assert(tokens.empty());

    //
    // Trim the content...
    //
    std::wstring contentToParse = content; 
    base::StringUtils::Trim(contentToParse);

    //
    // Extract file/line tokens since the last component is generic...
    //
    std::wstring fileToken;
    std::wstring lineToken;
    contentToParse = ExtractFileLineTokens(
        contentToParse,
        fileToken, 
        lineToken);

    //
    // Parse the tokens by using regex and append the file/line tokens...
    //
    for (const std::wstring& regexSeperator : m_regexSeparators) {
        
        bool status = Parse(
            contentToParse, 
            regexSeperator, 
            tokens);

        if (status) {
            tokens.push_back(fileToken);
            tokens.push_back(lineToken);
            
            return true;
        }
    }

    return false;
}

/**
 * Parses tokens.
 */
bool LogTokensParser::Parse(
    const std::wstring& content, 
    const std::wstring& regexSeperator,
    std::vector<std::wstring>& tokens)
{
    assert(tokens.empty());

    std::wsmatch matches;
    std::wregex regex(regexSeperator);
    if (!std::regex_search(content, matches, regex)) {
        return false;
    }

    for (size_t index = 1; index < matches.size(); ++index) {
        std::wstring token = matches.str(index);
        tokens.push_back(token);
    }

    return true;
}

/**
 * Extracts file/line tokens.
 */
std::wstring LogTokensParser::ExtractFileLineTokens(
    const std::wstring& content, 
    std::wstring& fileToken, 
    std::wstring& lineToken)
{
    //
    // Find the file line token...
    //
    size_t length = content.size();
    size_t startParenthesisIndex = content.find_last_of('(');
    size_t endParenthesisIndex = content.find_last_of(')');

    if (!(startParenthesisIndex != std::wstring::npos && 
          endParenthesisIndex != std::wstring::npos &&
          startParenthesisIndex < endParenthesisIndex && 
          endParenthesisIndex == length - 1)) {
        
        return content;
    }

    size_t fileLineTokenStartIndex = startParenthesisIndex + 1;
    size_t fileLineTokenEndIndex = endParenthesisIndex - 1;
    size_t fileLineTokenLength = base::Indexes::Size<size_t>(fileLineTokenStartIndex, fileLineTokenEndIndex);
    std::wstring fileLineToken = content.substr(fileLineTokenStartIndex, fileLineTokenLength);

    //
    // Find the seperator of file/line token...
    //
    size_t seperatorIndex = fileLineToken.find_last_of(':');

    if (seperatorIndex == std::wstring::npos)
    {
        return content;
    }

    //
    // Find the file token...
    //
    size_t fileTokenStartIndex = 0;
    size_t fileTokenEndIndex = seperatorIndex - 1;
    size_t fileTokenLength = base::Indexes::Size<size_t>(fileTokenStartIndex, fileTokenEndIndex);

    fileToken = fileLineToken.substr(fileTokenStartIndex, fileTokenLength);

    //
    // Find the line token...
    //
    size_t lineTokenStartIndex = seperatorIndex + 1;
    size_t lineTokenEndIndex = fileLineToken.size() - 1;
    size_t lineTokenLength = base::Indexes::Size<size_t>(lineTokenStartIndex, lineTokenEndIndex);

    lineToken = fileLineToken.substr(lineTokenStartIndex, lineTokenEndIndex);

    //
    // Extract result with out the file/line tokens...
    //
    size_t resultStartIndex = 0;
    size_t resultEndIndex = startParenthesisIndex - 1;
    size_t resultLength = base::Indexes::Size<size_t>(resultStartIndex, resultEndIndex);

    std::wstring result = content.substr(resultStartIndex, resultLength);
    base::StringUtils::TrimFromRight(result);

    return result;
}