#ifndef I_TABULAR_HEADER_PARSER_H_de1339fb_a0ed_4390_9fb6_7337f5b85ff6
#define I_TABULAR_HEADER_PARSER_H_de1339fb_a0ed_4390_9fb6_7337f5b85ff6

#include "ITabularHeader.h"

namespace tabular_data {

/**
 * The ITabularHeaderParser interface defines a parser of a Tabular Header.
 */
class ITabularHeaderParser {
public:
    ITabularHeaderParser() = default;
    virtual ~ITabularHeaderParser() = default;

    /**
     * Parses a header.
     */
    virtual ITabularHeaderSharedPtr Parse(const std::wstring& content) const = 0;
};

/**
 * Defines the Shared Ptr of Tabular Header Parser.
 */
using ITabularHeaderParserSharedPtr = std::shared_ptr<ITabularHeaderParser>;

} // namespace tabular_data

#endif // I_TABULAR_HEADER_PARSER_H_de1339fb_a0ed_4390_9fb6_7337f5b85ff6
