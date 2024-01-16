#ifndef CONSOLE_FILE_FINDER_COMMAND_MANIFEST_H_b044f250_96eb_4542_9eb7_7d702da7e7a6
#define CONSOLE_FILE_FINDER_COMMAND_MANIFEST_H_b044f250_96eb_4542_9eb7_7d702da7e7a6

#include "ICommandManifest.h"

namespace consolefilefinder {

/**
 * The ConsoleFileFinderCommandManifest class implements a console file finder command manifest.
 */
class ConsoleFileFinderCommandManifest final : public Command::ICommandManifest
    {
    public:
        /**
         * Creates a manifest.
         */
        static Command::ICommandManifestSharedPtr Make();

        /**
         * The ConsoleFileFinderCommandManifest constructor.
         */
        ConsoleFileFinderCommandManifest();

        /**
         * The ConsoleFileFinderCommandManifest destructor.
         */
        virtual ~ConsoleFileFinderCommandManifest();

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
        virtual const Command::ICommandHelpMetadata& GetHelpMetadata() const override;

    /**
     * Gets parameter-sets metadata of a command.
     */
    virtual void GetParameterSetsMetadata(
        std::vector<Command::IParameterSetMetadataSharedPtr>& parameterSetsMetadata) const override;

    private:
        /**
         * Initializes manifest.
         */
        void Initialize();

        /**
         * Creates a help metadata.
         */
        static Command::ICommandHelpMetadataSharedPtr CreateHelpMetadata();

        /**
         * Creates usage message.
         */
        static std::wstring CreateUsageMessage();

        /**
         * Creates parameter sets.
         */
        static void CreateParameterSets(std::vector<Command::IParameterSetMetadataSharedPtr>& parameterSets);

        /**
         * Creates a default parameter set.
         */
        static Command::IParameterSetMetadataSharedPtr CreateDefaultParameterSet();

        /**
         * Creates a parameter set1.
         */
        static Command::IParameterSetMetadataSharedPtr CreateParameterSet1();

        /**
         * Creates a parameter set2.
         */
        static Command::IParameterSetMetadataSharedPtr CreateParameterSet2();

        std::wstring m_name;
        std::wstring m_description;
        Command::ICommandHelpMetadataSharedPtr m_helpMetadata;
        std::vector<Command::IParameterSetMetadataSharedPtr> m_parameterSets;
    };

} // namespace consolefilefinder

#endif // CONSOLE_FILE_FINDER_COMMAND_MANIFEST_H_b044f250_96eb_4542_9eb7_7d702da7e7a6
