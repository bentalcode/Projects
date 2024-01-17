#ifndef I_TOKENS_PARSER_H_74829ec6_0071_4df3_935b_9d34cfdf7ee3
#define I_TOKENS_PARSER_H_74829ec6_0071_4df3_935b_9d34cfdf7ee3

#include <string>
#include <vector>
#include <memory>

namespace tabular_data {

/**
 * The ITokensParser interface defines a parser of tokens.
 */
class ITokensParser {
public:
    ITokensParser() = default;
    virtual ~ITokensParser() = default;

    /**
     * Parses tokens.
     */
    virtual bool Parse(
        const std::wstring& content, 
        std::vector<std::wstring>& tokens) const = 0;
};

/**
 * Defines the Shared Ptr of Tokens Parser.
 */
using ITokensParserSharedPtr = std::shared_ptr<ITokensParser>;

} // namespace tabular_data

#endif // I_TOKENS_PARSER_H_74829ec6_0071_4df3_935b_9d34cfdf7ee3
