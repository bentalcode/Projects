#ifndef COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122
#define COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122

#include "ICommandManifest.h"

namespace command {

    /**
     * The CommandManifest class implements a command manifest for defining commands.
     */
    class CommandManifest final : public ICommandManifest
    {
    public:
        /**
         * Creates a new Command manifest.
         */
        static ICommandManifestSharedPtr Make(
            const std::wstring& name,
            const std::wstring& description,
            const std::wstring& usageMessage);

        /**
         * Creates a new Command manifest.
         */
        static ICommandManifestSharedPtr Make(
            const std::wstring& name,
            const std::wstring& description,
            const std::wstring& usageMessage,
            const std::vector<IParameterSetMetadataSharedPtr>& parameterSetMetadata);


        /**
         * The CommandManifest constructor.
         */
        CommandManifest(
            const std::wstring& name,
            const std::wstring& description,
            const std::wstring& usageMessage,
            ICommandHelpMetadataSharedPtr helpMetadata,
            const std::vector<IParameterSetMetadataSharedPtr>& parameterSetMetadata);

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
        virtual const std::wstring& GetName() const override;

        /**
         * Gets description of a command.
         */
        virtual const std::wstring& GetDescription() const override;

        /**
         * Gets help metadata of a command.
         */
        virtual const ICommandHelpMetadata& GetHelpMetadata() const override;

        /**
         * Gets parameter-sets metadata of a command.
         */
        virtual void GetParameterSetsMetadata(std::vector<IParameterSetMetadataSharedPtr>& parameterSets) const override;

    private:
        std::wstring m_name;
        std::wstring m_description;
        std::wstring m_usageMessage;
        ICommandHelpMetadataSharedPtr m_helpMetadata;
        std::vector<IParameterSetMetadataSharedPtr> m_parameterSetMetadata;
    };

    //
    // Defines the SharedPtr of Command Manifest...
    //
    using ICommandManifestSharedPtr = std::shared_ptr<ICommandManifest>;

} // namespace command

#endif // COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122
