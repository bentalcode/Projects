#ifndef COMMAND_HELP_METADATA_H_efed9bb8_5f12_455c_88f5_076e86ddf7f4
#define COMMAND_HELP_METADATA_H_efed9bb8_5f12_455c_88f5_076e86ddf7f4

#include "ICommandHelpMetadata.h"
#include "IParameter.h"
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
        static IParameterSharedPtr CreateHelpParameter();

        /**
         * Creates meta-data of a help parameter.
         */
        static IParameterMetadataSharedPtr CreateHelpParameterMetadata();

        /**
         * Creates a new Command help metadata.
         */
        static ICommandHelpMetadataSharedPtr Make(
            const std::wstring& usageMessage,
            const std::wstring& shortName = CommandConstants::HELP_SHORT_NAME,
            const std::wstring& longName = CommandConstants::HELP_LONG_NAME);


        /**
         * The CommandHelpMetadata constructor.
         */
        CommandHelpMetadata(
            const std::wstring& shortName,
            const std::wstring& longName,
            const std::wstring& usageMessage);

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
        virtual const std::wstring& GetShortName() const override;

        /**
         * Gets a long name of a help parameter.
         */
        virtual const std::wstring& GetLongName() const override;

        /**
         * Gets a usage message of a command.
         */
        virtual const std::wstring& GetUsageMessage() const override;

    private:
        std::wstring m_shortName;
        std::wstring m_longName;
        std::wstring m_usageMessage;
    };

    //
    // Defines the SharedPtr of Command Help Metadata...
    //
    using ICommandHelpMetadataSharedPtr = std::shared_ptr<ICommandHelpMetadata>;

} // namespace command

#endif // COMMAND_HELP_METADATA_H_efed9bb8_5f12_455c_88f5_076e86ddf7f4
