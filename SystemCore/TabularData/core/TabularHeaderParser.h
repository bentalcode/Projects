#ifndef TABULAR_HEADER_PARSER_H_84fc6f43_773a_460c_b1a1_909fe57f35c1
#define TABULAR_HEADER_PARSER_H_84fc6f43_773a_460c_b1a1_909fe57f35c1

#include "ITabularHeaderParser.h"
#include "ParsingPolicyType.h"
#include "TokensParser.h"
#include "EventLog.h"

namespace tabular_data {

/**
 * The TabularHeaderParser class implements a Tokens Header Parser.
 */
class TabularHeaderParser final : public ITabularHeaderParser {
public:
    /**
     * Creates a Tabular Header Parser.
     */
    static ITabularHeaderParserSharedPtr Make(
        ParsingPolicyType parsingPolicyType = ParsingPolicyType::FAIL_ON_FIRST_ERROR, 
        ITokensParserSharedPtr tokenParser = TokensParser::Make(),
        IEventLogSharedPtr eventLog = EventLog::Make());

    /**
     * The TabularHeaderParser constructor.
     */
    TabularHeaderParser(
        ParsingPolicyType parsingPolicyType,
        ITokensParserSharedPtr tokenParser,
        IEventLogSharedPtr eventLog);

    /**
     * The TabularHeaderParser destructor.
     */
    virtual ~TabularHeaderParser();

    /**
     * Parses a header.
     */
    virtual ITabularHeaderSharedPtr Parse(const std::wstring& content) const override;

private:
    ParsingPolicyType m_parsingPolicyType;
    ITokensParserSharedPtr m_tokenParser;
    IEventLogSharedPtr m_eventLog;
};

} // namespace tabular_data

#endif // TABULAR_HEADER_PARSER_H_84fc6f43_773a_460c_b1a1_909fe57f35c1

