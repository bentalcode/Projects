#ifndef I_COMMAND_HELP_METADATA_H_03286718_f72f_46c0_841f_7d81827af3a0
#define I_COMMAND_HELP_METADATA_H_03286718_f72f_46c0_841f_7d81827af3a0

#include "ICommand.h"

namespace command {

    /**
     * The ICommandHelpMetadata interface defines meta-data of help of a command.
     */
    class ICommandHelpMetadata
    {
    public:
        /**
         * The constructor.
         */
        ICommandHelpMetadata() = default;

        /**
         * The destructor.
         */
        virtual ~ICommandHelpMetadata() = default;

        /**
         * The copy/move constructors.
         */
        ICommandHelpMetadata(const ICommandHelpMetadata&) = delete;
        ICommandHelpMetadata(ICommandHelpMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICommandHelpMetadata& operator=(const ICommandHelpMetadata&) = delete;
        ICommandHelpMetadata& operator=(ICommandHelpMetadata&&) = delete;

        /**
         * Gets a short name of a help parameter.
         */
        virtual const std::string& getShortName() const = 0;

        /**
         * Gets a long name of a help parameter.
         */
        virtual const std::string& getLongName() const = 0;

        /**
         * Gets a usage message of a command.
         */
        virtual const std::string& getUsageMessage() const = 0;
    };

    using ICommandHelpMetadataPtr = std::shared_ptr<ICommandHelpMetadata>;
}

#endif // I_COMMAND_HELP_METADATA_H_03286718_f72f_46c0_841f_7d81827af3a0
