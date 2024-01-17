#ifndef TABULAR_RECORD_PARSER_H_c1afd625_4fbf_48d1_95ed_7ae675c4f4ad
#define TABULAR_RECORD_PARSER_H_c1afd625_4fbf_48d1_95ed_7ae675c4f4ad

#include "ITabularRecordParser.h"
#include "ParsingPolicyType.h"
#include "TokensParser.h"
#include "EventLog.h"

namespace tabular_data {

/**
 * The TabularRecordParser class implements a Tabular Record Parser.
 */
class TabularRecordParser final : public ITabularRecordParser {
public:
    /**
     * Creates a Tabular Record Parser.
     */
    static ITabularRecordParserSharedPtr Make(
        ParsingPolicyType parsingPolicyType = ParsingPolicyType::FAIL_ON_FIRST_ERROR, 
        ITokensParserSharedPtr tokenParser = TokensParser::Make(),
        IEventLogSharedPtr eventLog = EventLog::Make());

    /**
     * The TabularRecordParser constructor.
     */
    TabularRecordParser(
        ParsingPolicyType parsingPolicyType, 
        ITokensParserSharedPtr tokenParser,
        IEventLogSharedPtr eventLog);

    /**
     * The TabularRecordParser destructor.
     */
    virtual ~TabularRecordParser();

    /**
     * Parses a record.
     */
    virtual ITabularRecordSharedPtr Parse(
        size_t recordIndex,
        const std::wstring& content) const override;

private:
    ParsingPolicyType m_parsingPolicyType;
    ITokensParserSharedPtr m_tokenParser;
    IEventLogSharedPtr m_eventLog;
};

} // namespace tabular_data

#endif // TABULAR_RECORD_PARSER_H_c1afd625_4fbf_48d1_95ed_7ae675c4f4ad
