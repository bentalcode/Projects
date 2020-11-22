#ifndef COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122
#define COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122

#include "ICommandManifest.h"

namespace command {

    /**
     * The CommandManifest class implements a command handler for running commands.
     */
    class CommandManifest final : public ICommandManifest
    {
    public:
        /**
         * Creates a new command manifest.
         */
        static ICommandManifestPtr make(
            const std::string& name,
            const std::string& description,
            const std::string& usageMessage);

        /**
         * Creates a new command manifest.
         */
        static ICommandManifestPtr make(
            const std::string& name,
            const std::string& description,
            const std::string& usageMessage,
            const std::vector<IParameterSetMetadataPtr>& parameterSetMetadata);


        /**
         * The CommandManifest constructor.
         */
        CommandManifest(
            const std::string& name,
            const std::string& description,
            const std::string& usageMessage,
            ICommandHelpMetadataPtr helpMetadata,
            const std::vector<IParameterSetMetadataPtr>& parameterSetMetadata);

        /**
         * The CommandManifest destructor.
         */
        virtual ~CommandManifest();

        /**
         * The copy/move constructors.
         */
        CommandManifest(const CommandManifest&) = delete;
        CommandManifest(CommandManifest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CommandManifest& operator=(const CommandManifest&) = delete;
        CommandManifest& operator=(CommandManifest&&) = delete;

        /**
         * Gets name of a command.
         */
        virtual const std::string& getName() const override;

        /**
         * Gets description of a command.
         */
        virtual const std::string& getDescription() const override;

        /**
         * Gets help metadata of a command.
         */
        virtual const ICommandHelpMetadata& getHelpMetadata() const override;

        /**
         * Gets parameter-sets metadata of a command.
         */
        virtual void getParameterSets(std::vector<IParameterSetMetadataPtr>& parameterSets) const override;

    private:
        std::string m_name;
        std::string m_description;
        std::string m_usageMessage;
        ICommandHelpMetadataPtr m_helpMetadata;
        std::vector<IParameterSetMetadataPtr> m_parameterSetMetadata;
    };

    using ICommandManifestPtr = std::shared_ptr<ICommandManifest>;
}

#endif // COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122
