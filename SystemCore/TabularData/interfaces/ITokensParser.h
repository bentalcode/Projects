#pragma once

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
