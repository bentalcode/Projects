#include "TabularRecordParser.h"
#include "SmartPointers.h"
#include "TabularRecord.h"
#include "TabularDataException.h"

using namespace TabularData;

/**
 * Creates a Tabular Record Parser.
 */
ITabularRecordParserSharedPtr TabularRecordParser::Make(
    ParsingPolicyType parsingPolicyType,
    ITokensParserSharedPtr tokenParser, 
    IEventLogSharedPtr eventLog)
{
    return std::make_shared<TabularRecordParser>(
        parsingPolicyType, 
        tokenParser, 
        eventLog);
}

/**
 * The TabularRecordParser constructor.
 */
TabularRecordParser::TabularRecordParser(
    ParsingPolicyType 
    parsingPolicyType, ITokensParserSharedPtr tokenParser,
    IEventLogSharedPtr eventLog) : 
    m_parsingPolicyType(parsingPolicyType)
{
    base::SmartPointers::Validate<ITokensParser>(tokenParser);
    base::SmartPointers::Validate<IEventLog>(eventLog);

    m_tokenParser = tokenParser;
    m_eventLog = eventLog;
}

/**
 * The TabularRecordParser destructor.
 */
TabularRecordParser::~TabularRecordParser() 
{
}

/**
 * Parses a header.
 */
ITabularRecordSharedPtr TabularRecordParser::Parse(
    size_t recordIndex,
    const std::wstring& content) const
{
    //
    // Parse tokens of header...
    //
    std::vector<std::wstring> tokens;
    bool status = m_tokenParser->Parse(content, tokens);

    if (!status) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream eventDescriptionStream;
        eventDescriptionStream 
            << L"The Tabular Record Parser has failed parsing tokens of record index: " << recordIndex 
            << L" with content: " << content
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring eventName = L"TabularRecordParser";
        std::wstring eventDescription = eventDescriptionStream.str();

        if (m_parsingPolicyType == ParsingPolicyType::FAIL_ON_FIRST_ERROR) {
            m_eventLog->SetErrorEvent(
                eventName, 
                eventDescription);
            
            throw TabularDataException(errorCode, eventDescription);
        } 
        else {
            m_eventLog->SetWarningEvent(
                eventName, 
                eventDescription);
            
            return nullptr;
        }
    }

    //
    // Create a record...
    //
    return TabularRecord::Make(
        recordIndex, 
        content, 
        tokens);
}
