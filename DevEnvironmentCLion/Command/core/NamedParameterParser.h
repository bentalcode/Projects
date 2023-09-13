#ifndef NAMED_PARAMETER_PARSER_H_fa9858c9_d9a0_4234_9161_18b863fe7420
#define NAMED_PARAMETER_PARSER_H_fa9858c9_d9a0_4234_9161_18b863fe7420

#include "IParser.h"
#include "IInputParameters.h"
#include "Pair.h"

namespace command {

    /**
     * The NamedParameterParser class implements a parser of a named parameter.
     */
    class NamedParameterParser final : public base::IParser<std::string, base::PairSharedPtr<std::string, std::string>>
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
        virtual base::IParsingResultSharedPtr<base::PairSharedPtr<std::string, std::string>> parse(const std::string& arg) override;

        /**
         * Checks if a parameter is named parameter.
         */
        static bool isNamedParameter(const std::string& arg);

    private:
        /**
         * Parses a named parameter.
         */
        static base::IParsingResultSharedPtr<base::PairSharedPtr<std::string, std::string>> parseNamedParameter(
            const std::string& arg,
            const std::string& prefix);

        /**
         * Checks if a parameter is long named parameter.
         */
        static bool isLongNamedParameter(const std::string& arg);

        /**
         * Checks if a parameter is short named parameter.
         */
        static bool isShortNamedParameter(const std::string& arg);
    };
}

#endif // NAMED_PARAMETER_PARSER_H_fa9858c9_d9a0_4234_9161_18b863fe7420
