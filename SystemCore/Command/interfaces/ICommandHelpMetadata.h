#ifndef I_COMMAND_HELP_METADATA_H_03286718_f72f_46c0_841f_7d81827af3a0
#define I_COMMAND_HELP_METADATA_H_03286718_f72f_46c0_841f_7d81827af3a0

#include <memory>

namespace Command {

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
        virtual const std::wstring& GetShortName() const = 0;

        /**
         * Gets a long name of a help parameter.
         */
        virtual const std::wstring& GetLongName() const = 0;

        /**
         * Gets a usage message of a command.
         */
        virtual const std::wstring& GetUsageMessage() const = 0;
    };

    //
    // Defines the SharedPtr of Command Help Metadata...
    //
    using ICommandHelpMetadataSharedPtr = std::shared_ptr<ICommandHelpMetadata>;

} // namespace Command

#endif // I_COMMAND_HELP_METADATA_H_03286718_f72f_46c0_841f_7d81827af3a0
