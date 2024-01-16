#include "TabularHeaderParser.h"
#include "SmartPointers.h"
#include "TabularHeader.h"
#include "TabularDataException.h"

using namespace TabularData;

/**
 * Creates a Tabular Header Parser.
 */
ITabularHeaderParserSharedPtr TabularHeaderParser::Make(
    ParsingPolicyType parsingPolicyType,
    ITokensParserSharedPtr tokenParser, 
    IEventLogSharedPtr eventLog)
{ 
    return std::make_shared<TabularHeaderParser>(
        parsingPolicyType, 
        tokenParser,
        eventLog);
}

/**
 * The TabularHeaderParser constructor.
 */
TabularHeaderParser::TabularHeaderParser(
    ParsingPolicyType parsingPolicyType, 
    ITokensParserSharedPtr tokenParser,
    IEventLogSharedPtr eventLog) : 
    m_parsingPolicyType(parsingPolicyType)
{ 
    base::SmartPointers::Validate<ITokensParser>(tokenParser);
    base::SmartPointers::Validate<IEventLog>(eventLog);

    m_tokenParser = tokenParser;
    m_eventLog = eventLog;
}

/**
 * The TabularHeaderParser destructor.
 */
TabularHeaderParser::~TabularHeaderParser() 
{
}

/**
 * Parses a header.
 */
ITabularHeaderSharedPtr TabularHeaderParser::Parse(const std::wstring& content) const 
{
    //
    // Parse tokens of header...
    //
    std::vector<std::wstring> tokens;
    bool status = m_tokenParser->Parse(content, tokens);

    if (!status) {
        if (m_parsingPolicyType == ParsingPolicyType::FAIL_ON_FIRST_ERROR) {
            long errorCode = base::ErrorCodes::INVALID_ARG;

            std::wstringstream errorMessageStream;
            errorMessageStream 
                << L"The Tabular Header Parser has failed parsing tokens with content: " << content
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw TabularDataException(errorCode, errorMessage);
        } 
        else {
            return nullptr;
        }
    }

    //
    // Create a header...
    //
    return TabularHeader::Make(tokens);
}
