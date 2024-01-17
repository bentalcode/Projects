#include "TokensParser.h"
#include <assert.h>

using namespace tabular_data;

/**
 * Creates a Tokens Parser.
 */
ITokensParserSharedPtr TokensParser::Make(const std::wstring& regexSeparator)
{
    return std::make_shared<TokensParser>(regexSeparator);
}

/**
 * The TokensParser constructor.
 */
TokensParser::TokensParser(const std::wstring& regexSeparator) : 
    m_regexSeparator(regexSeparator) 
{
}

/**
 * The TokensParser destructor.
 */
TokensParser::~TokensParser() 
{
}

/**
 * Parses tokens.
 */
bool TokensParser::Parse(
    const std::wstring& content, 
    std::vector<std::wstring>& tokens) const 
{
    assert(tokens.empty());

    std::copy(
        std::wsregex_token_iterator(content.begin(), content.end(), m_regexSeparator, -1), 
        std::wsregex_token_iterator(),
        std::back_inserter(tokens));

    return true;
}
