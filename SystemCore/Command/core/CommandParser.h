#ifndef COMMAND_PARSER_H_71982c11_e589_49dc_a280_b8ea2c24daad
#define COMMAND_PARSER_H_71982c11_e589_49dc_a280_b8ea2c24daad

#include "IMainParser.h"
#include "ICommandParameters.h"
#include "IInputParameters.h"
#include "ICommandManifest.h"

namespace Command {

    /**
     * The CommandParser class implements a parser of the Command.
     */
    class CommandParser final : public IMainParser<ICommandParametersSharedPtr>
    {
    public:
        /**
         * The CommandParser Constructor.
         */
        explicit CommandParser(ICommandManifestSharedPtr manifest);

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
         * Parses the parameters of command.
         */
        virtual IParsingResultSharedPtr<ICommandParametersSharedPtr> Parse(int argc, wchar_t *argv[]) override;

    private:
        /**
         * Parses input parameters of command.
         */
        IParsingResultSharedPtr<IInputParametersSharedPtr> ParseInputParameters(int argc, wchar_t *argv[]);

        /**
         * Parses parameter-sets of command.
         */
        IParsingResultSharedPtr<IParameterSetSharedPtr> ParseParameterSets(const IInputParameters& inputParameters);

        /**
         * Checks if a parameter is named parameter.
         */
        static bool IsNamedParameter(const std::wstring& arg);

        /**
         * Checks if a parameter is short named parameter.
         */
        static bool IsShortNamedParameter(const std::wstring& arg);

        /**
         * Checks if a parameter is long named parameter.
         */
        static bool IsLongNamedParameter(const std::wstring& arg);

        /**
         * Checks whether this is a help command.
        */
        static bool IsHelpCommand(const IInputParameters& inputParameters);

        /**
         * Creates a result of a help command.
         */
        static IParsingResultSharedPtr<ICommandParametersSharedPtr> CreateHelpCommandResult();

        //
        // The manifest of command...
        //
        ICommandManifestSharedPtr m_manifest;
    };

} // namespace Command

#endif // COMMAND_PARSER_H_71982c11_e589_49dc_a280_b8ea2c24daad
