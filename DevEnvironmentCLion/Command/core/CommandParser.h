#ifndef COMMAND_PARSER_H_71982c11_e589_49dc_a280_b8ea2c24daad
#define COMMAND_PARSER_H_71982c11_e589_49dc_a280_b8ea2c24daad

#include "IMainParser.h"
#include "ICommandParameters.h"
#include "IInputParameters.h"

namespace command {

    /**
     * The CommandParser class implements a parser of the command.
     */
    class CommandParser final : public base::IMainParser<ICommandParametersPtr>
    {
    public:
        /**
         * The CommandParser Constructor.
         */
        CommandParser();

        /**
         * The CommandParser destructor.
         */
        virtual ~CommandParser();

        /**
         * The copy/move constructors.
         */
        CommandParser(const CommandParser&) = delete;
        CommandParser(CommandParser&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CommandParser& operator=(const CommandParser&) = delete;
        CommandParser& operator=(CommandParser&&) = delete;

        /**
         * Parses the parameters of the command.
         */
        virtual base::IParsingResultPtr<ICommandParametersPtr> parse(int argc, char *argv[]) override;

    private:
        /**
         * Parses input parameters of a command.
         */
        base::IParsingResultPtr<IInputParametersPtr> parseInputParameters(int argc, char *argv[]);

        /**
         * Parses parameter-sets of a command.
         */
        base::IParsingResultPtr<IParameterSetPtr> parseParameterSets(const IInputParameters& inputParameters);

        /**
         * Checks if a parameter is named parameter.
         */
        static bool isNamedParameter(const std::string& arg);

        /**
         * Checks if a parameter is short named parameter.
         */
        static bool isShortNamedParameter(const std::string& arg);

        /**
         * Checks if a parameter is long named parameter.
         */
        static bool isLongNamedParameter(const std::string& arg);

        /**
         * Checks whether this is a help command.
        */
        static bool isHelpCommand(const IInputParameters& inputParameters);

        /**
         * Creates a result of a help command.
         */
        static base::IParsingResultPtr<ICommandParametersPtr> createHelpCommandResult();
    };
}

#endif // COMMAND_PARSER_H_71982c11_e589_49dc_a280_b8ea2c24daad
