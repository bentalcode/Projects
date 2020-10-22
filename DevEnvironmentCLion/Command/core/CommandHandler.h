#ifndef COMMAND_HANDLER_H_1b5a366f_f0f5_40c8_900b_241bbaba13bf
#define COMMAND_HANDLER_H_1b5a366f_f0f5_40c8_900b_241bbaba13bf

#include "ICommandHandler.h"
#include "ICommandManifest.h"
#include "ICommandMessageWriter.h"
#include "ParsingResult.h"

namespace command {

    /**
     * The CommandHandler class implements a command handler for running commands.
     */
    class CommandHandler : public ICommandHandler
    {
    public:
        /**
         * Creates a new command handler.
         */
        static ICommandHandlerPtr make(ICommandManifestPtr manifest);

        /**
         * The CommandHandler constructor.
         */
        explicit CommandHandler(ICommandManifestPtr manifest);

        /**
         * The CommandHandler destructor.
         */
        virtual ~CommandHandler();

        /**
         * The copy/move constructors.
         */
        CommandHandler(const CommandHandler&) = delete;
        CommandHandler(CommandHandler&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CommandHandler& operator=(const CommandHandler&) = delete;
        CommandHandler& operator=(CommandHandler&&) = delete;

        /**
         * Runs a command and returns the exit status.
         */
        virtual int run(ICommand& command, int argc, char *argv[]) override;

    private:
        /**
         * Runs a command.
         *
         * Returns true if running the command successfully.
         * Returns false if failing to run the command.
         */
        bool runCommand(ICommand& command, int argc, char *argv[]);

        /**
         * Parses the parameters of a command.
         */
        static base::IParsingResultPtr<ICommandParametersPtr> parseParameters(int argc, char *argv[]);

        /**
         * Checks whether this is a help command.
         */
        static bool isHelpCommand(const ICommandParameters& parameters);

        ICommandManifestPtr m_manifest;
        ICommandMessageWriterPtr m_commandMessageWriter;
    };
}

#endif // COMMAND_HANDLER_H_1b5a366f_f0f5_40c8_900b_241bbaba13bf
