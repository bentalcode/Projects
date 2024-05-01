#ifndef LOG_TOKENS_PARSER_H_5b8a3f06_00d0_48a2_85d2_51b4fe0fa8eb
#define LOG_TOKENS_PARSER_H_5b8a3f06_00d0_48a2_85d2_51b4fe0fa8eb

#include "ITokensParser.h"
#include <regex>

namespace logging {

    /**
     * The LogTokensParser class implements a Log Tokens Parser.
     */
    class LogTokensParser final : public tabular_data::ITokensParser {
    public:
        /**
         * Creates default regex seperators.
         */
        static std::vector<std::wstring> CreateDefaultRegexSeperators();

        /**
         * Creates a Log Tokens Parser.
         */
        static tabular_data::ITokensParserSharedPtr Make(const std::vector<std::wstring> = CreateDefaultRegexSeperators());

        /**
         * The LogTokensParser constructor.
         */
        explicit LogTokensParser(const std::vector<std::wstring>& regexSeparators);

        /**
         * The LogTokensParser destructor.
         */
        virtual ~LogTokensParser();

        /**
         * Parses tokens.
         */
        virtual bool Parse(
            const std::wstring& content,
            std::vector<std::wstring>& tokens) const override;

    private:
        static const std::wstring SPACE_REGEX;
        static const std::wstring LINE_INDEX_REGEX;
        static const std::wstring TIME_REGEX1;
        static const std::wstring TIME_REGEX2;
        static const std::wstring THREAD_ID_REGEX;
        static const std::wstring COMPONENT_REGEX;
        static const std::wstring LOG_LEVEL_REGEX;
        static const std::wstring FUNCTION_REGEX;
        static const std::wstring SHARED_MEMORY_REGEX;
        static const std::wstring MESSAGE_REGEX;
        static const std::wstring FILE_LINE_REGEX;

        static const std::wstring REGEX_SEPERATOR1;
        static const std::wstring REGEX_SEPERATOR2;

        /**
         * Parses tokens.
         */
        static bool Parse(
            const std::wstring& content,
            const std::wstring& regexSeperator,
            std::vector<std::wstring>& tokens);

        /**
         * Extracts file/line tokens.
         */
        static std::wstring ExtractFileLineTokens(
            const std::wstring& content,
            std::wstring& fileToken,
            std::wstring& lineToken);

        std::vector<std::wstring> m_regexSeparators;
    };

} // namespace logging

#endif // LOG_TOKENS_PARSER_H_5b8a3f06_00d0_48a2_85d2_51b4fe0fa8eb
