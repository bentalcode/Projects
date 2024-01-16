#ifndef NAMED_PARAMETER_PARSER_H_fa9858c9_d9a0_4234_9161_18b863fe7420
#define NAMED_PARAMETER_PARSER_H_fa9858c9_d9a0_4234_9161_18b863fe7420

#include "IParser.h"
#include "IInputParameters.h"
#include "Pair.h"

namespace command {

    /**
     * The NamedParameterParser class implements a parser of a named parameter.
     */
    class NamedParameterParser final : public IParser<std::wstring, base::PairSharedPtr<std::wstring, std::wstring>>
    {
    public:
        /**
         * The constructor.
         */
        NamedParameterParser();

        /**
         * The destructor.
         */
        virtual ~NamedParameterParser();

        /**
         * The copy/move constructors.
         */
        NamedParameterParser(const NamedParameterParser&) = delete;
        NamedParameterParser(NamedParameterParser&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        NamedParameterParser& operator=(const NamedParameterParser&) = delete;
        NamedParameterParser& operator=(NamedParameterParser&&) = delete;

        /**
         * Parses a named parameter.
         */
        virtual IParsingResultSharedPtr<base::PairSharedPtr<std::wstring, std::wstring>> Parse(const std::wstring& arg) override;

        /**
         * Checks if a parameter is named parameter.
         */
        static bool IsNamedParameter(const std::wstring& arg);

    private:
        /**
         * Parses a named parameter.
         */
        static IParsingResultSharedPtr<base::PairSharedPtr<std::wstring, std::wstring>> parseNamedParameter(
            const std::wstring& arg,
            const std::wstring& prefix);

        /**
         * Checks if a parameter is long named parameter.
         */
        static bool isLongNamedParameter(const std::wstring& arg);

        /**
         * Checks if a parameter is short named parameter.
         */
        static bool isShortNamedParameter(const std::wstring& arg);
    };

} // namespace command

#endif // NAMED_PARAMETER_PARSER_H_fa9858c9_d9a0_4234_9161_18b863fe7420
