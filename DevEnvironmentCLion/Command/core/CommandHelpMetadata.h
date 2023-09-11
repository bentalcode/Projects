#ifndef COMMAND_HELP_METADATA_H_efed9bb8_5f12_455c_88f5_076e86ddf7f4
#define COMMAND_HELP_METADATA_H_efed9bb8_5f12_455c_88f5_076e86ddf7f4

#include "ICommandHelpMetadata.h"
#include "INamedParameterMetadata.h"
#include "CommandConstants.h"

namespace command {

    /**
     * The CommandHelpMetadata class implements a command handler for running commands.
     */
    class CommandHelpMetadata : public ICommandHelpMetadata
    {
    public:
        /**
         * Creates a help parameter.
         */
        static IParameterPtr createHelpParameter();

        /**
         * Creates meta-data of a help parameter.
         */
        static INamedParameterMetadataPtr createHelpParameterMetadata();

        /**
         * Creates a new command help metadata.
         */
        static ICommandHelpMetadataPtr make(
            const std::string& usageMessage,
            const std::string& shortName = CommandConstants::helpShortName,
            const std::string& longName = CommandConstants::helpLongName);


        /**
         * The CommandHelpMetadata constructor.
         */
        CommandHelpMetadata(
            const std::string& shortName,
            const std::string& longName,
            const std::string& usageMessage);

        /**
         * The CommandHelpMetadata destructor.
         */
        virtual ~CommandHelpMetadata();

        /**
         * The copy/move constructors.
         */
        CommandHelpMetadata(const CommandHelpMetadata&) = delete;
        CommandHelpMetadata(CommandHelpMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CommandHelpMetadata& operator=(const CommandHelpMetadata&) = delete;
        CommandHelpMetadata& operator=(CommandHelpMetadata&&) = delete;

        /**
         * Gets a short name of a help parameter.
         */
        virtual const std::string& getShortName() const override;

        /**
         * Gets a long name of a help parameter.
         */
        virtual const std::string& getLongName() const override;

        /**
         * Gets a usage message of a command.
         */
        virtual const std::string& getUsageMessage() const override;

    private:
        std::string m_shortName;
        std::string m_longName;
        std::string m_usageMessage;
    };

    using ICommandHelpMetadataPtr = std::shared_ptr<ICommandHelpMetadata>;
}

#endif // COMMAND_HELP_METADATA_H_efed9bb8_5f12_455c_88f5_076e86ddf7f4
