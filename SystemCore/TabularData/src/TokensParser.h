#pragma once

#include "ITokensParser.h"
#include <regex>

namespace TabularData {

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

} // namespace TabularData
