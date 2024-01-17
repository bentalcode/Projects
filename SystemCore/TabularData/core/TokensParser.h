#ifndef TOKENS_PARSER_H_75ff5a2b_a300_47e9_afce_aaf2daadec27
#define TOKENS_PARSER_H_75ff5a2b_a300_47e9_afce_aaf2daadec27

#include "ITokensParser.h"
#include <regex>

namespace tabular_data {

/**
 * The TokensParser class implements a Tokens Parser.
 */
class TokensParser final : public ITokensParser {
public:
    /**
     * Creates a Tokens Parser.
     */
    static ITokensParserSharedPtr Make(const std::wstring& regexSeparator = L"[ \t]+");

    /**
     * The TokensParser constructor.
     */
    explicit TokensParser(const std::wstring& regexSeparator);

    /**
     * The TokensParser destructor.
     */
    virtual ~TokensParser();

    /**
     * Parses tokens.
     */
    virtual bool Parse(
        const std::wstring& content, 
        std::vector<std::wstring>& tokens) const override;

private:
    std::wregex m_regexSeparator;
};

} // namespace tabular_data

#endif // TOKENS_PARSER_H_75ff5a2b_a300_47e9_afce_aaf2daadec27
